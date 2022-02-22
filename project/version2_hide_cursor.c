//这版完成了光标隐藏
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int score = 0;//得分
int time = 0;//时间
char board[25][100];//游戏板
int snake[5000];//前2500个元素存x坐标，后2500个存y坐标（）
int last_tail[2];//上一次尾巴的坐标,x在前,y在后
int len = 0;//蛇的长度
char input = '0';//输入
char direct = 'a';//蛇的方向
void printMenu();//打印菜单的函数
void Game();//游戏主函数
void initFront();//初始化边界
void printBoard();//打印整个游戏面板
void initSnake();//初始化蛇
void printSnake();//打印蛇
int Judge();//判断蛇是否会死亡
void Fail();//游戏失败
void Move(char direct);//控制蛇的移动
void goto_xy(int x,int y);//定位光标位置到指定坐标的函数(网上找的)
void hideCursor();//用于隐藏光标(网上找的)
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // 第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void goto_xy(int x, int y)
{   
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x,y};
    SetConsoleCursorPosition(hOut, pos);
    HideCursor();
}
void printSnake(){
    for(int i = 0;i<2500;i++){
        if(snake[i]!=0){
            goto_xy(snake[i+2500],snake[i]+2);//snake[i]加2是因为最上面有两行计分器和说明
            printf("%c",board[snake[i]][snake[i+2500]]);
        }
    }
    goto_xy(last_tail[1],last_tail[0]+2);//抹掉原先的蛇尾
    printf(" ");
}
void Move(char direct){
    if(direct == 'a'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];//保存蛇尾的位置，等会清除
        snake[2500]--;
        snake[4999]--;
        board[snake[0]][snake[2500]] = '@';//蛇头前移一格
        board[snake[2499]][snake[4999]+1] = ' ';//蛇尾变成空格
        board[snake[0]][snake[2500]+1] = '*';//原蛇头的位置补上蛇尾
    }
}
void initSnake(){
    board[13][49] = '@';//@ is the snake head
    snake[0] = 13;
    snake[2500] = 49;
    board[13][50] = '*';//* is the snake tail
    snake[2499] = 13;//2499是最后一个蛇的x坐标
    snake[4999] = 50;
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
    while(1){//注意以下两个的顺序,这里想了好久
        HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coord;
        if(_kbhit()==0){
            Move(direct);
            printSnake();
            Sleep(500);
        }
        else{
            input = getch();
        }
        if(input=='q'){//q means quit the game
            system("cls");
            printf("GOOD BYE");
            Sleep(1000);      
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
    for(int i = 0;i<5000;i++){//初始化蛇
        snake[i] = 0;
    }
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