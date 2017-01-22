#include"Game.h"
#include<iostream>

#include"JSON.h"
#include"JSONValue.h"
#include"SFML\Network.hpp"

int main() 
{
	srand(time(NULL));

	/*
	Game game; // Create game instance 
	game.run(); // Run the game loop
	*/

	char* stringToSend[] = { "\"mieeh\"300" };

	sf::IpAddress ip("127.0.0.1");
	sf::UdpSocket socket;
	sf::Packet packet;

	JSONObject data;

	data[L"action"] = new JSONValue(L"AddScore");
	data[L"name"] = new JSONValue(std::wstring(stringToSend[1], stringToSend[1] + strlen(stringToSend[1])));
	data[L"score"] = new JSONValue(atof(stringToSend[2]));

	JSONValue *val = new JSONValue(data);
	data.clear();

	std::wstring dataString = val->Stringify();
	delete val;

	std::string notSoWide;
	notSoWide.assign(dataString.begin(), dataString.end());

	packet.append(notSoWide.c_str(), notSoWide.length());

	unsigned short port = 1000;

	if (!socket.send(packet, ip, port) != sf::Socket::Done) {
		std::cout << "Error sending packet to server" << std::endl;
	}

	socket.unbind();

	system("pause>null");
	return 0;
}