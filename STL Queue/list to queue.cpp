#include <iostream>
#include <list>
using namespace std;
template<class T,class Sequeue = list<T>>
class Myqueue
{
public:
	Myqueue()
		:s()
	{}
	void Push(const T& x)//����У�β��
	{
		s.push_back(x);
	}
	void Pop()//�����У�ͷ��
	{
		s.pop_front();
	}
	size_t Size()const//���д�С
	{
		return s.size();
	}
	T& Back()//���ض�β������
	{
		return s.back();
	}
	const T& Back()const
	{
		return s.back();
	}
	T& Front()//���ض�ͷ������
	{
		return s.front();
	}
	const T& Front()const
	{
		return s.front();
	}
	bool Empty()//�ж϶����Ƿ�Ϊ��
	{
		return s.empty();
	}
private:
	list<T> s;
};