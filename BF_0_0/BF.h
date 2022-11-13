#pragma once

#include "BF_interface.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class BF :public BF_INTERFACE
{
protected:
	cp _cap;//�洢�ռ�����
	cp _init_pos;//run��ʼʱָ���ʼλ��

protected:
	vector<char> cap;//�洢�ռ�
	unsigned cap_ptr;
	string code;
	unsigned code_ptr;

protected:
	void set_cap();//����_cap����cap
	void check_code()const;//���code���ݣ�ȥ��ע�ͣ�ȥ���հ��ַ�����������Ч�ַ��׳��쳣

public:
	BF() :_cap(_30), _init_pos(_left), cap_ptr(0), code_ptr(0), cap(30, 0) {}
	~BF() {}

	void load_file(const char*);//�����ļ����ݵ�code��
	void load_code(const char*);//�����ַ������ݵ�code��
	void set_compilation_parameter(cp);//����_cap��_init_pos
	void run();
};