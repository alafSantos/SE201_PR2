PREFIX := riscv64-unknown-elf-
SYSGCC := $(CC)
CC := $(PREFIX)gcc
OBJDUMP := $(PREFIX)objdump

CFLAGS:=-O -g -fno-pic -fno-inline -mcmodel=medlow -mabi=ilp32 -march=rv32im -Wall -static -nostdinc -nostartfiles -nodefaultlibs -nostdlib

.PHONY: all clean

all: insertion-sort.elf

insertion-sort.elf: insertion-sort.c
	$(CC) $(CFLAGS) -o $@ $<

insertion-sort-counters.elf: insertion-sort-counters.c
	$(SYSGCC) -o $@ $<

clean:
	rm -f insertion-sort.elf
