#include <iostream>
#include <deque>
using namespace std;
template<class T,class Sequeue = deque<T>>
class Myqueue
{
public:
	Myqueue()
		:s()
	{}
	void Push(const T& x)//����� ͷ��
	{
		s.push_back(x);
	}
	void Pop()//������ βɾ
	{
		s.pop_front();
	}
	bool Empty()//�ж϶����Ƿ�Ϊ��
	{
		return s.empty();
	}
	size_t Size()const//���д�С
	{
		return s.size();
	}
	T& Front()//���ض�ͷ������
	{
		return s.front();
	}
	const T& Front()const
	{
		return s.front();
	}
	T& Back()//���ض�β������
	{
		return s.back();
	}
	const T& Back()const
	{
		return s.back();
	}
private:
	//����==�����
	friend bool operator==(const Myqueue&x, const Myqueue& y);
	//����С�������
	friend bool operator<(const Myqueue&x, const Myqueue&y);
	deque<T> s;
};
 
template<class T,class Sequence>
bool operator==(const Myqueue<T, Sequence>&x, const Myqueue<T, Sequence>& y)
{
	return x.s == y.s;
}
template<class T, class Sequence>
bool operator<(const Myqueue<T, Sequence>&x, const Myqueue<T, Sequence>& y)
{
	return x.s < y.s;
}