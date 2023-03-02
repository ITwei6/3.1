#include "SLT.h"
//生成一个可以创建结点的函数
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
//void SLTPushBack(SLTNode** pphead, SLTData x)//尾插
//{
//	assert(pphead);
//	SLTNode* newNode = BuySLTNode(x);
//	//如果前面没有结点
//	if (*pphead == NULL)
//	{
//		*pphead = newNode;
//	}
//	else
//	{
//		//假设前面有结点
//	//找尾
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
////		// 找尾
////		SLTNode* tail = *pphead;
////		while (tail->next != NULL)
////		{
////			tail = tail->next;
////		}
////
////		tail->next = newnode;
////	}
////}
//void SLTPushFront(SLTNode** pphead, SLTData x)//头插
//{
//	assert(pphead);
//	SLTNode* newNode = BuySLTNode(x);
//	//假设前面有结点.发现有结点和没有结点一样
//	newNode->next = *pphead;
//	*pphead = newNode;
//}
//void SLTPrint(SLTNode* phead)//打印单链表
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
//void SLTPopBack(SLTNode** pphead)//尾删
//{
//	
//	assert(pphead);
//	//暴力检查是否删过头
//	assert(*pphead);
//	
//	//假设前面只有一个结点时。
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
//void SLTPopFront(SLTNode** pphead)//头删
//{
//	assert(pphead);
//	assert(*pphead);//暴力检查
//	//假设前面只有一个结点
//	//和
//		//假设前面有结点
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
		// 找尾
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
	// 暴力检查
	assert(pphead);
	assert(*pphead);

	// 温柔的检查
	//if (*pphead == NULL)
	//	return;

	// 1、只有一个节点
	// 2、多个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// 找尾
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
	// 暴力检查
	assert(pphead);
	assert(*pphead);

	// 温柔的检查
	//if (*pphead == NULL)
	//	return;

	SLTNode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}
SLTNode* SLTFind(SLTNode** pphead, SLTData x)//查找
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
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTData x)//在pos位置前面插入
{
	assert(pphead);
	assert(pos);
	//如果没有结点
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
void SLTErase(SLTNode** pphead, SLTNode* pos)//在pos位置之前删除
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
void SLTInsertAfter( SLTNode* pos, SLTData x)//在pos位置之后插入
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLTEraseAfter( SLTNode* pos)//在pos位置之后删除
{
	assert(pos);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}