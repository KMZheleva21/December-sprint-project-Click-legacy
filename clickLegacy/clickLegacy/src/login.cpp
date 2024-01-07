#include "../lib/precompile.hpp"

void loginMenu()
{
	int numOfAction;

	std::cout << "Enter the number of the action you want to select:" << std::endl;
	std::cout << "1.Login" << std::endl;
	std::cout << "2.Register" << std::endl;
	std::cin >> numOfAction;
	std::cout << std::endl;

	switch (numOfAction)
	{
		case 1:
			login();
			break;
	}

}

void login()
{
	bool check = false;
	std::string loginUsername;
	std::string loginPassword;
	std::string line;

	std::cout << "Enter username:";
	getline(std::cin, loginUsername);
	std::cout << std::endl;
	std::cout << "Enter password:";
	getline(std::cin, loginPassword);
	std::cout << std::endl;

	std::fstream loginFile;
	loginFile.open("./files/loginInfo.txt");


	while (!loginFile.eof())
	{
		getline(loginFile, line);
		if (line == (loginUsername + " " + loginPassword))
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
		std::cout << "Login Failed. Please try again!";
	}
}