#include "SLT.h"
void SLTtest1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist,1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);//��ӡ������
	SLTPopBack(&plist);//βɾ
	SLTPopBack(&plist);//βɾ
	SLTPrint(plist);//��ӡ������
}
void SLTtest2()
{
	SLTNode* plist = NULL;
	 SLTPushFront(&plist, 1);//ͷ��
	 SLTPushFront(&plist, 2);//ͷ��
	 SLTPushFront(&plist, 3);//ͷ��
	SLTPushFront(&plist, 4);//ͷ��
	SLTPrint(plist);//��ӡ������
	
}
int main()
{
	/*SLTtest1();*/
	SLTtest1();

}