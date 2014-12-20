// TCP_CLient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "base64.h"
#include "Packet.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

enum { max_length = 1024 };
std::string allKeys[248] = {
        "KEY_0",
        "KEY_1",
        "KEY_2",
        "KEY_3",
        "KEY_4",
        "KEY_5",
        "KEY_6",
        "KEY_7",
        "KEY_8",
        "KEY_9",
        "KEY_11",
        "KEY_12",
        "KEY_3SPEED",
        "KEY_4_3",
        "KEY_16_9",
        "KEY_AD",
        "KEY_ADDDEL",
        "KEY_ALT_MHP",
        "KEY_ANGLE",
        "KEY_ANTENA",
        "KEY_ANYNET",
        "KEY_ANYVIEW",
        "KEY_APP_LIST",
        "KEY_ASPECT",
        "KEY_AUTO_ARC_ANTENNA_AIR",
        "KEY_AUTO_ARC_ANTENNA_CABLE",
        "KEY_AUTO_ARC_ANTENNA_SATELLITE",
        "KEY_AUTO_ARC_ANYNET_AUTO_START",
        "KEY_AUTO_ARC_ANYNET_MODE_OK",
        "KEY_AUTO_ARC_AUTOCOLOR_FAIL",
        "KEY_AUTO_ARC_AUTOCOLOR_SUCCESS",
        "KEY_AUTO_ARC_CAPTION_ENG",
        "KEY_AUTO_ARC_CAPTION_KOR",
        "KEY_AUTO_ARC_CAPTION_OFF",
        "KEY_AUTO_ARC_CAPTION_ON",
        "KEY_AUTO_ARC_C_FORCE_AGING",
        "KEY_AUTO_ARC_JACK_IDENT",
        "KEY_AUTO_ARC_LNA_OFF",
        "KEY_AUTO_ARC_LNA_ON",
        "KEY_AUTO_ARC_PIP_CH_CHANGE",
        "KEY_AUTO_ARC_PIP_DOUBLE",
        "KEY_AUTO_ARC_PIP_LARGE",
        "KEY_AUTO_ARC_PIP_LEFT_BOTTOM",
        "KEY_AUTO_ARC_PIP_LEFT_TOP",
        "KEY_AUTO_ARC_PIP_RIGHT_BOTTOM",
        "KEY_AUTO_ARC_PIP_RIGHT_TOP",
        "KEY_AUTO_ARC_PIP_SMALL",
        "KEY_AUTO_ARC_PIP_SOURCE_CHANGE",
        "KEY_AUTO_ARC_PIP_WIDE",
        "KEY_AUTO_ARC_RESET",
        "KEY_AUTO_ARC_USBJACK_INSPECT",
        "KEY_AUTO_FORMAT",
        "KEY_AUTO_PROGRAM",
        "KEY_AV1",
        "KEY_AV2",
        "KEY_AV3",
        "KEY_BACK_MHP",
        "KEY_BOOKMARK",
        "KEY_CALLER_ID",
        "KEY_CAPTION",
        "KEY_CATV_MODE",
        "KEY_CHDOWN",
        "KEY_CHUP",
        "KEY_CH_LIST",
        "KEY_CLEAR",
        "KEY_CLOCK_DISPLAY",
        "KEY_COMPONENT1",
        "KEY_COMPONENT2",
        "KEY_CONTENTS",
        "KEY_CONVERGENCE",
        "KEY_CONVERT_AUDIO_MAINSUB",
        "KEY_CUSTOM",
        "KEY_CYAN",
        "KEY_DEVICE_CONNECT",
        "KEY_DISC_MENU",
        "KEY_DMA",
        "KEY_DNET",
        "KEY_DNIe",
        "KEY_DNSe",
        "KEY_DOOR",
        "KEY_DOWN",
        "KEY_DSS_MODE",
        "KEY_DTV",
        "KEY_DTV_LINK",
        "KEY_DTV_SIGNAL",
        "KEY_DVD_MODE",
        "KEY_DVI",
        "KEY_DVR",
        "KEY_DVR_MENU",
        "KEY_DYNAMIC",
        "KEY_ENTER",
        "KEY_ENTERTAINMENT",
        "KEY_ESAVING",
        "KEY_EXIT",
        "KEY_EXT1",
        "KEY_EXT2",
        "KEY_EXT3",
        "KEY_EXT4",
        "KEY_EXT5",
        "KEY_EXT6",
        "KEY_EXT7",
        "KEY_EXT8",
        "KEY_EXT9",
        "KEY_EXT10",
        "KEY_EXT11",
        "KEY_EXT12",
        "KEY_EXT13",
        "KEY_EXT14",
        "KEY_EXT15",
        "KEY_EXT16",
        "KEY_EXT17",
        "KEY_EXT18",
        "KEY_EXT19",
        "KEY_EXT20",
        "KEY_EXT21",
        "KEY_EXT22",
        "KEY_EXT23",
        "KEY_EXT24",
        "KEY_EXT25",
        "KEY_EXT26",
        "KEY_EXT27",
        "KEY_EXT28",
        "KEY_EXT29",
        "KEY_EXT30",
        "KEY_EXT31",
        "KEY_EXT32",
        "KEY_EXT33",
        "KEY_EXT34",
        "KEY_EXT35",
        "KEY_EXT36",
        "KEY_EXT37",
        "KEY_EXT38",
        "KEY_EXT39",
        "KEY_EXT40",
        "KEY_EXT41",
        "KEY_FACTORY",
        "KEY_FAVCH",
        "KEY_FF",
        "KEY_FF_",
        "KEY_FM_RADIO",
        "KEY_GAME",
        "KEY_GREEN",
        "KEY_GUIDE",
        "KEY_HDMI",
        "KEY_HDMI1",
        "KEY_HDMI2",
        "KEY_HDMI3",
        "KEY_HDMI4",
        "KEY_HELP",
        "KEY_HOME",
        "KEY_ID_INPUT",
        "KEY_ID_SETUP",
        "KEY_INFO",
        "KEY_INSTANT_REPLAY",
        "KEY_LEFT",
        "KEY_LINK",
        "KEY_LIVE",
        "KEY_MAGIC_BRIGHT",
        "KEY_MAGIC_CHANNEL",
        "KEY_MDC",
        "KEY_MENU",
        "KEY_MIC",
        "KEY_MORE",
        "KEY_MOVIE1",
        "KEY_MS",
        "KEY_MTS",
        "KEY_MUTE",
        "KEY_NINE_SEPERATE",
        "KEY_OPEN",
        "KEY_PANNEL_CHDOWN",
        "KEY_PANNEL_CHUP",
        "KEY_PANNEL_ENTER",
        "KEY_PANNEL_MENU",
        "KEY_PANNEL_POWER",
        "KEY_PANNEL_SOURCE",
        "KEY_PANNEL_VOLDOW",
        "KEY_PANNEL_VOLUP",
        "KEY_PANORAMA",
        "KEY_PAUSE",
        "KEY_PCMODE",
        "KEY_PERPECT_FOCUS",
        "KEY_PICTURE_SIZE",
        "KEY_PIP_CHDOWN",
        "KEY_PIP_CHUP",
        "KEY_PIP_ONOFF",
        "KEY_PIP_SCAN",
        "KEY_PIP_SIZE",
        "KEY_PIP_SWAP",
        "KEY_PLAY",
        "KEY_PLUS100",
        "KEY_PMODE",
        "KEY_POWER",
        "KEY_POWEROFF",
        "KEY_POWERON",
        "KEY_PRECH",
        "KEY_PRINT",
        "KEY_PROGRAM",
        "KEY_QUICK_REPLAY",
        "KEY_REC",
        "KEY_RED",
        "KEY_REPEAT",
        "KEY_RESERVED1",
        "KEY_RETURN",
        "KEY_REWIND",
        "KEY_REWIND_",
        "KEY_RIGHT",
        "KEY_RSS",
        "KEY_RSURF",
        "KEY_SCALE",
        "KEY_SEFFECT",
        "KEY_SETUP_CLOCK_TIMER",
        "KEY_SLEEP",
        "KEY_SOUND_MODE",
        "KEY_SOURCE",
        "KEY_SRS",
        "KEY_STANDARD",
        "KEY_STB_MODE",
        "KEY_STILL_PICTURE",
        "KEY_STOP",
        "KEY_SUB_TITLE",
        "KEY_SVIDEO1",
        "KEY_SVIDEO2",
        "KEY_SVIDEO3",
        "KEY_TOOLS",
        "KEY_TOPMENU",
        "KEY_TTX_MIX",
        "KEY_TTX_SUBFACE",
        "KEY_TURBO",
        "KEY_TV",
        "KEY_TV_MODE",
        "KEY_UP",
        "KEY_VCHIP",
        "KEY_VCR_MODE",
        "KEY_VOLDOWN",
        "KEY_VOLUP",
        "KEY_WHEEL_LEFT",
        "KEY_WHEEL_RIGHT",
        "KEY_W_LINK",
        "KEY_YELLOW",
        "KEY_ZOOM1",
        "KEY_ZOOM2",
        "KEY_ZOOM_IN",
        "KEY_ZOOM_MOVE",
        "KEY_ZOOM_OUT"
    };
    // всего 248 кодов

int main(int argc, char* argv[])
{
  try
  {
    /*if (argc != 3)
    {
      std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
	  system("pause");
      return 1;
    }*/

	  argc = 3;
	  argv[1] = "192.168.5.1";
	  argv[2] = "55000";


    boost::asio::io_service io_service;

    tcp::resolver resolver(io_service);
    tcp::resolver::query query(tcp::v4(), argv[1], argv[2]);
    tcp::resolver::iterator iterator = resolver.resolve(query);

    tcp::socket s(io_service);
    boost::asio::connect(s, iterator);
	int Mes = 0;
	while (Mes<249)
	{
		using namespace std;
		std::cout << "Enter message: ";
		cin>>Mes;
	Packet P;
	P.CreateDataPacket(allKeys[Mes]);
	boost::asio::write(s, boost::asio::buffer(P.AuthentificationPacket, P.AuthSize));
	char reply[max_length];
    boost::asio::read(s, boost::asio::buffer(reply, 21));
	boost::asio::write(s, boost::asio::buffer(P.DataPacket,P.DataSize));
	//boost::asio::read(s, boost::asio::buffer(reply, 21));
	}

	/*boost::asio::write(s, boost::asio::buffer(Auth,109));
	char reply[max_length];
    boost::asio::read(s, boost::asio::buffer(reply, 21));
	boost::asio::write(s, boost::asio::buffer(Menu,51));*/


	
    //using namespace std; // For strlen.
    //std::cout << "Enter message: ";
    //char request[max_length];
    //std::cin.getline(request, max_length);
    //size_t request_length = strlen(request);
    //boost::asio::write(s, boost::asio::buffer(request, request_length));

    //char reply[max_length];
    //size_t reply_length = boost::asio::read(s,
    //    boost::asio::buffer(reply, request_length));
    //std::cout << "Reply is: ";
    //std::cout.write(reply, reply_length);
    //std::cout << "\n";
	/*char Auth [109] = {0x0,0x14,0x0,0x69,0x70,0x68,0x6f,0x6e,0x65,0x2e,0x2e,0x69,0x61,0x70,0x70,
		0x2e,0x73,0x61,0x6d,0x73,0x75,0x6e,0x67,0x54,0x0,0x64,0x0,0x14,0x0,0x4d,0x54,0x6b,0x79,
		0x4c,0x6a,0x45,0x32,0x4f,0x43,0x34,0x77,0x4c,0x6a,0x45,0x77,0x4d,0x67,0x3d,0x3d,0x18,
		0x0,0x4d,0x44,0x41,0x74,0x4d,0x6a,0x49,0x74,0x4e,0x44,0x45,0x74,0x4e,0x7a,0x67,0x74,
		0x4e,0x55,0x59,0x74,0x4d,0x45,0x59,0x3d,0x20,0x0,0x61,0x57,0x6c,0x70,0x61,0x57,0x6c,
		0x70,0x61,0x57,0x6c,0x53,0x5a,0x57,0x31,0x76,0x64,0x47,0x56,0x44,0x62,0x32,0x35,0x30,
		0x63,0x6d,0x39,0x73,0x54,0x6d,0x46,0x34};

	char Menu [51] = {0x0,0x1d,0x0,0x69,0x70,0x68,0x6f,0x6e,0x65,0x2e,0x55,0x45,0x33,0x32,0x43,
		0x36,0x37,0x30,0x30,0x2e,0x69,0x61,0x70,0x70,0x2e,0x73,0x61,0x6d,0x73,0x75,0x6e,0x67,
		0x11,0x0,0x0,0x0,0x0,0xc,0x0,0x53,0x30,0x56,0x5a,0x58,0x30,0x31,0x46,0x54,0x6c,0x55,0x3d};*/
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }
  system("pause");
  return 0;
}

