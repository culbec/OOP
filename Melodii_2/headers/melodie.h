//
// Created by culbec on 17.06.2023.
//

#ifndef MELODII_2_MELODIE_H
#define MELODII_2_MELODIE_H

#include <string>

using std::string;

class Melodie {
private:
    int id;
    string titlu, artist, gen;

public:
    Melodie(int _id, string _titlu, string _artist, string _gen);

    int getId() const;

    const string& getTitlu() const;

    const string& getArtist() const;

    const string& getGen() const;

    void setId(const int& _id);
};

#endif //MELODII_2_MELODIE_H
