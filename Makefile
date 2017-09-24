CC := @$(CC)

CFLAGS += -Iincludes/
#CFLAGS += -Werror -g3
CFLAGS += -std=gnu11
CFLAGS += -O2
CFLAGS += -Wextra -Wall -Wshadow -Wfloat-equal -Wundef -Wpointer-arith
CFLAGS += -Wcast-align -Wstrict-prototypes -Waggregate-return
CFLAGS += -Wswitch-default -Wswitch-enum -Wunreachable-code -pedantic

SRCS = srcs/main.c \
       srcs/usage.c \
       srcs/ghb.c \
       srcs/print.c \
       srcs/prints.c \
       srcs/file.c \
       srcs/cartridge.c \
       srcs/nintendoLogo.c \
       srcs/rom.c \
       srcs/ram.c \
       srcs/company.c \
       srcs/entry.c \
       srcs/args.c

OBJS = $(SRCS:.c=.o)

NAME = ghb

RM = @rm -f

ECHO = -@printf
GREEN = "\x1b[32m"
RESET = "\x1b[0m"

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	$(ECHO) $(GREEN)"✓ Build successful !"$(RESET)"\n"

clean:
	$(RM) $(OBJS)
	$(ECHO) "✓ Cleaning object...\n"

fclean: clean
	$(RM) $(NAME)
	$(ECHO) "✓ Cleaning binaries...\n"

re: fclean all

.PHONY: all clean fclean re
