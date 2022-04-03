NAME = libft.a
RM = rm -rf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_strlen.c ft_bzero.c ft_putstr_fd.c ft_strjoin.c ft_strlcpy.c ft_itoa.c ft_strndup.c ft_split.c ft_memcmp.c ft_strnstr.c
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: clean fclean re all