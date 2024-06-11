#include "asmgen.h"

int main(void) {
     init_nasm();

     define_reg(RAX, 64, reg64, reg64_size);
     define_reg(RBX, 64, reg64, reg64_size);

     generate_add_instruction();

     return 0;
}
