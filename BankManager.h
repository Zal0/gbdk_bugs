#ifndef BANK_MANAGER_H
#define BANK_MANAGER_H

//#include "Stack.h"

#define N_PUSH_BANKS 10

extern UINT8 bank_stack[];

void PushBank(UINT8 b);
void PopBank();

//#define PUSH_BANK(N) PushBank(N);
//#define POP_BANK PopBank();
//#define REFRESH_BANK SWITCH_ROM_MBC1(StackPeek(bank_stack))

#define PUSH_BANK(N)
#define POP_BANK
#define REFRESH_BANK

#endif