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
