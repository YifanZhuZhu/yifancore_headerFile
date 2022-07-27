#include<stdio.h>
#include"yifancore.h"
int main()
{
	int a,m,n;
	scanf("%d%d",&m,&n);
	a=split(m,n);
	printf("%d",a);
	return 0;
}
