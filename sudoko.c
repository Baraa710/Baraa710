#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const int Size = 4;
void printGrid(const int Size, int grid[Size][Size]){
    for(int i =0; i < Size; i++){
        for(int j =0; j < Size; j++){
            printf("%d ", grid[i][j]);
              
        }       
        printf("\n");
    }
}

void findRow(int row, const int Size, int sudoko[Size][Size], int found[Size], int *index){
    for(int number = 1; number <= Size; number++){
        for(int i = 0; i < Size; i++){
            if(number == sudoko[row][i]){
                found[*(index)] = number; 
                (*index)+=1;
                break;
            }
        }
    }


}

void findCol(int col, const int Size, int sudoko[Size][Size], int found[Size], int *index){
    for(int number = 1; number <= Size; number++){
        for(int j = 0; j < Size; j++){
            if(number == sudoko[j][col]){
                found[*(index)] = number; 
                (*index)++;
                break;
            }
        }
    }

}

int missingNumber(const int Size, int found[Size]){
    bool missing = true;
    for(int number = 1; number <= Size; number++){
        missing = true;
        for(int index = 0; index < 2*Size; index++){
            if(found[index] == number){
                missing = false; 
            }
            if(!missing) {break;}

        }
        if(missing)
         {return number;}
    }
    return 0;
}

void fillSudoko(const int Size, int sudoko[Size][Size]){
    int found[7];
    for(int row = 0; row < Size; row ++){
        for(int col = 0; col< Size; col++){
            if(sudoko[row][col] == 0){
                found[0] = found[1] = found [2] = found[3] =found[4]=found[5]=found[6]= 0;
                int foundNum=0;
                
                findRow(row, Size, sudoko, found, &foundNum);
                findCol(col, Size, sudoko, found, &foundNum);
                sudoko[row][col] = missingNumber(Size, found);
            }
        }
    }
    printGrid(Size, sudoko);
}



int main(){
    //  0 3 4 0
    //  4 0 0 2
    //  1 0 0 3
    //  0 2 1 0
    int sudokoGrid[4][4] = {
        {0,3,4,0},
        {4,0,0,2},
        {1,0,0,3},
        {0,2,1,0},
    };
    
    printGrid(Size, sudokoGrid);
    fillSudoko(Size, sudokoGrid);
    printf("\n");
    
    return 0;
}


