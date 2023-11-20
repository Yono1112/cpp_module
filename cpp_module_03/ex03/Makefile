NAME = diamondTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
# -Wshadow
# Enables warnings for variable shadowing. This occurs when a variable declared in a local scope
# has the same name as a variable in an outer scope, potentially leading to unexpected behavior.
RM = rm -rf
SRCS = $(wildcard ./*.cpp)	
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
