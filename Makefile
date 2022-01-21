all:
	clang ft_*.c primitives.c implementation.c test.c && ./a.out > test.txt && cat test.txt
tool:
	clang ft_*.c primitives.c implementation.c tool.c -o tool
clean:
	rm -rf a.out a.out.dSYM

