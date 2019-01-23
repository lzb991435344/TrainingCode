
#include<stdio.h>
#include <string.h>
#include <iostream>
#include "afxmt.h"
using namespace std;

//实现一个单例,要求线程安全

class Lock
{
private:
	/**
	类CCriticalSection的对象表示一个“临界区”，
	它是一个用于同步的对象，同一时刻只允许一个线程存取
	资源或代码区
	*/
	CCriticalSection m_cs;
public:
	Lock(CCriticalSection&  cs) :m_cs(cs)
	{
		m_cs.Lock();
	}
	~Lock()
	{
		m_cs.Unlock();
	}

};

class Singleton
{
private:
	Singleton();
	Singleton(const Singleton&);
	Singleton& operator= (const Singleton&);
public:
	static Singleton* InitializeInstance();
	static Singleton* pInstance;
	static CCriticalSection cs;
};

Singleton* Singleton::pInstance = 0;//初始化静态对象
//初始化对象
Singleton* Singleton::InitializeInstance()
{
	if (NULL == pInstance)
	{//用lock实现线程安全，用资源管理类实现异常安全
		Lock lock(cs);

		//使用资源管理类，在抛出异常的时候，资源管理类对象
		//会被析构，析构总是发生的无论是因为异常抛出还是语句块结束。
		if (NULL == pInstance)
		{
			pInstance = new Singleton();
		}
	}
	return pInstance;
}

class SingletonClass
{
private:
	SingletonClass();
	SingletonClass(const SingletonClass& s);
	SingletonClass& operator=(const SingletonClass& s);
	static SingletonClass* instance;
public:
	//该函数使用static用于隐藏
	static SingletonClass* GetInstance()
	{
		static SingletonClass instance;
		return &instance;
	}
};
int main()
{
	getchar();
	system("pause");
	return 0;

}
