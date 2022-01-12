# libftprintfv2

42 school project, subject [here](https://github.com/Binary-Hackers/42_Subjects/blob/master/00_Projects/02_Algorithmic/ft_printf.pdf).

[See tests](test.c)<br />
[See tests results](output.txt)

### Dynamic vs non-dynamic printf

Dynamic PF allows user to register new specifiers at run-rime.<br />
Usage:
```C
	ft_printf_id_add(&ft_vsnprintf_ullong, "Lu", "llu", "zu", _);
	printf(...);
```

### Hashmap vs no hasmap

Hashmap is O(n) while a classic router that compares all strings is O(n*n) but here specifier lenghts should not be that long so the difference should not be important. Current implementation works with all clang specifiers without collision. <br />
<br />
[Implementation here](https://github.com/MarcFaussurier/libftprintfv2/blob/master/source/ft_printf_arg.c)

### Roadmap

- [x] architecture
- [x] dynamic specifiers
- [x] hashmap for specifiers
- [x] pass some basic tests
- [ ] pass mandatory tests
- [ ] pass all specifiers tests
- [ ] %b to print binary
- [ ] {colors}
- [ ] compile-time ft_printf(...) to bypass parsing and routing in compile-time formats
- [ ] store reccurent PF formats parsing results in run-time formats
