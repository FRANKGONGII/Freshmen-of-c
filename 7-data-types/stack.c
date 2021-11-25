#include<stdio.h>
#include<stdlib.h>
int checkOr(char* order,char* stack,int num)
{
    if(order[0] == 'p'&&order[1] == 'u')
    {
        char data;
        scanf(" ");
        scanf("%c",&data);
        stack[num] = data;
        return ++num;
    }
    else if(order[0] == 'p'&&order[1] == 'o')
    {
        if(num == 0)
        {
            printf("Empty\n");
            return num;
        }
        else
        {
            return --num;
        }
    }
    else if(order[0] == 't'&&order[1] == 'o')
    {
        if(num == 0)
        {
            printf("Empty\n");
        }   
        else
        {
            printf("%c\n",stack[num-1]);
        }
        return num;
    }
    else if(order[0] == 'p'&&order[1] == 'r')
    {
        if(num == 0)
        {
            printf("Empty\n");
            return num;
        }
        else
        {
            for(int i = num-1;i>=0;i--)
            {
                printf("| %c |\n",stack[i]);
            }
            printf("|===|\n");
            return num;
        }
        
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char* stack;
    stack = (char*)malloc(n*sizeof(char));
    char order[10];
    int num = 0;
    for(int i = 0;i<10;i++)
    {
        order[i] = '0';
    }
    for(int i = 0;i<n;i++)
    {
        stack[i] = '0';
    }
    for(int i = 1;i<=n;i++)
    {
        scanf("%s",order);
        num = checkOr(order,stack,num);
    }
    return 0;
}