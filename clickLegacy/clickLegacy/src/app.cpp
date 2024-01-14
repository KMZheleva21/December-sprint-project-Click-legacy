#include "../lib/precompile.hpp"

void app()
{
	bool* check = new bool;
	std::string* username = new std::string;
	loginMenu(username, check);
	possessionsMenu(username, check);
}