//
// Created by culbec on 19.06.2023.
//

#include "../headers/Undo_Redo.h"

UndoImbatranire::UndoImbatranire(Student& stud): student{stud} {}

void UndoImbatranire::undo() {
    this->student.setVarsta(this->student.getVarsta() - 1);
}

UndoIntinerire::UndoIntinerire(Student &stud): student{stud} {}

void UndoIntinerire::undo() {
    this->student.setVarsta(this->student.getVarsta() + 1);
}

UndoStergere::UndoStergere(const Student &stud, Repository &repo): student{stud}, repository{repo} {}

void UndoStergere::undo() {
    this->repository.add(student);
}

RedoImbatranire::RedoImbatranire(Student &stud): student{stud} {}

void RedoImbatranire::redo() {
    this->student.setVarsta(this->student.getVarsta() + 1);
}

RedoIntinerire::RedoIntinerire(Student &stud): student{stud} {}

void RedoIntinerire::redo() {
    this->student.setVarsta(this->student.getVarsta() - 1);
}

RedoStergere::RedoStergere(const Student &stud, Repository &repo): student{stud}, repository{repo} {}

void RedoStergere::redo() {
    this->repository.remove(this->student.getNrMatricol());
}
