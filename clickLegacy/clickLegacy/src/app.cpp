#include "../lib/precompile.hpp"

void app()
{
	bool* checkClose = new bool;
	bool* check = new bool;
	*checkClose = false;
	std::string* username = new std::string;
	loginMenu(username, check, checkClose);
	if (!checkClose)
		return;
	else possessionsMenu(username, check);
	delete checkClose;
	delete check;
	delete username;
}