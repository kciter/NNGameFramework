#pragma once

#include "NNPacketHeader.h"
#include <memory.h>

#define MAX_CHAT_LEN	1024

#define MAX_NAME_LEN	30
#define MAX_COMMENT_LEN	40

enum PacketTypes
{
	PKT_NONE	= 0,

	PKT_CS_LOGIN	= 1,
	PKT_SC_LOGIN	= 2,
	PKT_CS_MOVE		= 5,
	PKT_SC_MOVE		= 6,
	PKT_CS_LOGIN_BROADCAST = 7,
	PKT_SC_LOGIN_BROADCAST = 8,

} ;

#pragma pack(push, 1)

struct MoveBroadcastRequest : public NNPacketHeader
{
	MoveBroadcastRequest()
	{
		m_Size = sizeof(MoveBroadcastRequest);
		m_Type = PKT_CS_MOVE;
		m_PlayerId = -1;
		m_PositionX = 0;
		m_PositionY = 0;
		m_DeltaTime = 0;
		m_Direction = 0;
	}

	int m_PlayerId;
	float m_PositionX;
	float m_PositionY;
	float m_DeltaTime;
	char m_Direction;
};

struct MoveBroadcastResult : public NNPacketHeader
{
	MoveBroadcastResult()
	{
		m_Size = sizeof(MoveBroadcastResult) ;
		m_Type = PKT_SC_MOVE ;
		m_PlayerId = -1 ;
		m_PositionX = 0;
		m_PositionY = 0;
	}

	int	m_PlayerId ;
	float m_PositionX;
	float m_PositionY;
} ;

struct LoginRequest : public NNPacketHeader
{
	LoginRequest()
	{
		m_Size = sizeof(LoginRequest) ;
		m_Type = PKT_CS_LOGIN ;
		m_PlayerId = -1 ;
	}

	int	m_PlayerId ;
} ;

struct LoginResult : public NNPacketHeader
{
	LoginResult()
	{
		m_Size = sizeof(LoginResult) ;
		m_Type = PKT_SC_LOGIN ;
		m_PlayerId = -1 ;
		memset(m_Name, 0, MAX_NAME_LEN) ;
	}

	int		m_PlayerId ;
	double	m_PosX ;
	double	m_PosY ;
	double	m_PosZ ;
	char	m_Name[MAX_NAME_LEN] ;

} ;

struct LoginBroadcastRequest : public NNPacketHeader
{
	LoginBroadcastRequest()
	{
		m_Size = sizeof(LoginBroadcastRequest) ;
		m_Type = PKT_CS_LOGIN_BROADCAST ;
		m_PlayerId = -1;
	}

	int		m_PlayerId ;
} ;

struct LoginBroadcastResult : public NNPacketHeader
{
	LoginBroadcastResult()
	{
		m_Size = sizeof(LoginBroadcastResult) ;
		m_Type = PKT_SC_LOGIN_BROADCAST ;
		m_PlayerId = -1;
	}

	int		m_PlayerId ;
} ;


#pragma pack(pop)