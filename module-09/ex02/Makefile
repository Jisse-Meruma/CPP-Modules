NAME	:= PmergeMe

CC		:= c++
FLAGS	:= -g -Wall -Wextra -Werror -std=c++11

SRC		:= $(wildcard *.cpp)

OBJ_DIR	:= ./obj
OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

all: $(NAME)

run: all
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) -fsanitize=address -g $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(RM) $(OBJ)

fclean:
	@rm -rf $(OBJ_DIR)
	@$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: clean all fclean re
