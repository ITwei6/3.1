#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTData;
typedef struct SLTNode
{
	SLTData data;
	struct SLTNode* next;
}SLTNode;//结点
SLTNode* BuySLTNode(SLTData x);
void SLTPrint(SLTNode* pphead);//打印单链表
void SLTPushBack(SLTNode** pphead,SLTData x);//尾插
void SLTPushFront(SLTNode** pphead, SLTData x);//头插
void SLTPopBack(SLTNode** pphead);//尾删
void SLTPopFront(SLTNode** pphead);//头删
SLTNode* SLTFind(SLTNode** pphead, SLTData x);//查找
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTData x);//在pos位置前面插入
void SLTErase(SLTNode** pphead, SLTNode* pos);//在pos位置之前删除
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTData x);//在pos位置之后插入
void SLTEraseAfter(SLTNode** pphead, SLTNode* pos);//在pos位置之后删除