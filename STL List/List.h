//List.h
#pragma once
#include <iostream>
#include <Windows.h>
#include <cassert>
using namespace std;
template<class T>
struct ListNode
{
	ListNode(const T& x = T())//����ֵΪx�Ľڵ�
		: _prev(0)
		, _next(0)
		, _value(x)
	{}
 
	ListNode<T>* _prev;//ǰ��ָ��
	ListNode<T>* _next;//���ָ��
	T _value;//ֵ��
};
 
template<class T, class Ref, class Ptr>
struct __ListIterator__  //˫����������͵Ľṹ��
{
	typedef __ListIterator__<T, T&, T*> Iterator;//����������
	typedef __ListIterator__<const T, const T&, const T*> ConstIterator;//��������������
	typedef __ListIterator__<T, Ref, Ptr> Self;//��������
	typedef T ValueType;//ֵ������
	typedef Ref Reference;//��������
	typedef Ptr Pointer;//ָ������
	typedef ListNode<T>* LinkType;//����ָ������
	typedef size_t SizeType;//�޷�������
	LinkType _node;//ָ�����ָ��
 
	__ListIterator__(LinkType x)//����ֵΪx�Ľڵ�
		:_node(x)
	{}
	__ListIterator__()//���������
	{}
	__ListIterator__(const Iterator& x)//����x�ڵ�
	{
		_node = x._node;
	}
	bool operator==(const Iterator& x)//�Ƚ������==������
	{
		return _node == x._node;
	}
	bool operator!=(const Iterator& x)//�Ƚ��������=������
	{
		return _node != x._node;
	}
	Reference operator*()//����*�����
	{
		return _node->_value;
	}
	Pointer operator->()//����->�����
	{
		return &(_node->_value);
	}
	Self& operator++()//����ǰ��++�����
	{
		_node = _node->_next;
		return *this;
	}
	Self operator++(int)//���غ���++�����
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	Self& operator--()//����ǰ��--�����
	{
		_node = _node->_prev;
		return *this;
	}
	Self operator--(int)//���غ���--�����
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}
};
 
template<class T>
class List  //˫��ѭ��������
{
public:
	typedef ListNode<T> Node;//˫��ѭ������Ľ��
	typedef T ValueType;//ֵ��ΪT���͵Ľ��
	typedef ValueType* Pointer;//ָ������
	typedef const ValueType* ConstPointer;//����ָ������
	typedef ValueType& Reference;//��������
	typedef const ValueType& ConstReference;//������������
	typedef Node* LinkType;//���ָ������
	typedef size_t SizeType;//�޷�������
	typedef __ListIterator__<T, T&, T*> Iterator;//����������
	typedef __ListIterator__<const T, const T&, const T*> ConstIterator;//��������������
	List() //���캯��
		:_pHead(new Node(T()))
	{
		_pHead->_next = _pHead;
		_pHead->_prev = _pHead;
	}
	Iterator Begin()//���ص�һ���ڵ����һ���ڵ�ĵ�����(ͷ������һ���ڵ�)
	{
		return _pHead->_next;
	}
	ConstIterator Begin()const//���ص�һ���ڵ����һ���ڵ�ĳ���������(ͷ������һ���ڵ�)
	{
		return _pHead->_next;
	}
	Iterator End()//�������һ���ڵ����һ���ڵ�ĵ�����(ͷ���)
	{
		return _pHead;
	}
	ConstIterator End()const//�������һ���ڵ����һ���ڵ�ĳ���������(ͷ���)
	{
		return _pHead;
	}
	bool Empty()const//�ж������Ƿ�Ϊ��
	{
		return _pHead == _pHead->_next;
	}
	SizeType Size()const //��������ڵ����
	{
		SizeType count = 0;
		for (Iterator it = Begin(); it != End(); it++)
		{
			count++;
		}
		return count;
	}
	Reference Front()//���ص�һ���ڵ������
	{
		return _pHead->_next->_value;
	}
	ConstReference Front()const //���ص�һ���ڵ�ĳ�������
	{
		return _pHead->_next->_value;
	}
	Reference Back()//�������һ���ڵ������
	{
		return _pHead->_prev->_value;
	}
	ConstReference Back()const //�������һ���ڵ�ĳ�������
	{
		return _pHead->_prev->_value;
	}
	Iterator Insert(Iterator pos, const T& x) //��posλ��ǰ����
	{
		LinkType NewNode = new Node(x);
		LinkType cur = pos._node;
		NewNode->_next = cur;
		cur->_prev->_next = NewNode;
		NewNode->_prev = cur->_prev;
		cur->_prev = NewNode;
		return Iterator(NewNode);
	}
	void PushFront(const T& x) //ͷ��
	{
		Insert(Begin(), x);
	}
	void PushBack(const T& x)
	{
		Insert(End(), x);
	}
	Iterator Erase(Iterator pos) //ɾ��posλ�õĽڵ�
	{
		assert(pos != End());
		LinkType pTemp = pos._node;
		LinkType pDel = pTemp;
		pTemp->_prev->_next = pTemp->_next;
		pTemp->_next->_prev = pTemp->_prev;
		delete pDel;
		pDel = NULL;
		return pTemp;
	}
	void PopFront() //ͷɾ
	{
		Erase(Begin());
	}
	void PopBack() //βɾ
	{
		Erase(--End());
	}
	void Clear() //�������
	{
		while (!Empty())
		{
			PopBack();
		}
	}
	List(const List<T>& l) //���캯��
	{
		_pHead = new Node;
		LinkType pTmp = l.Begin();
		while (pTmp != l.End())
		{
			pTmp++;
			PushBack(pTmp->_value);
		}
	}
	List& operator=(const List& l) //��ֵ�����������
	{
		_pHead = new Node;
		LinkType pTmp = l.Begin();
		while (pTmp != l.End())
		{
			pTmp++;
			PushBack(pTmp->_value);
		}
	}
	~List() //��������
	{
		Clear();
		delete _pHead;
		_pHead = NULL;
	}
 
protected:
	LinkType _pHead;//ָ��ͷ����ָ��
};