/*
* ������ʽ��1R2,Ӧ����1�ո�2���������ϵ������EOF��ctrl+Z��ctrl+D��
* ����˼·��1. �õ���ϵ�󣬴���ڶ�ά����nums��
*           2. ͨ���������ҳ�nums��������в�ͬԪ�أ�����array����������1 2 2 3��array={1,2,3}��
*           3. ������ά����matrix������nums�õ��������ͼ��MR
*              ������1 2 2 3���õ�
*               0 1 0
*               0 0 1
*               0 0 0��
*           4. ͨ����������õ�M(R^n)
*           5. ����M(R^n)���õ����㳤��Ϊn��·����Ŀ
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int find_path(int n, int** matrix, int val, int index, int tindex, int numfill) {
	if (n == 1) {//�ѵ�����Ӧ����0����Ҳ���԰�����
		if (val == 0) {
			return 0;
		}
		else if (val == 1) {
			return 1;
		}
	}
	else {
		if (val == 1) {
			int m = 0;
			for (int j = 0;j < numfill;j++) {
				m += find_path(n - 1, matrix, matrix[tindex][j], tindex, j, numfill);
				return m;
			}
		}
		else if (val == 0) {
			return 0;
		}
	}
	return 0;
}
*/

void make_matrix(int nums[10000][2], int numpair, int* array, int numfill,int** matrix) {
	for (int i = 0;i < numpair;i++) {
		int num1 = nums[i][0];
		int num2 = nums[i][1];
		int index1 = 0;
		int index2 = 0;
		int tag = 0;
		for (int j = 0;j < numfill;j++) {
			if (num1 == array[j]) {
				index1 = j;
				tag++;
			}
			if (num2 == array[j]) {
				index2 = j;
				tag++;
			}
			if (tag == 2) {
				break;
			}
		}
		matrix[index1][index2] = 1;
	}
}
int main() {
	int numpair = 0;
	int nums[10000][2];
	int array[10000];
	int numfill = 0;
	int n = 0;
	int numpath = 0;
	printf("how long is the path?\n");
	scanf("%d", &n);
	printf("tell me the relations\n");
	while (scanf("%d %d", &nums[numpair][0], &nums[numpair][1]) != EOF) {
		numpair++;
	}
	memset(array, 0,10000);
	for (int i = 0;i < numpair;i++) {
		int if_equal1 = 0;
		int if_equal2 = 0;
		for (int j = 0;j < numfill;j++) {
			if (nums[i][0] == array[j]) {
				if_equal1 = 1;
			}
			if (nums[i][1] == array[j]) {
				if_equal2 = 1;
			}
			if (if_equal1 && if_equal2) {
				break;
			}
		}
		if (nums[i][0] != nums[i][1]) {
			if (if_equal1 == 0) {
				array[numfill] = nums[i][0];
				numfill++;
			}
			if (if_equal2 == 0) {
				array[numfill] = nums[i][1];
				numfill++;
			}
		}
		else {
			if (if_equal1 == 0) {
				array[numfill] = nums[i][0];
				numfill++;
			}
		}
	}
	int** matrix;
	matrix = (int**)malloc(numfill * sizeof(int*));
	for (int i = 0;i < numfill;i++) {
		matrix[i] = (int*)malloc(numfill * sizeof(int));
	}
	for (int i = 0;i < numfill;i++) {
		for (int j = 0;j < numfill;j++) {
			matrix[i][j] = 0;
		}
	}
	make_matrix(nums, numpair, array, numfill,matrix);

	/*
	printf("  ");
	for (int i = 0;i < numfill;i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	for (int i = 0;i < numfill;i++) {
		printf("%d ", array[i]);
		for (int j = 0;j < numfill;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	*/
	/*
	int** matrix1;
	matrix1 = (int**)malloc(numfill * sizeof(int*));
	for (int i = 0;i < numfill;i++) {
		matrix1[i] = (int*)malloc(numfill * sizeof(int));
	}
	for (int i = 0;i < numfill;i++) {
		for (int j = 0;j < numfill;j++) {
			matrix1[i][j] = matrix[i][j];
		}
	}
	*/
	/*
	int** matrix2;
	matrix2 = (int**)malloc(numfill * sizeof(int*));
	for (int i = 0;i < numfill;i++) {
		matrix2[i] = (int*)malloc(numfill * sizeof(int));
	}
	for (int i = 0;i < numfill;i++) {
		for (int j = 0;j < numfill;j++) {
			matrix2[i][j] = 0;
		}
	}

	for (int l = 0;l < n - 1;l++) {
		for (int i = 0;i < numfill;i++) {
			for (int j = 0;j < numfill;j++) {
				matrix2[i][j] = 0;
				for (int k = 0;k < numfill;k++) {
					matrix2[i][j] += matrix[i][k] * matrix1[k][j];
				}
			}
		}
		for (int i = 0;i < numfill;i++) {
			for (int j = 0;j < numfill;j++) {
				matrix[i][j] = matrix2[i][j];
			}
		}
	}
	*/
	
	printf("  ");
	for (int i = 0;i < numfill;i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	for (int i = 0;i < numfill;i++) {
		printf("%d ", array[i]);
		for (int j = 0;j < numfill;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	


	
	for (int i = 0;i < numfill;i++) {
		for (int k = 0;k < numfill;k++) {
			numpath += find_path(n, matrix,matrix[i][k],i,k,numfill);
		}
		//printf("%d:%d\n", array[i], numpath);
	}
	printf("%d\n", numpath);
	
	/*
	for (int i = 0;i < numfill;i++) {
		for (int j = 0;j < numfill;j++) {
			numpath += matrix[i][j];
		}
	}
	*/
	printf("number of path = %d\n", numpath);
	return 0;
}