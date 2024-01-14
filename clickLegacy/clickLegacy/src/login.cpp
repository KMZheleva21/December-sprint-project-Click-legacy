#include "../lib/precompile.hpp"

HANDLE console_txt = GetStdHandle(STD_OUTPUT_HANDLE);

struct COLOR {
	int white = 15;
	int green = 10;
	int red = 12;
	int blue = 9;
};
COLOR color_list;

void loginMenu(std::string* username, bool* check)
{
	int numOfAction;

	std::fstream loginFile;
	loginFile.open("./files/loginInfo.txt", std::ios::in | std::ios::out | std::ios::app);
	
	if (!loginFile)
	{
		SetConsoleTextAttribute(console_txt, color_list.red);
		std::cout << "Error openinng accounts file";
		return;
	}

	SetConsoleTextAttribute(console_txt, color_list.blue);
	std::cout << "Enter the number of the action you want to select:" << std::endl;
	std::cout << "[1] Login" << std::endl;
	std::cout << "[2] Register" << std::endl;
	std::cin >> numOfAction;
	std::cout << std::endl;

	switch (numOfAction)
	{
		case 1:
			login(loginFile, username, check);
			break;
		case 2:
			register1(loginFile);
			break;
	}

	loginFile.close();
}

void login(std::fstream& loginFile, std::string* username, bool* check1)
{
	bool check = false;
	std::string loginUsername;
	std::string loginPassword;
	std::string line;
	std::string inputLine;

	system("cls");
	std::cout << "Enter username: ";
	SetConsoleTextAttribute(console_txt, color_list.white);
	std::cin >> loginUsername;
	*username = loginUsername;
	std::cout << std::endl;
	SetConsoleTextAttribute(console_txt, color_list.blue);
	std::cout << "Enter password: ";
	SetConsoleTextAttribute(console_txt, color_list.white);
	std::cin >> loginPassword;
	std::cout << std::endl;

	inputLine = loginUsername + " " + loginPassword;

	while (!loginFile.eof())
	{
		getline(loginFile, line);
		if (line == inputLine)
		{
			check = true;
			break;
		}
	}
	*check1 = check;
	if (check)
	{
		SetConsoleTextAttribute(console_txt, color_list.green);
		std::cout << "Login Successful!";
	}
	else
	{
		SetConsoleTextAttribute(console_txt, color_list.red);
		std::cout << "No account with said account details detected" << std::endl;
	}
}

void register1(std::fstream& loginFile)
{
	std::fstream possessionfile;
	std::string registerUsername;
	std::string registerPassword;

	system("cls");
	std::cout << "Please enter a Username: ";
	std::cin >> registerUsername;
	std::cout << std::endl;
	std::cout << "Please enter a Password: ";
	std::cin >> registerPassword;
	loginFile << std::endl << registerUsername + " " + registerPassword;
}