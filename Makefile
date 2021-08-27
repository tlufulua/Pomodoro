NAME =		pomodoro
CC =		@cc
CFLAGS =	-Wall -Werror -Wextra -I $(INC)
INC=		inc/
SRCS_DIR=	srcs/
SRCS =
MAIN =		$(SRCS_DIR)pomodoro.c
OBJS =		$(MAIN:%.c=%.o) $(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(MAIN) $(INC)*.a -o $@

clean:
	@rm -f $(INC)*.gch
	@rm -f $(OBJS)
	@find . -name ".DS_Store" -delete
	@find . -name "*.swp" -delete

fclean:	clean
	@rm -f $(NAME)

re:		clean all
