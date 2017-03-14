#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include "server.h"

int main(int argc, char** argv)
{
	Server m_server;

	if (m_server.Connect(5001))
	{
		std::cout << "Server connected\n";
	}

	while (true)
	{
		if (m_server.Listen())
		{
			char buffer[100];
			int bytes_received = m_server.Receive(buffer, sizeof(buffer));
			if (-1 == bytes_received)
			{
				perror("Error in Server::Receive");
			}
			else
			{
				std::cout << "Received " << bytes_received << " bytes" << std::endl;
				std::cout << "Message contents: " << buffer << std::endl;
			}
			m_server.CloseClientSocket();
		}
	}
	return 0;
}
