# Minimal "Hello, World!" on Windows Without the Standard Library

This repository demonstrates how to write a minimal **"Hello, World!"** program in **C** on **Windows** without relying on the standard C library. The program directly uses the **Windows API** to write to the console.

## Why Avoid Standard Libraries?

In typical Windows applications, we rely on standard libraries like **MSVCRT** for basic operations, such as printing output. This repository shows how to use the **Windows API** directly to print a message to the console without involving external dependencies like `stdio.h`.

## Prerequisites

- **Microsoft Visual Studio** or **MinGW** installed on your system.
- A **Windows** environment to compile and run the code.

## The Program

The program below writes **"Hello, World!"** to the console using the Windows **`WriteFile`** function from the Windows API. It avoids using the standard C library entirely.

### Step 1: Creating the C Program

Here is the minimal program, written in **C**, that writes the message to the console:

```c
#include <windows.h>

int main() {
    const char message[] = "Hello, World!\n";
    DWORD bytesWritten;

    // Get the handle for standard output (stdout)
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // Write the message to stdout using WriteFile
    WriteFile(hStdOut, message, sizeof(message) - 1, &bytesWritten, NULL);

    // Exit the process with code 0
    ExitProcess(0);
}
```

### Step 2: Explanation of the Code

- **`const char message[] = "Hello, World!\n";`**: Defines the message to be printed to the console.
- **`HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);`**: Retrieves the handle to the standard output (stdout) stream.
- **`WriteFile(hStdOut, message, sizeof(message) - 1, &bytesWritten, NULL);`**: Writes the message to stdout. The `WriteFile` function writes data to the output stream, where:
  - `hStdOut`: The handle to the standard output.
  - `message`: The message to be printed.
  - `sizeof(message) - 1`: The length of the message excluding the null terminator.
  - `&bytesWritten`: Receives the number of bytes written.
  - `NULL`: Reserved parameter (not needed in this case).
- **`ExitProcess(0);`**: Exits the process with exit code `0`, indicating successful completion.

### Step 3: Compile and Run the Program

To compile and run the program on Windows, you can use **MinGW** or **Microsoft Visual Studio**. Here is how to do it using **MinGW**:

1. **Install MinGW** (if you haven't already) by following the installation instructions from [MinGW's website](http://www.mingw.org/).
2. **Open the command prompt** and navigate to the directory where your `main.c` file is located.

Then, run the following command to compile the program with the necessary flags:

\```bash
gcc -nostartfiles -nodefaultlibs -static -fno-stack-protector -o main.exe main.c
\```

After compilation, run the program:

\```bash
main.exe
\```

This will execute the program, and you should see **"Hello, World!"** printed to the console.

### Step 4: Explanation of the Compilation Command CFLAGS

- **`-nostartfiles`**: Tells GCC to avoid linking the default startup files (`crt0.o`), which would otherwise include standard C library functions.
- **`-nodefaultlibs`**: Prevents GCC from linking the default libraries, including the C standard library (`libc`).
- **`-static`**: Statically links the program, avoiding any dynamic linking.
- **`-fno-stack-protector`**: Disables stack protection to prevent conflicts when working with low-level code.

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

## Conclusion

In this repository, you learned how to write a minimal **"Hello, World!"** program on Windows using the **Windows API** directly, without relying on the standard C library. This approach is useful for low-level applications and embedded systems where you need to minimize external dependencies.

This readme has been generated by ChatGPT with human intervention. :thumbsup:
