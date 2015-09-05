#ifndef LOGIN_STATUS_H_
#define LOGIN_STATUS_H_

#include <RakLib\Packets\DataPacket.h>

class LoginStatus : public RakLib::DataPacket
{
public:
	int status;

public:
	LoginStatus(int status);
	void encode() override;

};
#endif

