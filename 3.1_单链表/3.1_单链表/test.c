#include "SLT.h"
void SLTtest1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist,1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);//打印单链表
	SLTPopBack(&plist);//尾删
	SLTPopBack(&plist);//尾删
	SLTPrint(plist);//打印单链表
}
void SLTtest2()
{
	SLTNode* plist = NULL;
	 SLTPushFront(&plist, 1);//头插
	 SLTPushFront(&plist, 2);//头插
	 SLTPushFront(&plist, 3);//头插
	SLTPushFront(&plist, 4);//头插
	SLTPrint(plist);//打印单链表
	
}
int main()
{
	/*SLTtest1();*/
	SLTtest1();

}