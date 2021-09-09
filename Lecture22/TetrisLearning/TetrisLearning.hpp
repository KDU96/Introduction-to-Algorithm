#ifndef _TETRIS_LEARNING_
#define _TETRIS_LEARNING_

#include <iostream>
using namespace std;

enum TetrixPieceType{
    A, B, C, D, E, F,
};
class Tetrisboard{
    private :
        int width;
        int height;
    public :
        Tetrisboard(const int& row, const int& col);
        ~Tetrisboard();
};
#endif
