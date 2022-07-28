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
    int num[20110];     //�˴���ΧҪ�������ݷ�Χ������,��Ϊ�˷�ʱλ���ᷭ�� 
    int len;
    char op;
    hp_int(){ memset(num,0,sizeof(num));  len = 1; op = '+';}
};//ע���֮ǰҪ���������λ����� 
int max(int a,int b){
    return (a > b) ? a : b;
}
bool operator > (hp_int a,hp_int b){//�����˴����жϷ�,�Է���Ϊ��һ�ؼ���,�Գ���Ϊ�ڶ��ؼ���,�Ծ���ֵΪ�����ؼ���,ע����� 
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
bool operator < (hp_int a,hp_int b){//������С��,ԭ��ͬ�� 
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
bool operator ==(hp_int a,hp_int b){//�����˵���,ԭ��ͬ�� 
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
hp_int operator + (hp_int a,hp_int b){//��� 
    hp_int c;                             //cΪ����ĺ� 
    c.len = max(a.len,b.len);           //�˴�ȡ�����Ϊ�˱�֤���������е�ÿһλ�����㵽 
    for(int i = 1;i <= c.len;i ++)      //��Ԥ����õ�δ��λ�Ĵ� 
        c.num[i] = a.num[i] + b.num[i]; 
    for(int i = 1;i <= c.len;i ++)      //����Ϊ��λ����,ע������λ��ʼɨ�� 
        if(c.num[i] >= 10)              //�����λԤ����õ��Ĵ𰸴���10����Ҫ��λ 
        {
            c.num[i + 1] += c.num[i] / 10;//��λ,�����Ϊʲô��Ҫ�����λ��ʼɨ,�������Ա�֤һ���Խ�λ�ɾ� 
            c.num[i] %= 10;             //������λ�� 
            c.len = max(c.len,i + 1);   //ע��:���������ĳ���Ҫȷ�����λ�н�λ����Ҫ���ģ���Ȼֻ��Ҫ�������������е���󳤶Ⱦ��� 
        }
    return c;
}
hp_int operator - (hp_int a,hp_int b){//��� 
    hp_int c,temp;                        //cΪ����Ĳ�,tempΪ�����Ĺ����� 
    c.len = max(a.len,b.len);           //ԭ��ͼӷ�һ������֤ÿһλ����� 
    if(b > a)                           //��������ȱ���������Ҫ������� 
    {
        c.op = '-';                     //�����ϸ����� 
        temp = a,a = b,b = temp;        //���������ͱ�������֤��ʱ�Ĵ𰸴��ڵ���0 
    }
    for(int i = 1;i <= c.len;i ++)      //Ԥ����õ���ʼ�� 
        c.num[i] = a.num[i] - b.num[i];
    for(int i = 1;i <= c.len;i ++)      //һ��Ϊ��λ����,ͬ�������λ��ʼ 
        if(c.num[i] < 0)                //���Ԥ����õ�����һλ��С��0 
        {
            c.num[i] += 10;             //��λ 
            c.num[i + 1] -= 1;          //��һλ��һ 
        }
    return c;
}
hp_int operator * (hp_int a,hp_int b){//��� 
    hp_int c;                             //cΪ����Ļ� 
    c.len = a.len + b.len + 1;          //��С��ʼ��һ�¹��ɻᷢ��������˻������¹���
/*
                    a[3]        a[2]        a[1]
*                               b[2]        b[1]
--------------------------------------------------
                a[3]b[1]  a[2]*b[1]   a[1]*b[1] 
+   a[3]b[2]    a[2]b[2]  a[1]*b[2]
--------------------------------------------------
    c[4]          c[3]      c[2]        c[1]

###��ʱ����ע�⵽һ�����ĵ�iλ����һ�����ĵ�jλ��˵ĵ�����Ӧ���ڴ𰸵ĵ�i + j - 1λ��
###���Ҳ�ͬ�ڼӼ������Ǵ�ʱ�Ĵ���ͨ����άö�ٵõ�����Ҫ���ۼ� 
### 
*/ 
    for(int i = 1;i <= a.len;i++)       //ÿһλ����ö�� 
        for(int j = 1;j <= b.len;j++)
            c.num[i + j - 1] += a.num[i]*b.num[j];//�ۼӵ�����������ʾ 
    for (int i = 1;i <= c.len;i ++)     //�ͼӷ�һ����Ҫ��λ��Ҫһ���Խ�λ�ɾ� 
    {
        if(c.num[i] >= 10)
        {
            c.num[i + 1] += c.num[i] / 10;//��λ��ֵ��������ǵ�ǰλ����10�Ժ�����ȡ�� 
            c.num[i] %= 10;             //������λ 
            c.len = max(c.len,i + 1);   //����ͼӷ�һ�� 
        }
    }
    return c;
}
hp_int numcopy(hp_int a,int l){//ת��ֵ�ĺ��� 
    hp_int b;
    for (int i=1;i<=a.len;i++) b.num[i+l-1]=a.num[i];
    b.len=a.len+l-1;
    b.op = '+';
    return b;
}
hp_int operator / (hp_int a,hp_int b){//���� 
    hp_int c;
    c.len = a.len - b.len + 1;
    for(int i = c.len;i >= 1;i --)
    {
        hp_int t = numcopy(b,i);          //����������10��(i - 1)���൱����ö���̵�λ�� 
        while(a > t || a == t)          //��������д>= �����ؾ�ֻ�����������䷳�� 
        {
            c.num[i]++;                 //�̵���һλ��һ 
            if(a == t) 	 break;			//���ʣ�µı������Ѿ����Ա������˾Ͳ��ý��Ų�����        
            a = a - t;					//��ȥ���Ա����ֵ
			while (a.len>0 && !a.num[a.len]) a.len--;         
        }
    }
	while (c.len > 0 && !c.num[c.len]) c.len--;
    return c;
/*
###�����ĸ�����ԱȽϳ�����Ҫ����ʱ��ȥ��� 
*/
}
hp_int operator % (hp_int a,hp_int b){//����,�󲿷ֺͳ�������һ��,���ķ���ֵֻ��Ҫ���ض�μ���ʣ�µ�a������ 
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
hp_int kkk(int b){//��һ����������ת��Ϊdata���ͣ����������غܶ಻ͬ���ͼ������� 
    int t = 0;
    hp_int c;
    while(b)
    { 
        t ++;                           //��λ�� 
        c.num[t] = b % 10;              //������һλ���� 
        b /= 10;                        //ɾȥ��һλ 
    }
    c.len = t;
    return c;
}
hp_int gcd(hp_int x,hp_int y){//�ݹ������Լ�� 
    if(y == kkk(0)) return x;
    else return gcd(y,x % y);
}
//��������� 

void hp_get(hp_int &a){//���������ַ�������,���������� 
    string s1;
    cin >> s1;
    if(s1[0] == '-')    a.op = '-',s1.erase(0,1);
    for(int i = 1;i <= s1.size();i ++)
        a.num[i] = int(s1[s1.size() - i]) - '0';//ע��Ҫ���򴢴����� 
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
