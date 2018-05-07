#ifndef SUDOKU_H
#define SUDOKU_H


#include <fstream>
#include <ctime>
#include <cstdlib>
#include "QFile"
#include "QString"
#include "sudoku.h"
#include "QDebug"
using namespace std;

class Sudoku{
    public:
        Sudoku();
        Sudoku(const int init_map[]);
        void setMap(const int set_map[]);
        int *getMap(void);
        int getElement(int index);
        bool checkUnity(int arr[]);
        bool isCorrect();
        void getQuestion();
        void setQuestion();
        int getFirstZeroIndex();
        void setElement(int index, int value);
        static const int sudokuSize = 81;
        int question[sudokuSize];
    private:
        int map[sudokuSize];

};


#endif // SUDOKU_H
