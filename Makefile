CC = clang

CFLAGS += -Iincludes/
#CFLAGS += -Werror -g3 -O2
CFLAGS += -std=c11
CFLAGS += -Wextra -Wall -Wshadow -Wfloat-equal -Wundef -Wpointer-arith
CFLAGS += -Wcast-align -Wstrict-prototypes -Waggregate-return
CFLAGS += -Wswitch-default -Wswitch-enum -Wunreachable-code -pedantic

SRCS = srcs/main.c \
       srcs/usage.c \
       srcs/ghb.c \
       srcs/print.c \
       srcs/file.c

OBJS = $(SRCS:.c=.o)

NAME = ghb

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re