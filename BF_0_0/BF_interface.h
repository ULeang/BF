#pragma once

enum cp
{
	_30 = 0, _100 = 1, _300 = 2, _1000 = 3,
	_left = 0, _middle = 4
};

class BF_INTERFACE
{
public:
	static BF_INTERFACE* create_BF();

	virtual void load_file(const char*) = 0;
	virtual void load_code(const char*) = 0;
	virtual void set_compilation_parameter(cp) = 0;
	virtual void run() = 0;
};