// 接受一个n元素集合，列出它的幂集
/*
*  个人思路：
*  1.本题要求一个给定n元素集合的幂集，就是求出这个数组的所有子集
*  2.要求集合的子集，我们只需要考虑这个集合内的元素在或者不在这个子集里面
*  3.在或不在的状态用0/1来表示，所以这个问题转变为求n个0/1的排列可能
*  4.例如n=3，就有000,001,010,011,100,101,110,111八种可能，这8个可能对应每个元素的存在性即可得出n=3时的全部子集
*/
/*
*  可能的一点缺陷：输出的幂集里面元素的排列并不是按照子集内元素个数多少排列的，可能不太符合阅读习惯
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int powersetNum;
void find_nextstatus(int** elementStatus_index, int elementNum);
void print_powerset(int* elementStatus_index, int elementNum, int* set);

void print_powerset(int* elementStatus_index, int elementNum, int* set) {
	int elementNownum = 0;
	for (int k = 0;k < elementNum;k++) {
		if (elementStatus_index[k]) {
			elementNownum++;
		}
	}
	powersetNum++;
	printf("{");
	for (int j = 0;j < elementNum;j++) {
		if (elementStatus_index[j]) {
			printf("%d", set[j]);
			elementNownum--;
			if (elementNownum) {
				printf(",");
			}
		}
	}
	printf("}");
	if (powersetNum != pow(2,elementNum)) {
		printf(",");
	}
}
void find_nextstatus(int** elementStatus_index, int elementNum) {
	if (!((*elementStatus_index)[elementNum - 1])) {
		(*elementStatus_index)[elementNum - 1] = 1;
	}
	else {
		int ifAdd = 1;
		(*elementStatus_index)[elementNum-1] = 0;
		for (int i = elementNum-2;i >= 0;i--) {
			if ((*elementStatus_index)[i] == 0 && ifAdd == 1) {
				(*elementStatus_index)[i] = 1;
				ifAdd = 0;
				break;
			}
			else {
				(*elementStatus_index)[i] = 0;
				continue;
			}
		}
	}
}
int main() {
	powersetNum = 0;
	int elementNum;
	scanf("%d", &elementNum);
	int* set;
	set = (int*)malloc(elementNum * sizeof(int));
	for (int i = 0;i < elementNum;i++) {
		scanf("%d", &set[i]);
	}
	int* elementStatus;
	elementStatus = (int*)malloc(elementNum * sizeof(int));
	for (int i = 0;i < elementNum;i++) {
		elementStatus[i] = 0;
	}

	printf("powerset = {");
	for (int j = 0;j < (int)pow(2, elementNum);j++) {
		print_powerset(elementStatus, elementNum, set);
		find_nextstatus(&elementStatus, elementNum);
	}
	printf("}");
}