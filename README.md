# `YIFANCORE`
——作者:YifanZhuZhu

## ** 更新: **
```
power函数采用了新的算法更快了
鸣谢:TakeOff0518
```
### `注意事项`
```
.h用于c语言文件,.hpp用于c++文件
```

###### `功能:`
1.`split` 函数:
即整数拆分
函数本体:
```c
//C语言
int split(int n,int m);
```
```cpp
//C++
int split(int n,int m);
```
函数功能:
计算一个数 `n` 拆分成整数后拆分的数量 `k` (拆分后的整数个数不大于 `m`)

2.`power` 函数

即幂运算
函数本体:
函数功能:
计算x的y次方

3.`encryptstr`函数和 `decryptstr` 函数
即字串符加密与解密
函数本体:
```c
//C语言
char* encryptstr(char* str);
char* decryptstr(char* str);
```
```cpp
//C++
char* encryptstr(char* str);
char* decryptstr(char* str);
```
函数功能:
简易的加解密

4.高精度整型 `hp_int`（Only featured in C++）

声明一个高精度整型：

```cpp
//C++
bigInt a;
```

四则运算以及取模：

```cpp
//C++
a+b;
a-b;
a*b;
a/b;
a%b;
```

最大公约数:

```cpp
//C++
bi_gcd(a,b);
```


输入函数：

```cpp
bi_get(a);
```

输出函数：

```cpp
bi_print(a);
```

##### `版本:1.1`
