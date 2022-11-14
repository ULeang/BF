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
		cp _mask;//�ڴ��С��run��ʼʱָ���ʼλ��

	protected:
		vector<char> mem;//�ڴ�
		int mem_ptr;//�ڴ���±�
		string code;//���ص�Դ����
		bool i_changed = false;
		bool o_changed = false;
		std::istream* default_in = &std::cin;
		std::ostream* default_out = &std::cout;

	protected:
		void set_mem_size();//����_mask����cap����_mask��Ч�׳��쳣

		void check_code();//ȥ��ע�ͣ�ȥ���հ��ַ�����������Ч�ַ��׳��쳣
		void remove_comment();//ȥ��ע��
		void remove_white_space();//ȥ���հ��ַ�����������Ч�ַ��׳��쳣
		bool is_invalid_char(char);//������Ϊ��Ч�ַ�����true

		void load_code(std::istream&);//�����м������ݵ�code��

		void environment_initialize();//��mem����Ԫ����Ϊ0������mem_ptr

	protected:
		void shift_left();
		void shift_right();
		void add();
		void reduce();
		void out();
		void in();
		void left_bracket(size_t&);
		void right_bracket(size_t&);

		size_t find_rb(size_t);//���ض�Ӧ����λ����[��]λ��
		size_t find_lb(size_t);//���ض�Ӧ����λ����]��[λ��

	public:
		BF() :_mask(_30 | _left), mem_ptr(0), mem(30, 0) {}
		~BF();

		void load_file(const char*);//�����ļ����ݵ�code�У����޷����ļ��׳��쳣
		void load_code(const char*);//�����ַ������ݵ�code��
		void set_compilation_parameter(cp);//����_mask
		void run();//��
		void set_in(const char*);
		void unset_in();
		void set_out(const char*);
		void unset_out();
	};
}