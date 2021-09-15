NAME   		=	libft.a
OUTPUT_DIR	=	../../lib

CC     		=	clang
CCFLAGS		=	-Wall -Werror -Wextra -g 

INC    		=	-I ./libft.h

SRCS		=	$(wildcard *.c)

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
