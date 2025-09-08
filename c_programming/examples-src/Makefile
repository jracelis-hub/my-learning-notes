# Variables

CC=gcc
WFLAGS=-Wall
DEBUG=-g

GDB=gdb

BUILD_DIR=./build/

SRC?=
EXE:=$(addprefix $(BUILD_DIR),$(basename $(SRC)))

.PHONY: run clean gdb

run: $(EXE)
	$(EXE)

gdb: $(EXE)
	$(GDB) $(EXE)

$(EXE): $(SRC) | $(BUILD_DIR)
	$(CC) $(WFLAGS) $(DEBUG) -o $@ $^

$(BUILD_DIR):
	@if [ ! -e $(BUILD_DIR) ]; then mkdir -p $(BUILD_DIR); fi

clean:
	@echo "Removing $(BUILD_DIR)*"
	@rm -r $(BUILD_DIR)*
