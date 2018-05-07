#include "sudokusol.h"


SudokuSol::SudokuSol()
{
    isSolvable = false;
}

void SudokuSol::backtracking(Sudoku question,Sudoku &answer){
    int firstZero = question.getFirstZeroIndex();
    if(firstZero == -1){
        answer = question;
        isSolvable = true;
        return;
    }
    for(int num=1 ; num<=9 ; ++num){
        question.setElement(firstZero,num);
        if(checkCondition(question.getMap())){
            backtracking(question,answer);
        }
        question.setElement(firstZero,0);
    }
    return;
}

bool SudokuSol::checkCondition(int *map){
    bool check_result;
    int check_arr[9];
    int location;
    for(int i=0; i<81; i+=9) // check rows
        {
            for(int j=0; j<9; ++j)
                check_arr[j] = map[i+j];
            check_result = checkCurrentUnity(check_arr);
            if(check_result == false)
                return false;
            }
    for(int i=0; i<9; ++i) // check columns
        {
            for(int j=0; j<9; ++j)
                check_arr[j] = map[i+9*j];
            check_result = checkCurrentUnity(check_arr);
            if(check_result == false)
                return false;
            }

        for(int i=0; i<9; ++i) // check cells
        {
            for(int j=0; j<9; ++j)
                {
                    location = 27*(i/3) + 3*(i%3)
                       +9*(j/3) + (j%3);
                    check_arr[j] = map[location];
                    }
            check_result =checkCurrentUnity(check_arr);
            if(check_result == false)
                return false;
            }
    return true;
   }

bool SudokuSol::checkCurrentUnity(int arr[]){
    int arr_unity[9]; // counters

    for(int i=0; i<9; ++i)
        arr_unity[i] = 0; // initialize
    for(int i=0; i<9; ++i)
        ++arr_unity[arr[i]-1]; // count
    for(int i=0; i<9; ++i){
        if(arr_unity[i] > 1) // all element
        return false;
    }
    return true;
}

bool SudokuSol::getIsSolvable(void){
    return isSolvable;
}


