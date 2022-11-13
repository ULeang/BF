#pragma once

#include "BF_interface.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class BF :public BF_INTERFACE
{
protected:
	cp _cap;//存储空间容量
	cp _init_pos;//run开始时指针初始位置

protected:
	vector<char> cap;//存储空间
	unsigned cap_ptr;
	string code;
	unsigned code_ptr;

protected:
	void set_cap();//根据_cap设置cap
	void check_code()const;//检查code内容，去除注释，去除空白字符，若包含无效字符抛出异常

public:
	BF() :_cap(_30), _init_pos(_left), cap_ptr(0), code_ptr(0), cap(30, 0) {}
	~BF() {}

	void load_file(const char*);//加载文件内容到code中
	void load_code(const char*);//加载字符串内容到code中
	void set_compilation_parameter(cp);//设置_cap和_init_pos
	void run();
};