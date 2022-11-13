#include "BF_interface.h"

int main(void)
{
	auto bf = BF_INTERFACE::create_BF();
	try
	{
		bf->load_file("code.txt");
		bf->set_compilation_parameter(_100 | _middle);
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