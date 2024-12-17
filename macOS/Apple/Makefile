# Set the compiler and flags
CC = gcc
CFLAGS = -nostartfiles -nodefaultlibs -static -fno-stack-protector

# Define source and output files
SRC = main.c
OUT = main
PREPROCESS_OUT = main.i

# Targets
all: $(OUT) $(PREPROCESS_OUT)

# Build the final executable
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -e __start -o $(OUT) $(SRC)
	@echo "main executable created"

# Build the preprocessed output '.i'
$(PREPROCESS_OUT): $(SRC)
	$(CC) -E $(CFLAGS) -e __start -o $(PREPROCESS_OUT) $(SRC)
	@echo "main preprocessed output created"

# Clean the generated files
clean:
	rm -f $(OUT) $(PREPROCESS_OUT)

.PHONY: all clean
