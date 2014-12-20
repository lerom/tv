#include "stdafx.h"
#include "Packet.h"
#include "base64.h"


Packet::Packet(void)
{
	//аутентификаци€
	/*std::string ip = "192.168.0.102";
	std::string mac = "00-22-41-78-5F-0F";
	std::string appstring = "iphone..iapp.samsung";
	std::string tvappstring = "iphone.UE32C4300.iapp.samsung";
	std::string remotename = "iiiiiiiiRemoteControlNax";*/
	ip = "192.168.0.102";
	mac = "00-22-41-78-5F-0F";
	appstring = "iphone..iapp.samsung";
	tvappstring = "iphone.UE32C4300.iapp.samsung";
	remotename = "iiiiiiiiRemoteControlNax";
	constStr = "iphone.UE32C6700.iapp.samsung";
	Packet::CreateAuthPacket();	
	//формируем пакет команды

}

void Packet::CreateAuthPacket()
{
	std::string ipBase64 = base64_encode(reinterpret_cast<const unsigned char*>(ip.c_str()), ip.length());
	std::string macBase64 = base64_encode(reinterpret_cast<const unsigned char*>(mac.c_str()), mac.length());
	std::string remotenameBase64 = base64_encode(reinterpret_cast<const unsigned char*>(remotename.c_str()), remotename.length());

	int payloadLength = ipBase64.length() + macBase64.length() + remotenameBase64.length() + 8;
	AuthSize = payloadLength + appstring.length() + 5;

	AuthentificationPacket = new char [AuthSize];

	
	//формируем пакет аутентификации
	AuthentificationPacket[0] = 0x00;
	AuthentificationPacket[1] = appstring.length();
	AuthentificationPacket[2] = appstring.length()>>8;
	for(int i = 0; i < appstring.length(); i++)
	{
		AuthentificationPacket[3+i] = appstring[i];
	}
	int currentNumber = appstring.length() + 2; // показывает последнюю заполненную €чейку в пакете

	AuthentificationPacket[currentNumber+1] = payloadLength;
	AuthentificationPacket[currentNumber+2] = payloadLength>>8;
	AuthentificationPacket[currentNumber+3] = 0x64;
	AuthentificationPacket[currentNumber+4] = 0x00;

	AuthentificationPacket[currentNumber+5] = ipBase64.length();
	AuthentificationPacket[currentNumber+6] = ipBase64.length()>>8;
	currentNumber = currentNumber + 7;
	for(int i = 0; i < ipBase64.length(); i++)
	{
		AuthentificationPacket[currentNumber+i] = ipBase64[i];
	}
	currentNumber = currentNumber + ipBase64.length();

	AuthentificationPacket[currentNumber] = macBase64.length();
	AuthentificationPacket[currentNumber+1] = macBase64.length()>>8;
	for(int i = 0; i < macBase64.length(); i++)
	{
		AuthentificationPacket[currentNumber+2+i] = macBase64[i];
	}
	currentNumber = 2 + currentNumber + macBase64.length();

	AuthentificationPacket[currentNumber] = remotenameBase64.length();
	AuthentificationPacket[currentNumber+1] = remotenameBase64.length()>>8;
	for(int i = 0; i < remotenameBase64.length(); i++)
	{
		AuthentificationPacket[currentNumber+2+i] = remotenameBase64[i];
	}
	currentNumber = 2 + currentNumber + remotenameBase64.length();
}

void Packet::CreateDataPacket(std::string KeyCode)
{
	//std::string constStrBase64 = base64_encode(reinterpret_cast<const unsigned char*>(constStr.c_str()), constStr.length());
	std::string constStrBase64 = constStr;
	std::string KeyCodeBase64 = base64_encode(reinterpret_cast<const unsigned char*>(KeyCode.c_str()), KeyCode.length());

	int payloadLength = KeyCodeBase64.length() + 5;
	DataSize = payloadLength + constStrBase64.length() + 5;

	DataPacket = new char [DataSize];
	
	//формируем пакет аутентификации
	DataPacket[0] = 0x00;
	DataPacket[1] = constStrBase64.length();
	DataPacket[2] = constStrBase64.length()>>8;
	for(int i = 0; i < constStrBase64.length(); i++)
	{
		DataPacket[3+i] = constStrBase64[i];
	}
	int currentNumber = constStrBase64.length() + 2; // показывает последнюю заполненную €чейку в пакете

	DataPacket[currentNumber+1] = payloadLength;
	DataPacket[currentNumber+2] = payloadLength>>8;
	DataPacket[currentNumber+3] = 0x00;
	DataPacket[currentNumber+4] = 0x00;
	DataPacket[currentNumber+5] = 0x00;

	DataPacket[currentNumber+6] = KeyCodeBase64.length();
	DataPacket[currentNumber+7] = KeyCodeBase64.length()>>8;
	currentNumber = currentNumber + 8;
	for(int i = 0; i < KeyCodeBase64.length(); i++)
	{
		DataPacket[currentNumber+i] = KeyCodeBase64[i];
	}
	currentNumber = currentNumber + KeyCodeBase64.length();
}

Packet::~Packet(void)
{
}




