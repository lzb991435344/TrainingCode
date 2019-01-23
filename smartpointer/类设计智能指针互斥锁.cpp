#include<stdio.h>
#include <string.h>
#include <iostream>
#include "afxmt.h"
using namespace std;

/**
设计一个抽象类，使得它可以完成有序数组归并的任务
*/

class Sequence 
{
public:
	virtual Object* next()=0;
	virtual bool hasNext()=0;
	virtual Object* top() = 0;
	virtual bool add(Object* obj) = 0;
};

class Object
{
public:
	virtual bool lessthan(Object* another);
};

/**
  设计一个多终端日志打印的接口，使得它可以动态支持不同终端
的日志打印

*/

//抽象类
class BaseTerminal
{
public:
	virtual void PrintLog(const string& message) = 0;
};

class Scene :public BaseTerminal
{
public:
	void PrintLog(const string& message) = 0;
};
class NetWork :public BaseTerminal
{
public:
	void PrintLog(const string& messsage) = 0;
};
//全局的打印日志函数
void  LogPrint(const BaseTerminal& terminal);


/**
  给N张牌和一个随机函数，实现一个洗牌算法
*/

void shuffle(int cards[], int n)
{
	if (NULL == cards)
	{
		return;
	}
	//随机种子
	srand(time(0));
	for(int i = 0 ; i < n - 1 ; i++)
	{
		int index = i + rand() % (n - i);
		int temp = cards[i];
		cards[i] = cards[index];
		cards[index] = temp;
	}
}

/**
  智能指针是一种资源管理类，通过对原始指针进行封装，
在资源管理对象进行析构时对指针指向的内存进行释放
实现一个智能指针
*/

class Object2;
class SmartPointer;

class Counter
{
	friend class SmartPointer;
public:
	Counter():ptr(NULL),cnt(0){}
	Counter(Object2* p):ptr(p),cnt(1){}
	~Counter() { delete ptr; }
private:
	Object2* ptr;
	int cnt;
};
class SmartPointer
{
public:
	SmartPointer(Object2* p)
	{
		ptr_counter = new Counter(p);
	}

	//拷贝构造函数
	SmartPointer(const SmartPointer& sp)
	{
		ptr_counter = sp.ptr_counter;
		++ptr_counter->cnt;//引用计数增加
	}

	//拷贝赋值函数
	SmartPointer& operator=(const SmartPointer& sp)
	{
		++sp.ptr_counter->cnt;
		--ptr_counter->cnt;
		if (0 == ptr_counter->cnt)
		{
			delete ptr_counter;
		}
		//重新赋值
		ptr_counter = sp.ptr_counter;
	}
	~SmartPointer()
	{
		--ptr_counter->cnt;//引用计数减1
		//引用计数为0时，释放指针
		if (0 == ptr_counter->cnt  )
		{
			delete ptr_counter;
		}
	}
private:
	Counter* ptr_counter;

};

/**

用普通的互斥锁编程实现一个读写锁*/

int  mutex_init() {}
void lock(int ) {}
void unlock(int) {}
int count_mutex = mutex_init();
int write_mutex = mutex_init();
int read_cout = 0;


void read_lock()
{
	lock(count_mutex);
	read_cout++;
	//当前读的数量为1
	if (1 == read_cout)
	{
		//锁住写互斥量
		lock(write_mutex);
	}
	//解锁计数互斥量
	unlock(count_mutex);
}

void read_unlock()
{
	lock(count_mutex);
	read_cout--;
	//当前读的计数为0
	if (0 == read_cout)
	{
		//释放写互斥量
		unlock(write_mutex);
	}
	unlock(count_mutex);
}

void write_lock()
{
	lock(write_mutex);
}

void write_unlock()
{
	unlock(write_mutex);
}
int main()
{
	getchar();
	system("pause");
	return 0;

}
