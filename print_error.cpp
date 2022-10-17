#include "my_cpu.h"

void	print_error(unsigned short n, int line_num)
{
	if (n == 1)
		std::cerr << "error code 01 _ !!!! Must be one input file !!!!\n";
	else if (n == 2)
		std::cerr << "error code 02 _ !!!! Wrong extension of file !!!!\n";
	else if (n == 3)
		std::cerr << "error code 03 _ !!!! Cannot opening the file !!!!\n";
	else if (n == 4)
		std::cerr << "error code 04 _ !!!! Invalid arguments in line " << line_num << "  !!!!\n";
	else if (n == 5)
		std::cerr << "error code 05 _ !!!! Cannot be divided by 0 !!!!\n";
	else if (n == 6)
		std::cerr << "error code 06 _ !!!! Double declaration of the label in line " << line_num << "  !!!!\n";
	else if (n == 7)
		std::cerr << "error code 07 _ !!!! " << line_num << "  !!!!\n";
	else if (n == 8)
		std::cerr << "error code 08 _ !!!! There is no instruction like in line " << line_num << "  !!!!\n";
	else if (n == 9)
		std::cerr << "error code 09 _ !!!! There is no label like in line " << line_num << "  !!!!\n";
	exit(1);
}
