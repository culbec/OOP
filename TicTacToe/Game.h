//
// Created by profi on 6/18/2023.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Game {
private:
    int id, dim;
    string sequence, player, status;
    vector<vector<int>> table; /* va fi o matrice: -1 -> jucatorul O; 0 -> spatiu gol; 1 -> jucatorul X */
public:
    Game(int _id, int _dim, const string &seq, const string &_player);

    int getId() const;

    int getDim() const;

    const string &getSequence() const;

    const string &getPlayer() const;

    const string &getStatus() const;

    vector<vector<int>> &getTable();

    void setDim(int _dim);

    void setSequence(const string &_sequence);

    void setPlayer(const string &_player);

    void setStatus(const string &_status);

};


#endif //TICTACTOE_GAME_H
