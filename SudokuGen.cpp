#include <SudokuGen.h>
#include <fstream>
using namespace std;

int *SudokuGen::getproblem(int x){
	ifstream in("problem",ios::in);
	for(int i=0 ; i<3 ; ++i){
		for(int j=0 ; j<81 ; ++j){
			in >> map[i][j];
		}
	}
	return map[x];
