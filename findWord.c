#include <stdio.h>
#include <stdbool.h>
#include <math.h>
void search2D(char word[], int wordSize, const int Size, char grid[Size][Size]);
bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size],
int row, int col, int rowDir, int colDir);
const int Size = 5;
void printFoundLocation(int rowDir, int colDir);
int main(){
    char grid[5][5] = {{'b','y','f','r','e'},{'n','e','u','q','c'},{'a','e','n','u','n'},{'y','s','s','u','p'},{'h','h','h','h','h'}};
    
    search2D("ben", 3, Size, grid);
}

void search2D(char word[], int wordSize, const int Size, char grid[Size][Size]){
    
    for (int i = 0; i < Size; i++){
        for(int j = 0; j < Size; j++){
            if(grid[i][j]==word[1]){
                for(int rowDir = -1; rowDir< 2; rowDir++){
                    for(int colDir = -1; colDir < 2; colDir++){
                        if(search1D(word, wordSize,Size, grid, i, j , rowDir, colDir)){
                            printFoundLocation(rowDir,colDir);
                            break;
                        } 
                    }   
                }
            }
       }
    }
}
bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size],
int row, int col, int rowDir, int colDir){
    for(int letter = 1; letter < wordSize; letter++){
        if(grid[row][col]!=word[letter]) { return false;}
        row+= rowDir; 
        col+= colDir;
    }
    return true;
}