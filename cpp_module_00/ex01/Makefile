NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror --std=c++98
RM = rm -rf
SRCS = $(wildcard $(SRC_DIR)/*.cpp)	

OBJ_DIR = obj
SRC_DIR = src

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INC = -I include

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
