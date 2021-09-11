NAME   		=	libft.a
OUTPUT_DIR	=	../../lib

CC     		=	clang
CCFLAGS		=	-Wall -Werror -Wextra -g 

INC    		=	-I ./libft.h

SRCS		=	ft_add_char.c		\
			ft_atof.c		\
			ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_char_isalnum.c	\
			ft_char_isalpha.c	\
			ft_char_isascii.c	\
			ft_char_isdigit.c	\
			ft_char_rep_count.c	\
			ft_intlen.c		\
			ft_itoa.c		\
			ft_memdel.c		\
			ft_memdel_strptr.c	\
			ft_putchar_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c		\
			ft_realloc.c		\
			ft_split.c		\
			ft_str_isnum.c		\
			ft_str_isprint.c	\
			ft_strcat.c 		\
			ft_strchr.c		\
			ft_strcmp.c		\
			ft_strdup.c		\
			ft_strjoin.c		\
			ft_strlcpy.c		\
			ft_strlen.c		\
			ft_strnlen.c		\
			ft_strrev.c		\
			get_next_line.c

OBJS_DIR	=	./objs
OBJS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJS_DIR)/%.o: %.c | message
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CCFLAGS) -c $(INC) $^ -o $@


$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@mkdir -p $(OUTPUT_DIR)
	@mv $(NAME) $(OUTPUT_DIR)
	@echo "\033[1mLibrary successfully built.\033[m"

message:
	@echo "\033[1mBuilding library....\033[m"

clean:
	@echo "\033[1mCleaning up library....\033[m"
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(addprefix $(OUTUT_DIR),$(NAME))
	@rm -rf $(OUTPUT_DIR)

git-ready: fclean
	@rm -f $(wildcard *~)

re: fclean all

.PHONY: all, clean, fclean, re
