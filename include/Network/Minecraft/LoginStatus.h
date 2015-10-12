/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* @author InusualZ
*
*
*/

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

