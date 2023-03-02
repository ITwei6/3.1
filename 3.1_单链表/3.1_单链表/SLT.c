#include "SLT.h"
//����һ�����Դ������ĺ���
//SLTNode* BuySLTNode(SLTData x)
//{
//	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
//	if (newNode == NULL)
//	{
//		perror("malloc");
//		return NULL;
//	}
//	newNode->data = x;
//	newNode->next = NULL;
//	return newNode;
//}
//void SLTPushBack(SLTNode** pphead, SLTData x)//β��
//{
//	assert(pphead);
//	SLTNode* newNode = BuySLTNode(x);
//	//���ǰ��û�н��
//	if (*pphead == NULL)
//	{
//		*pphead = newNode;
//	}
//	else
//	{
//		//����ǰ���н��
//	//��β
//		SLTNode* tail = *pphead;
//		while(tail->next!= NULL)
//		{
//			tail = tail->next;
//		}
//		tail->next = newNode;
//	}
//}
////void SLTPushBack(SLTNode** pphead, SLTData x)
////{
////	assert(pphead);
////
////	SLTNode* newnode = BuySLTNode(x);
////
////	if (*pphead == NULL)
////	{
////		*pphead = newnode;
////	}
////	else
////	{
////		// ��β
////		SLTNode* tail = *pphead;
////		while (tail->next != NULL)
////		{
////			tail = tail->next;
////		}
////
////		tail->next = newnode;
////	}
////}
//void SLTPushFront(SLTNode** pphead, SLTData x)//ͷ��
//{
//	assert(pphead);
//	SLTNode* newNode = BuySLTNode(x);
//	//����ǰ���н��.�����н���û�н��һ��
//	newNode->next = *pphead;
//	*pphead = newNode;
//}
//void SLTPrint(SLTNode* phead)//��ӡ������
//{
//	SLTNode* cur = phead;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//
//}
//void SLTPopBack(SLTNode** pphead)//βɾ
//{
//	
//	assert(pphead);
//	//��������Ƿ�ɾ��ͷ
//	assert(*pphead);
//	
//	//����ǰ��ֻ��һ�����ʱ��
//	if ((*pphead)->next = NULL)
//	{
//		free(*pphead);
//		*pphead = NULL;
//	}
//	else
//	{
//		SLTNode* tail = *pphead;
//		SLTNode* prev = NULL;
//		while (tail->next != NULL)
//		{
//			prev = tail;
//			tail = tail->next;
//		}
//		free(tail);
//		prev->next = NULL;
//	}
//}
//void SLTPopFront(SLTNode** pphead)//ͷɾ
//{
//	assert(pphead);
//	assert(*pphead);//�������
//	//����ǰ��ֻ��һ�����
//	//��
//		//����ǰ���н��
//		SLTNode* first = *pphead;
//		*pphead = first->next;
//		free(first);
//		first = NULL;
//	
//}
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	//while (cur->next != NULL)
	//while(cur != NULL)
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
		//cur++;
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTData x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SLTPushBack(SLTNode** pphead, SLTData x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// ��β
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SLTPushFront(SLTNode** pphead, SLTData x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}


void SLTPopBack(SLTNode** pphead)
{
	// �������
	assert(pphead);
	assert(*pphead);

	// ����ļ��
	//if (*pphead == NULL)
	//	return;

	// 1��ֻ��һ���ڵ�
	// 2������ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// ��β
		//SLTNode* prev = NULL;
		//SLTNode* tail = *pphead;
		//while (tail->next != NULL)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}

		//free(tail);
		//tail = NULL;

		//prev->next = NULL;

		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead)
{
	// �������
	assert(pphead);
	assert(*pphead);

	// ����ļ��
	//if (*pphead == NULL)
	//	return;

	SLTNode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}
SLTNode* SLTFind(SLTNode** pphead, SLTData x)//����
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		if (cur->next == x)
		{
            return cur;
		}
		cur = cur->next;
			
	}
	return NULL;
}
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTData x)//��posλ��ǰ�����
{
	assert(pphead);
	assert(pos);
	//���û�н��
	if (pos == *pphead)
	{
		SLTpushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuySLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SLTErase(SLTNode** pphead, SLTNode* pos)//��posλ��֮ǰɾ��
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SLTpopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev->next = pos->next;
		}
		free(pos);
		pos = NULL;
	}
}
void SLTInsertAfter( SLTNode* pos, SLTData x)//��posλ��֮�����
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLTEraseAfter( SLTNode* pos)//��posλ��֮��ɾ��
{
	assert(pos);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}