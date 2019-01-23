#include<stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
using namespace std;
class  A
{
public:
	A()
	{
		printf("A");
	}
    //没加virtual只析构A,加了virtual之后析构顺序为deC,deB,deA,
	//会析构子类的构造函数(构造顺序为A B C)
	 virtual  ~A() 
	{
		printf("deA");
	}
};
class B
{
public:
	B()
	{
		printf("B");
	}
	~B()
	{
		printf("deB");
	}
};

//class C:public B ,public A 打印出B A C deA
class C :public B, public A
{
public:
	C()
	{
		printf("C");
	}
	~C()
	{
		printf("deC");
	}
};