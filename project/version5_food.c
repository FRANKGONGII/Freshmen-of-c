//这版完成实现食物的随机出现
//这版尝试让蛇长长
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
int score = 0;//得分
int playtime = 0;//时间
char board[25][100];//游戏板
int snake[5000];//前2500个元素存y(纵)坐标，后2500个存(x横)坐标
int last_tail[2];//上一次尾巴的坐标,x在前,y在后
int len = 0;//蛇的长度
char input = '0';//输入
char now_direct = 'a';//蛇的目前方向
char last_direct = 'a';//蛇上一次的方向，这样设置目的是防止180度运动(不过好像优化掉了？就先保留吧)
int if_food = 0;//查看场上有没有食物，没有为0，有为1
void printMenu();//打印菜单的函数
void Game();//游戏主函数
void initFront();//初始化边界
void printBoard();//打印整个游戏面板
void initSnake();//初始化蛇
void printSnake();//打印蛇
int Judge();//判断蛇是否会死亡
void Fail();//游戏失败
int Move(char now_direct);//控制蛇的移动
void Food();//生成食物
void Eat();//判断是不是吃到了食物


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

void Eat(){
    if(board[snake[0]][snake[2500]] == '$'){
        score++;
        len++;
        if_food = 0;
    }
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
    goto_xy(last_tail[1],last_tail[0]+2);//抹掉原先的蛇尾
    printf(" ");
}
int Move(char now_direct){
    if (now_direct == 'a'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];//保存蛇尾的位置，等会清除
        if(last_direct =='a'){//不需要转向，只要跟着走
            snake[2500]--;
            snake[4999]--;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头左移一格
                board[snake[2499]][snake[4999]+1] = ' ';//原蛇尾变成空格
                board[snake[0]][snake[2500]+1] = '*';//原蛇头的位置补上蛇尾
                return 1;
            }
        }
        else if(last_direct == 'w'){//从上转到向左
            snake[2500]--;
            snake[2499]--;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头左移一格
                board[snake[2499]+1][snake[4999]] = ' ';//原先蛇尾变成空格
                board[snake[0]][snake[2500]+1] = '*';//原蛇头补上蛇尾
                return 1;
            }
        }
        else if(last_direct == 's'){//从向下转到向左
            snake[2500]--;
            snake[2499]++;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头下移一格
                board[snake[2499]-1][snake[4999]] = ' ';//原先蛇尾变成空格
                board[snake[0]][snake[2500]+1] = '*';//原蛇头补上蛇尾
                return 1;
            }
        }
    }
    else if (now_direct == 'd'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];
        if(last_direct=='d'){//保持原来的方向
            snake[4999]++; 
            snake[2500]++;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头右移一格
                board[snake[2499]][snake[4999]-1] = ' ';
                board[snake[0]][snake[2500]-1] = '*';
                return 1;
            }
        }
        else if(last_direct == 'w'){//从向上转到向右
            snake[2500]++;
            snake[2499]--;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头右移一格
                board[snake[2499]+1][snake[4999]] = ' ';
                board[snake[0]][snake[2500]-1] = '*';
                return 1;
            }
        }
        else if(last_direct == 's'){//从向下转到向右
            snake[2500]++;
            snake[2499]++;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头右移一格
                board[snake[2499]-1][snake[4999]] = ' ';
                board[snake[0]][snake[2500]-1] = '*';
                return 1;
            }
        }
    }
    else if(now_direct == 's'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];
        if(last_direct=='s'){//不需要转向，只是跟着走
            snake[2499]++;
            snake[0]++;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头下移一格
                board[snake[2499]-1][snake[4999]] = ' ';//原先蛇尾变成空格
                board[snake[0]-1][snake[2500]] = '*';//原蛇头补上蛇尾
                return 1;
            }
        }
        else if(last_direct=='a'){//从向左转向了
            snake[4999]--;
            snake[0]++;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头下移一格
                board[snake[2499]][snake[4999]+1] = ' ';//原先蛇尾变成空格
                board[snake[0]-1][snake[2500]] = '*';//原蛇头补上蛇尾
                return 1;
            }
        }
        else if(last_direct=='d'){//从向右转向了
            snake[4999]++;
            snake[0]++;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头下移一格
                board[snake[2499]][snake[4999]-1] = ' ';//原先蛇尾变成空格
                board[snake[0]-1][snake[2500]] = '*';//原蛇头补上蛇尾
                return 1;
            }
        }
    }
    else if(now_direct == 'w'){
        last_tail[0] = snake[2499];
        last_tail[1] = snake[4999];
        if(last_direct == 'w'){
            snake[0]--;
            snake[2499]--;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头上移一格
                board[snake[2499]+1][snake[4999]] = ' ';//原先蛇尾变成空格
                board[snake[0]+1][snake[2500]] = '*';//原蛇头补上蛇尾
                return 1;
            }
        }
        else if(last_direct == 'a'){//从向左转到向上
            snake[0]--;
            snake[4999]--;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头下移一格
                board[snake[2499]][snake[4999]+1] = ' ';//原先蛇尾变成空格
                board[snake[0]+1][snake[2500]] = '*';//原蛇头补上蛇尾
                return 1;
            }
        }
        else if(last_direct == 'd'){//从向右转到向上
            snake[0]--;
            snake[4999]++;
            if(board[snake[0]][snake[2500]]=='|'||board[snake[0]][snake[2500]]=='-'||board[snake[0]][snake[2500]]=='*'){
                return 0;
            }
            else{
                Eat();
                board[snake[0]][snake[2500]] = '@';//蛇头下移一格
                board[snake[2499]][snake[4999]-1] = ' ';//原先蛇尾变成空格
                board[snake[0]+1][snake[2500]] = '*';//原蛇头补上蛇尾
                return 1;
            }
        }
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
    printf("SCORE:%d TIME: %d",score,playtime);
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
    while(1){//注意以下_kbhit和getch的顺序,这里想了好久
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
                system("cls");
                printf("YOU DIE");
                Sleep(1000);
                return;
            }
            Sleep(300);
        }
        else{
            input = getch();
            if(input=='q'){//q means quit the game
                system("cls");
                printf("GOOD BYE");
                Sleep(1000);      
                return;       
            }
            else if(input=='p'){//p means pause the game
                
            }
            else if(input=='a'&&(now_direct!='d')){//a means move to left
                last_direct = now_direct;
                now_direct = input;
                int ret = Move(now_direct);
                if(ret==1){
                    printSnake();
                }
                else if(ret==0){
                    system("cls");
                    printf("YOU DIE");
                    Sleep(1000);
                    return;
                }
                Sleep(300);
            }
            else if(input=='d'&&(now_direct!='a')){//d means move to right
                last_direct = now_direct;
                now_direct = input;
                int ret = Move(now_direct);
                if(ret==1){
                    printSnake();
                }
                else if(ret==0){
                    system("cls");
                    printf("YOU DIE");
                    Sleep(1000);
                    return;
                }
                Sleep(300);
            }
            else if(input=='w'&&(now_direct!='s')){//w means move up
                last_direct = now_direct;
                now_direct = input;
                int ret = Move (now_direct);
                if(ret==1){
                    printSnake();
                }
                else if(ret == 0){
                    system("cls");
                    printf("YOU DIE");
                    Sleep(1000);
                    return;
                }
                Sleep(300);
            }
            else if(input=='s'&&(now_direct!='w')){//s means move down
                last_direct = now_direct;
                now_direct = input;
                int ret = Move (now_direct);
                if(ret == 1){
                    printSnake();
                }
                else if(ret == 0){
                    system("cls");
                    printf("YOU DIE");
                    Sleep(1000);
                    return;
                }
                Sleep(300);
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
        system("cls");
        printf("GOOD LUCK");//目前是想做一个倒计时3,2,1,good luck这样
        Sleep(1000);
        system("cls");
        Game();
    }
    return 0;
}
