#include <iostream>
#include <sys/types.h>
#include <unistd.h>

#include "server.h"
#include "client.h"

int server()
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
				buffer[bytes_received] = '\0';
				std::cout << "Received " << bytes_received << " bytes" << std::endl;
				std::cout << "Message contents: " << buffer << std::endl;
			}
			m_server.CloseClientSocket();
		}
	}
	return 0;
}

int client()
{
	Client m_client;
	char hostname[] = "localhost";

	if (m_client.Connect(hostname, 5001))
	{
		std::cout << "Client connected\n";
	}

	char message[26] = "Hello from the other side";
	ssize_t bytes_sent = m_client.Send(message, strlen(message));

	if (strlen(message) == bytes_sent)
	{
		std::cout << "Successfully sent " << bytes_sent << " bytes" << std::endl;
	}
	else
	{
		std::cerr << "Error sending message" << std::endl;
	}

	return 0;
}

int main(int argc, char** argv)
{
	if (2 != argc)
	{
		exit(0);
	}

	if (0 == atoi(argv[1]))
	{
		return server();
	}
	else
	{
		return client();
	}
}
