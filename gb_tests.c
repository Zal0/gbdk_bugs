#include <stdio.h>
#include <gb/font.h>
#include <gb/console.h>
#include <gb/drawing.h>

INT16 DespRight(INT16 a, INT8 b) {
	return a >> b;
}

#define NEG(A) (0xFFFF - A + 1)

void Test0()  {
//unary minus operator doesnt' work, and crashes when trying to print its value
	INT16 n   = 131;
	INT16 tmp = -n;
	
	//Printing -n crashes
	//printf("%d neg: %d ", n, tmp);
	
	//Workaround
	printf("%d neg: %d\n", n, NEG(n));
}


void Test1(UINT16 v0, INT8 v1) {
//extra cast required for adding UINT16 and negative INT8
	printf("%d ", v0 + v1); //it seems to be casting v1 to UINT16 instead of INT16
	printf("expetecd %d \n", v0 + (INT16)v1);
}

void Test2() {
//>> doesn't work with variables (it crashes or prints random values)
//It seems to work fine with consts
	UINT16 v16 = 50;
	UINT16 n = 2;
	
	//printf("%d\n", v16 >> n); //This crashes
	printf("%d \n", DespRight(v16, n));
}

struct StructTest {
	UINT8 v8;
};

void Test3_fix(UINT8 v8_0) {
	struct StructTest test = {0};
	printf("%d ", (UINT16)(v8_0 == test.v8));
	printf("%d\n", ((UINT16)v8_0 == (UINT16)test.v8));
}

void Test3(UINT8 v8_0) {
//operator == with UINT8 from struct and other UINT8
	struct StructTest test = {0};

	printf("%d ", (UINT16)(test.v8 == v8_0));
	Test3_fix(v8_0); //If I do the fix here then the previous printf gets fixed too...
}


void main(void) {	
	mode(get_mode() | M_NO_SCROLL);

	Test0();
	Test1(100, -50);
	Test2();
	Test3(5);
}

    
    
