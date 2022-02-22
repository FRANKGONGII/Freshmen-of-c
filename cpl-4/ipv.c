#include<stdio.h>
#include<string.h>
int ans[3];
int ansp[100][3];
int k = 0;
int Judge(char* ip,int sep,int len)
{
    if(sep==3)
    {
        if(ans[3]>=3)
        {
            return -1;
        }
        else if(ans[3]==2)
        {
            if(((ip[0]-48)*100+(ip[1]-48)*10+ip[2]-48)>255)
            {
                printf("yes");
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else if(sep==2||sep==1)
    {
        if((ans[sep]-ans[sep+1])>3)
        {
            return -1;
        }
        else if((ans[sep]-ans[sep+1])==3)
        {   
            if(((ip[ans[sep+1]+1]-48)*100+(ip[ans[sep+1]+2]-48)*10+ip[ans[sep+1]+3]-48)>255)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
}
void Print(char* ip,int len)
{
    for(int j = k-1;j>=0;j--)
    {
        int print = 3;
        for(int s = 0;s<len;s++)
        {
            printf("%c",ip[s]);
            if(s==ansp[j][print]&&print!=0)
            {
                printf(".");
                print--;
            }
        }
        if(j>0)
        {
            printf(",");
        }
    }
}
void ipv(char* ip,int sep,int len,int start)
//ip is the ipv4 address, sep means the parts needed to seperate, len is the length of ipv4,start is the first index
{
    if(sep==0)
    {
        if((len-1-ans[1])>3)
        {
            return;
        }
        else if((len-1-ans[1])==3)
        {
            if(((ip[ans[1]+1]-48)*100+(ip[ans[1]+2]-48)*10+ip[ans[1]+3]-48)>255)
            {
                return;
            }
        }
        if(ans[3]-0>1)
        {
            if(ip[0]=='0')
            {
                return;
            }
        }
        if(ans[2]-ans[3]>1)
        {
            if(ip[ans[3]+1]=='0')
            {
                return;
            }
        }
        if(ans[1]-ans[2]>1)
        {
            if(ip[ans[2]+1]=='0')
            {
                return;
            }
        }
        if(len-1-ans[1]>1)
        {
            if(ip[ans[1]+1]=='0')
            {
                return;
            }
        }
        for(int i = 3;i>=1;i--)
        {
            ansp[k][i] = ans[i];
        }
        k++;
        return;
    }
    else if(sep>0)
    {
        if(*(ip+start)=='0')
        {
            ans[sep] = start;
            int ret = Judge(ip,sep,len);
            if(ret>0)
            {
                ipv(ip,--sep,len,++start);
                sep++;
            }
        }
        else
        {
            for(int i = len-1-sep;i>=start;i--)
            {
                ans[sep] = i;
                int a = i+1;
                int ret = Judge(ip,sep,len);
                if(ret>0)
                {
                    ipv(ip,--sep,len,a);
                    sep++;
                }
            }
        }
    }
}
int main()
{
    char ip[32];
    int sep = 3;
    scanf("%s",ip);
    int len = strlen(ip);
    ipv(ip,sep,len,0);
    Print(ip,len);
    return 0;
}