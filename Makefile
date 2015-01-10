# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 12:26:14 by tdieumeg          #+#    #+#              #
#    Updated: 2015/01/10 11:36:28 by tdieumeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors
SOURCES =
OBJECTS = $(SOURCES:.cpp=.o)
NAME = ft_retro

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all