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
