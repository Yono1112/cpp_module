NAME = harl
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
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
