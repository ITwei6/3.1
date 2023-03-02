#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTData;
typedef struct SLTNode
{
	SLTData data;
	struct SLTNode* next;
}SLTNode;//���
SLTNode* BuySLTNode(SLTData x);
void SLTPrint(SLTNode* pphead);//��ӡ������
void SLTPushBack(SLTNode** pphead,SLTData x);//β��
void SLTPushFront(SLTNode** pphead, SLTData x);//ͷ��
void SLTPopBack(SLTNode** pphead);//βɾ
void SLTPopFront(SLTNode** pphead);//ͷɾ
SLTNode* SLTFind(SLTNode** pphead, SLTData x);//����
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTData x);//��posλ��ǰ�����
void SLTErase(SLTNode** pphead, SLTNode* pos);//��posλ��֮ǰɾ��
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTData x);//��posλ��֮�����
void SLTEraseAfter(SLTNode** pphead, SLTNode* pos);//��posλ��֮��ɾ��