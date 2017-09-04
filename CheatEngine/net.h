//

// Methods
SOCKET	Network_Connect(PBYTE IP, WORD Port);
VOID	Network_Disconnect(SOCKET Sock);
BOOL	Network_Receive(SOCKET Sock, PVOID Data, DWORD Size);
