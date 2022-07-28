# `YIFANCORE`
——作者:YifanZhuZhu

## ** 更新: **
```
power函数采用了新的算法更快了
鸣谢:TakeOff0518
GitHub账号:https://github.com/Takeoff0518
```
### `注意事项`
```
.h用于c语言文件,.hpp用于c++文件
```

###### `功能:`
1. split函数:
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
计算一个数(n)拆分成整数后拆分的数量(k)(拆分后的整数个数不大于m)

2. power函数
即幂运算
函数本体:
```c
//C语言
long long power(int x,int y);
```
```cpp
//C++
long long power(int x,int y);
```
函数功能:
计算x的y次方

3. encryptstr函数和decryptstr函数
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

3.高精度整型 `hp_int`

声明一个高精度整型：

```cpp
hp_int a;
```
支持四则运算以及取模，用法：

```cpp
a+b;
a-b;
a*b;
a/b;
a%b;
```

输入函数：

```cpp
hp_get(a);
```

输出函数：

```cpp
hp_print(a);
```
##### `版本:1.1`
