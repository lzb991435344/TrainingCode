
#include<stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include<time.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

template <class T>
class Array
{
public:
	//ctor
	Array(int sz =50)
	{
		assert(sz > 0);
		size = sz;
		list = new T[size];
	}
	//dtor
	~Array()
	{
		delete[] list;
	}

	//复制构造函数
	Array(const Array<T>& a)
	{
		size = a.size;
		//新建对象
		list = new T[size];
		//赋值
		for (int i = 0 ;i < size; i++)
		{
			list[i] = a[i];
		}
	}

	//=号重载
	Array<T>& operator= (const Array<T>& rhs)
	{
		if (this != rhs)
		{
			if (size != rhs.size)
			{
				delete[] list;
				size = rhs.size;
				list = new T[size];
			}
			for (int i = 0 ; i < size ; i++)
			{
				list[i] = rhs.list[i];
			}
		}
		return *this;
	}

	//下标[]重载
	T& operator[](int i)
	{
		assert(i >= 0 && i<size);
		return list[i];
	}
	//下标[]重载2
	const T& operator[]( int i)const
	{
		assert(i >= 0 && i < size);
		return list[i];
	}
	//重载指针转换运算符，将Array类的对象名转换为T类型的指针  
	//指向当前对象中的私有数组，  
	//因而可以像使用普通数组首地址一样使用Array类的对象名  
	/*operator T* ()
	{
		return list;
	}

	const operator T*() const 
	{
		return list;
	}*/
	//数组的大小
	int getsize() const 
	{
		return size;
	}

	//重新设置数组的大小
	void resize(int sz)
	{
		if (sz == size)
		{
			return;
		}
		//new出新的空间
		T* newlist = new T[sz];
		//确定循环的大小
		int n = sz < size ? sz : size;
		//复制新的值
		for (int i = 0 ; i < n ; i++)
		{
			newlist[i] = list[i];
		}
		delete[] list;
		list = newlist;
		size = sz;
	}
	//添加数据
	void add(const T x)
	{
		assert(size >= 0);
		size++;
		T* newlist = new T[size];
		for (int i =0 ;i <size - 1 ; i++)
		{
			newlist[i] = list[i];
		}
		newlist[size - 1] = x;
		delete[] list;
		list = newlist;
	}
	//在指定位置插入数据
	void insert(const int n ,const int x)
	{
		assert(size >= 0 && n < size );
		T* newlist = new T[n];
		for (int i = 0; i < n; i++)
		{
			newlist[i] = list[i];
		}
		newlist[n] = x;
		//后半段的赋值
		for (int i = n + 1 ; i < size ; i++)
		{
			newlist[i] = list[i - 1];
		}
		delete[] list;
		list = newlist;
	}
	//在指定位置删除数据
	void remove(const int n)
	{
		assert(size >= 0 && n < size);
		T* newlist = new T[--size];
		//复制[0,n-1]的数据
		for (int i = 0 ; i < n ; i++)
		{
			newlist[i] = list[i];
		}
		//数据移动,将n之后的元素往前移动一位
		for (int i = n + 1 ; i < size ; i++)
		{
			newlist[i - 1] = list[i];
		}
		delete[] list;
		list = newlist;
	}
private:
	T* list;
	int size;
};

int main()
{
	Array<int> a(4);
	cout << "size=" << a.getsize() << endl;
	for (int i = 0; i < a.getsize(); i++) {
		a[i] = i;
	}
	for (int i = 0; i < a.getsize(); i++) {
		cout << a[i] << endl;
	}
	cout << "***********test***************" << endl;
	cout << "add " << endl;
	a.add(53);
	for (int i = 0; i < a.getsize(); i++) {
		cout << a[i] << endl;
	}
	cout << "size=" << a.getsize() << endl;
	cout << "***********test***************" << endl;
	cout << "remove" << endl;
	a.remove(2);
	for (int i = 0; i < a.getsize(); i++) {
		cout << a[i] << endl;
	}
	cout << "size=" << a.getsize() << endl;
	cout << "***********test***************" << endl;
	cout << "insert" << endl;
	a.insert(2, 100);
	for (int i = 0; i < a.getsize(); i++) {
		cout << a[i] << endl;
	}
	cout << "size=" << a.getsize() << endl;
	cout << "***********test***************" << endl;
	getchar();
	system("pause");
	return 0;

}