NAME	:= phone

CC		:= g++
FLAGS	:= -Wall -Wextra -std=c++98

SRC		:= $(wildcard *.cpp)
HEADER	:= $(wildcard *.hpp)

OBJ		:= $(SRC:.cpp=.o)

all: $(NAME)

run: all
	./$(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: 
	@$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: clean all fclean re
