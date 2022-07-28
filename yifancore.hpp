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

#include<string>
#include<iostream>
#include<cstdio>
using namespace std;

struct hp_int{
    int num[20110];     //此处范围要开到数据范围的两倍,因为乘法时位数会翻倍 
    int len;
    char op;
    hp_int(){ memset(num,0,sizeof(num));  len = 1; op = '+';}
};//注意存之前要倒序处理最高位放最后 
int max(int a,int b){
    return (a > b) ? a : b;
}
bool operator > (hp_int a,hp_int b){//重载了大于判断符,以符号为第一关键字,以长度为第二关键字,以绝对值为第三关键字,注意符号 
    if(a.op == '+' && b.op == '-')  return true;
    if(a.op == '-' && b.op == '+')  return false;
    if(a.len > b.len)               return true;
    if(a.len < b.len)               return false;
    if(a.op == '-' && b.op == '-')
    {
        for(int i = a.len;i >= 1;i --)
            if(a.num[i] > b.num[i])         return false;
            else if(a.num[i] < b.num[i])    return true;
            else if(a.num[i] == b.num[i])   continue;
    }
    if(a.op == '+' && b.op == '+')
    {
        for(int i = a.len;i >= 1;i --)
            if(a.num[i] > b.num[i])         return true;
            else if(a.num[i] < b.num[i])    return false;
            else if(a.num[i] == b.num[i])   continue;
    }
    return false;
}
bool operator < (hp_int a,hp_int b){//重载了小于,原理同上 
    if(a.op == '+' && b.op == '-')  return false;
    if(a.op == '-' && b.op == '+')  return true;
    if(a.len > b.len)               return false;
    if(a.len < b.len)               return true;
    if(a.op == '-' && b.op == '-')
    {
        for(int i = a.len;i >= 1;i --)
            if(a.num[i] > b.num[i])         return true;
            else if(a.num[i] < b.num[i])    return false;
            else if(a.num[i] == b.num[i])   continue;
    }
    if(a.op == '+' && b.op == '+')
    {
        for(int i = a.len;i >= 1;i --)
            if(a.num[i] > b.num[i])         return false;
            else if(a.num[i] < b.num[i])    return true;
            else if(a.num[i] == b.num[i])   continue;
    }
    return false;
}
bool operator ==(hp_int a,hp_int b){//重载了等于,原理同上 
    if(a.len == b.len)
    {
        for(int i = a.len;i >= 1;i --)
        {
            if(a.num[i] != b.num[i])    return false;
            else continue;
        }
        return true;
    }
    return false;
}
hp_int operator + (hp_int a,hp_int b){//求和 
    hp_int c;                             //c为所求的和 
    c.len = max(a.len,b.len);           //此处取最大是为了保证两个加数中的每一位都被算到 
    for(int i = 1;i <= c.len;i ++)      //先预处理得到未进位的答案 
        c.num[i] = a.num[i] + b.num[i]; 
    for(int i = 1;i <= c.len;i ++)      //以下为进位处理,注意从最低位开始扫描 
        if(c.num[i] >= 10)              //如果这位预处理得到的答案大于10则需要进位 
        {
            c.num[i + 1] += c.num[i] / 10;//进位,这就是为什么需要从最低位开始扫,这样可以保证一次性进位干净 
            c.num[i] %= 10;             //保留个位数 
            c.len = max(c.len,i + 1);   //注意:保留下来的长度要确保最高位有进位才需要更改，不然只需要留下两个加数中的最大长度就行 
        }
    return c;
}
hp_int operator - (hp_int a,hp_int b){//求差 
    hp_int c,temp;                        //c为所求的差,temp为交换的过程量 
    c.len = max(a.len,b.len);           //原理和加法一样，保证每一位都算过 
    if(b > a)                           //如果减数比被减数大需要特殊操作 
    {
        c.op = '-';                     //给答案上个负号 
        temp = a,a = b,b = temp;        //交换减数和被减数保证这时的答案大于等于0 
    }
    for(int i = 1;i <= c.len;i ++)      //预处理得到初始答案 
        c.num[i] = a.num[i] - b.num[i];
    for(int i = 1;i <= c.len;i ++)      //一下为借位处理,同样从最低位开始 
        if(c.num[i] < 0)                //如果预处理得到的这一位答案小于0 
        {
            c.num[i] += 10;             //借位 
            c.num[i + 1] -= 1;          //上一位减一 
        }
    return c;
}
hp_int operator * (hp_int a,hp_int b){//求积 
    hp_int c;                             //c为所求的积 
    c.len = a.len + b.len + 1;          //从小开始找一下规律会发现两数相乘会有以下规律
/*
                    a[3]        a[2]        a[1]
*                               b[2]        b[1]
--------------------------------------------------
                a[3]b[1]  a[2]*b[1]   a[1]*b[1] 
+   a[3]b[2]    a[2]b[2]  a[1]*b[2]
--------------------------------------------------
    c[4]          c[3]      c[2]        c[1]

###此时我们注意到一个数的第i位和另一个数的第j位相乘的到的数应该在答案的第i + j - 1位；
###而且不同于加减法的是此时的答案是通过二维枚举得到的需要用累加 
### 
*/ 
    for(int i = 1;i <= a.len;i++)       //每一位依次枚举 
        for(int j = 1;j <= b.len;j++)
            c.num[i + j - 1] += a.num[i]*b.num[j];//累加的意义如上所示 
    for (int i = 1;i <= c.len;i ++)     //和加法一样需要进位，要一次性进位干净 
    {
        if(c.num[i] >= 10)
        {
            c.num[i + 1] += c.num[i] / 10;//进位的值不难理解是当前位除以10以后向下取整 
            c.num[i] %= 10;             //保留各位 
            c.len = max(c.len,i + 1);   //意义和加法一样 
        }
    }
    return c;
}
hp_int numcopy(hp_int a,int l){//转移值的函数 
    hp_int b;
    for (int i=1;i<=a.len;i++) b.num[i+l-1]=a.num[i];
    b.len=a.len+l-1;
    b.op = '+';
    return b;
}
hp_int operator / (hp_int a,hp_int b){//求商 
    hp_int c;
    c.len = a.len - b.len + 1;
    for(int i = c.len;i >= 1;i --)
    {
        hp_int t = numcopy(b,i);          //将除数乘以10的(i - 1)次相当于在枚举商的位数 
        while(a > t || a == t)          //由于懒得写>= 的重载就只好这样不厌其烦了 
        {
            c.num[i]++;                 //商的这一位加一 
            if(a == t) 	 break;			//如果剩下的被除数已经可以被整除了就不用接着操作了        
            a = a - t;					//减去可以保存的值
			while (a.len>0 && !a.num[a.len]) a.len--;         
        }
    }
	while (c.len > 0 && !c.num[c.len]) c.len--;
    return c;
/*
###除法的概念相对比较抽象，需要花点时间去理解 
*/
}
hp_int operator % (hp_int a,hp_int b){//求余,大部分和除法概念一样,最后的返回值只需要返回多次减完剩下的a就行了 
    for(int i = a.len - b.len + 1;i >= 1;i --)
    {
        hp_int t = numcopy(b,i);
        while(a > t || a == t)
        {
            if(a == t)    break;
            a = a - t;
            while (a.len>0&&!a.num[a.len]) a.len--;         
        }
    }
    return a;
}
hp_int kkk(int b){//将一个整数类型转化为data类型，避免了重载很多不同类型间的运算符 
    int t = 0;
    hp_int c;
    while(b)
    { 
        t ++;                           //求位数 
        c.num[t] = b % 10;              //保留这一位的数 
        b /= 10;                        //删去这一位 
    }
    c.len = t;
    return c;
}
hp_int gcd(hp_int x,hp_int y){//递归求最大公约数 
    if(y == kkk(0)) return x;
    else return gcd(y,x % y);
}
//运算符重载 

void hp_get(hp_int &a){//将数据用字符串读入,并处理正负 
    string s1;
    cin >> s1;
    if(s1[0] == '-')    a.op = '-',s1.erase(0,1);
    for(int i = 1;i <= s1.size();i ++)
        a.num[i] = int(s1[s1.size() - i]) - '0';//注意要倒序储存数字 
    a.len = s1.size();
}
void hp_print(hp_int c){
    if(c.op == '-')printf("-");
    bool flag = false;
    for(int i = c.len;i >= 1;i --)
        if(c.num[i] != 0 || flag == true)
        {
            printf("%d",c.num[i]);
            flag = true;
        }
    if(flag == false)
        printf("0");
    printf("\n"); 
}


#endif
