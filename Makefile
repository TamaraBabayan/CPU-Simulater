NAME = CPU

SRCS = $(shell find "." -name "*.cpp")

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

%.o : %.cpp
	@g++ -std=c++11 $(FLAGS) -c $< -o $(<:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	 @g++ -std=c++11 $(FLAGS) -o $(NAME) $(OBJS) 

clean : 
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: clean re fclean all
