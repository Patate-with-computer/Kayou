##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SCREEN_TEXT	=	display_screen_text.c	\
				free_screen_text.c		\
				get_size_txt.c			\
				draw_txt.c				\
				get_buffer.c			\
				draw_all_lines.c		\
				put_the_txt.c			\
				dialog.c				\
				get_a_key.c

ATTACK		=	add_an_attack.c		\
				display_attack.c	\
				set_all_rect.c		\
				move_attack.c

CURSOR_BAR	=	init_cursor_bar.c	\
				free_cursor.c		\
				display_cursor.c	\
				move_circle.c

ECHAP_MENU	=	set_e_menu.c	\
				init_echap_menu.c

ENEMY		=	init_an_enemy.c			\
				display_enemy.c			\
				convert_enemy.c			\
				read_enemy_file.c		\
				set_all_rect.c			\
				set_all_texture.c		\
				remove_life.c			\
				init_texture_and_var.c	\
				count_enemy.c			\
				print_life.c			\
				move_an_enemy.c			\
				$(addprefix attack/, $(ATTACK))

WINDOW_MANAGE	=	init_window.c		\
					free_window.c		\
					window_loop.c		\
					project_pt.c		\
					draw_background.c	\
					init_target.c		\
					draw_render_sprite.c	\
					display_horizon_bar.c	\
					move_cheat.c			\
					maze_mode.c				\
					demo.c

PLAYER		=	free_player.c		\
				init_player.c		\
				move_player.c		\
				set_rect_weapon.c	\
				display_weapon.c	\
				init_weapon.c		\
				add_all_weapon.c	\
				move_weapon.c		\
				point_in_triangle.c	\
				set_player_null.c	\
				move_camera.c		\
				check_weapon.c		\
				lock.c				\
				get_max.c


ROOM		=	set_hallway.c		\
            	set_labyrinth.c		\
				set_secret_room.c	\
				set_diag_map.c		\
				set_hell_room.c		\
				set_boss.c			\
				set_intro.c			\
				set_corrupted_room.c	\
				set_demo.c

EVENT_MANAGE	=	event_manage.c		\
					get_win_scale.c			\
					ground_evt_struct.c		\
					is_in_rect.c			\
					set_room_ground.c		\
					get_joy_button.c		\
					get_one_click.c			\
					get_one_button_click.c	\
					set_joystick_btn.c		\
					$(addprefix set_room/, $(ROOM))

FILE_MANAGE	=	get_file_write_name.c	\
				scan_all_line.c			\
				get_texture_name.c		\
				convert_file.c			\
				read_file.c				\
				create_rectangle.c		\
				print_step.c

WALL			=	free_wall.c				\
					distance_to_wall.c		\
					display_wall.c			\
					display_quad.c			\
					set_distance.c			\
					init_a_wall.c			\
					sort_wall.c				\
					break_wall.c			\
					create_breakable_wall.c	\
					add_breakable_array.c

ITEMS			=	init_an_items.c		\
					add_wall_items.c	\
					set_item_rect.c		\
					display_item.c		\
					check_item.c		\
					add_item_array.c

LIB				=	set_all_null.c				\
					get_millis.c				\
					set_song_lib_to_null.c		\
					null_game_assets_struct.c		\
					null_texture_pack_struct.c		\
					set_all_null_menu.c				\
					null_echap_menu.c				\
					get_max.c						\
					is_wall_visible.c				\
					get_texture_size.c				\
					get_cutstr.c

WEAPON_PURCHASE =	display_weapon_purchase.c	\
					display_price.c

SONG		=	create_song_librairie.c		\
			free_song.c			\
			init_sound_buff.c		\
			free_sound_buffer.c		\
			free_all_song_array.c	\
			free_sound_array.c		\
			init_an_song_array.c	\
			init_all_song_array.c	\
			play_song.c

GAME_MENU	=	destroy_menu_struct.c	\
			init_buttons.c			\
			init_menu.c				\
			launcher.c				\
			is_hovered.c			\
			save_menu.c				\
			print_button.c			\
			credits.c				\
			blink_text.c			\
			escape_menu.c			\
			opt_menu.c				\
			display_background.c	\
			game_over.c				\
			you_win.c


TEXTURE_PACK	=	texture_name.c		\
					init_texture_pack.c	\
					get_size_array.c	\
					init_one_pack.c		\
					free_one_pack.c		\
					free_texture_pack.c	\
					pack.c				\
					free_texture_name.c	\
					get_texture_pack_name.c	\
					load_text.c				\
					set_all_wall_texture.c

SAVE_MANAGE	=	write_a_save.c		\
				get_filename.c		\
				remove_a_save.c		\
				is_file_exist.c		\
				lunch_a_save.c		\
				display_save.c

INFOS		=	player_infos.c		\
				print_one_text.c	\
				print_one_texture.c	\
				minimap.c


MAIN			=	main.c

SRC_DIR		=	src

SRC		= 	$(addprefix $(SRC_DIR)/window_manage/, $(WINDOW_MANAGE))		\
			$(addprefix $(SRC_DIR)/screen_text/, $(SCREEN_TEXT))			\
			$(addprefix $(SRC_DIR)/cursor_bar/, $(CURSOR_BAR))				\
			$(addprefix $(SRC_DIR)/weapon_purchase/, $(WEAPON_PURCHASE))	\
			$(addprefix $(SRC_DIR)/echap_menu/, $(ECHAP_MENU))				\
			$(addprefix $(SRC_DIR)/save_manage/, $(SAVE_MANAGE))			\
			$(addprefix $(SRC_DIR)/game_menu/, $(GAME_MENU))				\
			$(addprefix $(SRC_DIR)/texture_pack/, $(TEXTURE_PACK))			\
			$(addprefix $(SRC_DIR)/lib/, $(LIB))							\
			$(addprefix $(SRC_DIR)/song_manage/, $(SONG))					\
			$(addprefix $(SRC_DIR)/event_manage/, $(EVENT_MANAGE))			\
			$(addprefix $(SRC_DIR)/player/, $(PLAYER))						\
			$(addprefix $(SRC_DIR)/file_manage/, $(FILE_MANAGE))			\
			$(addprefix $(SRC_DIR)/wall/, $(WALL))							\
			$(addprefix $(SRC_DIR)/enemy/, $(ENEMY))						\
			$(addprefix $(SRC_DIR)/items/, $(ITEMS))						\
			$(addprefix $(SRC_DIR)/infos/, $(INFOS))						\
			$(SRC_DIR)/$(MAIN)

NAME		=	wolf3d

CPPFLAGS	+=	-iquote./include/ -Wall -Wextra

CFLAGS		+=	-Wall -Wextra

CSFML		+=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CLIBS		+=	-lm

BUILD_DIR = build

OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

CC		?=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CSFML) $(CLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -fsanitize=address
debug: re

help:
	@echo "Exemple of usage:\n"
	@echo "make:\t\t\tCreate the binary wolf3d"
	@echo "make clean:\t\tDelete every '*.o', created by 'make'"
	@echo "make fclean:\t\tDelete everything created by 'make'"
	@echo "make re:\t\tDo 'make fclean' instruction and 'make' after"
	@echo "make help:\t\tDisplay the compilation manual"

.PHONY: all clean fclean re debug help
