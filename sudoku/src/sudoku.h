#include <iostream>
#include <cstring>

class Sudoku {
private:
    int grid[9][9]{};

 bool _solve(int x, int y) {
        bool result = false;
        //if fird is not equal to zero
        if (grid[y][x] == 0) {// y = row x = col
            //to finish, not done
            for (int i = 1; i <= 9; i++) {
                if(num_That_Work(x,y,i)){
                    grid[y][x] = i;
                    if (y + 1 == 9 && x + 1 == 9) {
                        return true;
                    }
                    else if (x + 1 == 9 && y < 8) {
                        result = _solve(0, y + 1);
                        if (result != true) {
                            grid[y][x] = 0;
                        }
                        else {
                            return result;
                        }
                    }//end else if
                    else {
                        result = _solve(x + 1, y);
                        if (result != true) {
                            grid[y][x] = 0;
                        }
                        else {
                            return result;
                        }
                    }
                }
            }
            return result;
        }//end if
        if (y + 1 == 9 && x + 1 == 9) {
            return true;
        }
        else if (x + 1 == 9 && y < 8) {
            return _solve(0, y + 1);
        }//end else if
        else {
            return _solve(x + 1, y);
        }
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
            if (grid[i%3][i/3] != otherGrid[i%3][i/3]) {
                return false;
            }
        }
        return true;
    }

    bool operator ==(const Sudoku & other) {
        memcpy(this->grid, other.grid, 9 * 9 * sizeof(int));
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
        return _solve(0,0);   // placeholder
    }
};
