#include<stdio.h>
int main()
{
    char symbol[100];
    int numbers[100];
    for(int i = 0;i<100;i++)
    {
        scanf("%d%c",&numbers[i],&symbol[i]);
        if(symbol[i]==EOF)
        {
            break;
        }
    }
    for(int i = 0;i<100;i++)
    {
        printf("%c",symbol[i]);
    }
    return 0;

}