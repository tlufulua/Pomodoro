NAME =				Pomodoro
CC =				@cc
CFLAGS =			-Wall -Werror -Wextra -I $(INC)
INC=				inc/
SRCS_DIR=			srcs/
SRCS =
MEDIA =				$(SRCS_DIR)/Media
INSTALL_PATH =		 ~/Documents/PomodoroV.1/
MAIN =				$(SRCS_DIR)pomodoro.c
OBJS =				$(MAIN:%.c=%.o) $(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))

all:	$(NAME)

$(NAME):	$(OBJS) $(INSTALL_PATH)
	@echo Installing...
	@sleep 5
	$(CC) $(CFLAGS) $(MAIN) $(INC)*.a -o $@
	@cp -R $(MEDIA) $(INSTALL_PATH)
	@mv $(NAME) $(INSTALL_PATH)
	@make clean
	@echo Instalation complete!
	@echo Pomodoro V.1 path: $(INSTALL_PATH)

$(INSTALL_PATH):
	@mkdir $(INSTALL_PATH)

clean:
	@rm -f $(INC)*.gch
	@rm -f $(OBJS)
	@find . -name ".DS_Store" -delete
	@find . -name "*.swp" -delete

fclean:	clean
	@rm -rf $(INSTALL_PATH)
	@echo Pomodoro V.1 uninstalled

re:		clean all
