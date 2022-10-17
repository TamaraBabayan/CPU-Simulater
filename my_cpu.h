#ifndef MY_CPU_H
#define MY_CPU_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <regex>

struct	instructions
{
	std::string opcode;
	std::string dest_register;
	std::string src_register;
	bool src_is_num;
	int	line_number;
};

struct my_cpu
{
	std::map<std::string, int> registers;
	int flag;
};


void print_error(unsigned short n, int line_num);
void cpu_init(my_cpu& fcpu);
std::vector<std::string> open_file(const std::string& argv);
void check_file(int argc, char **argv);
size_t parse(std::vector<std::string>& file_content, std::map<size_t, instructions>& code);
std::vector<std::string> split(const std::string& str);
std::string to_lower(std::string str);
int	is_number(const std::string& str);
void print_regs(my_cpu fcpu);
void execute(std::map<size_t, instructions> code, my_cpu& fcpu, size_t labels_count);
void init_maps(std::map<std::string, void(*)(const instructions&, my_cpu& fcpu)>& binary,
				std::map<std::string, void(*)(const instructions&, my_cpu& fcpu)>& unary,
				std::map<std::string, void(*)(const instructions&, my_cpu& fcpu, size_t& i)>& jmp);

void mov(const instructions& code_line, my_cpu& fcpu);
void add(const instructions& code_line, my_cpu& fcpu);
void sub(const instructions& code_line, my_cpu& fcpu);
void mul(const instructions& code_line, my_cpu& fcpu);
void div_(const instructions& code_line, my_cpu& fcpu);

void and_(const instructions& code_line, my_cpu& fcpu);
void or_(const instructions& code_line, my_cpu& fcpu);
void xor_(const instructions& code_line, my_cpu& fcpu);
void test(const instructions& code_line, my_cpu& fcpu);
void cmp(const instructions& code_line, my_cpu& fcpu);
void not_(const instructions& code_line, my_cpu& fcpu);

void inc(const instructions& code_line, my_cpu& fcpu);
void dec(const instructions& code_line, my_cpu& fcpu);

void je_jz(const instructions& code_line, my_cpu& fcpu, size_t& i);
void jne_jnz(const instructions& code_line, my_cpu& fcpu, size_t& i);
void jg_jnle(const instructions& code_line, my_cpu& fcpu, size_t& i);
void jge_jnl(const instructions& code_line, my_cpu& fcpu, size_t& i);
void jl_jnge(const instructions& code_line, my_cpu& fcpu, size_t& i);
void jle_jng(const instructions& code_line, my_cpu& fcpu, size_t& i);

#endif
