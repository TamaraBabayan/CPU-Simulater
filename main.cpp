#include "my_cpu.h"

int main(int argc, char **argv)
{
	my_cpu fcpu;
	cpu_init(fcpu);
	check_file(argc, argv);
	std::vector<std::string> file_content;
	file_content = open_file(argv[1]);
	std::map<size_t, instructions> code;
	size_t labels_count = parse(file_content, code);
	execute(code, fcpu, labels_count);
	print_regs(fcpu);
}
