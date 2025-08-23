#include <iostream>


int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 0;
	while (av[++i])
	{
		int j = -1;
		while (av[i][++j])
			std::cout << (char)std::toupper(av[i][j]);
	}
	std::cout << "\n";
	return (0);
}
