#pragma once

#include "BF_interface.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class BF :public BF_INTERFACE
{
protected:
	cp _mask;//存储空间容量、run开始时指针初始位置

protected:
	vector<char> mem;//存储空间
	int mem_ptr;
	string code;

protected:
	void set_cap();//根据_mask设置cap

	void check_code();//检查code内容，去除注释，去除空白字符，若包含无效字符抛出异常
	void remove_comment();
	void remove_and_check();
	bool is_invalid_char(char);

	void load_code(std::istream&);//从流中加载内容到code中

	void environment_initialize();

protected:
	void shift_left();
	void shift_right();
	void add();
	void reduce();
	void out();
	void in();
	void left_bracket(size_t&);
	void right_bracket(size_t&);

	size_t find_rb(size_t);
	size_t find_lb(size_t);

public:
	BF() :_mask(_30 | _left), mem_ptr(0), mem(30, 0) {}
	~BF() {}

	void load_file(const char*);//加载文件内容到code中，若无法打开文件抛出异常
	void load_code(const char*);//加载字符串内容到code中
	void set_compilation_parameter(cp);//设置_mask
	void run();
};