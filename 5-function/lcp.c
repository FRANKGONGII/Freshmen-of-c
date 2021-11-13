#include<stdio.h>
#include<string.h>
int checkLcp(int str1,int str2,char str[105][105])
{
    int count = 0;
    for(int i = 0;i<105;i++)
    {
        if(str[str1-1][i]!='\0'&&str[str2-1][i]!='\0'&&str[str1-1][i] == str[str2-1][i])
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    char str[105][105];
    for(int i = 0;i<n;i++)
    {
        scanf("%s",str[i]);
        getchar();
    }
    for(int i = 0;i<q;i++)
    {
        int str1 = 0;
        int str2 = 0;
        scanf("%d %d",&str1,&str2);
        int ret = checkLcp(str1,str2,str);
        printf("%d",ret);
        if(i!=q-1)
        {
            printf("\n");
        }
    }

}