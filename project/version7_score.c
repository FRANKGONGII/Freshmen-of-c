//这版加分功能
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
int score = 0;//得分
int play_time = 0;//时间
char board[25][100];//游戏板
int snake[5000];//前2500个元素存y(纵)坐标，后2500个存(x横)坐标(2500=25*100)
int last_tail[2];//上一次尾巴的坐标,0->y,1->x
int len = 0;//蛇除了头和尾巴的长度
char ch = 0;//游戏的难度
char input = '0';//输入
char now_direct = 'a';//蛇的目前方向
char last_direct = 'a';//蛇上一次的方向，这样设置目的是防止180度运动
int if_food = 0;//场上有没有食物，没有为0，有为1
void printMenu();//打印菜单的函数
void Game();//游戏主函数
void initFront();//初始化边界
void printBoard();//打印整个游戏面板
void initSnake();//初始化蛇
void printSnake();//打印蛇
int Judge();//判断蛇是否会死亡
void Fail();//游戏失败,结束面板
int Move(char now_direct);//控制蛇的移动
void Food();//生成食物

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

void Fail(){
    system("cls");
    printf("you final score is %d",score);
    Sleep(3000);
    return;
}
void Food(){
    int x = 0;
    int y = 0;
    while(1){ 
        srand((unsigned int)time(NULL));//一开始设定了时间int为time，找了好久才发现，一定要注意变量名的设置啊。。
        x = rand()%98+1;
        srand((unsigned int)time(NULL));
        y = rand()%23+3;
        if(board[y-2][x]!='@'&&board[y-2][x]!='*'){
            board[y-2][x] = '$';
            goto_xy(x,y);
            printf("$");
            if_food = 1;//放下了一个食物
            break;
        }
    }
}
void printSnake(){
    for(int i = 0;i<2500;i++){
        if(snake[i]!=0){
            goto_xy(snake[i+2500],snake[i]+2);//snake[i]加2是因为最上面有两行计分器和说明
            printf("%c",board[snake[i]][snake[i+2500]]);
        }
    }
}
int Move(char now_direct){
    if (now_direct == 'a'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];//保存蛇尾的位置，等会清除
        if(board[snake[0]][snake[2500]-1]=='-'||board[snake[0]][snake[2500]-1]=='|'||board[snake[0]][snake[2500]-1]=='*'){
            return 0;
        }
        else if(board[snake[0]][snake[2500]-1]!='$'){
            board[snake[0]][snake[2500]-1] = '@';
            snake[4999] = snake[len+2500]; 
            snake[2499] = snake[len];//蛇尾动
            board[snake[2499]][snake[4999]] = '*';//改变蛇尾
            for(int i = len;i>=1;i--){//蛇身动
                snake[i+2500] = snake[i+2500-1];
                snake[i] = snake[i-1];
            }
            snake[2500]--;//蛇头动
            board[snake[0]][snake[2500]] = '@';//改变蛇头
            for(int i = 1;i<=len;i++){
                board[snake[i]][snake[i+2500]] = '*';//改变蛇身
            }
            board[last_tail[0]][last_tail[1]] = ' ';//原蛇尾重置
            goto_xy(last_tail[1],last_tail[0]+2);
            printf("%c",board[last_tail[0]][last_tail[1]]);
            return 1;
        }
        else if(board[snake[0]][snake[2500]-1]=='$'){
            score++;
            goto_xy(6,1);
            printf("%d",score);
            board[snake[0]][snake[2500]-1] = '@';
            if_food = 0;
            snake[len+1] = snake[len];
            snake[len+2500+1] = snake[len+2500];//新的身体在原先len的位置
            for(int i = len;i>=1;i--){//全部前移一格
                snake[i] = snake[i-1];
                snake[i+2500] = snake[i+2500-1];
            }
            snake[2500]--;//蛇头动
            board[snake[0]][snake[2500]] = '@';//改变蛇头
            len++;
            for(int i = 1;i<=len;i++){
                board[snake[i]][snake[i+2500]] = '*';//改变蛇身
            }
            return 1;
        }
    }
    else if (now_direct == 'd'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];
        if(board[snake[0]][snake[2500]+1]=='-'||board[snake[0]][snake[2500]+1]=='|'||board[snake[0]][snake[2500]+1]=='*'){
            return 0;
        }
        else if(board[snake[0]][snake[2500]+1]!='$'){
            snake[4999] = snake[len+2500]; 
            snake[2499] = snake[len];//蛇尾动
            for(int i = len;i>=1;i--){//蛇身动
                snake[i+2500] = snake[i+2500-1];
                snake[i] = snake[i-1];
            }
            snake[2500]++;//蛇头动
            board[snake[0]][snake[2500]] = '@';//改变蛇头
            for(int i = 1;i<=len;i++){
                board[snake[i]][snake[i+2500]] = '*';//改变蛇身
            }
            board[snake[2499]][snake[4999]] = '*';//改变蛇尾
            board[last_tail[0]][last_tail[1]] = ' ';//原蛇尾重置
            goto_xy(last_tail[1],last_tail[0]+2);
            printf("%c",board[last_tail[0]][last_tail[1]]);//清除原蛇尾
            return 1;
        }
        else if(board[snake[0]][snake[2500]+1]=='$'){
            score++;
            goto_xy(6,1);
            printf("%d",score);
            board[snake[0]][snake[2500]+1] = '@';
            if_food = 0;
            snake[len+1] = snake[len];
            snake[len+2500+1] = snake[len+2500];//新的身体在原先len的位置
            for(int i = len;i>=1;i--){//全部前移一格
                snake[i] = snake[i-1];
                snake[i+2500] = snake[i+2500-1];
            }
            snake[2500]++;//蛇头动
            board[snake[0]][snake[2500]] = '@';//改变蛇头
            len++;
            for(int i = 1;i<=len;i++){
                board[snake[i]][snake[i+2500]] = '*';//改变蛇身
            }
            return 1;
        }
    }
    else if(now_direct == 's'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];
        if(board[snake[0]+1][snake[2500]]=='-'||board[snake[0]+1][snake[2500]-1]=='|'||board[snake[0]+1][snake[2500]-1]=='*'){
            return 0;
        }
        else if(board[snake[0]+1][snake[2500]]!='$'){
            snake[4999] = snake[len+2500]; 
            snake[2499] = snake[len];//蛇尾动
            for(int i = len;i>=1;i--){//蛇身动
                snake[i+2500] = snake[i+2500-1];
                snake[i] = snake[i-1];
            }
            snake[0]++;//蛇头动
            board[snake[0]][snake[2500]] = '@';//改变蛇头
            for(int i = 1;i<=len;i++){
                board[snake[i]][snake[i+2500]] = '*';//改变蛇身
            }
            board[snake[2499]][snake[4999]] = '*';//改变蛇尾
            board[last_tail[0]][last_tail[1]] = ' ';//原蛇尾重置
            goto_xy(last_tail[1],last_tail[0]+2);
            printf("%c",board[last_tail[0]][last_tail[1]]);
            return 1;
        }
        else if(board[snake[0]+1][snake[2500]]=='$'){
            score++;
            goto_xy(6,1);
            printf("%d",score);
            board[snake[0]+1][snake[2500]] = '@';
            if_food = 0;
            snake[len+1] = snake[len];
            snake[len+2500+1] = snake[len+2500];//新的身体在原先len的位置
            for(int i = len;i>=1;i--){//全部前移一格
                snake[i] = snake[i-1];
                snake[i+2500] = snake[i+2500-1];
            }
            snake[0]++;//蛇头动
            board[snake[0]][snake[2500]] = '@';//改变蛇头
            len++;
            for(int i = 1;i<=len;i++){
                board[snake[i]][snake[i+2500]] = '*';//改变蛇身
            }
            return 1;
        }
    }
    else if(now_direct == 'w'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];
        if(board[snake[0]-1][snake[2500]]=='-'||board[snake[0]-1][snake[2500]]=='|'||board[snake[0]-1][snake[2500]]=='*'){
            return 0;
        }
        else if(board[snake[0]-1][snake[2500]]!='$'){
            snake[4999] = snake[len+2500]; 
            snake[2499] = snake[len];//蛇尾动
            for(int i = len;i>=1;i--){//蛇身动
                snake[i+2500] = snake[i+2500-1];
                snake[i] = snake[i-1];
            } 
            snake[0]--;//蛇头动
            board[snake[0]][snake[2500]] = '@';//改变蛇头
            for(int i = len;i>=1;i--){
                board[snake[i]][snake[i+2500]] = '*';//改变蛇身
            }
            board[snake[2499]][snake[4999]] = '*';//改变蛇尾
            board[last_tail[0]][last_tail[1]] = ' ';//原蛇尾重置
            goto_xy(last_tail[1],last_tail[0]+2);
            printf("%c",board[last_tail[0]][last_tail[1]]);
            return 1;
        }
        else if(board[snake[0]-1][snake[2500]]=='$'){
            score++;
            goto_xy(6,1);
            printf("%d",score);
            board[snake[0]-1][snake[2500]] = '@';
            if_food = 0;
            snake[len+1] = snake[len];
            snake[len+2500+1] = snake[len+2500];//新的身体在原先len的位置
            for(int i = len;i>=1;i--){//全部前移一格
                snake[i] = snake[i-1];
                snake[i+2500] = snake[i+2500-1];
            }
            snake[0]--;//蛇头动
            board[snake[0]][snake[2500]] = '@';//改变蛇头
            len++;
            for(int i = 1;i<=len;i++){
                board[snake[i]][snake[i+2500]] = '*';//改变蛇身
            }
            return 1;
        }
    }
}
void initSnake(){
    board[13][49] = '@';
    snake[0] = 13;
    snake[2500] = 49;
    board[13][50] = '*';
    snake[2499] = 13;//2499是最后一个蛇的x坐标
    snake[4999] = 50;
}
void printBoard(){
    printf("GREEDY SNAKE\n");
    printf("SCORE:%d ",score);
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
    while(1){//注意_kbhit和getch的顺序,这里想了好久
        HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coord;
        if(if_food==0){//场上没有食物
            Food();//出现一个食物
        }
        if(_kbhit()==0){
            last_direct = now_direct;
            int ret = Move(now_direct);
            if(ret==1){
                printSnake();
            }
            else if(ret==0){
                Sleep(1000);
                return;
            }
            Sleep(play_time);
        }
        else{
            input = getch();
            if(input=='q'){//q means quit the game
                Sleep(1000);      
                return;       
            }
            else if(input=='p'){//p means pause the game
                system("pause > nul");
            }
            else if(input=='a'&&(now_direct!='d')){//a means move to left
                last_direct = now_direct;
                now_direct = input;
                int ret = Move(now_direct);
                if(ret==1){
                    printSnake();
                }
                else if(ret==0){
                    Sleep(1000);
                    return;
                }
                Sleep(play_time);
            }
            else if(input=='d'&&(now_direct!='a')){//d means move to right
                last_direct = now_direct;
                now_direct = input;
                int ret = Move(now_direct);
                if(ret==1){
                    printSnake();
                }
                else if(ret==0){
                    Sleep(1000);
                    return;
                }
                Sleep(play_time);
            }
            else if(input=='w'&&(now_direct!='s')){//w means move up
                last_direct = now_direct;
                now_direct = input;
                int ret = Move (now_direct);
                if(ret==1){
                    printSnake();
                }
                else if(ret == 0){
                    Sleep(1000);
                    return;
                }
                Sleep(play_time);
            }
            else if(input=='s'&&(now_direct!='w')){//s means move down
                last_direct = now_direct;
                now_direct = input;
                int ret = Move (now_direct);
                if(ret == 1){
                    printSnake();
                }
                else if(ret == 0){
                    Sleep(1000);
                    return;
                }
                Sleep(play_time);
            }
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
        fflush(stdin);
        system("cls");
        printf("easy(e),normal(n) or hard(h)?\n");
        ch = getch();
        if(ch == 'e'){
            play_time = 300;
        }
        else if(ch=='n'){
            play_time  = 200;
        }
        else if(ch=='h'){
            play_time = 100;
        }
        system("cls");
        printf("GOOD LUCK");
        Sleep(1000);
        system("cls");
        Game();
        Fail();
    }
    return 0;
}
