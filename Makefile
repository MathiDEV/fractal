###################################################
##      ___                                      ##
##    /\__\     MathiDEV - github.com/MathiDEV   ##
##   /::L_L_                                     ##
##  /:/L:\__\     Prj: Fractals  -  Lang: C      ##
##  \/_/:/  /                                    ##
##    /:/  /          © MathiDEV 2022            ##
##    \/__/                                      ##
###################################################

SRC	=	fractals.c \
		src/arguments_parser.c\
		src/apply_iterations.c \
		src/error_handling.c \
		src/display_fractal.c

TEST_SRC = tests/tests_fractals.c \
		src/arguments_parser.c\
		src/apply_iterations.c \
		src/error_handling.c \
		src/display_fractal.c

OBJ	=	$(SRC:.c=.o)

NAME	=	fractals

TESTS	=	-lcriterion --coverage

LIB	=		-L./lib -lmy

CFLAGS =	-I./include $(LIB)

${NAME}:	${OBJ}
			make -C./lib/my
			gcc -o ${NAME} ${OBJ} $(CFLAGS)

all :		${NAME}

clean:
			rm -f ${OBJ}
			make clean -C./lib/my


fclean:	clean
			rm -f ${NAME}
			make fclean -C./lib/my

			rm -f *.gcno *.gcda unit_tests

re:		fclean all

unit_tests:		re
		gcc -o unit_tests $(TEST_SRC) $(CFLAGS) $(TESTS)

tests_run:		unit_tests
		./unit_tests

.PHONY: all clean fclean re unit_tests tests_run
