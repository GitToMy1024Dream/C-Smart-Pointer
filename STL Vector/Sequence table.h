#pragma once
#include <iostream>
#include <Windows.h>
#include <assert.h>
using namespace std;
typedef int DataType;
class Vector
{
public:
	explicit Vector(size_t capacity = 3)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		_capacity += 3;
		_size = 0;
	}
	//���캯�� ��size��ֵΪdata��Ԫ��
	Vector(size_t n, const DataType& data)
	{
		_pData = (DataType*)malloc(_capacity * sizeof(DataType));
		_size = n;
		_capacity = n;
		for(size_t idx = 0;idx < _size;++idx)
		{
			_pData[idx] = data;
		}
	}
	//��������
	Vector(const Vector& v)
		: _capacity(v._capacity)//����
		, _size(v._size)//��ЧԪ�صĸ���
	{
		_pData = new DataType[_capacity];
		// �Ƚ�1��2����ȱ�㣿
		// 1 memcpy���src��dstָ����ڴ�ռ��ص������ܱ�֤�Ƿ����ݸ���
		//memcpy(_pData, v._pData, sizeof(DataType)*_size);
		// 2 Ч�ʽϵͣ����Ƚϰ�ȫ
		for(size_t idx = 0; idx < _size; ++idx)
			_pData[idx] = v._pData[idx];
	}
	//���ظ�ֵ�����
	Vector& operator=(const Vector& v)
	{
		if(this != &v)
		{
			_pData = v._pData;
			_size = v._size;
			_capacity = v._capacity;
		}
	}
	//��������
	~Vector()
	{
		if(_pData != NULL)
		{
			free(_pData);
			_pData = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
	void PushBack(const DataType& data);//β��
	void PopBack();//βɾ
	void Insert(size_t pos, const DataType& data);//��posλ�ú������ֵΪdata��Ԫ��
	void Erase(size_t pos);//ɾ��posλ���ϵ�Ԫ��
	int Find(const DataType& data)const;//Ѱ��ֵΪdata��Ԫ�ط����±�
	void Clear();//���˳���
	size_t Size()const;//����˳���Ĵ�С
	void ReSize(size_t size, const DataType& data);//��_size �� size֮���Ԫ�ظ�ֵΪdata
	size_t Capacity()const;//˳��������Ĵ�С
	bool Empty()const;//�ж�˳����Ƿ�Ϊ��
	DataType& Front();//���ص�һ��Ԫ�ص�����
	const DataType& Front()const;//ͬ�� �ɶԳ���
	DataType& Back();//�������һ��Ԫ�ص�����
	const DataType& Back()const;//ͬ��
	//��n��ֵΪdata��Ԫ�ص�vector��.����������������Ϊvector��ֵ��ǰ������.
	void Assign(size_t n, const DataType& data);
	DataType& operator[](size_t index);//�±���ʽ綨��
	const DataType& operator[](size_t index)const;//ͬ��
	DataType& At(size_t index);//
	const DataType& At(size_t index)const;//ͬ��
 
private:
	void _CheckCapacity();
	friend std::ostream& operator<<(std::ostream& _cout, const Vector& v);
private:
	DataType* _pData;//�ռ��׵�ַ
	size_t _capacity;//����
	size_t _size;//��ЧԪ�صĸ���
};