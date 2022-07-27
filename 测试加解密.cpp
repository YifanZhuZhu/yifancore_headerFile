#include<cstdio>
#include"yifancore.hpp"
char a[1000]; 
int main()
{
	scanf("%s",a);
	strcpy(a,encryptstr(a));
	printf("加密后:%s\n",a);
	strcpy(a,decryptstr(a));
	printf("解密后:%s",a);
	return 0;
}
