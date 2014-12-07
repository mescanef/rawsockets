#ifndef LOGGER_HPP
#define LOGGER_HPP

// global includes
#include <fstream>
#include <string>
// local includes
#include "Defines.hpp"

using std::string;
using std::ofstream;
using std::ios_base;
using std::endl;

namespace rawsockets
{
	class Logger
	{
	public:
		Logger();
		~Logger();
		void Log(const string&);
	};

}

#endif // LOGGER_HPP
