ODIR = obj
INCLUDE_DIR = includes
SRCS = ${wildcard part1/*.c} ${wildcard part2/*.c}
SRCS_BONUS = ${SRCS} ${wildcard _bonus/*.c}
OBJS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS}}
OBJS_BONUS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS_BONUS}}

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -I${INCLUDE_DIR}
RM = rm -rf

NAME = libft.a

${ODIR}/%.o: %.c
	@mkdir -p ${@D}
	CC ${CC_FLAGS} -c $< -o $@

${ODIR}/%.o: _bonus/%.c
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

.PHONY: clean fclean re 
