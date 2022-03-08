###################################################
##      ___                                      ##
##    /\__\     MathiDEV - github.com/MathiDEV   ##
##   /::L_L_                                     ##
##  /:/L:\__\      Prj: Libmy  -  Lang: C        ##
##  \/_/:/  /                                    ##
##    /:/  /          © MathiDEV 2022            ##
##    \/__/                                      ##
###################################################

SRC=	my_getnbr.c \
		my_putchar.c \
		my_putstr.c \
		my_split.c \
		my_strisnum.c \
		my_strlen.c

NAME=	libmy.a

LIB_DEST=	../

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) $(LIB_DEST)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
