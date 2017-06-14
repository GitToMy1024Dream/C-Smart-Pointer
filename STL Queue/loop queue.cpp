#pragma once
#include <iostream>
using namespace std;
template<class T>
class Queue
{
public:
	Queue(size_t capacity = 5)//���캯��
		:_capacity(capacity + 1)
		, _count(0)
		, _front(0)
		, _rear(0)
	{
		_pData = new T[capacity];//����ռ�
	}
	void Push(const T& x)//����β��
	{
		//����
		if (((_rear + 1) % _capacity) == _front && (Size() == _capacity))
		{
			cout << "Queue Full." << endl;
			return;
		}
		_pData[_count] = x;
		_count++;
		_rear = (_rear + 1) % _capacity;
	}
	void Pop()//����ͷɾ
	{
		if (_front == _rear)//�ӿ�
		{
			cout << "Queue Empty" << endl;
			return;
		}
		T temp = _pData[_front];
		_pData[_front] = NULL;
		_front = (_front + 1) % _capacity;
		_count--;
	}
	T& Front()//���ض�ͷ������
	{
		if (Empty())
		{
			cout << "Queue Empty!" << endl;
		}
		return _pData[_front];
	}
	const T& Front()const
	{
		if (Empty())
		{
			cout << "Queue Empty!" << endl;
		}
		return _pData[_front];
	}
	T& Back()//���ض�β������
	{
		return _pData[_rear-1];
	}
	const T& Back()const
	{
		return _pData[_rear-1];
	}
	size_t Size()const//���еĴ�С
	{
		return _count;
	}
	bool Empty()const//�ж϶����Ƿ�Ϊ��
	{
		return _front == _rear ;
	}
	~Queue()//��������
	{
		if (_pData)
		{
			delete[] _pData;
			_pData = NULL;
			_count = 0;
			_rear = _front = 0;
		}
	}
 
private:
	T* _pData;//�������ݵ�ָ��
	size_t _capacity;//����
	size_t _front;//��ͷ
	size_t _rear;//��β
	size_t _count;//��ЧԪ�ظ���
};