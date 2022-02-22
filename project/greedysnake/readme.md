！！greedysnake.c是游戏源代码，sanke.exe是用gcc生成好的可以在windows下玩的游戏程序

以下为实验报告
一、平台及编译器
    使用Windows操作系统，gcc编译器,编译指令gcc greedysnake.c
二、使用的库
    <stdio.h> <string.h> <stdlib.h> <windows.h> <conio.h> <time.h>
三、使用的较为特殊的函数及其移植性
    1.getch(),在头文件<conio.h>中,用于在不回显的情况下获得用户的输入。如果要在linux系统下运行，需要改为_getch()
    2.void goto_xy(int x,int y),定位光标位置到指定坐标的函数(网上找的),依赖于<windows.h>
      实现代码:
      void goto_xy(int x, int y)
      {   
         HANDLE hOut;
         hOut = GetStdHandle(STD_OUTPUT_HANDLE);
         COORD pos = {x,y};
         SetConsoleCursorPosition(hOut, pos);
         HideCursor();
      } 
    3.void hideCursor();//用于隐藏光标(网上找的)
     实现代码:
      void HideCursor()
      {
         CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // 第二个值为0表示隐藏光标
         SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
      }
四、设计思路和少许可能是bug的小问题
    1.大致设计思路：
      1）先获得用户选择的游戏难度
      2）再生成游戏界面，进行一些初始化
      3）蛇的运动和成长是最关键的，我使用了数组和两个全局变量now_direct和last_direct完成这个过程：如果蛇是要直线运动，那么把last_direct的值赋给now_direct，同时运动；如果要拐弯，就重新从用户处获得now_direct。在运动时，数组的前2500个元素储存的
      是蛇每个节点的y坐标，后2500个是x坐标，运动时蛇头先向获得的方向动一个格子，蛇身体的每个节点再移动到它的前一个节点的位置；
      如果蛇吃到了食物，那么就要加入一个新的节点，这个节点的位置实际上是刚才的尾巴
      4）如果判断蛇头将要碰到边界或身体，就会死，也就是说需要一定的预判
      5）玩家死了之后显示分数，询问是否再次游戏
    2.一些我发现的我不知道理解的问题
      1）滚键盘wasd，蛇会在双手离开键盘后抽搐一下，我尝试了助教给出的方法，但是好像并不能很好地解决问题
      2) 还是滚键盘，有的时候蛇会死，但是我没法确定这算不算bug，因为程序已经接受了用户的所有指令并判断了，或许按照指令确实会死，
      只是没有打印出来死的时候的情况。。
      总而言之，只要比较优雅地游戏（玩贪吃蛇为啥要滚键盘呢？），应该是没有太大的问题的。。
五、自认为做得好的地方
      我觉得自己在蛇的移动上面做得比较好，虽然方法可能繁琐了，而且现在想来用链表应该简单不少，但是还是用数组比较好地解决了这个问题。
    另外虽然写不出按时间增快的蛇，但是我设置了几种难度梯度，也算是丰富了一下玩法吧。

    