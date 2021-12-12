#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Strcmp(char** index,int mindex,int k)
{
    int lenm = strlen(*(index+mindex));
    int lenk = strlen(*(index+k));
    if(*(*(index+mindex))<*(*(index+k)))
    {
        return mindex;
    }
    else if(*(*(index+mindex))>*(*(index+k)))
    {
        return k;
    }
    else if(*(*(index+mindex))==*(*(index+k)))
    {
        int i;
        for(i = 1;i<=lenm&&i<=lenk;i++)
        {
            if(*(*(index+mindex)+i)<*(*(index+k)+i))
            {
                return mindex;
            }
            else if(*(*(index+mindex)+i)>*(*(index+k)+i))
            {
                return k;
            }
        }
        if(i==lenm+1)
        {
            return mindex;
        }
        else if(i == lenk+1)
        {
            return k;
        }
    }
}
int main()
{
   char *str;
   char sep;
   str = (char*)malloc(20000*sizeof(char));
   scanf("%s",str);
   getchar();
   scanf("%c",&sep);
   char **index;
   index = (char**)malloc(2000*sizeof(char*));
   for(int j = 0;j<2000;j++)
   {
       *(index+j) = (char*)malloc(2000*sizeof(char));
   }
   int len = strlen(str);
   int p = 0;
   int k = 0;
   for(int i = 0;i<len;i++)
   {
       if(*(str+i)!=sep)
       {
           *(*(index+p)+k) = *(str+i);
           k++; 
       }
       else if(*(str+i)==sep)
       {
           k = 0;
           p++;
       }
   }
   //得到每个字符串,p是最大元素的下标
   for(int i= 0;i<=p;i++)
   {
       int mindex = i;
       for(int k = i+1;k<=p;k++)
       {
           mindex = Strcmp(index,mindex,k);
       }
       char* tmp = *(index+i);
       *(index+i) = *(index+mindex);
       *(index+mindex) = tmp;
   }
   for(int i = 0;i<=p;i++)
   {
       int len = strlen(*(index+i));
       for(int j = 0;j<len;j++)
       {
           printf("%c",*(*(index+i)+j));
       }
       printf("\n");
   }
   //打印结果
   
}