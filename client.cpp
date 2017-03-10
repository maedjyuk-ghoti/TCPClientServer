#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>

#include <iostream>
#include <string>

#include "client.h"

bool Client::Connect(char* hostname, int port)
{
	struct addrinfo  hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];
	char port_str[6];
	sprintf(port_str, "%i", port);

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(hostname, port_str, &hints, &servinfo)) != 0)
	{
		std::cerr << "Unable to use getaddrinfo\n";
		return false;
	}

	// loop through all the results and connect to the first we can
	for (p = servinfo; p != NULL; p = p->ai_next)
	{
		if ((m_socket = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
		{
			continue;
		}

		if (connect(m_socket, p->ai_addr, p->ai_addrlen) == -1)
		{
			continue;
		}

		break; // we have a socket to which we are connected
	}

	if (NULL == p)
	{
		std::cerr << "Unable to find a port on which to connect\n";
		return false;
	}

	freeaddrinfo(servinfo);

	return true;
}
