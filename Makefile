# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:52:53 by nsoares-          #+#    #+#              #
#    Updated: 2023/08/13 22:39:30 by nsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror #-pthread -fsanitize=thread
RM = rm -rf
INCLUDE = philo.h 

# _________SOURCES____________

SOURCE_FILES = philo.c \
				src/utils.c \
				src/init.c \
				src/threads.c \
				src/actions.c \
				
				

OBJS_FILES = $(SOURCE_FILES:.c=.o)

# __________COLORS____________

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# _________MESSAGE_____________

COMPILATION_START	=	echo "\n$(BOLD_YELLOW)Make: $(NO_COLOR)Compilation start...\n"

PHILO_READY  =   echo "\n$(BOLD_YELLOW)Philo ready! ✅ \n"

CLEANED		=	echo "\n$(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n$(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

RE          =   echo "\n$(BOLD_YELLOW)Re: $(NO_COLOR)Compilation restarted \n"

# __________RULES______________

all: compilation_start $(NAME)

$(NAME): $(OBJS_FILES)
		$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(NAME)
	@   $(PHILO_READY)

compilation_start:
	@ $(COMPILATION_START)

clean:
	@ $(RM) $(OBJS_FILES)
	@ $(CLEANED)
	
fclean: clean
	@ $(RM) $(NAME)
	@ $(FCLEANED)
		
re:	fclean all
	@ $(RE) 
