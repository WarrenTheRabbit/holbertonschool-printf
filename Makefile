CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format

SRC = $(wildcard *.c)
OBJECTS = $(SRC:.c=.o)

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

%.o: %.c
	@echo Compiling '$<' to object code...
	@$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	@echo Cleaning...
	@rm -f $(OBJECTS) 
	@echo 		CLEANING COMPLETED
	@echo -----------------------------------------

edit: 
	@vim Makefile

