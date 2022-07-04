#include <stdio.h>
int TMax=0x7FFFFFFF;
int TMin=0x80000000;

typedef unsigned char *byte_pointer;
// 显示机器字节
void show_bytes(byte_pointer start, int len){
	int i;
	for(i=0; i<len; i++){
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x, sizeof(void *));
}

//测试字节
void test_show_bytes(int val){
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;

	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

// 判断机器是小端法还是大端法
int is_little_endian(){
	int val = 0x87654321;
	int i;
	byte_pointer valp = (byte_pointer) &val;
	if(valp[0] != 0x21) return 0;
	else return 1;
}

//判断x+y是否溢出
int uadd_ok(unsigned x, unsigned y){
	unsigned s = x+y;

	if(s < x || s < y) return 1;
	else return 0;
}

// 正溢出和负溢出的处理
int saturating_add(int x, int y){
	int sum = x+y;
	if(x > 0 && y > 0 && sum < 0) return TMax;
	if(x < 0 && y < 0 && sum > 0) return TMin;
	
	return sum;
}
int main(){
	int val = 0x87654321;
	byte_pointer valp = (byte_pointer) &val;
	// show_bytes(valp, 1);
	// show_bytes(valp, 2);
	// show_bytes(valp, 3);
	show_bytes(valp, sizeof(val));
	printf("%d", TMax + TMax + 3);
	printf("\n");
	
	return 0;
}