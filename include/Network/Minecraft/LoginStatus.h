#ifndef LOGIN_STATUS_H_
#define LOGIN_STATUS_H_

#include "DataPacket.h"

class LoginStatus : public DataPacket
{
public:
	int status;

public:
	LoginStatus(int status);
	void encode();
	void decode();
};
#endif

