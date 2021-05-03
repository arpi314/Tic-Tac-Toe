#include <stdio.h>

void board(char arr[3][3]);
int checkWin(char arr[3][3]);

int main(){
    //initializes temporary values for the 2D array
    char arr[3][3] = {{' ', ' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    int win=0, moves, player=1, row, col, i;

    board(arr);

    for(i=0; i<9; i++){

        if(player==1){

            printf("X's turn");

            do{
                printf("\nRow: ");
                scanf("%i", &row);
            }while(row < 0 || row >3);

            do{
                printf("Column: ");
                scanf("%i", &col);
            }while(col < 0 || col > 3);

            if(arr[row-1][col-1] == 'X' || arr[row-1][col-1] =='O'){
                i -= 1;
                printf("\n(%i, %i)\nOccupied!\n", row-1, col-1);

            }else{
                arr[row-1][col-1] = 'X';
                player = 0;
            }

            board(arr);
            
            if(checkWin(arr) == 1){
                win = 1;
                i = 10;
            }


        }else{

            printf("O's turn");

            do{
                printf("\nRow: ");
                scanf("%i", &row);
            }while(row < 0 || row >3);

            do{
                printf("Column: ");
                scanf("%i", &col);
            }while(col < 0 || col > 3);

            if(arr[row-1][col-1] == 'X' || arr[row-1][col-1] =='O'){
                i -= 1;
                printf("\n(%i, %i)\nOccupied!\n", row-1, col-1);
            }else{
                arr[row-1][col-1] = 'O';

                player=1;
            }

            board(arr);

            if(checkWin(arr) == 1){
                win = 2;
                i = 10;
            }

        }
    }

    //prints who the winner is 
    if(i==9 && win==0){         
        printf("Its a tie!");
    }else if(win == 1){
        printf("X wins!");
    }else if(win == 2){
        printf("O wins!");
    }

}

//the board 
void board(char arr[3][3]){

    printf(" %c | %c | %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", arr[2][0], arr[2][1], arr[2][2]);

}

//checks the winner
//something is wrong with the conditionals as it only checks in this specific order
int checkWin(char arr[3][3]){

    if(arr[0][0] != ' ' && arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]){         //First Row X
        return 1;
    }else if(arr[1][0] != ' ' && arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]){   //Second Row X
        return 1;
    }else if(arr[2][0] != ' ' && arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]){   //Third Row X
        return 1;
    }else if(arr[0][0] != ' ' && arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]){   //First Column X
        return 1;
    }else if(arr[0][1] != ' ' && arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]){   //Second Column X
        return 1;
    }else if(arr[0][2] != ' ' && arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2]){   //Third Column X
        return 1;
    }else if(arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){   //Diagonal L-R X
        return 1;
    }else if(arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){   //Diagonal R-L X
        return 1;
    }else{
        return 0;
    }
}


