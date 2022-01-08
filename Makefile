all:
	clang *.c */*.c && ./a.out > output.txt && cat output.txt
clean:
	rm -rf a.out a.out.dSYM

