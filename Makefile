# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 14:34:06 by ylabbe            #+#    #+#              #
#    Updated: 2022/06/15 14:25:36 by ylabbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------- so long --------------------------------------------------------- #
SOLONGSRC = sources/main.c \
			sources/utils.c \
			sources/images.c \
			sources/verification_de_la_carte.c \
			sources/deplacement_du_personnage.c \
			sources/initilialisation_de_la_carte.c \
			sources/deplacement_du_personnage_suite.c
SOLONGOBJ = $(SOLONGSRC:.c=.o)

# ---------- so long bonus --------------------------------------------------- #
BONUSSRC =  bonus/main_bonus.c \
			bonus/utils_bonus.c \
			bonus/images_bonus.c \
			bonus/images_suite_bonus.c \
			bonus/verification_de_la_carte_bonus.c \
			bonus/deplacement_du_personnage_bonus.c \
			bonus/initilialisation_de_la_carte_bonus.c \
			bonus/deplacement_du_personnage_suite_bonus.c
BONUSOBJ = $(BONUSSRC:.c=.o)

# ---------- get_next_line --------------------------------------------------- #
GNLSRC = include/get_next_line/get_next_line.c \
			include/get_next_line/get_next_line_utils.c
GNLOBJ = $(GNLSRC:.c=.o)

# ---------- ft_printf ------------------------------------------------------- #
PRINTFSRC = @cd include/ft_printf && make
PRINTFOUT = include/ft_printf/libftprintf.a

# ---------- libft ----------------------------------------------------------- #
LIBFTSRC = @cd include/libft && make
LIBFTOUT = include/libft/libft.a

# ---------- commandes ------------------------------------------------------- #
COMP = @gcc
FLAGS = -Wall -Werror -Wextra
REMOVE = @rm -rfd
AR = @ar rcs
NAME = so_long
MINILIBX = -lmlx -framework OpenGL -framework AppKit

# ---------- règles ---------------------------------------------------------- #
all: $(NAME)
	@echo "\033[33;32mCompilation du projet terminé"

$(NAME): $(SOLONGOBJ) $(GNLOBJ) libftpeche ft_printfaubergine
	@$(COMP) $(SOLONGOBJ) $(MINILIBX) $(GNLOBJ) $(LIBFTOUT) $(PRINTFOUT) -o $(NAME)

bonus: fclean libftpeche ft_printfaubergine $(BONUSOBJ) $(GNLOBJ)
	@$(COMP) $(BONUSOBJ) $(MINILIBX) $(GNLOBJ) $(LIBFTOUT) $(PRINTFOUT) -o $(NAME)

libftpeche:
	@$(LIBFTSRC)

ft_printfaubergine:
	@$(PRINTFSRC)

%.o: %.c src/so_long.h bonus/so_long_bonus.h
	@$(COMP) $(FLAGS) -Imlx -c $< -o $@

clean:
	$(REMOVE) $(SOLONGOBJ) $(GNLOBJ) $(MAINOBJ) $(BONUSOBJ)
	@cd include/libft && make clean
	@cd include/ft_printf && make clean
	@echo "\033[33;32mclean terminé"

fclean: clean
	$(REMOVE) $(NAME)
	@cd include/libft && make fclean
	@cd include/ft_printf && make fclean
	@echo "\033[33;32mfclean terminé"

re: fclean all
