# Minimal "Hello, World!" on ARM32 Linux Without the Standard Library

This repository demonstrates how to write a minimal **"Hello, World!"** program in **C** on **32-bit ARM Linux** without relying on the C standard library. We will use **syscalls** directly to perform output to the terminal.

## Why Avoid Standard Libraries?

In typical Linux applications, we use libraries like **glibc** to perform standard operations, such as writing to the console. 

This repository will show how to use syscalls directly to perform a task that is commonly done by the standard library — in this case, printing a message to the screen.

## Prerequisites

- **GCC** (GNU Compiler Collection) or any C compiler.
- An **32-bit ARM Linux** environment, either physical or virtual.

## The Program

We'll create a program that prints **"Hello, World!"** to the terminal using the **`write()`** syscall. 

The `write()` syscall is used to output data to a file descriptor, in this case, `STDOUT` (file descriptor `1`).

### Step 1: Creating the C Program

The **C** program, [main.c](./main.c), that writes the message to the terminal using a direct syscall.

### Step 2: Explanation of the Code

- **`const char message[] = "Hello, World!\n";`**: Defines the message to be printed.
- **`long size = sizeof(message) - 1;`**: Calculates the length of the message (excluding the null-terminator).
- **First Syscall (Write)**: The assembly code that follows the `asm` block makes the `write()` system call:
  - `mov r0, #1` sets the file descriptor to `1`, which corresponds to standard output (`stdout`).
  - `ldr r1, =message` loads the pointer to the message into register `r1`.
  - `mov r2, size` moves the message size into register `r2`.
  - `mov r7, #4` sets the syscall number for `write()` (syscall number 4 for ARM).
  - `svc #0` triggers the syscall.
- **Second Syscall (Exit)**: The second `asm` block makes the `exit()` system call:
  - `mov r0, #0` sets the exit code to `0`.
  - `mov r7, #1` sets the syscall number for `exit()` (syscall number 1 for ARM).
  - `svc #0` triggers the syscall.

### Step 3: Compile and Run the Program

To compile and run the program, use the following steps in the terminal:

```bash
gcc -nostartfiles -nodefaultlibs -static -fno-stack-protector -o main main.c
./main
```

Explanation of flags used:
- `-nostartfiles`: Prevents GCC from linking the standard startup files (`crt0`, etc.) which would otherwise add additional dependencies like `glibc`.
- `-nodefaultlibs`: Tells the linker not to link the default libraries (such as `libc`).
- `-static`: Statically links the program to avoid any dynamic linking.
- `-fno-stack-protector`: Disables stack protection to avoid issues when dealing with low-level code.

You should see the output:

```
Hello, World!
```

## The Preprocessed `.i` File

The `.i` file is the output of the **preprocessing stage** of the C compilation process. It contains the result after **macros** have been expanded, **include files** have been processed, and conditional compilation has been resolved.

### Generating the `.i` File

In our Makefile, we use the following command to generate the `.i` file:

```bash
gcc -E -nostartfiles -nodefaultlibs -static -fno-stack-protector -o main.i main.c
```

This command tells GCC to run the preprocessor step (using the `-E` flag) and output the result into a file called `main.i`. The contents of `main.i` will show all the preprocessing done to the original source file.

### Contents of the `.i` File

In our case, the `.i` file will show:

- The source code after all `#include` directives are processed.
- All macros expanded, such as those from `#define` and `#ifdef`.
- Any conditional compilation branches resolved.

This can be useful for debugging or understanding how GCC interprets and processes your source code before it moves on to the actual compilation and assembly steps.

## Conclusion

In this repository, you learned how to write a minimal "Hello, World!" program on ARM32 Linux using direct syscalls instead of relying on the standard C library.

This readme has been generated by ChatGPT with human intervention. :thumbsup:
