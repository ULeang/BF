#pragma once
#include <iostream>

enum cp
{
	_modemask = 0xff
};
constexpr static cp _30;
constexpr static cp _100;
constexpr static cp _300;
constexpr static cp _1000;
constexpr static cp _left;
constexpr static cp _middle;
constexpr static cp operator|(cp, cp);

class BF_INTERFACE
{
public:
	static BF_INTERFACE* create_BF();

	virtual void load_file(const char*) = 0;
	virtual void load_code(const char*) = 0;
	virtual void set_compilation_parameter(cp) = 0;
	virtual void run() = 0;
};