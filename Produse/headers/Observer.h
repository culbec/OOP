#pragma once

class Observer {
protected:
    string tipAgregat;
    int numberOf = 0;

public:
    Observer(const string& tip, int num): tipAgregat(tip), numberOf{num} {}

    // returneaza tipul agregat observer-ului
    const string& getTip() const {
        return this->tipAgregat;
    }

    // isi da update
    virtual void update(int num) = 0;

    virtual ~Observer() = default;
};
