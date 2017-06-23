GBDK_DIR = C:/gbdk_n/gbdk-n
LCC = C:/gbdk/bin/lcc
BIN = $(GBK_DIR)/bin
OBJ = ./obj

CFLAGS = -mgbz80 --no-std-crt0 -I $(GBDK_DIR)/include -I $(GBDK_DIR)/include/asm



all: clean build

build:
	mkdir -p $(OBJ)
	sdcc $(CFLAGS) -c gb_tests.c -o $(OBJ)/gb_tests.rel
	sdcc $(CFLAGS) -c Print.c -o $(OBJ)/Print.rel
	sdcc $(CFLAGS) -c --constseg CODE_2 font.c -o $(OBJ)/font.rel
	$(LCC) -Wl-yt1 -Wl-yo4 -o gb_testsLCC.gb $(OBJ)/gb_tests.rel $(OBJ)/Print.rel $(OBJ)/font.rel


clean:
	rm -rf $(OBJ)
	rm -f *.gb
