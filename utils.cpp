#include "my_cpu.h"

void cpu_init(my_cpu& fcpu)
{
	fcpu.registers["r1"] = 0;
	fcpu.registers["r2"] = 0;
	fcpu.registers["r3"] = 0;
	fcpu.registers["r4"] = 0;
	fcpu.registers["r5"] = 0;
	fcpu.registers["r6"] = 0;
	fcpu.registers["r7"] = 0;
	fcpu.registers["r8"] = 0;
	fcpu.registers["r9"] = 0;
	fcpu.registers["r10"] = 0;
	fcpu.flag = 0;
}

std::string to_lower(std::string str)
{
	std::string result;
	size_t i = 0;
	while (i < str.size())
	{
		result += tolower(str[i]);
		++i;
	}
	return (result);
}

int	is_number(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

std::vector<std::string>	open_file(const std::string& argv)
{
	std::vector<std::string>	file_content;
	std::string	line;
	std::ifstream file(argv);
	if (file.is_open() == 0)
	{
		print_error(3,-1);
	}
	
	while (getline(file, line))
	{
		file_content.push_back(line);
	}
	return (file_content);
}

//check file's extension
void check_file(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i]) {
			++i;
		}
		i -= 6;
		if (strcmp(argv[1] + i, ".myasm") != 0) {
			print_error(2, -1);
		}
	} else {
		print_error(1, -1);
	}
}

//split a line
std::vector<std::string> split(const std::string& line)
{
	std::vector<std::string> splited_line;
	int i = 0;
	
	while (line[i]) {
		while (line[i] == ' ' || line[i] == '\t') {
	 		i++;
		}
		int j = i;
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0') {
			i++;
		}
		splited_line.push_back(line.substr(j,i - j));
	}
 return (splited_line);
}

static void init_binary(std::map<std::string, void(*)(const instructions&, my_cpu& fcpu)>& binary)
{
	binary = {{"mov", mov},
		{"sub", sub},
		{"add", add},
		{"mul", mul},
		{"div", div_},
		{"and", and_},
		{"or", or_},
		{"xor", xor_},
		{"test", test},
		{"cmp", cmp}
	};
}

static void init_unary(std::map<std::string, void(*)(const instructions&, my_cpu& fcpu)>& unary)
{
	unary = {{"not", not_},
		{"inc", inc},
		{"dec", dec}
	};
}

static void init_jmp(std::map<std::string, void(*)(const instructions&, my_cpu& fcpu, size_t& i)>& jmps)
{
	jmps = {{"je",je_jz},
		{"jz",je_jz},
		{"jne",jne_jnz},
		{"jnz",jne_jnz},
		{"jg",jg_jnle},
		{"jnle",jg_jnle},
		{"jge",jge_jnl},
		{"jnl",jge_jnl},
		{"jl",jl_jnge},
		{"jnge",jl_jnge},
		{"jle",jle_jng},
		{"jng",jle_jng}
	};
}

void init_maps(std::map<std::string, void(*)(const instructions&, my_cpu& fcpu)>& binary, 
			std::map<std::string, void(*)(const instructions&, my_cpu& fcpu)>& unary, 
			std::map<std::string, void(*)(const instructions&, my_cpu& fcpu, size_t& i)>& jmps)
{
	init_binary(binary);
	init_unary(unary);
	init_jmp(jmps);
}
