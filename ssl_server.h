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
	void InitOpenSSL();
	void GenerateContext();

	// These are used in GenerateContext
	static SSL_CTX* CreateContext();
	static void ConfigureContext(SSL_CTX* const ssl_context);

private:
	SSL* ssl;
	SSL_CTX* ssl_context;
	bool ssl_active;
};

#endif
