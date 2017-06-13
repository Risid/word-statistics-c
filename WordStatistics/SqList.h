#include <stdio.h>
#include <malloc.h>
#include <string.h>
#if defined(_MSC_VER)
#define strcasecmp _stricmp
#endif

#define LIST_INIT_SIZE 100    // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10      // ���Ա�洢�ռ�ķ�������

typedef struct {
	char word[21];            // �洢���ʣ�������20���ַ�
	int count;                // ���ʳ��ֵĴ���
} ElemType;
typedef struct {
	ElemType *elem;           // �洢�ռ��ַ
	int length;               // ��ǰ����
	int listsize;             // ��ǰ����Ĵ洢����
} SqList;

/* ˳���ĳ�ʼ�� */
int InitList(SqList *L);

/*
 * ˳����ϲ���ָ���ĵ���. 
 * ���ҵ������ʵĳ��ִ�����1������0�����򷵻ظõ��ʵĲ���λ��. 
 */
int LocateElem(SqList *L, char *s);

/* ��˳����ϲ����µĵ��� */
int InsertList(SqList *L, int i, char *s);

/* ���˳����ϴ洢�ĵ���ͳ����Ϣ */
void PrintList(SqList *L);
