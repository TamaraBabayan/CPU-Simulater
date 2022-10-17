#include "my_cpu.h"

void execute(std::map<size_t, instructions> code, my_cpu& fcpu, size_t labels_count)
{
	std::map<std::string, void(*)(const instructions&, my_cpu& fcpu)> binary;          //binary operations
	std::map<std::string, void(*)(const instructions&, my_cpu& fcpu)> unary;           //unary instructions
	std::map<std::string, void(*)(const instructions&, my_cpu& fcpu, size_t& i)> jmps; //jumps
	init_maps(binary, unary, jmps);
	for (size_t i = 1; i <= code.size() + labels_count; ++i) {
		if (code.find(i) != code.end()) {
			if (binary.find(to_lower(code[i].opcode))!= binary.end()) {
				binary[to_lower(code[i].opcode)](code[i], fcpu);
			} else if (unary.find(to_lower(code[i].opcode)) != unary.end()) {
				unary[to_lower(code[i].opcode)](code[i], fcpu);
			} else if (jmps.find(to_lower(code[i].opcode)) != jmps.end()) {
				jmps[to_lower(code[i].opcode)](code[i], fcpu, i);
			} else {
				print_error(8, i);
			}
		}
	}
}
