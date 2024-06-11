#ifndef ASMGEN_H
#define ASMGEN_H

#include <stdio.h>
#include <stdlib.h>

#define RAX 0
#define RCX 1
#define RDX 2
#define RBX 3
#define RSP 4
#define RBP 5
#define RSI 6
#define RDI 7
#define R8  8
#define R9  9

/** Enum for operand types */
typedef enum {
     REG,  // Register
     FPU,  // Floating Point Unit
     SSE,  // Streaming SIMD Extentions
     XMM,  // Streaming SIMD Extentions
     YMM,  // Streaming SIMD Extentions
     ZMM,  // Streaming SIMD Extentions
     MASK, // Mask Register
     ATTR, // Attribute Register
     MMX,  // MultiMedia Extentions
} OperandType;

/** Operand struct */
typedef struct {
     int idx;          // Index of the operand
     int bit;          // Bit size of the operand
     OperandType kind; // Type of the operand
     int attr;         // Attribute of the operand
} Operand;

/** Declaration of the reg64 array */
extern const char* reg64[];
extern size_t reg64_size;

////////////////////////////////////////
/// Functions
////////////////////////////////////////
void init_nasm(void);
void define_reg(int idx, int bit, const char **reg_table, size_t size);
void emit_asm(const char *format, ...);
void generate_add_instruction(void);

#endif // ASMGEN_H
