#ifndef SSL_SERVER_H
#define SSL_SERVER_H

#include <openssl/ssl.h>
#include <openssl/err.h>
#include "server.h"

class SSLServer : public Server
{
public:
	SSLServer();
	SSLServer(Server const &server);
	~SSLServer();

	// bool Connect(int const port); parent class provides this for now
	bool Listen();
	int Receive(char* const buffer, int const buffer_len);

private:
	static SSLCTX* CreateContext();

private:
	bool ssl_active;
}

#endif
