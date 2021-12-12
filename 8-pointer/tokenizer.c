#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* res1 = "const";char* res2 = "int";char* res3 = "float";
char* res4 = "double";char* res5 = "static";char* res6 = "void";
char* res7 = "char";char* res8 = "extern";char* res9 = "return";
char* res10 = "break";char* res11 = "enum";
char* res12 = "struct";char* res13 = "typedef";
char* res14 = "union";char* res15 = "goto";char* res16 = "long";
int* result;
int k = 0;
char* index = ";";
void Anal(char* start,int len)
{ 
    if(((*(start))>='0')&&((*(start))<='9'))
    //judge the element is an int or a float
    {
        int i = 0;
        int tag = 0;
        for(i = 0;i<len;i++)
        {
            if((*(start+i))>='0'&&(*(start+i))<='9')
            {
                tag++;
            }
            else if(*(start+i)=='.')
            {
                if(*(start+i+1)!='.')
                {
                    if(*(start+i+1)>='0'&&*(start+i)<='9')
                    {
                        tag = 0;
                        break;
                    }
                    else
                    {
                        tag = -1000;
                        break;
                    }
                }
                else if(i == len-1)
                {
                    tag = 0;
                    break;
                }
                else
                {
                    tag = -1000;
                    break;
                }
            }
            else if(*(start+i)!=';'&&*(start+i)!='.'&&*(start+i)>'9'&&*(start+i)<'0')
            {
                tag = -1000;
            }
            
        }
        if(tag == len)
        {
            *(result+k) = 2;
            k++;
            return;
            //2 means interger;
        }
        else if(tag == 0)
        {
            *(result+k) = 3;
            k++;
            return ;
            //3 means float;
        }
        else
        {
            *(result+k) = 0;
            k++;
            return;
            //0 means Compile Error;
        }
    }
    else if(*(start)=='.')
    {
        int tag = 0;
        for(int i = 1;i<len;i++)
        {
            if(*(start+i)>='0'&&*(start+i)<='9')
            {
                ;
            }
            else
            {
                tag = 1;
                break;
            }
        }
        if(tag == 0)
        {
            *(result+k) = 3;
            k++;
            //3 means float;
        }
        else
        {
            *(result+k) = 0;
            k++;
            //0 means Error;
        }
    }
    else if(
    (strcmp(start,res1)&&strcmp(start,res2)&&strcmp(start,res3)
    &&strcmp(start,res4)&&strcmp(start,res5)&&strcmp(start,res6)
    &&strcmp(start,res7)&&strcmp(start,res8)&&strcmp(start,res9)
    &&strcmp(start,res10)&&strcmp(start,res11)
    &&strcmp(start,res12)&&strcmp(start,res13)
    &&strcmp(start,res14)&&strcmp(start,res15)
    &&strcmp(start,res16))==0)
    {
        *(result+k) = 1;
        k++;
        return;
        //1 means reserved;
    }
    else if(*(start)=='_'||(*(start)>='a'&&*(start)<='z'))
    {
        int tag = 0;
        for(int i = 1;i<len;i++)
        {
            if((*(start)>='a'&&*(start)<='z')||(*(start)>='0'&&*(start)<'9')||*(start)=='_')
            {
                tag = 0;
            }
            else
            {
                tag = 1;
            }
        }
        if(tag == 0)
        {
            *(result+k) = 4;
            k++;
            return;
            //4 means variable;
        }
    }
    else if(*(start)=='+'||*(start)=='-'||*(start)=='*'||*(start)=='/'||*(start)=='<'||*(start)=='>'||*(start)=='='||*(start)=='!')
    {
        if(len==1)
        {
            *(result+k) = 5;
            k++;
            //5 means operator;
        }
        else if(len==2)
        {
            if((*(start)=='='&&*(start+1)=='=')||(*(start)=='!'&&*(start+1)=='=')||(*(start)=='>'&&*(start+1)=='=')||(*(start)=='<'&&*(start+1)=='='))
            {
                *(result+k) = 5;
                k++;
                //5 means operator;
            }
            else
            {
                *(result+k) = 0;
                k++;
                //0 means error;
            }
        }
    }
    else if(*(start)==';'&&len==1)
    {
        *(result+k) = 6;
        k++;
        //6 means \n;
    }
    else
    {
        *(result+k) = 0;
        k++;
        //0 means error;
    }
}
int main()
{
    char* str;
    str = (char*)malloc(100000*sizeof(char));
    result = (int*)malloc(100000*sizeof(int));
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        int position = 0;
        for(int i = 0;i<len;i++)
        {
            if(*(str+i)==';')
            {
                position = i;
                break;
            }
        }
        if(position == 0)
        {
            Anal(str,len);
        }
        else if(position == len-1)
        {
            *(str+len-1) = '\0';
            Anal(str,len-1);
            Anal(index,1);
        }
        else
        {
            Anal(str,position);
            Anal(index,1);
            Anal(str+position+1,len-position-1);
        }
    }
    int printag = 1;
    for(int j = 0;j<k;j++)
    {
        if(*(result+j)==0)
        {
            printag = 0;
            break;
        }
    }
    for(int j= 0;j<k;j++)
    {
        if(printag)
        {
            if(*(result+j)==1)
            {
                printf("reserved ");
            }
            else if(*(result+j)==2)
            {
                printf("integer ");
            }
            else if(*(result+j)==3)
            {
                printf("float ");
            }
            else if(*(result+j)==4)
            {
                printf("variable ");
            }
            else if(*(result+j)==5)
            {
                printf("operator ");
            }
            else if((*(result+j)==6)&&(j!=k-1))
            {
                printf("\n");
            }
        }
        else
        {
            printf("Compile Error");
            break;
        }
    }
    return 0;
}