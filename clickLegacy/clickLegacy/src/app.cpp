#include "../lib/precompile.hpp"

app::app()
{
	bool* check = new bool;
	std::string* username = new std::string;
	loginMenu(username, check);
	showPossessions(username, check);
}