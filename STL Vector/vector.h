#pragma once
template<class T>
class Vector
{
public:
	typedef T ValueType;//��������T���洢��vector��
	typedef ValueType* Pointer;//ָ��T��ָ��
	typedef const ValueType* ConstPointer;
	typedef ValueType* Iterator;//����vector�ĵ�����
	typedef const ValueType* ConstIterator;//����vector�ĳ���������
	typedef ValueType& Reference;//T��һ������
	typedef const ValueType& ConstReference;//T�ĳ�������
	typedef size_t SizeType;//����������
 
 
public:
	Vector()//���캯��
		: _start(0)
		, _end(0)
		, _endOfStorage(0)
	{}
 
	Vector(SizeType n, const T& value)//����һ��vector������Ϊn����СΪvalue
	{
		FillAndInit(n, value);
	}
 
	Vector(SizeType n)//����һ��vector��Ԫ������Ϊn
	{
		FillAndInit(n, T());
	}
 
	Vector(const Vector<T>& v)//�������캯��
	{
		CheckCapacity();
		_start = new T[v.Capacity()];
		_end = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
 
		for (size_t idx = 0; idx < v.Size(); ++idx)
			_start[idx] = v[idx];
	}
 
	Vector<T>& operator=(const Vector<T>& v)//��ֵ�����������
	{
		if (this != &v)
		{
			_start = v._start;
			_end = v._end;
			_endOfStorage = v._endOfStorage;
		}
		return *this;
	}
	~Vector()//��������
	{
		delete[] _start;
		_start = _end = 0;
	}
 
 
	/////////////////////Capacity//////////////////////
	SizeType Capacity()const//���ص�ǰ�������ɵ����Ԫ�صĸ���
	{
		return SizeType(_endOfStorage - Begin());
	}
	SizeType Size()const//����vector��Ԫ������
	{
		return SizeType(End() - Begin());
	}
	SizeType MaxSize()const//�������������vectorԪ������ֵ
	{
		return (SizeType(-1) / sizeof(T));
	}
	bool Empty()const//�ж�vector�Ƿ�Ϊ��
	{
		if (Size() == 0)
			return true;
		return false;
	}
 
	//////////////Acess/////////////////////
	Reference operator[](size_t index)//���ص�n��Ԫ��
	{
		return *(Begin() + index);
	}
	ConstReference operator[](size_t index)const
	{
		return *(Begin() + index);
	}
	Reference Front()//���ص�һ��Ԫ��
	{
		return *Begin();
	}
	ConstReference Front()const
	{
		return *Begin();
	}
	Reference Back()//�������һ��Ԫ��
	{
		return *(End() - 1);
	}
	ConstReference Front()const
	{
		return *(End() - 1);
	}
 
 
	/////////////Iterator//////////////////
	Iterator Begin()//����vector��ͷָ��
	{
		return _start;
	}
	ConstIterator Begin()const
	{
		return _start;
	}
	Iterator End()//����vector��βָ��
	{
		return _end;
	}
	ConstIterator End()const
	{
		return _end;
	}
 
	//////////////Modify///////////////////
	void PushBack(const T& value)//β��
	{
		CheckCapacity();
		Insert(End(), value);
	}
	void PopBack()
	{
		Iterator pos = End();
		Erase(--pos);
	}
 
	// ��positionλ�ò���Ԫ��data
	Iterator Insert(Iterator position, const T& data)
	{
		CheckCapacity();
		for (Iterator index = End(); index != position; index--)
		{
			*index = *(index - 1);
		}
		*position = data;
		_end++;
	}
 
	// ɾ��positionλ�õ�Ԫ��
	Iterator Erase(Iterator position)
	{
		Iterator end = End();
		for (Iterator index = position; index != End(); ++index)
		{
			*index = *(index + 1);
		}
		_end--;
	}
	//���
	void clear()
	{
		Erase(Begin(), End());
	}
	
protected:
	void FillAndInit(SizeType n, const T& value)
	{
		_start = new T[n];
		for (size_t index = 0; index < _end; ++index)
		{
			_start[index] = value;
		}
	}
	void CheckCapacity()
	{
		if (_end == _endOfStorage)
		{
			Iterator NewStart = new T[2 * Size()];
			Iterator NewEnd = NewStart;
			for (Iterator i = Begin(); i != End(); i++, NewEnd++)
			{
				*NewEnd = *i;
			}
			delete[] _start;
			_start = NewStart;
			_end = NewEnd;
			_endOfStorage = _start + 2 * Size();
		}
	}
protected:
	Iterator _start;
	Iterator _end;
	Iterator _endOfStorage;
 
};