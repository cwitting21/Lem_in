NAME = lem-in

SRCS_FILES = get_next_line.c \
			 lem-in.c \
			 count_ants.c \
			 initialize_map.c \
			 parse_map_to_struct.c \

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libprintf/libftprintf.a

SRCS_PATH = src

H_PATH = includes

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libprintf
	gcc $(CFLAGS) -I $(H_PATH) -I ./libprintf/includes -o $(NAME) $(SRCS) $(LIBFT)

clean:
	rm -f $(OBJECTS)
	make clean -C ./libprintf

fclean: clean
	rm -f $(NAME) $(LIBFT) 
	make fclean -C ./libprintf

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -I $(H_PATH) -I ./libprintf/includes -c -o $@ $<
