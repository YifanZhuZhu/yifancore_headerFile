/*
Made By YifanZhuZhu.
*/
#ifndef _YIFANCORE_H
#define _YIFANCORE_H

int split(int n,int m)
{
    if(n==1||m==1)return 1;
    else if(n<m)return split(n,n);
    else if(n==m)return split(n,n-1)+1;
    else return split(n,m-1)+split(n-m,m);
}

long long power(int x,int y)
{
	if(y==0)return 1;
	else return x*power(x,y-1);
}

#include<cstring>

char* encryptstr(char* str)
{
	int i;
	if(strlen(str)==0)
	{
		return str;
	}
	for(i=0;str[i]!='\0';i++)
	{
		str[i]=255-str[i];
	}
	return str;
}

char* decryptstr(char* str)
{
	int i;
	if(strlen(str)==0)
	{
		return str;
	}
	for(i=0;str[i]!='\0';i++)
	{
		str[i]=255-str[i];
	}
	return str;
}

#endif

