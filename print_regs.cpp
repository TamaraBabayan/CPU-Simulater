#include "my_cpu.h"

void print_regs(my_cpu fcpu)
{
	std::cout << "r1" << " = " << fcpu.registers["r1"] << std::endl;
	std::cout << "r2" << " = " << fcpu.registers["r2"] << std::endl;
	std::cout << "r3" << " = " << fcpu.registers["r3"] << std::endl;
	std::cout << "r4" << " = " << fcpu.registers["r4"] << std::endl;
	std::cout << "r5" << " = " << fcpu.registers["r5"] << std::endl;
	std::cout << "r6" << " = " << fcpu.registers["r6"] << std::endl;
	std::cout << "r7" << " = " << fcpu.registers["r7"] << std::endl;
	std::cout << "r8" << " = " << fcpu.registers["r8"] << std::endl;
	std::cout << "r9" << " = " << fcpu.registers["r9"] << std::endl;
	std::cout << "r10" << " = " << fcpu.registers["r10"] << std::endl;
}