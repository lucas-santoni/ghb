CC = @clang

CFLAGS += -Iincludes/
#CFLAGS += -Werror -g3
CFLAGS += -std=c11
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

ECHO = @echo
GREEN = "\x1b[32m"
RESET = "\x1b[0m"

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	$(ECHO) $(GREEN)"✓ Build successful !"$(RESET)

clean:
	$(RM) $(OBJS)
	$(ECHO) "✓ Cleaning object..."

fclean: clean
	$(RM) $(NAME)
	$(ECHO) "✓ Cleaning binaries..."

re: fclean all

.PHONY: all clean fclean re
