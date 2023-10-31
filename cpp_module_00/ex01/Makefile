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
cppcheck:
	mkdir -p log
	cppcheck --enable=all --check-config --error-exitcode=1 --inconclusive --force --suppress=missingIncludeSystem --std=c++11 $(INCLUDE) $(SRCS). 2> ./log/resule.log

tidy:
	@find ./ -name '*.cpp' -or -name '*.hpp' | while read file; do \
		clang-tidy $$file -- -Wall -Wextra -Werror -std=c++98 $(INCLUDE) >> ./log/tidy.log; \
	done

