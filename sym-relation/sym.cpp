/*
* 个人思路：
* 1. 首先，我们获取输入集合A，把它放在nums数组里面
* 2. 然后，我们得到笛卡尔积AxA， 把它放在array数组里面
* 3. 之后，我们通过遍历array得到形如（a,b),(b,a)的满足对称的一对（或一个，比如（1,1））有序对
*    把这些成对（或一个）的有序对选一个存入sym数组
* 4. 下面考虑对于每个对称关系R，R都可能包含或者不包含sym数组内的有序对，这个问题类似于第一次作业里面的求集合的幂集，因此直接使用了上次的思路（和少量代码）
* 
* 可能缺点：
* 由于一开始理解错了题意，使用了过于暴力的方法，实现思路应该可以简化。。
*/


#include<math.h>
#include<stdio.h>
#include<stdlib.h>
void print_R(int* elementStatus, int symnum, int** sym) {
    int count = 0;
    for (int i = 0;i < symnum;i++) {
        if (elementStatus[i] == 1) {
            count++;
        }
    }
    for (int i = 0;i < symnum;i++) {
        if (elementStatus[i] == 1) {
            if (sym[i][0] != sym[i][1]) {
                count--;
                printf("(%d,%d),", sym[i][0], sym[i][1]);
                printf("(%d,%d)", sym[i][1], sym[i][0]);
                if (count) {
                    printf(",");
                }
            }
            else {
                count--;
                printf("(%d,%d)", sym[i][0], sym[i][1]);
                if (count) {
                    printf(",");
                }
            }
        }
    }
}
void find_nextstatus(int** elementStatus_index, int elementNum) {
    if (!((*elementStatus_index)[elementNum - 1])) {
        (*elementStatus_index)[elementNum - 1] = 1;
    }
    else {
        int ifAdd = 1;
        (*elementStatus_index)[elementNum - 1] = 0;
        for (int i = elementNum - 2;i >= 0;i--) {
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
void find_R(int** sym, int symnum) {
    int* elementStatus;
    elementStatus = (int*)malloc(symnum * sizeof(int));
    for (int i = 0;i < symnum;i++) {
        elementStatus[i] = 0;
    }
    for (int j = 0;j < (int)pow(2, symnum);j++) {
        find_nextstatus(&elementStatus, symnum);
        printf("R%d = {", j + 1);
        print_R(elementStatus, symnum, sym);
        printf("}");
        printf("\n");
    }
}
int main() {
    int n;
    printf("How many elements are there in array A?\n");
    scanf_s("%d", &n);
    int* nums = (int*)malloc(sizeof(int) * n);
    int** sym = (int**)malloc(sizeof(int*) * n * n);
	int** array = (int**)malloc(sizeof(int*) * n * n);
    int symnum = 0;
	for (int i = 0; i < n*n; i++){
		array[i] = (int*)malloc(sizeof(int) * 2);
        sym[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (int i = 0; i < n; i++){
        scanf_s("%d",&nums[i]);
	}
    for (int i = 0;i < n;i++) {
        int num = nums[i];
        int index = 0;
        for (int j = 0; j < n;j++) {
            array[j+i*n][0] = num;
            array[j + i * n][1] = nums[index];
            index++;
        }
    }
    for (int i = 0;i < n*n;i++) {
        int num1 = array[i][0];
        int num2 = array[i][1];
        if (num1 == num2) {
            sym[symnum][0] = num1;
            sym[symnum][1] = num2;
            symnum++;
        }
        else {
            for (int j = i + 1;j < n*n;j++) {
                if (array[j][0] == num2 && array[j][1] == num1) {
                    sym[symnum][0] = num1;
                    sym[symnum][1] = num2;
                    symnum++;
                }
            }
        }
    }
    find_R(sym, symnum);
    return 0;
}