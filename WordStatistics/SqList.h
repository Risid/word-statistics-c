#include <stdio.h>
#include <malloc.h>
#include <string.h>
#if defined(_MSC_VER)
#define strcasecmp _stricmp
#endif

#define LIST_INIT_SIZE 100    // 线性表存储空间的初始分配量
#define LISTINCREMENT 10      // 线性表存储空间的分配增量

typedef struct {
	char word[21];            // 存储单词，不超过20个字符
	int count;                // 单词出现的次数
} ElemType;
typedef struct {
	ElemType *elem;           // 存储空间基址
	int length;               // 当前长度
	int listsize;             // 当前分配的存储容量
} SqList;

/* 顺序表的初始化 */
int InitList(SqList *L);

/*
 * 顺序表上查找指定的单词. 
 * 若找到，单词的出现次数增1，返回0，否则返回该单词的插入位置. 
 */
int LocateElem(SqList *L, char *s);

/* 在顺序表上插入新的单词 */
int InsertList(SqList *L, int i, char *s);

/* 输出顺序表上存储的单词统计信息 */
void PrintList(SqList *L);
