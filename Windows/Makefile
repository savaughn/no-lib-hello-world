# Set the compiler and flags
CC = gcc
CFLAGS = -nostartfiles -nodefaultlibs -static -fno-stack-protector

# Define source and output files
SRC = main.c
OUT = main.exe
PREPROCESS_OUT = main.i

# Targets
all: $(OUT) $(PREPROCESS_OUT)

# Build the final executable
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)
	@echo "main.exe executable created"

# Build the preprocessed output '.i'
$(PREPROCESS_OUT): $(SRC)
	$(CC) -E $(CFLAGS) -o $(PREPROCESS_OUT) $(SRC)
	@echo "main.i preprocessed output created"

# Clean the generated files
clean:
	del /f $(OUT) $(PREPROCESS_OUT)

.PHONY: all clean
