#include <iostream>
using namespace std;
#pragma warning (disable:4996)
//�ر��ļ�
struct Fclose
{
	void operator()(void* ptr)
	{
		fclose((FILE*)ptr);
		cout << "fclose()" << endl;
	}
};
//�ͷ�malloc
struct Free
{
	void operator()(void *ptr)
	{
		free(ptr);
		cout << "free()" << endl;
	}
};
//Ĭ��Ϊdelete
struct DefaultDelete
{
	void operator()(void *ptr)
	{
		delete ptr;
		cout << "delete()" << endl;
	}
};

template<class T,class Deleter = DefaultDelete>
class SharedPtr
{
public:
	SharedPtr(T* ptr);
	SharedPtr(T* ptr, Deleter del);
	SharedPtr(const SharedPtr<T, Deleter>& ap);
	~SharedPtr();
	SharedPtr<T, Deleter>& operator=(SharedPtr<T, Deleter> ap);
	T& operator*();
	T& operator*()const;
	T* operator->();
	T* operator->()const;
	long GetCount()const;
	T* GetPtr()const;
private:
	T* _ptr;
	long* _count;
	Deleter _del;
};

template<class T,class Deleter = DefaultDelete>
SharedPtr<T, Deleter>::SharedPtr(T* ptr)//���캯��
	:_ptr(ptr)
	,_count(new long(1))
{}
template<class T, class Deleter = DefaultDelete>
SharedPtr<T, Deleter>::SharedPtr(T* ptr,Deleter del)//���캯��
	: _ptr(ptr)
	, _count(new long(1))
	,_del(del)
{}

template<class T,class Deleter = DefaultDelete>
SharedPtr<T, Deleter>::SharedPtr(const SharedPtr<T, Deleter>& sp)//��������
	:_ptr(sp._ptr)
	,_count(sp._count)
	,_del(sp._del)
{
	++(*_count);
}

template<class T,class Deleter = DefaultDelete>
SharedPtr<T, Deleter>::~SharedPtr()//��������
{
	if (--(*_count) == 0)
	{
		_del(_ptr);
		delete _count;
	}
}
template<class T, class Deleter = DefaultDelete>//��ֵ�����������
SharedPtr<T, Deleter>& SharedPtr<T, Deleter>::operator=(SharedPtr<T, Deleter> sp)
{
	std::swap(_ptr, sp._ptr);
	std::swap(_count, sp._count);
	std::swap(_del, sp._del);
	return *this;
}

template<class T,class Deleter = DefaultDelete>
T& SharedPtr<T, Deleter>::operator*()//���ؽ�����
{
	return *_ptr;
}

template<class T, class Deleter = DefaultDelete>
T& SharedPtr<T, Deleter>::operator*()const
{
	return *_ptr;
}

template<class T, class Deleter = DefaultDelete>
T* SharedPtr<T, Deleter>::operator->()//���ؼ�������
{
	return _ptr;
}

template<class T, class Deleter = DefaultDelete>
T* SharedPtr<T, Deleter>::operator->()const
{
	return _ptr;
}

template<class T,class Deleter = DefaultDelete>
long SharedPtr<T, Deleter>::GetCount()const//��ȡ���ü���
{
	return *_count;
}

template<class T,class Deleter = DefaultDelete>
T* SharedPtr<T, Deleter>::GetPtr()const//��ȡ����ָ��
{
	return _ptr;
}

int main()
{
	SharedPtr<int> sp1(new int(1));//Ĭ��Ϊdelete
	SharedPtr<FILE, Fclose> sp2(fopen("1.txt", "w+"), Fclose());//�ļ�����
	SharedPtr<string, Free> sp3((string *)malloc(sizeof(string)), Free());//�ַ�������
	system("pause");
	return 0;
}