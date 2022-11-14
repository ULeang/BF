#include "BF_interface.h"
#include <iostream>
#include <stdexcept>

using ULya::BF_INTERFACE;

void para(BF_INTERFACE* bf, int argc, char** argv, int& i)
{
	if (!strcmp(argv[i], "-30"))
		bf->set_compilation_parameter(ULya::_30);
	else if (!strcmp(argv[i], "-100"))
		bf->set_compilation_parameter(ULya::_100);
	else if (!strcmp(argv[i], "-300"))
		bf->set_compilation_parameter(ULya::_300);
	else if (!strcmp(argv[i], "-1000"))
		bf->set_compilation_parameter(ULya::_1000);
	else if (!strcmp(argv[i], "-left"))
		bf->set_compilation_parameter(ULya::_left);
	else if (!strcmp(argv[i], "-middle"))
		bf->set_compilation_parameter(ULya::_middle);
	else if (!strcmp(argv[i], "-i"))
	{
		if (i == argc - 1)
			throw std::invalid_argument("error:no input-file");
		else if (argv[i + 1][0] == '-')
			throw std::invalid_argument("error:invalid input-file");
		bf->set_in(argv[i + 1]);
		++i;
	}
	else if (!strcmp(argv[i], "-o"))
	{
		if (i == argc - 1)
			throw std::invalid_argument("error:no output-file");
		else if (argv[i + 1][0] == '-')
			throw std::invalid_argument("error:invalid output-file");
		bf->set_out(argv[i + 1]);
		++i;
	}
	else
		throw std::invalid_argument("error:invalid compilation parameter");
}

int main(int argc, char** argv)
{
	auto bf = BF_INTERFACE::create_BF();
	bool _file = false;

	try {
		for (int i = 1; i < argc; ++i)
			if (argv[i][0] == '-')
				para(bf, argc, argv, i);
			else if (!_file)
			{
				bf->load_file(argv[i]);
				_file = true;
			}
			else
			{
				throw std::invalid_argument("error:only one file permitted");
			}
		bf->run();
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what();
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what();
	}
	catch (std::logic_error& ex)
	{
		std::cout << ex.what();
	}

	return 0;
}