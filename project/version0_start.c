//原版，全屏闪烁
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int score = 0;
int time = 0;
char board[25][100];
int snake[5000];
int len = 0;
//5000 to store the x,y of snake, the first 2500 are x and rest are y
char input = '0';
char direct = 'a';
void printMenu();
void Game();
void initFront();
void printBoard();
void initSnake();
void printSnake();
int Judge();
void Fail();
void Move(char direct);
void Move(char direct){
    if(direct == 'a'){
        snake[2500]--;
        snake[2501]--;
        board[snake[0]][snake[2500]] = '@';
        board[snake[1]][snake[2501]+1] = ' ';
        board[snake[0]][snake[2500]+1] = '*';
    }
}
void initSnake(){
    board[13][49] = '@';//@ is the snake head
    snake[0] = 13;
    snake[2500] = 49;
    board[13][50] = '*';//* is the snake body
    snake[1] = 13;
    snake[2501] = 50;
}
void printBoard(){
    printf("GREEDY SNAKE\n");
    printf("SCORE:%d TIME: %d",score,time);
    for(int i = 0;i<68;i++){
        printf(" ");
    }
    printf("PAUSE: p QUIT: q\n");
    for(int i = 0;i<25;i++){
        for(int j = 0;j<100;j++){
                printf("%c",board[i][j]);
            }
            printf("\n");
        }
    }
void initFront(){
    for(int i = 0;i<25;i++){
        for(int j = 0;j<100;j++){
            board[i][j] = ' ';
        }
    }
    for(int i = 0;i<100;i++){
        board[0][i] = '-';
    }
    for(int i = 1;i<25;i++){
        board[i][0] = '|';
        board[i][99] = '|';
    }
    for(int i = 0;i<100;i++){
        board[24][i] = '-';
    }
}
void Game(){
    initFront();
    initSnake();
    printBoard();
    while(1){//注意以下两个的顺序
        if(_kbhit()==0){
            Move(direct);
            system("cls");
            printBoard();
        }
        else{
            input = getch();
        }
        
        if(input=='q'){//q means quit the game
            system("cls");
            printf("GOOD BYE");      
            return;       
        }
        else if(input=='p'){//p means pause the game
            
        }
        else if(input=='a'){//a means move to left

        }
        else if(input=='d'){//d means move to right

        }
        else if(input=='w'){//w means move up

        }
        else if(input=='s'){//s means move down

        }
    }
}
int main(){
    printf("GREEDY SNAKE\n");
    printf("input s to start the game\n");
    if(getch()=='s'){
        system("cls");
        printf("GOOD LUCK");//目前是想做一个倒计时3,2,1,good luck这样
        Sleep(1000);
        system("cls");
        Game();
    }
    return 0;
}