//
// Created by culbec on 19.06.2023.
//

#include "../headers/Service.h"

Service::Service(Repository &repo) : repository{repo} {}

vector<Student> &Service::getStudenti() {
    return this->repository.getStudenti();
}

void Service::modify(int _id, int _newVarsta) {
    if (_newVarsta < 0 || _newVarsta > 90) {
        throw runtime_error("Nu se mai poate scadea varsta!\n");
    }

    try {
        int oldVarsta = this->repository.find(_id).getVarsta();
        this->repository.modify(_id, _newVarsta);
        if (_newVarsta == oldVarsta - 1) {
            this->undos.push_back(new UndoIntinerire{this->repository.find(_id)});
            this->redos.push_back(new RedoIntinerire{this->repository.find(_id)});
        } else if (_newVarsta == oldVarsta + 1) {
            this->undos.push_back(new UndoImbatranire{this->repository.find(_id)});
            this->redos.push_back(new RedoImbatranire{this->repository.find(_id)});
        }
    } catch (runtime_error &rE) {
        throw rE;
    }
}

void Service::remove(Student &student) {
    string errors;

    try {
        this->repository.remove(student.getNrMatricol());
        this->undos.push_back(new UndoStergere{student, repository});
        this->redos.push_back(new RedoStergere{student, repository});
    } catch (runtime_error &rE) {
        errors += "Nu exista studentul cu id-ul " + string{std::to_string(student.getNrMatricol())} + "\n";
    }


    if (!errors.empty()) {
        throw runtime_error(errors);
    }
}

void Service::undo() {
    if (!this->undos.empty()) {
        this->undos.back()->undo();
        delete this->undos.back();
        this->undos.pop_back();
        return;
    }

    throw runtime_error("Nu mai exista actiuni undo!\n");
}

void Service::redo() {
    if (!this->redos.empty()) {
        this->redos.back()->redo();
        delete this->redos.back();
        this->redos.pop_back();
        return;
    }

    throw runtime_error("Nu mai exista actiuni redo!\n");
}

void Service::sortStudenti() {
    sort(this->repository.getStudenti().begin(), this->repository.getStudenti().end(),
         [](const Student &s1, const Student &s2) {
             return s1.getVarsta() < s2.getVarsta();
         });
}
