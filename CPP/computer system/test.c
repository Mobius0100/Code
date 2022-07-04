#include<stdio.h>
#include<stdlib.h>
int bang(int x) {
  return ((x | (x + 0x7fffffff)) >> 31) + 1;
}

int divpwr2(int x, int n) {
    //负数以补码形式存储，最高位为符号位。补码等于反码+1
    int bias = (x>>31)&0xF;
    printf("%x",x+bias);
    return (x+bias) >> n;
}

int negate(int x) {
  return (~x + 1);
}

int isPositive(int x) {
  return (x >> 31) & 1;
}

int bitCount(int x) {
  int val;
  //制作mask: 0001 0001 0001 0001 0001 0001 0001 0001
  int tmp = 1;
  tmp |= tmp << 4;
  tmp |= tmp << 8;
  tmp |= tmp << 16;
  //计算每个byte里1的数量
  val = (tmp & x) + (tmp & (x>>1))
  + (tmp & (x>>2)) + (tmp & (x>>3));
  //折叠两次，1的数量保存在低4位中
  val += val >> 16;  
  val += val >> 8;
  val += val >> 4;
  return val & 0xf;
}

int main(){
    printf("%d\n", bitCount(2191));

    return 0;
}