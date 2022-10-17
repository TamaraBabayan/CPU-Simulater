#include "my_cpu.h"

void mov(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.registers[code_line.dest_register] = std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.registers[code_line.dest_register] = fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void add(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.registers[code_line.dest_register] += std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.registers[code_line.dest_register] += fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void sub(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.registers[code_line.dest_register] -= std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.registers[code_line.dest_register] -= fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void mul(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.registers[code_line.dest_register] *= std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.registers[code_line.dest_register] *= fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void div_(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		if (std::stoi(code_line.src_register) != 0) {
			fcpu.registers[code_line.dest_register] /= std::stoi(code_line.src_register);
		} else {
			print_error(5, code_line.line_number);
		}
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		if (fcpu.registers[code_line.src_register] != 0) {
			fcpu.registers[code_line.dest_register] /= fcpu.registers[code_line.src_register];
		} else {
			print_error(5, code_line.line_number);
		}
	} else {
		print_error(4, code_line.line_number);
	}
}

void and_(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.registers[code_line.dest_register] &= std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.registers[code_line.dest_register] &= fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void or_(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.registers[code_line.dest_register] |= std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.registers[code_line.dest_register] |= fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void xor_(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.registers[code_line.dest_register] ^= std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.registers[code_line.dest_register] ^= fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void test(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.flag = fcpu.registers[code_line.dest_register] & std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.flag = fcpu.registers[code_line.dest_register] & fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void cmp(const instructions& code_line, my_cpu& fcpu)
{
	if (code_line.src_is_num) {
		fcpu.flag = fcpu.registers[code_line.dest_register] - std::stoi(code_line.src_register);
	} else if (fcpu.registers.find(code_line.src_register) != fcpu.registers.end()){
		fcpu.flag = fcpu.registers[code_line.dest_register] - fcpu.registers[code_line.src_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void not_(const instructions& code_line, my_cpu& fcpu)
{
	if (fcpu.registers.find(code_line.dest_register) != fcpu.registers.end()){
		fcpu.registers[code_line.dest_register] = ~fcpu.registers[code_line.dest_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void inc(const instructions& code_line, my_cpu& fcpu)
{
	if (fcpu.registers.find(code_line.dest_register) != fcpu.registers.end()){
		++fcpu.registers[code_line.dest_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void dec(const instructions& code_line, my_cpu& fcpu)
{
	if (fcpu.registers.find(code_line.dest_register) != fcpu.registers.end()){
		--fcpu.registers[code_line.dest_register];
	} else {
		print_error(4, code_line.line_number);
	}
}

void je_jz(const instructions& code_line, my_cpu& fcpu, size_t& i)
{
	if (fcpu.flag == 0) {
		i = std::stoi(code_line.dest_register);
	}
}

void jne_jnz(const instructions& code_line, my_cpu& fcpu, size_t& i)
{
	if (fcpu.flag != 0) {
		i = std::stoi(code_line.dest_register);
	}
}

void jg_jnle(const instructions& code_line, my_cpu& fcpu, size_t& i)
{
	if (fcpu.flag > 0) {
		i = std::stoi(code_line.dest_register);
	}
}

void jge_jnl(const instructions& code_line, my_cpu& fcpu, size_t& i)
{
	if (fcpu.flag >= 0) {
		i = std::stoi(code_line.dest_register);
	}
}

void jl_jnge(const instructions& code_line, my_cpu& fcpu, size_t& i)
{
	if (fcpu.flag < 0) {
		i = std::stoi(code_line.dest_register);
	}
}

void jle_jng(const instructions& code_line, my_cpu& fcpu, size_t& i)
{
	if (fcpu.flag <= 0) {
		i = std::stoi(code_line.dest_register);
	}
}
