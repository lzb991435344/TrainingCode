#include<stdio.h>
#include <iostream>

using namespace std;

int numberofOne(unsigned int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);
	}
	return count;
}

int numberofZero(unsigned int x)
{
	int count = 0;
	while (x + 1)
	{
		count++;
		x = x | (x + 1);
	}
	return count;
}

//求二进制数中1的个数
int f(unsigned int n)
{
	unsigned int m = 0;
	for (m = 0 ; n ; m++)
	{
		n &= (n-1);
	}
	return m;
}
int main(void)
{
	int m = 1;
	int n = 2;
	cout << numberofOne(m)<<endl;
	cout << numberofOne(n) << endl;

	cout << numberofZero(m) << endl;
	cout << numberofZero(n) << endl;
	getchar();
	system("pause");
	return 0;

}