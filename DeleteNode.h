#ifndef __DELETENODE_H__
#define __DELETENODE_H__
#include<iostream>
using namespace std;

struct ListNode
{
	int _data;
	ListNode* _next;

};

void DeleteNode(ListNode*& pHead,ListNode* ToBeDelete)
{
	//指针判断
	if (pHead == NULL || ToBeDelete == NULL)
		return;

	//分情况删除
	//1.只有一个节点
	if (pHead->_next == NULL && pHead == ToBeDelete)
	{
		delete pHead;
		pHead = NULL;
		ToBeDelete = NULL;
	}

	//2.删除尾节点
	else if (ToBeDelete->_next == NULL)
	{
		ListNode* cur = pHead;
		while (cur)
		{
			if (cur->_next == NULL)
				break;

			cur = cur->_next;
		}

		delete cur;
		cur = NULL;
	}
	//3.其他情况
	else
	{
		ListNode* Next = ToBeDelete->_next;
		ToBeDelete->_value = Next->_value;
		ToBeDelete->_next = Next->_next;

		delete Next;
		Next = NULL;
	}

}




#endif //__DELETENODE_H__