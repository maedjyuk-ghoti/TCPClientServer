#ifndef SERVER_H
#define SERVER_H

class Server
{
public:
	Server();
	~Server();

	int GetListenSocket() { return m_socket; }
	int GetClientSocket() { return m_client_socket; }

	/**
	 * Connects to the specified port
	 * Returns true if successful; false otherwise
	 */
	virtual bool Connect(const int port);

	/**
	 * Listens on the port
	 * Blocking call
	 * Returns true if a connection is established; false otherwise
	 */
	virtual bool Listen();

	/**
	 * Receive a message from a connected client
	 * Blocking call
	 * Returns the number of bytes received if successful; -1 otherwise
	 */
	virtual int Receive(char* const buffer, const int buffer_len);

	virtual int CloseClientSocket();

protected:
	bool SetListenSocket(int const socket) { m_socket = socket; return true; }
	bool SetClientSocket(int const socket) { m_client_socket = socket; return true; }

	int m_socket;			// Socket on which to listen for connection
	int m_client_socket;	// Socket which is connected to a client
};

#endif
