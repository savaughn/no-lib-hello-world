// Minimal "Hello, World!" program for macOS ARM without the standard library

void _start() {
    const char message[] = "Hello, World!\n";
    long size = sizeof(message) - 1;

    // Use syscall for write(1, message, size)
    asm(
        "mov x0, 1;"         // file descriptor (1 for stdout)
        "ldr x1, =message;"  // pointer to the message
        "mov x2, %0;"        // size of the message
        "mov x8, 0x2000004;" // syscall number for write
        "svc 0;"              // invoke syscall
        :
        : "r"(size)
        : "x0", "x1", "x2", "x8"
    );


    // Exit syscall (exit(0))
    asm(
        "mov x0, 0;"         // exit code (0 for success)
        "mov x8, 0x2000001;" // syscall number for exit
        "svc 0;"              // invoke syscall
    );

}
