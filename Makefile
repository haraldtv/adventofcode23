sourceFiles := main.c dec1.c
cleanFiles := main main.exe errors.txt adventofcode

SRC_dir := .
SRC_files := $(shell find $(SRC_dir) -name '*.c')

TARGET := adventofcode 

GCC_LINKS := -lm -lncurses -lpanel
GCC_ARGS := -Wall -Werror -Wpedantic

math-library: $(SRC_files)
	gcc $(GCC_ARGS) -O3 $(GCC_LINKS) -o $(TARGET) $(SRC_files) | tee ./errors



clean:
	rm $(cleanFiles)
