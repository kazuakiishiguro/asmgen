#include "asmgen.h"
#include <stdarg.h>

/** Array of 64-bit registers */
const char* reg64[] = {
     "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi"
};

/** Size of the reg64 array */
size_t reg64_size = sizeof(reg64) / sizeof(char*);

/** Initialization function for NASM */
void init_nasm(void) {
     printf("; NASM ASM Code\n");
}

/** Define a register
 *
 * @param idx       Index of the register
 * @param bit       Bit size of the register
 * @param reg_table Table of register names
 * @param size      Size of the table
 */
void define_reg(int idx, int bit, const char **reg_table, size_t size) {
     if (idx < 0 || idx >= (int)size) {
	  fprintf(stderr, "Invalid register index: %d\n", idx);
	  exit(EXIT_FAILURE);
     }
     printf("Register: %s, Bit: %d\n", reg_table[idx], bit);
}

/** Emit an assembly instruction
 *
 * @param format Format string
 * @param ...    Arguments
 */
void emit_asm(const char *format, ...) {
     va_list args;
     va_start(args, format);
     vprintf(format, args);
     va_end(args);
     printf("\n");
}

/** Generate an ADD instruction */
void generate_add_instruction(void) {
     emit_asm("add %%rax, %%rbx");
}
