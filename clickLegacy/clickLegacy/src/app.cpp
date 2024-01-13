#include "../lib/precompile.hpp"

app::app()
{
	std::string* username = new std::string;
	loginMenu(username);
	showPossessions(username);
}