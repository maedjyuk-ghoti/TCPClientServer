#include <openssl/ssl.h>
#include <openssl/err.h>
#include "ssl_client.h"

SSLClient::SSLClient()
	: Client()
	, ssl_active(false)
{
}


SSLClient::SSLClient(Client const &client)
	: Client(client)
	, ssl_active(false)
{
}


SSLClient::~SSLClient()
{
}


bool SSLClient::Connect(char const * const hostname, int const port)
{
	if (!Client::Connect(hostname, port))
	{
		return false;
	}

	// ssl handshake here
	return false;
}


ssize_t SSLClient::Send(char const * const message, int const message_length)
{
	// encrypt message here
	
	//Client::Send(encrypted_message, encrypted_message_length);
	
	return 0;
}
