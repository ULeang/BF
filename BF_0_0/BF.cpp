#include "BF.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <utility>
#include <cctype>

using std::ifstream;

cp _30 = static_cast<cp>(0x01);
cp _100 = static_cast<cp>(0x02);
cp _300 = static_cast<cp>(0x04);
cp _1000 = static_cast<cp>(0x08);
cp _left = static_cast<cp>(0x10);
cp _middle = static_cast<cp>(0x20);

constexpr cp operator|(cp _1, cp _2)
{
	return static_cast<cp>(_1 | _2);
}

void BF::set_cap()
{
	switch (0xf & _mask)
	{
	case 0x1:
		mem.resize(30);
		break;
	case 0x2:
		mem.resize(100);
		break;
	case 0x4:
		mem.resize(300);
		break;
	case 0x8:
		mem.resize(1000);
		break;
	default:
		throw std::invalid_argument("error:invalid parameter-capacity");
	}
}

void BF::check_code()
{
	if (code.size() == 0)
		return;
	remove_comment();
	remove_and_check();
}

void BF::remove_comment()
{
	auto pos = code.find('/');
	decltype(code.find('/')) _n_pos;
	while (pos != string::npos)
	{
		if (pos == code.size() - 1)
			break;

		if (code[pos + 1] == '/')
		{
			_n_pos = code.find('\n', pos + 1);
			if (_n_pos == string::npos)
			{
				code.erase(pos);
				break;
			}
			else
				code.erase(pos, _n_pos - pos + 1);
		}
		pos = code.find('/', pos);
	}
}

void BF::remove_and_check()
{
	for (int i = code.size() - 1; i > -1; --i)
	{
		if (isspace(code[i]))
			code.erase(i, 1);
		else if (is_invalid_char(code[i]))
			throw std::invalid_argument("error:invalid char");
	}
}

bool BF::is_invalid_char(char c)
{
	switch (c)
	{
	case '<':case '>':case '+':case '-':case '.':case ',':case '[':case ']':
		return false;
		break;
	default:
		return true;
	}
}

void BF::load_code(std::istream& i)
{
	code.clear();
	string temp;
	while (std::getline(i, temp))
		code = code + temp;
}

void BF::environment_initialize()
{
	for (auto& x : mem)
		x = 0;

	switch (0x3 & (_mask >> 4))
	{
	case 0x1:
		mem_ptr = 0;
		break;
	case 0x2:
		mem_ptr = mem.size() / 2 - 1;
		break;
	}
}

void BF::shift_left()
{
	if (--mem_ptr < 0)
		throw std::out_of_range("runtime error:ptr out of range(<)");
}

void BF::shift_right()
{
	if (++mem_ptr > mem.capacity() - 1)
		throw std::out_of_range("runtime error:ptr out of range(>)");
}

void BF::add()
{
	++mem[mem_ptr];
}

void BF::reduce()
{
	--mem[mem_ptr];
}

void BF::out()
{
	std::cout << mem[mem_ptr];
}

void BF::in()
{
	std::cin >> mem[mem_ptr];
}

void BF::left_bracket(size_t& p)
{
	if (mem[mem_ptr] == 0)
	{
		auto temp_p = find_rb(p);
		if (temp_p == string::npos)
			throw std::logic_error("runtime error:cant match [");
		p = temp_p + 1;
	}
}

void BF::right_bracket(size_t& p)
{

	if (mem[mem_ptr] != 0)
	{
		auto temp_p = find_lb(p);
		if (temp_p == string::npos)
			throw std::logic_error("runtime error:cant match ]");
		p = temp_p + 1;
	}
}

size_t BF::find_rb(size_t p)
{
	if (p > code.size() - 2)
		return string::npos;

	int count = 1;
	size_t temp_p = p;
	while (count)
	{
		temp_p = code.find_first_of("[]", temp_p + 1);
		if (temp_p == string::npos)
			return string::npos;
		if (code[temp_p] == ']')
			--count;
		else
			++count;
	}

	return temp_p;
}

size_t BF::find_lb(size_t p)
{
	if (p == 0)
		return string::npos;

	int count = 1;
	size_t temp_p = p;
	while (count)
	{
		temp_p = code.find_last_of("[]", temp_p - 1);
		if (temp_p == string::npos)
			return string::npos;
		if (code[temp_p] == '[')
			--count;
		else
			++count;
	}

	return temp_p;
}

void BF::load_file(const char* file)
{
	ifstream fin(file, std::ios::in);
	if (!fin)
		throw std::invalid_argument("error:cant open the file");

	load_code(fin);
}

void BF::load_code(const char* co)
{
	code = co;
}

void BF::set_compilation_parameter(cp c)
{
	_mask = c;
}

void BF::run()
{
	if (code.size() == 0)
		return;

	environment_initialize();

	for (size_t i = 0; i < code.size(); )
		switch (code[i])
		{
		case '<':
			shift_left(); ++i; break;
		case '>':
			shift_right(); ++i; break;
		case '+':
			add(); ++i; break;
		case '-':
			reduce(); ++i; break;
		case '.':
			out(); ++i; break;
		case ',':
			in(); ++i; break;
		case '[':
			left_bracket(i);  break;
		case ']':
			right_bracket(i);  break;
		}
}

BF_INTERFACE* BF_INTERFACE::create_BF()
{
	return new BF;
}
