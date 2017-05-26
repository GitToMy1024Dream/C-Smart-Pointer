template<class T>
class AutoPtr
{
public:
	AutoPtr();
	AutoPtr(T* ptr);
	AutoPtr(AutoPtr<T>& ap);
	AutoPtr<T>& operator=(AutoPtr<T>& ap);
	~AutoPtr();
	T& operator*();
	T& operator*()const;
	T* operator->();
	T* operator->()const;
protected:
	T* _ptr;
};
 
template<class T>//���캯��
AutoPtr<T>::AutoPtr()
	:_ptr(NULL)
{}
template<class T>
AutoPtr<T>::AutoPtr(T* ptr) // ����д��const T* ptr��const���͵ĸ�ֵ���ܸ���const����
	:_ptr(ptr)
{}
template<class T>//��������
AutoPtr<T>::AutoPtr(AutoPtr<T>& ap)
	:_ptr(ap._ptr)
{
	ap._ptr = NULL;
}
 
template<class T>//��ֵ�����������
AutoPtr<T>& AutoPtr<T>::operator=(AutoPtr<T>& ap)
{
	if (this != &ap)
	{
		delete this->_ptr;
		this->_ptr = ap._ptr;
		ap._ptr = NULL;
	}
	return *this;
}
template<class T>//��������
AutoPtr<T>::~AutoPtr()
{
	if (this->_ptr)
	{
		delete this->_ptr;
		this->_ptr = NULL;
	}
}
 
template<class T>//����*
T& AutoPtr<T>::operator*()
{
	return *(this->_ptr);
}
template<class T>
T& AutoPtr<T>::operator*()const
{
	return *(this->_ptr);
}
 
template<class T>//����->
T* AutoPtr<T>::operator->()
{
	return this->_ptr;
}
template<class T>
T* AutoPtr<T>::operator->()const
{
	return this->_ptr;
}