CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format

SRC = $(wildcard *.c)
OBJECTS = $(SRC:.c=.o)

EXPECT_PASS = tests/expect_pass
EXPECT_FAIL = tests/expect_fail

TEST_TARGETS = \
	test_that_prints_string \
	test_that_prints_string_with_newline_character \
	test_that_prints_single_character \
	test_that_handles_single_character \
	test_that_prints_string_with_string_format_with_newline_character \
	test_that_prints_positive_integer_with_newline_character \
	test_that_prints_negative_integer_with_newline_character
	
all:
	@echo
	@echo ' ' The current project always depends on root level source
	@echo ' ' and object files:
	@echo 
	@echo '     ' SRC: $(SRC)
	@echo ' ' OBJECTS: $(OBJECTS)
	@echo 
	@echo ' '  Entry points are not stored in root.
	@echo
	@echo ' ' When built, the \'main\' entry point is supplied from the
	@echo ' ' \'\\tests\' directory. 
	@echo
	@echo ' ' \'make test\' compiles and tests all entry points. 
	@echo ' ' A single entry point can be built with \'make test_that_X\'.
	@echo
	@echo '     'e.g. \'make test_that_single_plain_character_prints\'
	@echo
	@echo ' ' \'make list\' shows available entry points.
	@echo

%.o: %.c
	@echo Compiling '$<' to object code...
	@$(CC) -g $(CFLAGS) -c $< -o $@

test: clean $(TEST_TARGETS)
	@echo
	@echo Completed tests.

test_that_prints_string: $(OBJECTS)
	@$(CC) -g $(CFLAGS) $^ tests/$@.c -o tests/$@
	@$(EXPECT_PASS) tests/$@ 'Hello world!'
	
test_that_prints_string_with_newline_character: $(OBJECTS)
	@$(CC) -g $(CFLAGS) $^ tests/$@.c -o tests/$@
	@$(EXPECT_PASS) tests/$@ "Let's try to printf a simple sentence."
	
test_that_prints_single_character: $(OBJECTS)
	@$(CC) -g $(CFLAGS) $^ tests/$@.c -o tests/$@
	@$(EXPECT_PASS) tests/$@ 'c'

test_that_handles_single_character: $(OBJECTS)
	@$(CC) -g $(CFLAGS) $^ tests/$@.c -o tests/$@
	@$(EXPECT_PASS) tests/$@ 'c'

test_that_prints_string_with_string_format_with_newline_character: $(OBJECTS)
	@$(CC) -g $(CFLAGS) $^ tests/$@.c -o tests/$@
	@$(EXPECT_PASS) tests/$@ "Let's try to printf a simple sentence."

test_that_prints_positive_integer_with_newline_character: $(OBJECTS)
	@$(CC) -g $(CFLAGS) $^ tests/$@.c -o tests/$@
	@$(EXPECT_PASS) tests/$@ "number = 123."

test_that_prints_negative_integer_with_newline_character: $(OBJECTS)
	@$(CC) -g $(CFLAGS) $^ tests/$@.c -o tests/$@
	@$(EXPECT_PASS) tests/$@ "number = -123."

# Phony targets execute even if target exists in file system.
.PHONY: clean test list edit 

list:
	@echo The following test entry points are availble:
	@echo
	@$(foreach target, $(TEST_TARGETS),echo "\t"$(target);)

clean:
	@echo Cleaning...
	@rm -f $(OBJECTS) 
	@echo 		CLEANING COMPLETED
	@echo -----------------------------------------

edit: 
	@vim Makefile

