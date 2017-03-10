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
	bool Connect(char* hostname, int port);

	bool Send(char* message);

private:
	int m_socket;
};

#endif
