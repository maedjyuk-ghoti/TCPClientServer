#include <openssl/ssl.h>
#include <openssl/err.h>
#include "ssl_server.h"

SSLServer::SSLServer()
	: Server()
	, ssl_active(false)
{
	SSL_load_error_strings();
	OpenSSL_add_ssl_algorithms();
}


SSLServer::SSLServer(Server const &server)
	: Server(Server)
	, ssl_active(false)
{
}


SSLServer::~SSLServer()
{
}


bool SSLServer::Listen()
{
	if (Server::Listen())
	{
		SSL_CTX* ssl_context = CreateContext();
		ConfigureContext(ssl_context);
	}


	return false;
}


int SSLServer::Receive(char* const buffer, int const buffer_len)
{
	return 0;
}


SSL_CTX* SSLServer::CreateContext()
{
	const SSL_METHOD *method;
	SSL_CTX *ssl_context;

	method = SSLv23_server_method();

	ssl_context = SSL_CTX_new(method);
	if (!ssl_context)
	{
		std::cerr << "ERROR: Unable to create SSL context: " << strerror(errno) << std::endl;
		ERR_print_errors_fp(stderr);
		exit(EXIT_FAILURE);
	}
	
	return ssl_context;
}
