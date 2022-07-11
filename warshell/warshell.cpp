#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
int road_len = 0;
int road[1000] = { 0 };
void find_road(int ele_num, int** matrix, int start) {
	if (road_len == ele_num) {
		for (int i = 0;i < road_len;i++) {
			printf("%d ", road[i]);
		}
		printf("\n");
		return;
	}
	int if_all_zero = 1;
	for (int j = 0;j < ele_num;j++) {
		if (matrix[start][j] == 1) {
			if_all_zero = 0;
			break;
		}
	}//先检查一下是不是全部为0；确认要不要写下这个位
	if (if_all_zero) {
		for (int i = 0;i < road_len;i++) {
			printf("%d ", road[i]);
		}
		printf("\n");
	}
	else {//不是全部为0,写下这一位
		road[road_len] = start;
		road_len++;
		for (int i = 0;i < ele_num;i++) {
			if (matrix[start][i] == 1) {//找到能去的下一位，递归操作
				find_road(ele_num, matrix, i);
				road_len--;
			}
		}
	}
	return;
}
*/


void make_matrix(int pairs[10000][2], int pair_num, int* elements, int ele_num, int** matrix) {
	for (int i = 0;i < pair_num;i++) {
		int num1 = pairs[i][0];
		int num2 = pairs[i][1];
		int index1 = 0;
		int index2 = 0;
		int tag = 0;
		for (int j = 0;j < ele_num;j++) {
			if (num1 == elements[j]) {
				index1 = j;
				tag++;
			}
			if (num2 == elements[j]) {
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

void warshell(int ele_num, int** matrix,int** matrix2,int warshell_time) {
	if (warshell_time > ele_num) {
		return;
	}
	else {
		for (int i = 0;i < ele_num;i++) {
			for (int j = 0;j < ele_num;j++) {
				if (matrix[i][j] == 1) {
					matrix2[i][j] = 1;
				}
			}
		}
		int line_e1[10000] = { 0 };
		int line_num = 0;
		int row_e1[10000] = { 0 };
		int row_num = 0;
		for (int i = 0;i < ele_num;i++) {
			if (matrix[warshell_time - 1][i] == 1) {
				line_e1[line_num++] = i;
			}
			if (matrix[i][warshell_time - 1] == 1) {
				row_e1[row_num++] = i;
			}
		}
		for (int i = 0;i < line_num;i++) {
			for (int j = 0;j < row_num;j++) {
				matrix2[row_e1[j]][line_e1[i]] = 1;
			}
		}
		for (int i = 0;i < ele_num;i++) {
			for (int j = 0;j < ele_num;j++) {
				matrix[i][j] = matrix2[i][j];
				matrix2[i][j] = 0;
			}
		}
		warshell(ele_num, matrix, matrix2, warshell_time + 1);
	}
}
	
int main() {
	int n = 0;
	int pair_num = 0;
	int pairs[10000][2] = { 0 };
	int elements[10000] = { 0 };
	int ele_num = 0;
	int warshell_time = 1;
	printf("how many elements in set A?\n");
	scanf("%d", &n);// |A| = n
	printf("input the relations:\n");
	while (scanf("%d %d", &pairs[pair_num][0], &pairs[pair_num][1]) != EOF) {
		pair_num++;
	}
	memset(elements, 0, 10000);
	for (int i = 0;i < pair_num;i++) {
		int if_equal1 = 0;
		int if_equal2 = 0;
		for (int j = 0;j < ele_num;j++) {
			if (pairs[i][0] == elements[j]) {
				if_equal1 = 1;
			}
			if (pairs[i][1] == elements[j]) {
				if_equal2 = 1;
			}
			if (if_equal1 && if_equal2) {
				break;
			}
		}// 先看看以前是不是已经有了这两个元素
		if (pairs[i][0] != pairs[i][1]) {
			if (if_equal1 == 0) {
				elements[ele_num] = pairs[i][0];
				ele_num++;
			}
			if (if_equal2 == 0) {
				elements[ele_num] = pairs[i][1];
				ele_num++;
			}
		}
		else {
			if (if_equal1 == 0) {
				elements[ele_num] = pairs[i][0];
				ele_num++;
			}
		}
	}

	int** matrix;
	matrix = (int**)malloc(ele_num * sizeof(int*));
	for (int i = 0;i < ele_num;i++) {
		matrix[i] = (int*)malloc(ele_num * sizeof(int));
	}
	for (int i = 0;i < ele_num;i++) {
		for (int j = 0;j < ele_num;j++) {
			matrix[i][j] = 0;
		}
	}
	int** matrix2;
	matrix2 = (int**)malloc(ele_num * sizeof(int*));
	for (int i = 0;i < ele_num;i++) {
		matrix2[i] = (int*)malloc(ele_num * sizeof(int));
	}
	for (int i = 0;i < ele_num;i++) {
		for (int j = 0;j < ele_num;j++) {
			matrix2[i][j] = 0;
		}
	}
	make_matrix(pairs, pair_num, elements, ele_num, matrix);
	/*
	for (int i = 0;i < ele_num;i++) {
          find_road(ele_num, matrix,i);
	}
	*/
	
	warshell(ele_num, matrix,matrix2,warshell_time);
	printf("  ");
	for (int i = 0;i < ele_num;i++) {
		printf("%d ", elements[i]);
	}
	printf("\n");
	for (int i = 0;i < ele_num;i++) {
		printf("%d ", elements[i]);
		for (int j = 0;j < ele_num;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	for (int i = 0;i < ele_num;i++) {
		for (int j = 0;j < ele_num;j++) {
			if (matrix[i][j] != 0) {
				printf("(%d->%d)\n", elements[i], elements[j]);
			}
		}
	}
}