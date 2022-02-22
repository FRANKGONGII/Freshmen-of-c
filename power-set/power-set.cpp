// ����һ��nԪ�ؼ��ϣ��г������ݼ�
/*
*  ����˼·��
*  1.����Ҫ��һ������nԪ�ؼ��ϵ��ݼ�����������������������Ӽ�
*  2.Ҫ�󼯺ϵ��Ӽ�������ֻ��Ҫ������������ڵ�Ԫ���ڻ��߲�������Ӽ�����
*  3.�ڻ��ڵ�״̬��0/1����ʾ�������������ת��Ϊ��n��0/1�����п���
*  4.����n=3������000,001,010,011,100,101,110,111���ֿ��ܣ���8�����ܶ�Ӧÿ��Ԫ�صĴ����Լ��ɵó�n=3ʱ��ȫ���Ӽ�
*/
/*
*  ���ܵ�һ��ȱ�ݣ�������ݼ�����Ԫ�ص����в����ǰ����Ӽ���Ԫ�ظ����������еģ����ܲ�̫�����Ķ�ϰ��
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