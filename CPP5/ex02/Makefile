CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = C05ex02

FILE = _shrubbery

SRCS = main.cpp AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)
	-rm -f *$(FILE)

re: fclean all
