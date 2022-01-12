# libftprintfv2

[See progress](output.txt)

### Dynamic vs non-dynamic printf

Dynamic PF allows user to register new specifiers at run-rime.
Usage:
```C
	ft_printf_id_add(&ft_vsnprintf_ullong, "Lu", "llu", "zu", _);
	printf(...);
```

### Hashmap vs no hasmap

Hashmap is O(n) while a classic router that compares all strings is O(n*n) but here specifier lenghts should not be that long so the difference should not be important. Current implementation works with all clang flags without collision. 
[implemented here](https://github.com/MarcFaussurier/libftprintfv2/blob/master/source/ft_printf_arg.c)

### TODOS

- [x] architecture and basic tests
- [ ] pass mandatory tests
- [ ] pass bonus tests
- [ ] %b to print binary
- [ ] all specifiers
- [ ] compile ft_printf(...) to bypass parsing and routing in static formats. Parse source-code to find-out custom (but non-run-time) specifiers
- [ ] store reccurent run-time PF formats parsing results
