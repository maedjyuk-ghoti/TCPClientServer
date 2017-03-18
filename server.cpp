#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>

#include "server.h"


Server::Server()
	: m_socket(0)
	, m_client_socket(0)
{
}


Server::~Server()
{
	if (0 != m_client_socket)
	{
		close(m_client_socket);
	}
	if (0 != m_socket)
	{
		close(m_socket);
	}
}


bool Server::Connect(const int port)
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


int Server::CloseClientSocket()
{
	return close(m_client_socket);
}


bool Server::Listen()
{
	if (0 == m_socket)
	{
		return false;
	}

	struct sockaddr_in addr;
	uint len = sizeof(addr);

	m_client_socket = accept(m_socket, (struct sockaddr*)&addr, &len);
	if (-1 == m_client_socket)
	{
		std::cerr << "Unable to accept\n";
		return false;
	}

	return true;
}


int Server::Receive(char* const buffer, int  buffer_len)
{
	return recv(m_client_socket, buffer, buffer_len, 0);
}
