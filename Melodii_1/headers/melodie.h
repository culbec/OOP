//
// Created by culbec on 16.06.2023.
//

#ifndef MELODII_1_MELODIE_H
#define MELODII_1_MELODIE_H

#include <string>

using std::string;

class Melodie {
private:
    int id;
    string titlu, artist;
    int rank;

public:
    Melodie(int i, string t, string a, int r);

    int getId() const;

    const string& getTitlu() const;
    const string& getArtist() const;

    int getRank() const;
    void setRank(int r);
};

#endif //MELODII_1_MELODIE_H
