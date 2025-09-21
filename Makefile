CROSS = aarch64-none-elf-
CC = $(CROSS)gcc
LD = $(CROSS)ld
OBJCOPY = $(CROSS)objcopy

CFLAGS = -Wall -O2 -ffreestanding -nostdlib -nostartfiles -mgeneral-regs-only
LDFLAGS = -T linker.ld -nostdlib

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC)) build/boot.o
TARGET = build/kernel/chrix_asm.elf

all: $(TARGET)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

build/boot.o: boot.S
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ) linker.ld
	$(LD) $(LDFLAGS) -o $@ $(OBJ)

clean:
	rm -rf build

run: $(TARGET)
	qemu-system-aarch64 -M virt -cpu cortex-a53 -nographic -kernel $(TARGET)

