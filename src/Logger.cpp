#include "Logger.hpp"

namespace rawsockets
{
	Logger::Logger()
	{
	}

	Logger::~Logger()
	{
	}

	void Logger::Log(const string& text)
	{
		ofstream log_file(LOGFILENAME, ios_base::out | ios_base::app);
		log_file << text << endl;
	}
}
