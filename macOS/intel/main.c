// Minimal "Hello, World!" program for macOS x86_64 without the standard library

void _start() {
    const char message[] = "Hello, World!\n";
    long size = sizeof(message) - 1;

    // Use syscall for write(1, message, size)
    asm(
        "mov $0x2000004, %%rax;"    // syscall number for write
        "mov $1, %%rdi;"            // file descriptor (1 for stdout)
        "mov %0, %%rsi;"            // pointer to the message
        "mov %1, %%rdx;"            // size of the message
        "syscall;"                  // invoke the syscall
        :
        : "r"(message), "r"(size)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );


    // Exit syscall (exit(0))
    asm(
        "mov $0x2000001, %%rax;" // syscall number for exit
        "xor %%rdi, %%rdi;"      // exit code (0 for success)
        "syscall;"               // invoke syscall
    );
}
