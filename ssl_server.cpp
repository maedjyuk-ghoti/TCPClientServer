#include <openssl/ssl.h>
#include <openssl/err.h>
#include <iostream>

#include "ssl_server.h"

SSLServer::SSLServer()
	: Server()
	, ssl_active(false)
{
	InitOpenSSL();
	GenerateContext();	
}


SSLServer::SSLServer(Server const &server)
	: Server(server)
	, ssl_active(false)
{
	InitOpenSSL();
	GenerateContext();	
}


SSLServer::~SSLServer()
{
	Server::~Server();

	SSL_free(ssl);
	SSL_CTX_free(ssl_context);
	EVP_cleanup();
}


bool SSLServer::Listen()
{
	if (0 != m_client_socket
		|| Server::Listen())
	{
		ssl = SSL_new(ssl_context);
		SSL_set_fd(ssl, m_client_socket);

		if (SSL_accept(ssl) <= 0)
		{
			ERR_print_errors_fp(stderr);
		}
		else
		{
			return true;
		}
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


void SSLServer::ConfigureContext(SSL_CTX* const ssl_context)
{
	SSL_CTX_set_ecdh_auto(ssl_context, 1);

	// Set the key and cert
	if (SSL_CTX_use_certificate_file(ssl_context, "cert.pem", SSL_FILETYPE_PEM) < 0)
	{
		ERR_print_errors_fp(stderr);
		exit(EXIT_FAILURE);
	}

	if (SSL_CTX_use_PrivateKey_file(ssl_context, "key,pem", SSL_FILETYPE_PEM) < 0)
	{
		ERR_print_errors_fp(stderr);
		exit(EXIT_FAILURE);
	}
}


void SSLServer::InitOpenSSL()
{
	SSL_load_error_strings();
	OpenSSL_add_ssl_algorithms();
}


void SSLServer::GenerateContext()
{
	ssl_context = CreateContext();
	ConfigureContext(ssl_context);
}
