CC = gcc
CFLAGS = -Wall -Wextra
SRCDIR = src

# Output executables
TEST_LIST = test_linked_list
TEST_STRING = test_string
REVERSE_PROG = reverse_file

# Source files
LIST_SRC = $(SRCDIR)/linked_list.c
STRING_SRC = $(SRCDIR)/linked_string.c
TEST_LIST_SRC = $(SRCDIR)/test_linked_list.c
TEST_STRING_SRC = $(SRCDIR)/test_linked_string.c
REVERSE_SRC = $(SRCDIR)/reverse_file.c

# Object files (in source directory)
LIST_OBJS = $(LIST_SRC:.c=.o)
STRING_OBJS = $(STRING_SRC:.c=.o)
TEST_LIST_OBJS = $(TEST_LIST_SRC:.c=.o)
TEST_STRING_OBJS = $(TEST_STRING_SRC:.c=.o)
REVERSE_OBJS = $(REVERSE_SRC:.c=.o)

# Add source directory to include path
CFLAGS += -I$(SRCDIR)

# Default target
all: $(TEST_LIST) $(TEST_STRING) $(REVERSE_PROG)

# Run all tests including file reversal
test: $(TEST_LIST) $(TEST_STRING) $(REVERSE_PROG)
	@echo "Running linked list tests..."
	./$(TEST_LIST)
	@echo "\nRunning linked string tests..."
	./$(TEST_STRING)
	@echo "\nTesting file reversal..."
	@echo "This is a test file.\nIt has multiple lines.\nLet's reverse it!" > test_input.txt
	@echo "Original file contents:"
	@cat test_input.txt
	./$(REVERSE_PROG) test_input.txt test_output.txt
	@echo "\nReversed file contents:"
	@cat test_output.txt
	@rm test_input.txt test_output.txt

# Run just the reversal test
test-reverse: $(REVERSE_PROG)
	@echo "Testing file reversal..."
	@echo "This is a test file.\nIt has multiple lines.\nLet's reverse it!" > test_input.txt
	@echo "Original file contents:"
	@cat test_input.txt
	./$(REVERSE_PROG) test_input.txt test_output.txt
	@echo "\nReversed file contents:"
	@cat test_output.txt
	@rm test_input.txt test_output.txt

# Compilation rules
$(TEST_LIST): $(LIST_OBJS) $(TEST_LIST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_STRING): $(LIST_OBJS) $(STRING_OBJS) $(TEST_STRING_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(REVERSE_PROG): $(LIST_OBJS) $(STRING_OBJS) $(REVERSE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Object file compilation
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(SRCDIR)/*.o $(TEST_LIST) $(TEST_STRING) $(REVERSE_PROG) test_input.txt test_output.txt

# Header file dependencies
$(LIST_OBJS): $(SRCDIR)/linked_list.h
$(STRING_OBJS): $(SRCDIR)/linked_string.h $(SRCDIR)/linked_list.h
$(TEST_LIST_OBJS): $(SRCDIR)/linked_list.h
$(TEST_STRING_OBJS): $(SRCDIR)/linked_string.h $(SRCDIR)/linked_list.h
$(REVERSE_OBJS): $(SRCDIR)/linked_string.h $(SRCDIR)/linked_list.h

.PHONY: all clean test test-reverse