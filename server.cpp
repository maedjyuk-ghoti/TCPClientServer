#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>

#include "server.h"

bool Server::Connect(int port)
{
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > m_socket) {
		std::cerr << "Unable to create socket\n";
		return false;
    }

    if (0 > bind(m_socket, (struct sockaddr*)&addr, sizeof(addr))) {
		std::cerr << "Unable to bind\n";
		return false;
    }

    if (0 > listen(m_socket, 1)) {
		std::cerr << "Unable to listen\n";
		return false;
    }

    return true;
}

int Server::Listen()
{
	if (0 == m_socket)
	{
		return -1;
	}

	while(true)
	{
		struct sockaddr_in addr;
		uint len = sizeof(addr);
		
		int client = accept(m_socket, (struct sockaddr*)&addr, &len);
		if (-1 == client)
		{
			std::cerr << "Unable to accept\n";
			return 1;
		}

		// child thread code
		if (!fork())
		{
			close(m_socket);
			if (send(client, "Hello World!", 13, 0) == -1)
			{
				std::cerr << "Unable to send\n";
			}
			close(client);
			exit(0);
		}
		// end child thread code

		close(client);
	}

	return 0;
}
