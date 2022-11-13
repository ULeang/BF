#pragma once

namespace ULya
{
	enum cp
	{
		_modemask = 0xff
	};
	constexpr static cp _30 = static_cast<cp>(0x01);
	constexpr static cp _100 = static_cast<cp>(0x02);
	constexpr static cp _300 = static_cast<cp>(0x04);
	constexpr static cp _1000 = static_cast<cp>(0x08);
	constexpr static cp _left = static_cast<cp>(0x10);
	constexpr static cp _middle = static_cast<cp>(0x20);

	constexpr cp operator|(cp _1, cp _2);

	class BF_INTERFACE
	{
	public:
		static BF_INTERFACE* create_BF();

		virtual void load_file(const char*) = 0;
		virtual void load_code(const char*) = 0;
		virtual void set_compilation_parameter(cp) = 0;
		virtual void run() = 0;
	};
}