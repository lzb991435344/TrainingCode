#include<stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>



//从0-N-1中等概率输出m个不重复的数
/**
证明：
1.输出不同的m个值：
由这个for循环循环n次，且在满足条件时才输出i,可知，输出不同值的要求已满足，因为每次输出的
都是i值，而i值每次都是不一样的，m--保证了程序在输出了m个值后就不再输出i。
2.等概率：
  在i=0时，rand()%(n-i)的取值范围为0到n-1，共n个数，此时要输出0只需要rand()%(n-i)小于m，
故i=0被输出的概率为m/n;
在i=1时，rand()%(n-i)的取值范围为0到n-2，共n-1个数，若i=0没有被输出，则m--未被执行，
此时i=1被输出的概率为m/(n-1)，若i=0已经被输出了，则m变为m-1，此时i=1被输出的概率为(m-1)/(n-1)；由概率论的知识，可知此时i=1被输出的概率为

P=(1-m/n)*(m/(n-1))+m/n*((m-1)/(n-1))=m/n；

以此类推，可知每个数被输出的概率都为m/n。
*/
void knuth(int n ,int m)
{
	srand((unsigned int)time(0));
	for (int i = 0 ; i < n ; i++)
	{
		if (rand()%(n - i) < m)
		{
			cout<< i<<endl;
			m--;
		}
	}
}

//给定一个返回0~6的随机自然数的函数，记为rand6()，则如何用rand6()函数构造
//返回0~9随机自然数的函数rand9()？

/**
  把第一个rand6()产生的随机数a放在个位上，而把第二个rand6()产生的随机数b放在十位上，
所有可能为：00~06,10~16,20~26,30~36，40~46,50~56，60~66。很容易看出这些就是7进制数，
所以我们用rand6()*7+rand6()就能生成0~49范围的随机数，而且每个数产生的概率相等，都是1/49。
产生40~49之间的随机数时不保留而重新产生一个新的随机数，这样产生0~39之间的数也是等概率的，
仍然都是1/49，对于产生的数我们记为r（0<= r <=39），则 r/4 即可返回0~9范围的数。而且 r 取
0~3这四个数时 r/4 返回0，r 取4~7这四个数时 r/4 返回1，……，r 取36~39这四个数时 r/4 返回9。
因此返回0~9范围的每个数字的概率都是4/49，满足等概率。
*/
// 随机产生0~6之间的数
int rand6()
{
	return rand() % 7;
}

// 用rand6()编写随机产生0~9之间的数
int rand9()
{
	int a, b, r;
	do {
		a = rand6();
		b = rand6();
		cout << "a = " << a << ", b = " << b << endl;
		r = a * 7 + b;
	} while (r >= 40);

	return r / 4;
}

int main()
{
	//knuth(10,5);
	/**
   函数一：int rand(void)；
   返回一个[0,RAND_MAX]间的随机整数。
   函数二：void srand(unsigned seed)；
   参数seed是srand()的种子，用来初始化srand()的起始值
	*/
	srand((unsigned)time(NULL));
	printf("%d",rand9());

	getchar();
	system("pause");
	return 0;
}
