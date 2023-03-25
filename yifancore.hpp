/*
Made By YifanZhuZhu.
*/
#ifndef _YIFANCORE_HPP
#define _YIFANCORE_HPP
#include <iostream>
#include <cstdio>
#include <cstring>
int split(int __n, int __m)
{
	if (__n == 1 || __m == 1)
		return 1;
	else if (__n < __m)
		return split(__n, __n);
	else if (__n == __m)
		return split(__n, __n - 1) + 1;
	else
		return split(__n, __m - 1) + split(__n - __m, __m);
}

long long power(int __x, int __y)
{
	long long __ans = 1;
	while (__y)
	{
		if (__y & 1)
			__ans = __ans * __x;
		__x *= __x;
		__y >>= 1;
	}
	return __ans;
}

char *encryptstr(char *__str)
{
	int i;
	if (strlen(__str) == 0)
	{
		return __str;
	}
	for (i = 0; __str[i] != '\0'; i++)
	{
		__str[i] = 255 - __str[i];
	}
	return __str;
}

char *decryptstr(char *__str)
{
	int i;
	if (strlen(__str) == 0)
	{
		return __str;
	}
	for (i = 0; __str[i] != '\0'; i++)
	{
		__str[i] = 255 - __str[i];
	}
	return __str;
}

struct bigInt
{
	int __num[1005];
	int __len;
	char __op;
	bigInt()
	{
		memset(__num, 0, sizeof(__num));
		__len = 1;
		__op = '+';
	}
};

int max(int __a, int __b)
{
	return (__a > __b) ? __a : __b;
}

bool operator>(bigInt __a, bigInt __b)
{
	if (__a.__op == '+' && __b.__op == '-')
		return true;
	if (__a.__op == '-' && __b.__op == '+')
		return false;
	if (__a.__len > __b.__len)
		return true;
	if (__a.__len < __b.__len)
		return false;
	if (__a.__op == '-' && __b.__op == '-')
	{
		for (int i = __a.__len; i >= 1; i--)
			if (__a.__num[i] > __b.__num[i])
				return false;
			else if (__a.__num[i] < __b.__num[i])
				return true;
			else if (__a.__num[i] == __b.__num[i])
				continue;
	}
	if (__a.__op == '+' && __b.__op == '+')
	{
		for (int i = __a.__len; i >= 1; i--)
			if (__a.__num[i] > __b.__num[i])
				return true;
			else if (__a.__num[i] < __b.__num[i])
				return false;
			else if (__a.__num[i] == __b.__num[i])
				continue;
	}
	return false;
}

bool operator<(bigInt __a, bigInt __b)
{
	if (__a.__op == '+' && __b.__op == '-')
		return false;
	if (__a.__op == '-' && __b.__op == '+')
		return true;
	if (__a.__len > __b.__len)
		return false;
	if (__a.__len < __b.__len)
		return true;
	if (__a.__op == '-' && __b.__op == '-')
	{
		for (int i = __a.__len; i >= 1; i--)
			if (__a.__num[i] > __b.__num[i])
				return true;
			else if (__a.__num[i] < __b.__num[i])
				return false;
			else if (__a.__num[i] == __b.__num[i])
				continue;
	}
	if (__a.__op == '+' && __b.__op == '+')
	{
		for (int i = __a.__len; i >= 1; i--)
			if (__a.__num[i] > __b.__num[i])
				return false;
			else if (__a.__num[i] < __b.__num[i])
				return true;
			else if (__a.__num[i] == __b.__num[i])
				continue;
	}
	return false;
}

bool operator==(bigInt a, bigInt b)
{
	if (a.__len == b.__len)
	{
		for (int i = a.__len; i >= 1; i--)
		{
			if (a.__num[i] != b.__num[i])
				return false;
			else
				continue;
		}
		return true;
	}
	return false;
}

bigInt operator+(bigInt a, bigInt b)
{
	bigInt __c;
	__c.__len = max(a.__len, b.__len);
	for (int i = 1; i <= __c.__len; i++)
		__c.__num[i] = a.__num[i] + b.__num[i];
	for (int i = 1; i <= __c.__len; i++)
		if (__c.__num[i] >= 10)
		{
			__c.__num[i + 1] += __c.__num[i] / 10;
			__c.__num[i] %= 10;
			__c.__len = max(__c.__len, i + 1);
		}
	return __c;
}

bigInt operator-(bigInt a, bigInt b)
{
	bigInt __c, temp;
	__c.__len = max(a.__len, b.__len);
	if (b > a)
	{
		__c.__op = '-';
		temp = a, a = b, b = temp;
	}
	for (int i = 1; i <= __c.__len; i++)
		__c.__num[i] = a.__num[i] - b.__num[i];
	for (int i = 1; i <= __c.__len; i++)
		if (__c.__num[i] < 0)
		{
			__c.__num[i] += 10;
			__c.__num[i + 1] -= 1;
		}
	return __c;
}

bigInt operator*(bigInt __a, bigInt __b)
{
	bigInt __c;
	__c.__len = __a.__len + __b.__len + 1;
	for (int i = 1; i <= __a.__len; i++)
		for (int j = 1; j <= __b.__len; j++)
			__c.__num[i + j - 1] += __a.__num[i] * __b.__num[j];
	for (int i = 1; i <= __c.__len; i++)
	{
		if (__c.__num[i] >= 10)
		{
			__c.__num[i + 1] += __c.__num[i] / 10;
			__c.__num[i] %= 10;
			__c.__len = max(__c.__len, i + 1);
		}
	}
	return __c;
}

bigInt numcopy(bigInt __a, int __l)
{
	bigInt __b;
	for (int i = 1; i <= __a.__len; i++)
		__b.__num[i + __l - 1] = __a.__num[i];
	__b.__len = __a.__len + __l - 1;
	__b.__op = '+';
	return __b;
}

bigInt operator/(bigInt __a, bigInt __b)
{
	bigInt __c;
	__c.__len = __a.__len - __b.__len + 1;
	for (int i = __c.__len; i >= 1; i--)
	{
		bigInt t = numcopy(__b, i);
		while (__a > t || __a == t)
		{
			__c.__num[i]++;
			if (__a == t)
				break;
			__a = __a - t;
			while (__a.__len > 0 && !__a.__num[__a.__len])
				__a.__len--;
		}
	}
	while (__c.__len > 0 && !__c.__num[__c.__len])
		__c.__len--;
	return __c;
}

bigInt operator%(bigInt __a, bigInt __b)
{
	for (int i = __a.__len - __b.__len + 1; i >= 1; i--)
	{
		bigInt __t = numcopy(__b, i);
		while (__a > __t || __a == __t)
		{
			if (__a == __t)
				break;
			__a = __a - __t;
			while (__a.__len > 0 && !__a.__num[__a.__len])
				__a.__len--;
		}
	}
	return __a;
}

bigInt __kkk(int __b)
{
	int __t = 0;
	bigInt __c;
	while (__b)
	{
		__t++;
		__c.__num[__t] = __b % 10;
		__b /= 10;
	}
	__c.__len = __t;
	return __c;
}

bigInt bi_gcd(bigInt __x, bigInt __y)
{
	if (__y == __kkk(0))
		return __x;
	else
		return bi_gcd(__y, __x % __y);
}

void bi_get(bigInt &__a)
{
	std::string __s1;
	std::cin >> __s1;
	if (__s1[0] == '-')
		__a.__op = '-', __s1.erase(0, 1);
	for (unsigned int i = 1; i <= __s1.size(); i++)
		__a.__num[i] = int(__s1[__s1.size() - i]) - '0';
	__a.__len = __s1.size();
}
void bi_print(bigInt __c)
{
	if (__c.__op == '-')
		printf("-");
	bool __flag = false;
	for (int i = __c.__len; i >= 1; i--)
		if (__c.__num[i] != 0 || __flag == true)
		{
			printf("%d", __c.__num[i]);
			__flag = true;
		}
	if (__flag == false)
		printf("0");
	printf("\n");
}

#endif
