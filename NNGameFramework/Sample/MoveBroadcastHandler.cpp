
#include "PacketHandler.h"
#include <stdio.h>
#include <windows.h>
#include <assert.h>

MoveBroadcastHandler::MoveBroadcastHandler()
{

}
MoveBroadcastHandler::~MoveBroadcastHandler()
{

}
void MoveBroadcastHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_MOVE:
		{
			if ( circularBuffer->Read((char*)&m_MoveBroadcastResultPacket, header->m_Size) )
			{
				assert( m_MoveBroadcastResultPacket.m_PlayerId != -1  ) ;
			}
			else
			{
				assert(false) ;
			}
		}
	}
}
