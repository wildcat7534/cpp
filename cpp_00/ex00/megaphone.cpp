#include <iostream>
#include <string>

int	main(int ac, char *av[])
{
	int 	i;
	int	j;

	i = 0;
	j = 0;
	if (ac < 2)
	{
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
			return (0);
	}
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			char chara = toupper(av[i][j++]);
			std::cout << chara;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);

}
