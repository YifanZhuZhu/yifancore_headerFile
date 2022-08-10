#include<stdio.h>
#include"yifancore.h"
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	long long a=power(m,n);
	printf("%lld",a);
	return 0;
}
