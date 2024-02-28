//
// Created by culbec on 17.06.2023.
//

#ifndef TRACTOARE_TRACTOR_H
#define TRACTOARE_TRACTOR_H

#include <string>

using std::string;

class Tractor {
private:
    int id;
    string denumire, tip;
    int numarRoti;
public:
    Tractor(int _id, string _denumire, string _tip, int _numarRoti);

    int getId() const;

    const string& getDenumire() const;

    const string& getTip() const;

    int getNumarRoti() const;

    void setNumarRoti(int _numarRoti);
};


#endif //TRACTOARE_TRACTOR_H
