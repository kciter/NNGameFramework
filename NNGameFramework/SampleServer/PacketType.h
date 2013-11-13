#pragma once

#define MAX_CHAT_LEN	1024

#define MAX_NAME_LEN	30
#define MAX_COMMENT_LEN	40

enum PacketTypes
{
	PKT_NONE	= 0,

	PKT_CS_LOGIN	= 1,
	PKT_SC_LOGIN	= 2,

	PKT_CS_CHAT		= 3,
	PKT_SC_CHAT		= 4,

	PKT_CS_MOVE		= 5,
	PKT_SC_MOVE		= 6,

	PKT_CS_LOGIN_BROADCAST = 7,
	PKT_SC_LOGIN_BROADCAST = 8,

} ;

#pragma pack(push, 1)

struct PacketHeader
{
	PacketHeader() : mSize(0), mType(PKT_NONE) 	{}
	short mSize ;
	short mType ;
} ;

struct MoveBroadcastRequest : public PacketHeader
{
	MoveBroadcastRequest()
	{
		mSize = sizeof(MoveBroadcastRequest);
		mType = PKT_CS_MOVE;
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

struct MoveBroadcastResult : public PacketHeader
{
	MoveBroadcastResult()
	{
		mSize = sizeof(MoveBroadcastResult) ;
		mType = PKT_SC_MOVE ;
		m_PlayerId = -1 ;
		m_PositionX = 0;
		m_PositionY = 0;
	}

	int	m_PlayerId ;
	float m_PositionX;
	float m_PositionY;
} ;

struct LoginRequest : public PacketHeader
{
	LoginRequest()
	{
		mSize = sizeof(LoginRequest) ;
		mType = PKT_CS_LOGIN ;
		mPlayerId = -1 ;
	}

	int	mPlayerId ;
} ;

struct LoginResult : public PacketHeader
{
	LoginResult()
	{
		mSize = sizeof(LoginResult) ;
		mType = PKT_SC_LOGIN ;
		mPlayerId = -1 ;
		memset(mName, 0, MAX_NAME_LEN) ;
	}

	int		mPlayerId ;
	double	mPosX ;
	double	mPosY ;
	double	mPosZ ;
	char	mName[MAX_NAME_LEN] ;

} ;

struct LoginBroadcastRequest : public PacketHeader
{
	LoginBroadcastRequest()
	{
		mSize = sizeof(LoginBroadcastRequest) ;
		mType = PKT_CS_LOGIN_BROADCAST ;
		m_PlayerId = -1;
	}

	int		m_PlayerId ;
} ;

struct LoginBroadcastResult : public PacketHeader
{
	LoginBroadcastResult()
	{
		mSize = sizeof(LoginBroadcastResult) ;
		mType = PKT_SC_LOGIN_BROADCAST ;
		m_PlayerId = -1;
	}

	int		m_PlayerId ;
} ;

#pragma pack(pop)