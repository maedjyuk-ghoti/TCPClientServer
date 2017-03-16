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
	bool Connect(char const * const hostname, int const port);

	ssize_t Send(char const * const message, int const message_length);

private:
	int m_socket;
};

#endif
