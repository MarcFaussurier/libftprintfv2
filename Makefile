all:
	cc -g -c ft*.c fmt*.c
	ar -rcs libftprintf.a *.o
main: all
	cc main.c libftprintf.a && ./a.out
clean:
	rm -rf a.out a.out.dSYM *.o
fclean:	clean
	rm -rf *.a
re: fclean all
