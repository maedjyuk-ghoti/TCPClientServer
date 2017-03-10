#include <iostream>
#include "server.h"

int main(int argc, char** argv)
{
	Server m_server;

	if (m_server.Connect(5001))
	{
		std::cout << "Server connected\n";
	}

	m_server.Listen();

	return 0;
}
