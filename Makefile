NAME = libasm.a

SRC = ft_write.s \
	  ft_read.s \
	  ft_strlen.s \
	  ft_strcpy.s \
	  ft_strdup.s \
	  ft_strcmp.s \

SRC_BONUS = ft_list_size_bonus.s \
			ft_list_push_front_bonus.s \
			ft_list_sort_bonus.s \
			ft_list_remove_if_bonus.s \
			ft_atoi_base_bonus.s

OBJ = $(SRC:.s=.o)


OBJ_BONUS = $(SRC_BONUS:.s=.o)

FLAGS = -f macho64

NASM = nasm

all: $(NAME)

$(NAME): $(OBJ)

bonus: $(OBJ_BONUS)

%.o : %.s
		@$(NASM) $(FLAGS) $<
		@ar -rc $(NAME) $@

clean:
		@rm -rf $(OBJ)
		@rm -rf $(OBJ_BONUS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
