int	main(int ac)
{
	__block int		k;
	void			*_f;

	k = 0;
	f = ^ void (){
		k += 1;
	};
	( (void(*)())f)();
	( (void(*)())f)();
	printf("%i\n",k);

	return (0);
}
