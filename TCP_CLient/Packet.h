#pragma once
#include <string>
class Packet
{
	
public:
	std::string ip;
	std::string mac;
	std::string appstring;
	std::string tvappstring;
	std::string remotename;
	std::string constStr;
	char *AuthentificationPacket;
	char *DataPacket;
	int AuthSize;
	int DataSize;
	void CreateAuthPacket();
	void CreateDataPacket(std::string KeyCode);
	Packet(void);
	~Packet(void);
};

