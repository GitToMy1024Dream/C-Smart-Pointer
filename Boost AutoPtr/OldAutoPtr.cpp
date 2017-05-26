template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = NULL);
	AutoPtr(AutoPtr<T>& ap);
	AutoPtr<T>& operator=(AutoPtr<T>& ap);
	~AutoPtr();
	T& operator*();
	T& operator*()const;
	T* operator->();
	T* operator->()const;
protected:
	T* _ptr;
	mutable bool _owner;
};
 
template<class T>//���캯��
AutoPtr<T>::AutoPtr(T* ptr)
	:_ptr(ptr)
	,_owner(true)
{}
 
template<class T>//��������
AutoPtr<T>::AutoPtr(AutoPtr<T>& ap)
	:_ptr(ap._ptr)
	,_owner(true)
{
	ap._owner = false;
}
 
template<class T>//��ֵ�����������
AutoPtr<T>& AutoPtr<T>::operator=(AutoPtr<T>& ap)
{
	if (this != &ap)
	{
		delete this->_ptr;
		this->_ptr = ap._ptr;
		this->_owner = true;
		ap._owner = false;
	}
	return *this;
}
 
template<class T>//��������
AutoPtr<T>::~AutoPtr()
{
	if (this->_ptr)
	{
		this->_owner = false;
		delete this->_ptr;
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
template<class T>//����->const
T* AutoPtr<T>::operator->()const
{
	return this->_ptr;
}