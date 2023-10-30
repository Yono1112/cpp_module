NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror --std=c++98
RM = rm -rf
SRCS =	src/main.cpp	\
	src/Contact.cpp	\
	src/Phonebook.cpp	\

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

INC = -I include

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(INC)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
