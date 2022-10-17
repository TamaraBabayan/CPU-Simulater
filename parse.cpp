#include "my_cpu.h"

static std::string get_label(std::string& line, int index, int line_num)
{
	std::string label_in_line = line.substr(0, index);
	line = std::regex_replace(line, std::regex(label_in_line), std::to_string(line_num + 1));
	return (label_in_line);
}

static void find_remove_labels_2(std::vector<std::string>& file_content, std::map<std::string, int>& labels)
{
	std::vector<std::string> splited_line;
	for (size_t i = 0; i < file_content.size(); ++i) {
		splited_line = split(file_content[i]);
		if (tolower(splited_line[0][0]) == 'j') {
			if (labels.find(splited_line[1]) != labels.end()) {
				file_content[i] = std::regex_replace(file_content[i], std::regex(splited_line[1]), std::to_string(labels[splited_line[1]] + 1));
			} else {
				print_error(9, i + labels.size());
			}
		}
	}
}

static int find_remove_labels(std::vector<std::string>& file_content, std::map<std::string, int>& labels)
{
	size_t index;
	std::string label_in_line;
	for (size_t i = 0; i < file_content.size(); ++i) {
		index = file_content[i].find(':');
		if (index != std::string::npos) {
			label_in_line = get_label(file_content[i], index, i);
			if (labels.find(label_in_line) == labels.end()) {
				labels[label_in_line] = i;
			} else {
				print_error(6, i);
			}
		}
	}
	find_remove_labels_2(file_content, labels);
	return (labels.size());
}

void set_instructions(std::vector<std::string> file_content,std::map<size_t, instructions>& code, int labels_count)
{
	std::vector<std::string> splited_line;
	for (size_t i = 0; i < file_content.size(); ++i) {
		if (file_content[i].find(':') == std::string::npos) {
			file_content[i] = std::regex_replace(file_content[i], std::regex(","), " ");
			splited_line = split(file_content[i]);
			if (splited_line.size() == 3) {
				code[i + 1].opcode = splited_line[0];
				code[i + 1].dest_register = splited_line[1];
				code[i + 1].src_register = splited_line[2];
				code[i + 1].line_number  = i + 1;
				if (is_number(splited_line[2])) {
					code[i + 1].src_is_num = true;
				} else {
					code[i + 1].src_is_num = false;
				}
				code[i + 1].line_number = i;
			} else if (splited_line.size() == 2) {
				code[i + 1].opcode = splited_line[0];
				code[i + 1].dest_register = splited_line[1];
				code[i + 1].line_number = i + 1;
			} else if (splited_line.size() == 1) {
				continue;
			} else {
				code[i].opcode = "\0";
				print_error(7,i + labels_count - 1);
			}
		}
	}
}

size_t parse(std::vector<std::string>& file_content, std::map<size_t, instructions>& code)
{
	instructions instr;
	std::map<std::string, int> labels;
	int labels_count;
	labels_count = find_remove_labels(file_content, labels);
	set_instructions(file_content, code, labels_count);
	return (labels_count);
}
