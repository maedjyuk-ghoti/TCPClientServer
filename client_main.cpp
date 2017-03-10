#include <iostream>
#include "client.h"

int main(int argc, char** argv)
{
	Client m_client;
	char hostname[] = "localhost";

	if (m_client.Connect(hostname, 5001))
	{
		std::cout << "Client connected\n";
	}

	//m_client.Listen();

	return 0;
}
