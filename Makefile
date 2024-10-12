CFLAGS	= -fsanitize=address -g3
CC      = cc
NFLAGS = -lmlx -lXext -lX11
SRCS_C    = bonus/colors_bonus.c bonus/cub3d_bonus.c bonus/distance_bonus.c bonus/door_file_bonus.c\
			bonus/draw_bonus.c bonus/free_bonus.c bonus/ft_split_bonus.c bonus/garbage_collector_bonus.c\
			bonus/get_next_line_bonus.c bonus/inisial_bonus.c bonus/init_info_bonus.c bonus/map_bonus.c\
			bonus/parssing1_bonus.c bonus/parssing_bonus.c bonus/player_bonus.c bonus/print_bonus.c\
			bonus/render_maps_bonus.c  bonus/utils1_bonus.c bonus/utils_bonus.c\
			bonus/validators_bonus.c
SRC	= colors.c cub3d.c distance.c draw.c free.c ft_split.c garbage_collector.c get_next_line.c \
	  inisial.c init_info.c parssing1.c parssing.c player.c print.c render_maps.c utils1.c utils.c

NAME = cub3d
NAME_C = cub3d_bonus
OBJT = $(SRC:.c=.o)
OBJS_C 	= $(SRCS_C:.c=.o)
all : $(NAME)

$(NAME): $(OBJT)
	$(CC) $(CFLAGS) $(OBJT) $(NFLAGS) -o $(NAME) 

bonus: $(NAME_C)

$(NAME_C): $(OBJS_C)
		   $(CC) $(CFLAGS) $(OBJS_C) $(NFLAGS) -o $(NAME_C)
%.o: %.c
	$(CC) $(CFLAGS) -I -Imlx_linux -O3 -c $< -o $@
clean : 
		rm -f $(OBJT) $(OBJS_C)
fclean : clean
		rm -f $(NAME) $(NAME_C)
re : fclean all