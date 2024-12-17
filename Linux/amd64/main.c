// Hello, World in C with no external dependencies

void _start() {
    const char message[] = "Hello, world!\n";
    long size = sizeof(message) - 1;

    // Use syscall for write(1, message, size)
    asm(
        "mov $1, %%rax;"       // syscall number (1 for write)
        "mov $1, %%rdi;"       // file descriptor (1 for stdout)
        "mov %0, %%rsi;"       // pointer to the message
        "mov %1, %%rdx;"       // size of the message
        "syscall;"             // invoke the syscall
        :
        : "r"(message), "r"(size)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );

    // Exit syscall (exit(0))
    asm(
        "mov $60, %%rax;"      // syscall number (60 for exit)
        "xor %%rdi, %%rdi;"    // exit code (0 for success)
        "syscall;"             // invoke the syscall
        :
        :
        : "%rax", "%rdi"
    );
}

// gcc -nostartfiles -nodefaultlibs -static -fno-stack-protector -o main main.c
