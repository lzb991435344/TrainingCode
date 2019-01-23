#include "pch.h"
#include<stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

//memcpy存在内存重叠的问题，使用memmove
//实现一个memcpy()
void* memcpy(void* dst, const void* src, size_t len)
{
	if (NULL == dst || NULL == src)
	{
		return NULL;
	}
	void* ret = dst;
	//无内存重叠,从低地址复制
	if (dst <= src || (char*)dst > (char*)src + len)
	{
		while (len--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else//有内存重叠,从高地址复制
	{
		//先找到从高地址复制的位置
		dst = (char*)dst + len - 1;
		src = (char*)src + len - 1;
		while (len--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}

//避免内存重叠,使用MyMemmove
void* MyMemmove(void* str1, void* str2,size_t n)
{
	char* pStr1 = (char*)str1;
	char* pStr2 = (char*)str2;
	if (pStr1 < pStr2)//从pStr1复制到pStr2,从低地址往高地址复制
	{
		for (size_t i = 0;i < n ; i++)
		{
			*(pStr1++) = (*pStr2++);
		}
	}
	else//从pStr2复制到pStr1,从高地址往高地址复制
	{
		pStr1 += n - 1;
		pStr2 += n - 1;
		for (size_t i = 0; i < n ; i++)
		{
			*(pStr1--) = *(pStr2--);
		}
	}
	return str1;
}
int main()
{

	//unsigned char i = 1;//8位，0~2^8-1
	//i -= 4;//-3
	//printf("%d", i); //2^8-3
	getchar();
	system("pause");
	return 0;

}
