#ifndef SERVER_H
#define SERVER_H

class Server
{
public:
	Server();
	~Server() {}

	/**
	 * Connects to the specified port
	 * Returns true if successful; false otherwise
	 */
	bool Connect(const int port);

	/**
	 * Listens on the port
	 * Blocking call
	 * Returns true if a connection is established; false otherwise
	 */
	bool Listen();

	/**
	 * Receive a message from a connected client
	 * Blocking call
	 * Returns the number of bytes received if successful; -1 otherwise
	 */
	int Receive(char* buffer, int buffer_len);

	int CloseClientSocket();

private:
	int m_socket;			// Socket on which to listen for connection
	int m_client_socket;	// Socket which is connected to a client
};

#endif
