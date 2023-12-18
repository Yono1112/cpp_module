NAME = diamondTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
# -Wshadow
# Enables warnings for variable shadowing. This occurs when a variable declared in a local scope
# has the same name as a variable in an outer scope, potentially leading to unexpected behavior.
RM = rm -rf
SRCS = $(wildcard *.cpp)	
OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
