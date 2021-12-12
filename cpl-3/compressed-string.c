//we need to translate a compressed string 
//rules: 1. {{} = {
//       2. {}} = }
//       3. {N}(2<=N<=30), repeat the front char for N times

#include<stdio.h>
#include<string.h>
int main()
{
    char c_str[200];
    scanf("%s",c_str);
    int len = strlen(c_str);
    for(int i = 0;i<len;i++)
    {
        if(c_str[i]!='{'&&c_str[i]!='}')
        {
            printf("%c",c_str[i]);
        }
        //print a normal char as usual
        else if(c_str[i]=='{')
        {
            if((c_str[i+1]=='{'||c_str[i+1]=='}')&&c_str[i+2]=='}')
            {
                printf("%c",c_str[i+1]);
                i += 2;
            }
            //situation like {}} or{{}
            else if(c_str[i+2]=='}'&&(c_str[i+1]!='{'||c_str[i+1]!='}'))
            {
                if(c_str[i-1]!='}')
                {
                    for(int j = 0;j<c_str[i+1]-48-1;j++)
                    {
                        printf("%c",c_str[i-1]);
                    }
                    i+=2;
                }
                //situation like {N}
                else if(c_str[i-1]=='}')
                {
                    for(int j = 0;j<c_str[i+1]-48-1;j++)
                    {
                        printf("%c",c_str[i-2]);
                    }
                    i+=2;
                }
                //situation like {}}{N}
            }
            else if(c_str[i+3]=='}')
            {
                int time = (c_str[i+1]-48)*10+(c_str[i+2]-48);
                if(c_str[i-1]!='}')
                {
                    for(int j = 0;j<time-1;j++)
                    {
                        printf("%c",c_str[i-1]);
                    }
                }
                else if(c_str[i-1]=='}')
                {
                    for(int j =  0;j<time-1;j++)
                    {
                        printf("%c",c_str[i-2]);
                    }
                }
                i+=3;
            }
            //same situations, but N is bigger than ten
        }
    }
    return 0;
}