#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define OPC(i) ((i)>>12)
#define DR(i) (((i)>>9)&0x7)
#define SR1(i) (((i)>>6)&0x7)
#define SR2(i) ((i)&0x7)
#define FIMM(i) ((i>>5)&01)
#define IMM(i) ((i)&0x1F)
#define SEXTIMM(i) sext(IMM(i),5)
#define FCND(i) (((i)>>9)&0x7)
#define POFF(i) sext((i)&0x3F, 6)
#define POFF9(i) sext((i)&0x1FF, 9)
#define POFF11(i) sext((i)&0x7FF, 11)
#define FL(i) (((i)>>11)&1)
#define BR(i) (((i)>>6)&0x7)
#define TRP(i) ((i)&0xFF)

uint16_t PC_START = 0x3000;
uint16_t mem[UINT16_MAX+1] = {0};
static inline uint16_t iotamr(uint16_t address) { return mem[address]; }
static inline void iotamw(uint16_t address, uint_16 val) { mem[address] = val; }

enum regist { R0 = 0; R1, R2, R3, R4, R5, R6, R7, RPC, RCND, RCNT, };
uint16_t reg[RCNT] = {0};

typedef void (*op_ex_f)(uint16_t instruction);
//
// ... other operations here
//
static inline void add(uint16_t i)  { /* code here */ }
static inline void and(uint16_t i)  { /* code here */ }
//
// ... other operations here
//
op_ex_f op_ex[NOPS] = { 
    br, add, ld, st, jsr, and, ldr, str, rti, not, ldi, sti, jmp, res, lea, trap 
};
