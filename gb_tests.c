#include "font.h"
#include "Print.h"

void InitScrollTiles/*Color*/(UINT8 first_tile, UINT8 n_tiles, UINT8* tile_data, UINT8 tile_bank/*, UINT8* palette_entries*/) {
	//UINT8 i;
	//
	//PUSH_BANK(tile_bank);
	set_bkg_data(first_tile, n_tiles, tile_data);
	//for(i = first_tile; i < first_tile + n_tiles; ++i) {
	//	scroll_tile_info[i] = palette_entries ? palette_entries[i] : 0;
	//}
	//POP_BANK;
}


INT16 DespRight(INT16 a, INT8 b) {
	return a >> b;
}

#define NEG(A) (0xFFFF - A + 1)

void Test0()  {
//unary minus operator doesnt' work, and crashes when trying to print its value
	INT16 n   = 131;
	INT16 tmp = -n;
	
	//Printing -n crashes
	Printf("%d neg: %d ", n, tmp);
	
	//Workaround
	Printf("%d neg: %d\n", n, NEG(n));
}


void Test1(UINT16 v0, INT8 v1) {
//extra cast required for adding UINT16 and negative INT8
	Printf("%d ", v0 + v1); //it seems to be casting v1 to UINT16 instead of INT16
	Printf("expetecd %d \n", v0 + (INT16)v1);
}

void Test2() {
//>> doesn't work with variables (it crashes or prints random values)
//It seems to work fine with consts
	UINT16 v16 = 50;
	UINT16 n = 2;
	
	//Printf("%d\n", v16 >> n); //This crashes
	Printf("%d \n", DespRight(v16, n));
}

struct StructTest {
	UINT8 v8;
};

void Test3_fix(UINT8 v8_0) {
	struct StructTest test = {0};
	Printf("%d ", (UINT16)(v8_0 == test.v8));
	Printf("%d\n", ((UINT16)v8_0 == (UINT16)test.v8));
}

void Test3(UINT8 v8_0) {
//operator == with UINT8 from struct and other UINT8
	struct StructTest test = {0};

	Printf("%d ", (UINT16)(test.v8 == v8_0));
	Test3_fix(v8_0); //If I do the fix here then the previous Printf gets fixed too...
}

UINT16 n = 0;
void main(void) {	
	disable_interrupts();
	DISPLAY_OFF;
	LCDC_REG = 0x67;
	
	BGP_REG = OBP0_REG = OBP1_REG = 0xE4U;

	SWITCH_ROM_MBC1(2);
	INIT_CONSOLE(font, 1, 18);
	
	DISPLAY_ON;
	enable_interrupts();

	Printf("Hello World\n");

	Test0();
	//Test1(100, -50);
	//Test2();
	//Test3(5);
	while(1) {
		wait_vbl_done();
	}
}

    
    