#ifndef SSL_CLIENT_H
#define SSL_CLIENT_H

#include "client.h"

class SSLClient : public Client
{
public:
	SSLClient();
	SSLClient(Client const &client);
	~SSLClient();

	bool Connect(char const * const hostname, int const port);

	ssize_t Send(char const * const message, int const message_length);

private:
	bool ssl_active;
};

#endif
