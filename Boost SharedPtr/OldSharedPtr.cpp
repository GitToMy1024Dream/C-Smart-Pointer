#include <iostream>
using namespace std;
 
template<class T>
class SharedPtr
{
public:
	SharedPtr();
	SharedPtr(T* ptr);
	SharedPtr(const SharedPtr<T>& ap);
	~SharedPtr();
	SharedPtr<T>& operator=(SharedPtr<T> ap);
	T& operator*();
	T& operator*()const;
	T* operator->();
	T* operator->()const;
	long GetCount()const;
	T* GetPtr()const;
private:
	T* _ptr;
	long* _pCount;
};
 
template<class T>//���캯��
SharedPtr<T>::SharedPtr()
	:_ptr(NULL)
	,_pCount(new long(1))
{}
 
template<class T>//���캯��(������)
SharedPtr<T>::SharedPtr(T* ptr)
	:_ptr(ptr)
	,_pCount(new long(1))
{}
 
template<class T>//�������캯��
SharedPtr<T>::SharedPtr(const SharedPtr<T>& ap)
	:_ptr(ap._ptr)
	,_pCount(ap._pCount)
{
	++(*this->_pCount);
}
 
template<class T>//��������
SharedPtr<T>::~SharedPtr()
{
	if (--(*this->_pCount) == 0)
	{
		delete this->_ptr;
		delete this->_pCount;
	}
}
//����һ
template<class T>//��ֵ�����������
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T> ap)
{
	if (this != &ap)
	{
		if (--(*this->_pCount) == 0)
		{
			delete this->_ptr;
			delete this->_pCount;
		}
		this->_ptr = ap._ptr;
		this->_pCount = ap._pCount;
		++(*this->_pCount);
	}
	return *this;
}
 
//������
//template<class T>
//SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T> ap)
//{
//	swap(this->_ptr, ap->_ptr);
//	swap(this->_pCount, ap->_pCount);
//	return *this;
//}
 
template<class T>//����*�����
T& SharedPtr<T>::operator*()
{
	return *(this->_ptr);
}
template<class T>//����*�����const
T& SharedPtr<T>::operator*()const
{
	return *(this->_ptr);
}
 
template<class T>//����->�����
T* SharedPtr<T>::operator->()
{
	return this->_ptr;
}
template<class T>//����->�����const
T* SharedPtr<T>::operator->()const
{
	return this->_ptr;
}
 
template<class T>//��ȡ��ǰ���ü����ĸ���
long SharedPtr<T>::GetCount()const
{
	return *(this->_pCount);
}
 
template<class T>
T* SharedPtr<T>::GetPtr()const//��ǰ�Ķ���ָ��
{
	return this->_ptr;
}
 
int main()
{
	SharedPtr<int> ap1(new int(2));
	SharedPtr<int> ap2(ap1);
	SharedPtr<int> ap3 = ap2;
	system("pause");
	return 0;
}