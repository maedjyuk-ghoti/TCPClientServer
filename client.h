#ifndef CLIENT_H
#define CLIENT_H

class Client
{
public:
	Client() {}
	~Client() {}

	/**
	 * Connects to the specified port
	 * Returns true if successful; false otherwise
	 */
	bool Connect(const char* const hostname, const int port);

	ssize_t Send(const char* const message, const int message_length);

private:
	int m_socket;
};

#endif
