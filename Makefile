all:
	cc -g -c ft*.c fmt*.c va*.c
	ar -rcs libftprintf.a *.o
main: all
	cc -g main.c libftprintf.a && ./a.out
bonus: all
clean:
	rm -rf a.out a.out.dSYM *.o
fclean:	clean
	rm -rf *.a
re: fclean all
