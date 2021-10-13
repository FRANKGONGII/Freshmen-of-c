#include<stdio.h>
#include<string.h>
void bubble(int arr[],int size) 
{   
	int alt = 0;
	for (int i = 0;i < size - 1;i++)
	{
     int flag = 1;   
		for (int j = 0;j < size -1-i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				alt = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = alt;
             flag = 0; 
          }
		}
     if (flag ==1)
     {
      break;  
     }
	}
}
int main()
{   
	int sz2 = 0;
	int i = 0;
	int arr1[9] = {9,8,7,6,5,4,3,2,1};
	sz2 = sizeof(arr1) / sizeof(arr1[0]);
	bubble(arr1,sz2);
	for (i = 0;i < sz2;i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}
