# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 09:06:22 by ysmeding          #+#    #+#              #
#    Updated: 2023/09/25 08:48:01 by ysmeding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MYSOURCES = ft_itoa.c  \
			ft_putstr_fd.c \
			ft_strmapi.c \
			ft_atoi.c \
			ft_memchr.c \
			ft_split.c \
			ft_strncmp.c \
			ft_bzero.c \
			ft_memcmp.c \
			ft_strchr.c \
			ft_strnstr.c \
			ft_calloc.c \
			ft_memcpy.c \
			ft_strdup.c \
			ft_strrchr.c \
			ft_isalnum.c \
			ft_memmove.c \
			ft_striteri.c \
			ft_strtrim.c \
			ft_isalpha.c \
			ft_memset.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_isascii.c \
			ft_putchar_fd.c \
			ft_strlcat.c \
			ft_tolower.c \
			ft_isdigit.c \
			ft_putendl_fd.c \
			ft_strlcpy.c \
			ft_toupper.c \
			ft_isprint.c \
			ft_putnbr_fd.c \
			ft_strlen.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstsize.c \
			ft_printf.c \
			ft_printf_convc.c \
			ft_printf_convdi.c \
			ft_printf_convp.c \
			ft_printf_convs.c \
			ft_printf_convu.c \
			ft_printf_convxX.c \
			ft_printf_percentage.c \
			ft_checkflag.c \
			ft_ltoa.c \
			ft_ltohex.c \
			ft_lltohex.c \
			ft_printf_convhelp.c \
			ft_checkflagconv.c \
			ft_checkflagorder.c \
			get_next_line.c \
			get_next_line_utils.c

MYOBJECTS = $(MYSOURCES:.c=.o)

AR = ar

CC = cc

CFLAGS = -Wall -Werror -Wextra

MYHEADERS = ft_printf.h \
			get_next_line.h \
			libft.h
		
all: $(NAME)

$(NAME): $(MYOBJECTS) $(MYHEADERS)
	@$(AR) -rcs $(NAME) $(MYOBJECTS)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re