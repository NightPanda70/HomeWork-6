#include <iostream>
#include <cstring>

class Sudoku {
private:
    int grid[9][9]{};

  //recursive function that solves Sudoku
    bool _solve(int x, int y) {
        bool result = false;
        //find a cell that is empty and test possible nums
        if (grid[y][x] == 0) {// y = row x = col
            for (int i = 1; i <= 9; i++) {//test all pos input
                if(num_That_Work(x,y,i)){
                    grid[y][x] = i;
                    if (y + 1 == 9 && x + 1 == 9) {
                        return true;
                    }//end inner if
                    else if (x + 1 == 9 && y < 8) {
                        result = _solve(0, y + 1);
                        if (result != true) {
                            grid[y][x] = 0;
                        }//end inner if
                        else {
                            return result;
                        }//end else
                    }//end else if
                        result = _solve(x + 1, y);
                        if (result != true) {
                            grid[y][x] = 0;
                        }//end inner if
                        else {
                            return result;
                        }//end if
                }//end if
            }//end for
            return result;
        }//end if
        //move to the next cell
        if (y + 1 == 9 && x + 1 == 9) {
            return true;
        }//end if
        else if (x + 1 == 9 && y < 8) {
            return _solve(0, y + 1);
        }//end else if
        else {
            return _solve(x + 1, y);
        }//end else
    }//end _solve

    //test if number work
    //return true if numbers work
    bool num_That_Work(int x, int y, int num) {
        for (int i = 0; i < 9; i++) {//check H and V if num is there
            if (grid[y][i] == num || grid[i][x] == num) return false;
        }//end for
        //location i the cube
        int x_Loc = (x / 3) * 3;
        int y_Loc = (y / 3) * 3;

        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                if (grid[y_Loc + i][x_Loc + j] == num) return false;
            }//end inner for
        }//end for
        return true;
    }//end num
public:
    explicit Sudoku(int (*grid)[9]) {
        memcpy(this->grid, grid, 9 * 9 * sizeof(int));
    }

    bool operator ==(const int (*otherGrid)[9]) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%9][i/9] != otherGrid[i%9][i/9]) {
                return false;
            }
        }
        return true;
    }

    bool operator ==(const Sudoku & other) {
        for (int i=0; i<9*9; i++) {
#ifdef PRINT
            printf("comparing grid(%d, %d)\n", i%9, i/9);
#endif
            if (grid[i%9][i/9] != other.grid[i%9][i/9]) {
                return false;
            }
        }
        return true;
    }

    int get(int i, int j) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j];
        }

        return -1;
    }

    int set(int i, int j, int val) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j] = val;
        }
        return -1;
    }

    void print() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf(" [%d] ", get(i, j));
                if (j == 8) {
                    printf("\n");
                }
            }
        }
    }

    bool solve() {
        // homework
        return _solve(0,0);//call _solve returns tree when done
    }
};
