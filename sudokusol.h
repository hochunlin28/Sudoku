#ifndef SUDOKUSOL_H
#define SUDOKUSOL_H

#include "QFile"
#include <QString>
#include <QDebug>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "sudoku.h"

class SudokuSol
{
public:
    SudokuSol();
    void getCustomerQuestion();
    void backtracking(Sudoku question, Sudoku &answer);
    bool checkCurrentUnity(int arr[]);
    bool checkCondition(int *map);
    bool getIsSolvable(void);
private:
    bool isSolvable;

};


#endif // SUDOKUSOL_H
