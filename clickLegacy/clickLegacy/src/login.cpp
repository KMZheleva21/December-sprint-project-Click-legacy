#include "../lib/precompile.hpp"

HANDLE console_txt = GetStdHandle(STD_OUTPUT_HANDLE);
struct COLOR {
	int white = 15;
	int green = 10;
	int red = 12;
	int blue = 9;
};
COLOR color_list;

void loginMenu(std::string* username, bool* check, bool* checkClose)
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
	
	std::cout << "  /$$$$$$  /$$       /$$$$$$  /$$$$$$  /$$   /$$       /$$       /$$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$  /$$     /$$ " << std::endl;
	std::cout << " /$$__  $$| $$      |_  $$_/ /$$__  $$| $$  /$$/      | $$      | $$_____/ /$$__  $$ /$$__  $$ /$$__  $$|  $$   /$$/ " << std::endl;
	std::cout << "| $$  |__/| $$        | $$  | $$  |__/| $$ /$$/       | $$      | $$      | $$  |__/| $$  | $$| $$  |__/ |  $$ /$$/  " << std::endl;
	std::cout << "| $$      | $$        | $$  | $$      | $$$$$/        | $$      | $$$$$   | $$ /$$$$| $$$$$$$$| $$        |  $$$$/   " << std::endl;
	std::cout << "| $$      | $$        | $$  | $$      | $$  $$        | $$      | $$__/   | $$|_  $$| $$__  $$| $$         |  $$/    " << std::endl;
	std::cout << "| $$    $$| $$        | $$  | $$    $$| $$|  $$       | $$      | $$      | $$  | $$| $$  | $$| $$    $$    | $$     " << std::endl;
	std::cout << "|  $$$$$$/| $$$$$$$$ /$$$$$$|  $$$$$$/| $$ |  $$      | $$$$$$$$| $$$$$$$$|  $$$$$$/| $$  | $$|  $$$$$$/    | $$     " << std::endl;
	std::cout << " |______/ |________/|______/ |______/ |__/  |__/      |________/|________/ |______/ |__/  |__/ |______/     |__/     " << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the number of the action you want to select:" << std::endl;
	std::cout << "[1] Login" << std::endl;
	std::cout << "[2] Register" << std::endl;
	std::cout << "[3] Exit" << std::endl;

	std::cin >> numOfAction;
	std::cout << std::endl;

	switch (numOfAction)
	{
		case 1:
			login(loginFile, username, check, checkClose);
			break;
		case 2:
			register1(loginFile, username, check, checkClose);
			break;
		case 3:
			std::exit(0);
	}

	loginFile.close();
}

void login(std::fstream& loginFile, std::string* username, bool* check1, bool* checkClose)
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
		std::string answer;
		SetConsoleTextAttribute(console_txt, color_list.red);
		std::cout << "No account with said account details detected. Would you like to register? (Yes/No)" << std::endl;
		std::cin >> answer;
		if (answer == "Yes")
		{
			register1(loginFile, username, check1, checkClose);
		}
		else
		{
			system("cls");
			loginMenu(username, check1, checkClose);
		}
	}
}

void register1(std::fstream& loginFile, std::string* username, bool* check, bool* checkClose)
{
	std::string registerUsername;
	std::string registerPassword;

	system("cls");
	std::cout << "Please enter a Username: " << std::endl;
	std::cout << "[*]The username must not contain any spaces or special characters" << std::endl;
	std::cin >> registerUsername;
	std::cout << std::endl;
	while (true)
	{
		std::cout << "Please enter a Password: " << std::endl;
		std::cout << "[*] The password must be between 6 and 16 characters long." << std::endl;
		std::cout << "[*] The password must not contain any spaces." << std::endl;
		std::cout << "[*] The password must have at least 1 upper-case character" << std::endl;
		std::cout << "[*] The password must have at least 1 special character" << std::endl;
		std::cout << "[*] The password must have at least 1 number" << std::endl;
		std::cin >> registerPassword;
		if (checkPassword(registerPassword))
		{
			break;
		}
		else
		{
			std::cout << "Your password doesn't meet the requirements. Please try again!";
			Sleep(3000);
			system("cls");
		}
	}
	bool checkFind = false;
	while (!loginFile.eof())
	{
		std::string line;
		getline(loginFile, line);
		if(line.find(registerUsername))
		{
			checkFind = true;
			break;
		}

	}
	if (!checkFind)
	{
		loginFile << std::endl << registerUsername + " " + registerPassword;
	}
	else
	{
		std::string answer;
		std::cout << std::endl << "An account with said username already exists. Would you like to log-in into this account? (Yes/No)" << std::endl;
		std::cin >> answer;
		if (answer == "Yes")
		{
			login(loginFile, username, check, checkClose);
		}
		else
		{
			*checkClose = true;
			return;
		}
	}
}

bool checkPassword(std::string password)
{
	bool checkSize = false;
	bool checkSpaces = false;
	bool checkUpper = false;
	bool checkSpecial = false;
	bool checkNumber = false;

	if (password.size() >= 6 && password.size() <= 16) checkSize = true;

	if (password.find(' ') != std::string::npos) checkSpaces = true;

	for (int i = 0; i < password.size(); i++)
	{
		if (password[i] >= 65 && password[i] <= 90) checkUpper = true;
		if (password[i] >= 48 && password[i] <= 57) checkNumber = true;
		if (!(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 48 && password[i] <= 57) && !(password[i] >= 97 && password[i] <= 122)) checkSpecial = true;
	}

	if (checkSize && checkUpper && checkNumber && checkSpecial && !checkSpaces)
		return true;
	else
		return false;
}