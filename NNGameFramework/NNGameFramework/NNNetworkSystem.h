
#pragma once

#include "NNConfig.h"
#include "NNPacketHeader.h"
#include "NNCircularBuffer.h"
#include <map>

#define assert(_Expression) (void)( (!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0) )

struct OverlappedIO : public OVERLAPPED
{
	OverlappedIO()
	{}
} ;
class NNNetworkSystem
{
public:
	static NNNetworkSystem* GetInstance();
	static void ReleaseInstance();

	bool Init();
	void Destroy();
	bool Connect( const char* serverIP, int port );

	void OnRead(size_t len);
	void OnWriteComplete(size_t len);
	bool PostRecv();
	
	void SetPacketFunction( short packetType, void(*Function)(NNPacketHeader&) );

	NNCircularBuffer* GetRecvBuffer() { return &m_RecvBuffer; }
	NNCircularBuffer* GetSendBuffer() { return &m_SendBuffer; }
	
	bool Send(NNPacketHeader* pkg);
private:
	WSADATA m_WSAData;
	SOCKET m_Socket;

	SOCKADDR_IN m_ServerAddr;

	char* m_ServerIP;
	int m_Port;

	NNCircularBuffer m_RecvBuffer;
	NNCircularBuffer m_SendBuffer;

	OverlappedIO m_OverlappedSend;
	OverlappedIO m_OverlappedRecv;

	std::map<short,void(*)(NNPacketHeader&)> m_PacketFunction;

private:
	static NNNetworkSystem* m_pInstance;

	NNNetworkSystem();
	~NNNetworkSystem();
};
void CALLBACK RecvCompletion(DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags) ;
void CALLBACK SendCompletion(DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags) ;
