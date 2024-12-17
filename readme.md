# Minimal "Hello, World!" Without the Standard Library

This project demonstrates how to write minimal "Hello, World!" programs on various operating systems without relying on the C standard library. By using direct system calls or native OS functions, the program is kept as lightweight as possible, avoiding external dependencies. This is a fun exploration of low-level programming and how different OSes handle basic output operations.

## Operating Systems Covered

- **Linux (amd64)**: The Linux, 64-bit amd, version uses direct syscalls (`write()` and `exit()`) to interact with the system and print a message to the terminal.
- **Linux (arm)**: The Linux, 32-bit arm, version uses direct syscalls (`write()` and `exit()`) to interact with the system and print a message to the terminal.
- **Linux (arm64)**: The Linux, 64-bit arm, version uses direct syscalls (`write()` and `exit()`) to interact with the system and print a message to the terminal.
- **Windows (x86_64)**: The Windows, 64-bit, version uses native Windows API functions (`WriteFile` and `ExitProcess`) to achieve the same result without linking to the C runtime library.
- **macOS (arm64)**: The macOS, ARM 64-bit version uses direct syscalls (`write()` and `exit()`) to interact with the system and print a message to the terminal. It utilizes ARM64-specific syscall conventions with `svc` for invoking system calls.
- **macOS (x86_64)**: The macOS, 64-bit Intel version uses direct syscalls (`write()` and `exit()`) to interact with the system and print a message to the terminal. It uses the `syscall` instruction to trigger system calls and follows x86_64 conventions.

Each implementation demonstrates the use of system-specific mechanisms for output, avoiding standard libraries such as `glibc` on Linux or `MSVCRT` on Windows.

## Features

- Minimalistic approach — no standard library, just the OS-specific system calls or APIs.
- Platform-specific implementations for **Linux**, **Windows**, and **macOS**.
- Clear explanation of each step and the underlying system calls or functions used.

## Prerequisites

- A C compiler (e.g., GCC for Linux and MinGW for Windows).
- A **Linux**, **Windows**, or **macOS** environment to build and run the programs.
- Cross-compiling is not supported here. I assume that you are running this example on the intended target hardware.

## Explanations

Refer to each specific OSes' readme file for explanation and build commands. For ease of use, each system contains a Makefile.

## Acknowledgments

This project was generated with ChatGPT with human intervention. :thumbsup:
