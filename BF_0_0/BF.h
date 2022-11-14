#pragma once

#include "BF_interface.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace ULya
{
	using std::vector;
	using std::string;

	class BF :public BF_INTERFACE
	{
	protected:
		cp _mask;//内存大小、run开始时指针初始位置

	protected:
		vector<char> mem;//内存
		int mem_ptr;//内存的下标
		string code;//加载的源代码
		bool i_changed = false;
		bool o_changed = false;
		std::istream* default_in = &std::cin;
		std::ostream* default_out = &std::cout;

	protected:
		void set_mem_size();//根据_mask设置cap，若_mask无效抛出异常

		void check_code();//去除注释，去除空白字符，若包含无效字符抛出异常
		void remove_comment();//去除注释
		void remove_white_space();//去除空白字符，若包含无效字符抛出异常
		bool is_invalid_char(char);//若参数为无效字符返回true

		void load_code(std::istream&);//从流中加载内容到code中

		void environment_initialize();//将mem所有元素置为0，设置mem_ptr

	protected:
		void shift_left();
		void shift_right();
		void add();
		void reduce();
		void out();
		void in();
		void left_bracket(size_t&);
		void right_bracket(size_t&);

		size_t find_rb(size_t);//返回对应参数位置上[的]位置
		size_t find_lb(size_t);//返回对应参数位置上]的[位置

	public:
		BF() :_mask(_30 | _left), mem_ptr(0), mem(30, 0) {}
		~BF();

		void load_file(const char*);//加载文件内容到code中，若无法打开文件抛出异常
		void load_code(const char*);//加载字符串内容到code中
		void set_compilation_parameter(cp);//设置_mask
		void run();//润
		void set_in(const char*);
		void unset_in();
		void set_out(const char*);
		void unset_out();
	};
}