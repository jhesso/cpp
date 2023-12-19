# Program name
NAME		=	weapon

# Compiler and compilation flags
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# Build files and directories
SRC_PATH	=	src/
OBJ_PATH	=	obj/
INC_PATH	=	include/
SRC			=	main.cpp \
				Weapon.class.cpp \
				HumanA.class.cpp \
				HumanB.class.cpp
SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ			=	$(SRC:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))
INC			=	-I $(INC_PATH)

# Main rule
all: $(OBJ_PATH) $(NAME)

# Object directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Program linking rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

# Clean up build files
clean:
	/bin/rm -rf $(OBJ_PATH)

# Remove program executable
fclean: clean
	/bin/rm -f $(NAME)

# Clean and recompile project
re: fclean all

.PHONY: all clean fclean re
