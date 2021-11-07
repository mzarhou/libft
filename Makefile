ODIR = obj
SRCS = ${shell find . -not -name "*_bonus.c" -name "*.c" -maxdepth 1}
SRCS_BONUS = ${shell find . -name "*.c" -maxdepth 1}
OBJS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS}}
OBJS_BONUS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS_BONUS}}

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
RM = rm -rf

NAME = libft.a

${ODIR}/%.o: %.c
	@mkdir -p ${@D}
	CC ${CC_FLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

bonus: ${OBJS_BONUS}
	ar rc ${NAME} ${OBJS_BONUS}
	ranlib ${NAME}

clean:
	${RM} ${ODIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re bonus all
