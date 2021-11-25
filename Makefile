EXE		=	push_swap

SRCS_DIR	=	./srcs
OBJS_DIR	=	./objs

SRCS		=	$(wildcard $(SRCS_DIR)/*.c)
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC		=	clang
CCFLAGS		=	-Wall -Werror -Wextra -g
CPPFLAGS	=	-I $(INC)
LDFLAGS		=	-L./lib
LDLIBS		=	-lft
INC		=	./inc/libft

all:
	make -C $(INC) all
	$(MAKE) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	echo "\033[1mCompilation \033[1;32mOK\033[m"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $@

clean:
	make -C $(INC) clean
	rm -rf $(OBJS) $(OBJS_DIR)
	echo "\033[1mAll clean.\033[m"

fclean:
	make -C $(INC) fclean
	rm -rf $(OBJS) $(OBJS_DIR) $(EXE)
	echo "\033[1mAll clean.\033[m"

git-ready:
	make -C $(INC) git-ready
	rm -rf $(OBJS) $(OBJS_DIR) $(EXE)
	rm -f $(wildcard *~) $(wildcard */*~)
	rm -rf others/__pycache__ others/push_swap
	echo "\033[1mReady to push.\033[m"

re: fclean all

message:
	echo "Building executable..."


.PHONY: all, re, clean, fclean, message
