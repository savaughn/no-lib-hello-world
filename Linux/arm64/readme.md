# Minimal "Hello, World!" on ARM Linux Without the Standard Library

This project demonstrates how to write a minimal **"Hello, World!"** program in **C** on **ARM Linux** without relying on the C standard library. It uses **syscalls** directly to perform output to the terminal and exit the program.

## Why Avoid Standard Libraries?

In typical ARM Linux applications, we use libraries like **glibc** to perform standard operations, such as writing to the console. This repository shows how to use syscalls directly, bypassing standard libraries, which results in a smaller and more self-contained program.

## Prerequisites

- **GCC** (GNU Compiler Collection) for ARM architecture.
- An **ARM Linux** environment (either physical or virtual).
- Basic knowledge of Linux system calls.

## The Program

The program prints **"Hello, World!"** to the terminal using the **`write()`** syscall and then exits with a return code of 0 using the **`exit()`** syscall. 

### Step 1: Creating the C Program

The C program, [main.c](./main.c), writes the message to the terminal using direct syscalls.

### Step 2: Explanation of the Code

- **`const char message[] = "Hello, World!\n";`**: Defines the message to be printed.
- **`long size = sizeof(message) - 1;`**: Calculates the length of the message (excluding the null-terminator).
- **First Syscall (Write)**: The `syscall` function is used to directly call the `write()` syscall with:
  - `SYS_write`: The syscall number for `write()`.
  - `STDOUT_FILENO`: The file descriptor for standard output (1).
  - The message and its length.
- **Second Syscall (Exit)**: The `syscall` function is also used to directly call the `exit()` syscall:
  - `SYS_exit`: The syscall number for `exit()`.
  - `0`: The exit code indicating success.

### Step 3: Compile and Run the Program

To compile and run the program on ARM Linux, follow these steps:

```bash
gcc -nostartfiles -nodefaultlibs -static -fno-stack-protector -o main main.c
./main
```

Explanation of flags used:
- `-nostartfiles`: Prevents GCC from linking standard startup files (`crt0`), which would bring in additional dependencies like `glibc`.
- `-nodefaultlibs`: Tells the linker not to link default libraries such as `libc`.
- `-static`: Statically links the program to avoid dynamic dependencies.
- `-fno-stack-protector`: Disables stack protection to prevent issues with low-level code.

You should see the output:

```
Hello, World!
```

## The Preprocessed `.i` File

The `.i` file is the result of the **preprocessing stage** of the C compilation process. It contains the expanded source code, after macros have been expanded, include files have been processed, and conditional compilation has been resolved.

### Generating the `.i` File

You can generate the `.i` file using the following command:

```bash
gcc -E -nostartfiles -nodefaultlibs -static -fno-stack-protector -o main.i main.c
```

This will run the preprocessor (`gcc -E`) and output the result into the file `main.i`.

### Contents of the `.i` File

In our case, the `.i` file will show:
- The processed source code after all `#include` directives are handled.
- All macros expanded, such as those from `#define` and `#ifdef`.
- Any conditional compilation branches resolved.

This file can help you understand how GCC interprets and processes your source code before it is compiled and assembled.

## Conclusion

In this project, you learned how to write a minimal "Hello, World!" program on **ARM Linux** using direct syscalls, bypassing the C standard library.

This README has been generated with the help of ChatGPT. :thumbsup:
