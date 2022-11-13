#include "pch.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class BF :public BF_INTERFACE
{
protected:
	cp cap;
	cp init_pos;

protected:
	vector<char> cap;
	unsigned s_ptr;
	string code;
	unsigned c_ptr;

public:
	BF();
	~BF();

	void load_file(const char*);
	void load_code(const char*);
	void set_compilation_parameter(cp);
	void run();
};

BF_INTERFACE* BF_INTERFACE::create_BF()
{
	return new BF;
}