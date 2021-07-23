CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror

SRCS	:= $(shell find "." -name "*.c" ! -name "ft_lst*.c")

BONUSES := $(shell find "." -name "ft_lst*.c")

OBJS	:= ${SRCS:.c=.o}

BONUS_OBJS 	:= ${BONUSES:.c=.o}

NAME 	= libft

RM		:= rm -f

.c.o	:
			${CC}  ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${BONUS_OBJS}
			${CC} -c ${SRCS}
			ar rc libft.a ${OBJS} ${BONUS_OBJS}
			ranlib libft.a

bonus : ${BONUS_OBJS}
		ar rc libft.a ${BONUS_OBJS}

all		:	$(NAME)


clean 	:
			${RM} ${OBJS}
			${RM} libft.a
			${RM} ${BONUS_OBJS}

fclean	:	clean
			${RM} $(NAME)

.PHONY	:	all clean fclean re bonus .c.o
			
re		:	clean fclean $(NAME) 
