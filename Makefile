NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCDIR = src
INCDIR = inc
OBJDIR = obj
LIBFT_DIR = libft
RM = rm -rf

SRCS = $(addprefix $(SRCDIR)/, main.c move.c sort_utils.c sort.c utils.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
INCS = $(addprefix $(INCDIR)/, push_swap.h)
LIBFT_SRCS = ft_isdigit.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c
LIBFT_OBJS = $(addprefix $(OBJDIR)/, $(LIBFT_SRCS:.c=.o))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_OBJS)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
