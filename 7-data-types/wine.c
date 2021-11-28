#include<stdio.h>
#include<stdlib.h>
void Sort(int* type,int* index,int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int min = type[i];
        int mindex = i;
        for(int j = i+1;j<n;j++)
        {
            if(type[j]<min)
            {
                min = type[j];
                mindex = j;
            }
        }
        int tmp = type[i];
        type[i] = min;
        type[mindex] = tmp;
        int tmp2 = index[mindex];
        index[mindex] = index[i];
        index[i] = tmp2;
    }
}
int main()
{
    int n,l;
    scanf("%d%d",&n,&l);
    int* type;
    type = (int*)malloc(n*sizeof(int));
    //types of wine
    int* mount;
    mount = (int*)malloc(n*sizeof(int));
    //mount of each wine
    int* index;
    index = (int*)malloc(n*sizeof(int));
    //record the index
    for(int i = 0;i<n;i++)
    {
        index[i] = i;
    }
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&type[i]);
    }
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&mount[i]);
    }
    Sort(type,index,n);
    int money = 0;
    for(int i = n-1;i>=0;i--)
    {
        int tmpl = l;
        tmpl -= mount[index[i]];
        if(tmpl>=0)
        //the battle is enough for this kind of wine
        {
            money += (type[i]*mount[index[i]]);
        }
        else
        //battle is too small for this kind of wine
        {
            money += l*type[i];
            break;
        }
        l -= mount[index[i]];
    }
    printf("%d",money);
    return 0;
}