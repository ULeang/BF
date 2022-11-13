#pragma once

#include "BF_interface.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class BF :public BF_INTERFACE
{
protected:
	cp _mask;//�洢�ռ�������run��ʼʱָ���ʼλ��

protected:
	vector<char> mem;//�洢�ռ�
	int mem_ptr;
	string code;

protected:
	void set_cap();//����_mask����cap

	void check_code();//���code���ݣ�ȥ��ע�ͣ�ȥ���հ��ַ�����������Ч�ַ��׳��쳣
	void remove_comment();
	void remove_and_check();
	bool is_invalid_char(char);

	void load_code(std::istream&);//�����м������ݵ�code��

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

	void load_file(const char*);//�����ļ����ݵ�code�У����޷����ļ��׳��쳣
	void load_code(const char*);//�����ַ������ݵ�code��
	void set_compilation_parameter(cp);//����_mask
	void run();
};