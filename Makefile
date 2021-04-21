EXEC = exe

CC = gcc
CFLAGS = -Wall -Wextra
#LDFlags =

SRC = main.c \

OBJ = $(addprefix obj/,$(SRC:.c=.o))	

.phony : clean mrproper

all : build $(EXEC)
	@echo "Compilation Réussie"
build : 
	@mkdir -p obj

$(EXEC) : $(OBJ)
	$(CC) $^ -o $@ 
	
obj/%.o : src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	rm -rf obj

mrproper : clean
	rm -rf $(EXEC)
