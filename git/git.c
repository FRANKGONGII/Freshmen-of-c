
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESS 1 
#define UNSUCCESS 0 
#define FOR_INCREASE(i, a, b) for(int i=a;i<=b;++i)
#define FOR_DECREASE(i, a, b) for(int i=a;i>=b;--i)

int find_num_cmt;
int find_cmt[5000];
char* min, max;

unsigned int BKDRHash(char* str, int iHashTableSize);

#define FILENAME_MAX_LENGTH 200     
#define MAX_FILENAME_NUMBER   20000   
#define MAX_FILE_NUMBER 20000        
#define MAX_FILE_CONTENT_LENGTH 2560000 
#define COMMITNAME_MAX_LENGTH 200   
#define MAX_COMMITNAME_NUMBER 20000  
#define MAX_COMMIT_NUMBER 20000		 
#define COMMAND_PARA_MAX_LENGTH  200  
#define HASH_SPACE_MULTIPLE   4   
#define STRING_HASH_NULLKEY '\0'				 
#define StringHash(a,  b) BKDRHash(a,  b)				
#define HASHMAP_INSERT(HashMapName,  sKey,  iValue) \
{ \
	/* 求hash 地址*/ \
	int iHashAddress = StringHash(sKey,  HashMapName.iCount); \
    /* 发生冲突  */ \
	while (HashMapName.sarrKey[iHashAddress][0] != STRING_HASH_NULLKEY) \
	{ \
		/* 如果地址中的key值与要插入的值相同，替换掉原来的值 */ \
		if (strcmp(HashMapName.sarrKey[iHashAddress],  sKey) == 0) { \
			HashMapName.iarrValue[iHashAddress] = iValue; \
			return SUCCESS; \
		} \
		/* 如果key和当前的key值不同，利用开放定址的线性探测法解决冲突，寻找下一个 */ \
		iHashAddress = (++iHashAddress) % HashMapName.iCount; \
	} \
	/* 插入值 */ \
	HashMapName.iarrValue[iHashAddress] = iValue; \
	strcpy(HashMapName.sarrKey[iHashAddress],  sKey); \
	return SUCCESS; \
}

#define HASHMAP_SEARCH(HashMapName,  sKey,  iValue) \
{ \
	/* 求hash地址*/ \
	int iHashAddress = StringHash(sKey,  HashMapName.iCount); \
	/* 当前key为空，没有找到，返回失败 */ \
	if (HashMapName.sarrKey[iHashAddress][0] == STRING_HASH_NULLKEY) \
		return UNSUCCESS; \
	/* 发生冲突 , 如果当前key不是空但是和寻找的key不同 */ \
	while (strcmp(HashMapName.sarrKey[iHashAddress],  sKey) != 0) \
	{ \
		/*printf("Filename Hash search conflict key:%s with key:%s\n",  sKey,  HashMapName.sarrKey[iHashAddress]); */ \
		/* 利用开放定址的线性探测法解决冲突  */ \
		iHashAddress = (++iHashAddress) % HashMapName.iCount; \
		if (HashMapName.sarrKey[iHashAddress][0] == STRING_HASH_NULLKEY) \
			return UNSUCCESS; \
	} \
	/* 查找成功 */ \
	*iValue = HashMapName.iarrValue[iHashAddress]; \
	return SUCCESS; \
}


int iHashSearchReturn;


#ifdef OLD_CPP_FILENAME_MAP
map<string, int> stFilenameHashMap;
#else // OLD_CPP_FILENAME_MAP
struct FilenameHashMap {
    char sarrKey[MAX_FILENAME_NUMBER * HASH_SPACE_MULTIPLE][FILENAME_MAX_LENGTH];
    int iarrValue[MAX_FILENAME_NUMBER * HASH_SPACE_MULTIPLE];
    int iCount;
}stFilenameHashMap;

int InsertFilenameHashMap(char* sKey, int iValue) {
    HASHMAP_INSERT(stFilenameHashMap, sKey, iValue);
}
int SearchFilenameHashMap(char* sKey, int* iValue) {
    HASHMAP_SEARCH(stFilenameHashMap, sKey, iValue)
}
#endif // OLD_CPP_FILENAME_MAP

#ifdef OLD_CPP_COMMITNAME_MAP
map<string, int> stCommitnameHashMap;
#else //OLD_CPP_COMMITNAME_MAP

struct CommitnameHashMap {
    char sarrKey[MAX_COMMITNAME_NUMBER * HASH_SPACE_MULTIPLE][COMMITNAME_MAX_LENGTH];
    int iarrValue[MAX_COMMITNAME_NUMBER * HASH_SPACE_MULTIPLE];
    int iCount;
}stCommitnameHashMap;

int InsertCommitnameHashMap(char* sKey, int iValue) {
    HASHMAP_INSERT(stCommitnameHashMap, sKey, iValue);
}

int SearchCommitnameHashMap(char* sKey, int* iValue) {
    HASHMAP_SEARCH(stCommitnameHashMap, sKey, iValue)
}
#endif //OLD_CPP_COMMITNAME_MAP


void init_system_string_hashmap() {
    int i;
#ifndef OLD_CPP_FILENAME_MAP
    stFilenameHashMap.iCount = MAX_FILENAME_NUMBER * HASH_SPACE_MULTIPLE;
    for (i = 0; i < MAX_FILENAME_NUMBER * HASH_SPACE_MULTIPLE; i++)
        stFilenameHashMap.sarrKey[i][0] = STRING_HASH_NULLKEY;
#endif // OLD_CPP_FILENAME_MAP

#ifndef OLD_CPP_COMMITNAME_MAP
    stCommitnameHashMap.iCount = MAX_COMMITNAME_NUMBER * HASH_SPACE_MULTIPLE;

    for (i = 0; i < MAX_COMMITNAME_NUMBER * HASH_SPACE_MULTIPLE; i++)
        stCommitnameHashMap.sarrKey[i][0] = STRING_HASH_NULLKEY;
#endif // OLD_CPP_COMMITNAME_MAP
}


int iFilenameSID, iCurrentWorkSpace, iFileContentSID, iCurrentOperatFilenameID;


int iarrFileSearchMarks[MAX_FILE_NUMBER], iFileSearchTimesID, iWriteTempCount, iCommandsNumber, iMergeTempHead;


int iListFileNumber, iCommitSearchBuffer[MAX_COMMIT_NUMBER], iCommitSearchCount;


int iCommandOperatOffset, iCommandOperatLength;


char sCommandPara[COMMAND_PARA_MAX_LENGTH];
char sWriteContent[MAX_FILE_CONTENT_LENGTH], ch;
char sMergeCommitName[COMMAND_PARA_MAX_LENGTH];


char* cpTemp;


#ifdef OLD_CPP_FILENAME_MAP
string str, mestr;
#endif // OLD_CPP_FILENAME_MAP

char sarrFilename1[MAX_FILENAME_NUMBER][FILENAME_MAX_LENGTH];

// starrFileContents  用于适应file最大数量
struct myfile {
    int iLength;
    char* cpContent;
}starrFileContents[MAX_FILE_NUMBER];


struct workspace {
    int iNamekey[5000];
    int iFileindex[5000];
    int iNum;
    int iHead, iHead2;
}starrWorkSpaces[MAX_COMMIT_NUMBER];






void write_file(int fileid) {
    if (iCommandOperatOffset + iCommandOperatLength > starrFileContents[fileid].iLength) {
        cpTemp = (char*)malloc((iCommandOperatOffset + iCommandOperatLength + 1) * sizeof(char));
        memset(cpTemp, '.', iCommandOperatOffset + iCommandOperatLength);
        cpTemp[iCommandOperatOffset + iCommandOperatLength] = '\0';
        for (int i = 0;i < starrFileContents[fileid].iLength;++i)
            cpTemp[i] = starrFileContents[fileid].cpContent[i];
        if (starrFileContents[fileid].iLength > 0)
            free(starrFileContents[fileid].cpContent);
        starrFileContents[fileid].iLength = iCommandOperatOffset + iCommandOperatLength;
        starrFileContents[fileid].cpContent = cpTemp;
    }
    for (int i = 0;i < iCommandOperatLength;++i)
        starrFileContents[fileid].cpContent[iCommandOperatOffset + i] = sWriteContent[i];
}


void copy_file(int fromfile, int tofile) {
    starrFileContents[tofile].iLength = starrFileContents[fromfile].iLength;
    if (starrFileContents[fromfile].iLength > 0) {
        starrFileContents[tofile].cpContent = (char*)malloc((starrFileContents[fromfile].iLength + 1) * sizeof(char));
        memcpy(starrFileContents[tofile].cpContent, starrFileContents[fromfile].cpContent, starrFileContents[fromfile].iLength);
        starrFileContents[tofile].cpContent[starrFileContents[fromfile].iLength] = '\0';
    }
}


void read_file(int fileid) {
    int i;
    for (i = iCommandOperatOffset;
        i < iCommandOperatOffset + iCommandOperatLength && i < starrFileContents[fileid].iLength;
        ++i)
        putchar(starrFileContents[fileid].cpContent[i]);
    for (;i < iCommandOperatOffset + iCommandOperatLength;++i)
        putchar('.');
    putchar('\n');
}


void unlink_file(int fileid) {
    if (starrFileContents[fileid].iLength > 0) {
        free(starrFileContents[fileid].cpContent);
        starrFileContents[fileid].iLength = -1;
    }
}



void git_write() {
    scanf("%s%d%d", sCommandPara, &iCommandOperatOffset, &iCommandOperatLength);
#ifdef OLD_CPP_FILENAME_MAP
    str = string(sCommandPara);
    if (!stFilenameHashMap.count(str)) {
        stFilenameHashMap[sCommandPara] = ++iFilenameSID;
        /
            sarrFilename[iFilenameSID] = str;
    }
    iCurrentOperatFilenameID = stFilenameHashMap[str];
#else // OLD_CPP_FILENAME_MAP
    if (SearchFilenameHashMap(sCommandPara, &iHashSearchReturn) != SUCCESS) {

        InsertFilenameHashMap(sCommandPara, ++iFilenameSID);

        strcpy(sarrFilename1[iFilenameSID], sCommandPara);
        iCurrentOperatFilenameID = iFilenameSID;
    }
    else
        iCurrentOperatFilenameID = iHashSearchReturn;
#endif // OLD_CPP_FILENAME_MAP 

    getchar();
    iWriteTempCount = 0;
    while ((ch = getchar()) > 30) sWriteContent[iWriteTempCount++] = ch;

    int if_exsit = 0;
    int exsit_index = 0;
    for (int i = 1;i <= starrWorkSpaces[iCurrentWorkSpace].iNum;i++) {
        if (starrWorkSpaces[iCurrentWorkSpace].iNamekey[i] == iCurrentOperatFilenameID) {
            exsit_index = starrWorkSpaces[iCurrentWorkSpace].iFileindex[i];
            if_exsit = 1;
        }
    }
    if (if_exsit) {
        write_file(exsit_index);
    }
    else {
        iFileSearchTimesID++;
        iarrFileSearchMarks[starrWorkSpaces[iCurrentWorkSpace].iHead] = iFileSearchTimesID;
        iarrFileSearchMarks[starrWorkSpaces[iCurrentWorkSpace].iHead2] = iFileSearchTimesID;
        FOR_DECREASE(i, iCurrentWorkSpace - 1, 1) {
            if (iarrFileSearchMarks[i] == iFileSearchTimesID) {
                iarrFileSearchMarks[starrWorkSpaces[i].iHead] = iFileSearchTimesID;
                iarrFileSearchMarks[starrWorkSpaces[i].iHead2] = iFileSearchTimesID;

                int if_exsit = 0;
                int exsit_index = 0;
                for (int j = 1;j <= starrWorkSpaces[i].iNum;j++) {
                    if (starrWorkSpaces[i].iNamekey[j] == iCurrentOperatFilenameID) {
                        exsit_index = starrWorkSpaces[i].iFileindex[j];
                        if_exsit = 1;
                    }
                }
                if (if_exsit) {
                    starrWorkSpaces[iCurrentWorkSpace].iNum++;
                    starrWorkSpaces[iCurrentWorkSpace].iNamekey[starrWorkSpaces[iCurrentWorkSpace].iNum] = iCurrentOperatFilenameID;
                    starrWorkSpaces[iCurrentWorkSpace].iFileindex[starrWorkSpaces[iCurrentWorkSpace].iNum] = ++iFileContentSID;


                    copy_file(exsit_index, iFileContentSID);
                    write_file(iFileContentSID);
                    return;
                }
            }
        }
        starrWorkSpaces[iCurrentWorkSpace].iNum++;
        starrWorkSpaces[iCurrentWorkSpace].iNamekey[starrWorkSpaces[iCurrentWorkSpace].iNum] = iCurrentOperatFilenameID;
        starrWorkSpaces[iCurrentWorkSpace].iFileindex[starrWorkSpaces[iCurrentWorkSpace].iNum] = ++iFileContentSID;
        write_file(iFileContentSID);
    }
}



void git_read() {
    scanf("%s%d%d", sCommandPara, &iCommandOperatOffset, &iCommandOperatLength);
#ifdef OLD_CPP_FILENAME_MAP    									
    str = string(sCommandPara);
    if (!stFilenameHashMap.count(str)) {
        for (int i = 0;i < iCommandOperatLength;++i) putchar('.');
        putchar('\n');
        return;
    }
    iCurrentOperatFilenameID = stFilenameHashMap[str];
#else // OLD_CPP_FILENAME_MAP
    if (SearchFilenameHashMap(sCommandPara, &iHashSearchReturn) != SUCCESS) {
        for (int i = 0;i < iCommandOperatLength;++i) putchar('.');
        putchar('\n');
        return;
    }
    else

        iCurrentOperatFilenameID = iHashSearchReturn;
#endif // OLD_CPP_FILENAME_MAP
    int if_exsit = 0;
    int exsit_index = 0;
    for (int i = 1;i <= starrWorkSpaces[iCurrentWorkSpace].iNum;i++) {
        if (starrWorkSpaces[iCurrentWorkSpace].iNamekey[i] == iCurrentOperatFilenameID) {
            exsit_index = starrWorkSpaces[iCurrentWorkSpace].iFileindex[i];
            if_exsit = 1;
        }
    }
    if (if_exsit) {
        read_file(exsit_index);
    }
    else {
        iFileSearchTimesID++;
        iarrFileSearchMarks[starrWorkSpaces[iCurrentWorkSpace].iHead] = iFileSearchTimesID;
        iarrFileSearchMarks[starrWorkSpaces[iCurrentWorkSpace].iHead2] = iFileSearchTimesID;
        FOR_DECREASE(i, iCurrentWorkSpace - 1, 1) {
            if (iarrFileSearchMarks[i] == iFileSearchTimesID) {
                iarrFileSearchMarks[starrWorkSpaces[i].iHead] = iFileSearchTimesID;
                iarrFileSearchMarks[starrWorkSpaces[i].iHead2] = iFileSearchTimesID;
                int if_exsit = 0;
                int exsit_index = 0;
                for (int j = 1;j <= starrWorkSpaces[i].iNum;j++) {
                    if (starrWorkSpaces[i].iNamekey[j] == iCurrentOperatFilenameID) {
                        exsit_index = starrWorkSpaces[i].iFileindex[j];
                        if_exsit = 1;
                    }
                }
                if (if_exsit) {
                    read_file(exsit_index);
                    return;
                }
            }
        }
        read_file(0);
    }

}


void git_unlink() {
    scanf("%s", sCommandPara);
#ifdef OLD_CPP_FILENAME_MAP
    str = string(sCommandPara);
    if (!stFilenameHashMap.count(str)) {
        return;
    }
    iCurrentOperatFilenameID = stFilenameHashMap[str];
#else // OLD_CPP_FILENAME_MAP
    if (SearchFilenameHashMap(sCommandPara, &iHashSearchReturn) != SUCCESS) {
        return;
    }
    else
        // 文件存在就获取对应的文件索引值
        iCurrentOperatFilenameID = iHashSearchReturn;
#endif // OLD_CPP_FILENAME_MAP




    int if_exsit = 0;
    int exsit_index = 0;
    for (int i = 1;i <= starrWorkSpaces[iCurrentWorkSpace].iNum;i++) {
        if (starrWorkSpaces[iCurrentWorkSpace].iNamekey[i] == iCurrentOperatFilenameID) {
            exsit_index = starrWorkSpaces[iCurrentWorkSpace].iFileindex[i];
            if_exsit = 1;
        }
    }
    if (if_exsit) {
        unlink_file(exsit_index);
    }


    else {
        iFileSearchTimesID++;
        iarrFileSearchMarks[starrWorkSpaces[iCurrentWorkSpace].iHead] = iFileSearchTimesID;
        iarrFileSearchMarks[starrWorkSpaces[iCurrentWorkSpace].iHead2] = iFileSearchTimesID;
        FOR_DECREASE(i, iCurrentWorkSpace - 1, 1) {
            if (iarrFileSearchMarks[i] == iFileSearchTimesID) {
                iarrFileSearchMarks[starrWorkSpaces[i].iHead] = iFileSearchTimesID;
                iarrFileSearchMarks[starrWorkSpaces[i].iHead2] = iFileSearchTimesID;

                int if_exsit = 0;
                int exsit_index = 0;
                for (int j = 1;j <= starrWorkSpaces[i].iNum;j++) {
                    if (starrWorkSpaces[i].iNamekey[j] == iCurrentOperatFilenameID) {
                        exsit_index = starrWorkSpaces[i].iFileindex[j];
                        if_exsit = 1;
                    }
                }
                if (if_exsit) {
                    if (starrFileContents[exsit_index].iLength > 0) {
                        starrWorkSpaces[iCurrentWorkSpace].iNum++;
                        starrWorkSpaces[iCurrentWorkSpace].iNamekey[starrWorkSpaces[iCurrentWorkSpace].iNum] = iCurrentOperatFilenameID;
                        starrWorkSpaces[iCurrentWorkSpace].iFileindex[starrWorkSpaces[iCurrentWorkSpace].iNum] = ++iFileContentSID;
                        starrFileContents[iFileContentSID].iLength = -1;
                    }
                    return;
                }
            }
        }
    }
}



void git_ls() {
    char* stMinname;
    char* stMaxname;
    stMaxname = (char*)malloc(200 * sizeof(char));
    stMinname = (char*)malloc(200 * sizeof(char));
    memset(stMaxname, 0, 200);
    memset(stMinname, 0, 200);
    int itmpnamekey[5000];
    int itmpfileindex[5000];
    int find_num_cmt = 0;
    int add = 0;
    int num_itmp = 0;
    iFileSearchTimesID++;
    iarrFileSearchMarks[iCurrentWorkSpace] = iFileSearchTimesID;
    for (int i = iCurrentWorkSpace;i >= 1;i--) {
        if (iarrFileSearchMarks[i] == iFileSearchTimesID) {
            iarrFileSearchMarks[starrWorkSpaces[i].iHead] = iFileSearchTimesID;
            iarrFileSearchMarks[starrWorkSpaces[i].iHead2] = iFileSearchTimesID;
            find_cmt[++find_num_cmt] = i;
        }
    }
    for (int i = find_num_cmt;i >= 1;i--) {
        for (int j = 1;j <= starrWorkSpaces[find_cmt[i]].iNum;j++) {
            int tag = 0;
            for (int k = 1;k <= num_itmp;k++) {
                if (itmpnamekey[k] == starrWorkSpaces[find_cmt[i]].iNamekey[j]) {
                    itmpfileindex[k] = starrWorkSpaces[find_cmt[i]].iFileindex[j];
                    tag = 1;
                }
            }
            if (tag == 0) {
                add++;
                int tmp = add;
                itmpnamekey[tmp] = starrWorkSpaces[find_cmt[i]].iNamekey[j];
                itmpfileindex[tmp] = starrWorkSpaces[find_cmt[i]].iFileindex[j];
                num_itmp++;
            }
        }
    }
    int file_num = 0;
    for (int i = 1;i <= num_itmp;i++) {
        if (starrFileContents[itmpfileindex[i]].iLength > 0) {
            if (file_num == 0) {
                stMinname = sarrFilename1[itmpnamekey[i]];
                stMaxname = sarrFilename1[itmpnamekey[i]];
            }
            if (strcmp(sarrFilename1[itmpnamekey[i]], stMinname) < 0) {
                stMinname = sarrFilename1[itmpnamekey[i]];
            }
            if (strcmp(sarrFilename1[itmpnamekey[i]], stMaxname) > 0) {
                stMaxname = sarrFilename1[itmpnamekey[i]];
            }
            file_num++;
        }
    }
    if (file_num) {
        printf("%d %s %s\n", file_num, stMinname, stMaxname);
    }
    else {
        printf("0\n");
    }
}



void git_commit() {
    scanf("%s", sCommandPara);
    if (!starrWorkSpaces[iCurrentWorkSpace].iNum) {
        return;
    }
#ifdef OLD_CPP_COMMITNAME_MAP    
    str = string(sCommandPara);
    if (stCommitnameHashMap.count(str))
        return;
    stCommitnameHashMap[str] = iCurrentWorkSpace;
#else // OLD_CPP_COMMITNAME_MAP

    if (SearchCommitnameHashMap(sCommandPara, &iHashSearchReturn) == SUCCESS) {

        return;
    }
    else
        InsertCommitnameHashMap(sCommandPara, iCurrentWorkSpace);
#endif // OLD_CPP_COMMITNAME_MAP
    ++iCurrentWorkSpace;
    starrWorkSpaces[iCurrentWorkSpace].iHead = iCurrentWorkSpace - 1;
    starrWorkSpaces[iCurrentWorkSpace].iNum = 0;
    memset(starrWorkSpaces[iCurrentWorkSpace].iFileindex, 0, 5000);
    memset(starrWorkSpaces[iCurrentWorkSpace].iNamekey, 0, 5000);
}


void git_checkout() {
    scanf("%s", sCommandPara);
    if (starrWorkSpaces[iCurrentWorkSpace].iNum) {
        return;
    }
#ifdef OLD_CPP_COMMITNAME_MAP    
    str = string(sCommandPara);
    if (!stCommitnameHashMap.count(str))
        return;
    starrWorkSpaces[iCurrentWorkSpace].iHead = stCommitnameHashMap[str];
#else // OLD_CPP_COMMITNAME_MAP

    if (SearchCommitnameHashMap(sCommandPara, &iHashSearchReturn) != SUCCESS)

        return;
    else

        starrWorkSpaces[iCurrentWorkSpace].iHead = iHashSearchReturn;
#endif // OLD_CPP_COMMITNAME_MAP

    starrWorkSpaces[iCurrentWorkSpace].iNum = 0;
    memset(starrWorkSpaces[iCurrentWorkSpace].iFileindex, 0, 5000);
    memset(starrWorkSpaces[iCurrentWorkSpace].iNamekey, 0, 5000);
}

void git_merge() {
    scanf("%s%s", sMergeCommitName, sCommandPara);
    if (starrWorkSpaces[iCurrentWorkSpace].iNum)
        return;
#ifdef OLD_CPP_COMMITNAME_MAP    
    mestr = string(sMergeCommitName);
    if (!stCommitnameHashMap.count(mestr))
        return;
    iMergeTempHead = stCommitnameHashMap[mestr];
    if (iMergeTempHead == starrWorkSpaces[iCurrentWorkSpace].iHead)
        return;
    str = string(sCommandPara);
    if (stCommitnameHashMap.count(str)) return;
    starrWorkSpaces[iCurrentWorkSpace].iHead2 = iMergeTempHead;
    stCommitnameHashMap[str] = iCurrentWorkSpace;
#else // OLD_CPP_COMMITNAME_MAP

    if (SearchCommitnameHashMap(sMergeCommitName, &iHashSearchReturn) != SUCCESS)

        return;
    iMergeTempHead = iHashSearchReturn;

    if (iMergeTempHead == starrWorkSpaces[iCurrentWorkSpace].iHead)
        return;

    if (SearchCommitnameHashMap(sCommandPara, &iHashSearchReturn) == SUCCESS)

        return;

    starrWorkSpaces[iCurrentWorkSpace].iHead2 = iMergeTempHead;

    InsertCommitnameHashMap(sCommandPara, iCurrentWorkSpace);
#endif // OLD_CPP_COMMITNAME_MAP
    ++iCurrentWorkSpace;
    starrWorkSpaces[iCurrentWorkSpace].iHead = iCurrentWorkSpace - 1;
    starrWorkSpaces[iCurrentWorkSpace].iNum = 0;
    memset(starrWorkSpaces[iCurrentWorkSpace].iFileindex, 0, 5000);
    memset(starrWorkSpaces[iCurrentWorkSpace].iNamekey, 0, 5000);
}

unsigned int BKDRHash(char* str, int iHashTableSize)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str)
    {
        hash = (hash * seed + (*str++)) % iHashTableSize;
    }

    return (hash);
}

int main() {
    init_system_string_hashmap();
    iCurrentWorkSpace = 1;

    scanf("%d", &iCommandsNumber);
    while (iCommandsNumber--) {
        scanf("%s", sCommandPara);
        if (sCommandPara[0] == 'w' && sCommandPara[1] == 'r') {
            git_write();
            continue;
        }
        if (sCommandPara[0] == 'r' && sCommandPara[1] == 'e') {
            git_read();
            continue;
        }
        if (sCommandPara[0] == 'u' && sCommandPara[1] == 'n') {
            git_unlink();
            continue;
        }
        if (sCommandPara[0] == 'l' && sCommandPara[1] == 's') {
            git_ls();
            continue;
        }
        if (sCommandPara[0] == 'c' && sCommandPara[1] == 'o') {
            git_commit();
            continue;
        }
        if (sCommandPara[0] == 'c' && sCommandPara[1] == 'h') {
            git_checkout();
            continue;
        }
        if (sCommandPara[0] == 'm' && sCommandPara[1] == 'e') {
            git_merge();
            continue;
        }
    }
    return 0;
}
