CC      = gcc
CFLAGS  = -Wall -Wextra -pedantic -std=c11 -Iinclude
SRC     = src/bst.c src/main.c
TEST_SRC = src/bst.c tests/test_bst.c
TARGET  = bst
TEST    = test_bst

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST) $^
	./$(TEST)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST)

.PHONY: all run test clean
