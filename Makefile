all: test_printf
test_hash:
	clang ft_cprint.c ft_cprintf.c test_hash.c -o test_hash && ./test_hash > test_hash.txt && cat test_hash.txt
test_printf:
	clang ft_*.c test_printf.c -o test_printf && ./test_printf > test_printf.txt && cat test_printf.txt
clean:
	rm -rf a.out a.out.dSYM test_printf test_printf.dSYM test_hash test_hash.dSYM

