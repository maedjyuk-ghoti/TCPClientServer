#ifndef SERVER_H
#define SERVER_H

class Server
{
public:
	Server() {}
	~Server() {}

	/**
	 * Connects to the specified port
	 * Returns true if successful; false otherwise
	 */
	bool Connect(int port);
	
	/**
	 * Listens on the port
	 * Blocking call
	 * Returns -1 if m_socket is not connected
	 */
	int Listen();

private:
	int m_socket;
};

#endif
