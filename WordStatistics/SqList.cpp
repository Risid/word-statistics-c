#include "stdafx.h"
#include "SqList.h"


int InitList(SqList* L)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (!L->elem)
	{
		return -1;
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;

	return 0;
}

int LocateElem(SqList* L, char* s)
{
	//int insertLocate = 0;

	for (int i = 0; i < L->length; ++i)
	{
		int cmp = strcasecmp(s, L->elem[i].word);
		if (cmp == 0)
		{
			L->elem[i].count++;
			return -1;
		}
		if (cmp < 0)
		{
			return i;
		}
	}
	return L->length;

}

int InsertList(SqList* L, int i, char* s)
{
	if (i < 0 || i > L->length)
	{
		return -1;
	}
	if (L->length >= L->listsize)
	{
		ElemType *newbase = (ElemType *)realloc(L->elem, sizeof(ElemType) * (L->listsize + LIST_INIT_SIZE));
		if (!newbase)
		{
			return -1;
		}

	}
	for (int j = L->length - 1; j >= i; j--) {
		L->elem[j + 1] = L->elem[j];
	}
	strcpy_s(L->elem[i].word, s);
	L->elem[i].count = 1;
	L->length += 1;
	return 1;
}

void PrintList(SqList* L)
{
	for (int i = 0; i < L->length; ++i)
	{
		printf("%s\t%d\n", L->elem[i].word, L->elem[i].count);
	}
}
