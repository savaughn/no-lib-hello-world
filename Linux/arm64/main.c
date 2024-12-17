// Hello, World in C with no external dependencies for ARM64 Linux

void _start() {
    const char message[] = "Hello, world!\n";
    long size = sizeof(message) - 1;

    // Use syscall for write(1, message, size)
    asm volatile (
        "mov r0, #1;"           // File descriptor 1 (stdout)
        "ldr r1, =message;"     // Load the address of the message
        "mov r2, %0;"           // Move the size of the message to r2
        "mov r7, #4;"           // Syscall number for sys_write (4)
        "svc #0;"               // Make the syscall
        : : "r"(size)           // Input: message size
        : "r0", "r1", "r2", "r7" // Clobbered registers
    );

    // Exit syscall (exit(0))
    asm volatile (
        "mov r0, #0;"           // Exit status 0
        "mov r7, #1;"           // Syscall number for sys_exit (1)
        "svc #0;"               // Make the syscall
    );
}
