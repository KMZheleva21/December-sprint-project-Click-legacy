#include "../lib/precompile.hpp"

void loginMenu()
{
	int numOfAction;

	std::fstream loginFile;
	loginFile.open("./files/loginInfo.txt", std::ios::in | std::ios::out);
	
	if (!loginFile)
	{
		std::cout << "Error openinng accounts file";
		return;
	}

	std::cout << "Enter the number of the action you want to select:" << std::endl;
	std::cout << "1.Login" << std::endl;
	std::cout << "2.Register" << std::endl;
	std::cin >> numOfAction;
	std::cout << std::endl;

	switch (numOfAction)
	{
		case 1:
			login(loginFile);
			break;
		case 2:
			register1(loginFile);
			break;
	}

	loginFile.close();
}

void login(std::fstream& loginFile)
{
	bool check = false;
	std::string loginUsername;
	std::string loginPassword;
	std::string line;
	std::string inputLine;

	std::cout << "Enter username: ";
	getline(std::cin, loginUsername);
	std::cin.ignore();
	std::cout << std::endl;
	std::cout << "Enter password: ";
	std::cin >> loginPassword;
	std::cin.ignore();
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
	if (check)
	{
		std::cout << "Login Successful!";
	}
	else
	{
		std::cout << "No account with said account details detected. Please check for any mistakes and try again!";
	}
}

void register1(std::fstream& loginFile)
{
	std::string registerUsername;
	std::string registerPassword;

	std::cout << "Please enter a Username: ";
	std::cin >> registerUsername;
	std::cin.ignore();
	std::cout << std::endl;
	std::cout << "Please enter a Password: ";
	std::cin >> registerPassword;
	std::cin.ignore();

	loginFile << registerUsername + " " + registerPassword;
}