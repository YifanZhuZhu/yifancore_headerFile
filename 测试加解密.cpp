#include<cstdio>
#include"yifancore.hpp"
char a[1000]; 
int main()
{
	scanf("%s",a);
	strcpy(a,encryptstr(a));
	printf("���ܺ�:%s\n",a);
	strcpy(a,decryptstr(a));
	printf("���ܺ�:%s",a);
	return 0;
}
