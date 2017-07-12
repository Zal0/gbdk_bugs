GBDK_DIR = C:/gbdk_n/gbdk-n
LCC = C:/gbdk/bin/lcc
BIN = $(GBK_DIR)/bin
OBJ = ./obj

CFLAGS = -mgbz80 --no-std-crt0 --fsigned-char -I $(GBDK_DIR)/include -I $(GBDK_DIR)/include/asm



all: clean build

build:
	mkdir -p $(OBJ)
	sdcc $(CFLAGS) -c gb_tests.c -o $(OBJ)/gb_tests.rel
	sdcc $(CFLAGS) -c Print.c -o $(OBJ)/Print.rel
	sdcc $(CFLAGS) -c bank1.c -o $(OBJ)/bank1.rel
	sdcc $(CFLAGS) -c font.c -o $(OBJ)/font.rel
	sdcc -mgbz80 --no-std-crt0 --data-loc 0xc0a0 -Wl-b_CODE_1=0x4000 -wl-b_CODE_2=0x4000 $(GBDK_DIR)/lib/crt0.rel $(GBDK_DIR)/lib/gb.lib $(OBJ)/gb_tests.rel $(OBJ)/Print.rel $(OBJ)/font.rel $(OBJ)/bank1.rel -o $(OBJ)/gb_tests.ihx
	makebin -Z -yo 4 -yt 1 -s 65536 $(OBJ)/gb_tests.ihx gb_tests.gb
	
#$(LCC) -Wl-yt1 -Wl-yo4 -o gb_testsLCC.gb $(OBJ)/gb_tests.rel $(OBJ)/Print.rel $(OBJ)/font.rel div.o mul.o

#sdcc -mgbz80 --no-std-crt0 --data-loc 0xc0a0 -Wl-b_CODE_2=0x8000 $(GBDK_DIR)/lib/crt0.rel $(GBDK_DIR)/lib/gb.lib $(OBJ)/gb_tests.rel $(OBJ)/Print.rel $(OBJ)/font.rel -o $(OBJ)/gb_tests.ihx
#	c:\gbdk\bin\link-gbz80 -- -z -yt1 -yo4 gb_tests.gb obj/gb_tests.ihx
#	makebin -Z $(OBJ)/gb_tests.ihx gb_tests.gb

clean:
	rm -rf $(OBJ)
	rm -f *.gb
