#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);
	char* arr;
	arr = (char*)malloc(n * sizeof(char));
	scanf("%s",arr);
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
	for(int i = 0;i<n;i++)
    {
        int a = arr[i] - 48;
        printf("%d ",a);
        sum = sum + a*pow(2.0,n-1-i);
    
    }
	printf("%d", sum);
	return 0;
}