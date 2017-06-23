GBDK_DIR = C:/gbdk_n/gbdk-n
BIN = $(GBK_DIR)/bin
OBJ = ./obj

build:
	mkdir -p $(OBJ)
	sdcc -mgbz80 --no-std-crt0 -I $(GBDK_DIR)/include -I $(GBDK_DIR)/include/asm -c gb_tests.c -o $(OBJ)/gb_tests.rel
	sdcc -mgbz80 --no-std-crt0 -I $(GBDK_DIR)/include -I $(GBDK_DIR)/include/asm -c Print.c -o $(OBJ)/Print.rel
	sdcc -mgbz80 --no-std-crt0 -I $(GBDK_DIR)/include -I $(GBDK_DIR)/include/asm -c font.c -o $(OBJ)/font.rel
	sdcc -mgbz80 --no-std-crt0 --data-loc 0xc0a0 -L $(GBDK_DIR)/lib $(GBDK_DIR)/lib/crt0.rel gb.lib -o a.ihx $(OBJ)/gb_tests.rel $(OBJ)/Print.rel $(OBJ)/font.rel -o $(OBJ)/gb_tests.ihx
	makebin -Z $(OBJ)/gb_tests.ihx gb_tests.gb

clean:
	rm -rf $(OBJ)
	rm -f *.gb
