#include<iostream>
#include "yifancore.hpp"
using namespace std;
bigInt a,b;
int main(){
    bi_get(a); bi_get(b);
    bi_print(a+b);
    return 0;
}