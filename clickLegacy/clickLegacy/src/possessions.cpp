#include "../lib/precompile.hpp"


void possessionsMenu(std::string* username, bool* check)
{
	while (true)
	{
		int action;
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "[1] Show your current possessions" << std::endl;
		std::cout << "[2] Add to your possessions" << std::endl;
		std::cout << "[3] Transfer your possessions" << std::endl << std::endl;
		std::cout << "Enter the number of the action you would like to do: ";
		std::cin >> action;

		switch (action)
		{
		case 1:
			showPossessions(username, check);
			std::cout << std::endl << std::endl;
			std::cout << "Enter '1' to close menu:" << std::endl;
			std::cin >> action;
			while (action != 1)
			{
				std::cout << "You entered a wrong action. Try again" << std::endl;
				std::cin >> action;
			}
			system("cls");
			break;
		case 2:
			addToPossessions(username, check);
			system("cls");
			break;
		case 3:
			transferPossessions(username, check);
			break;
		default:
			std::cout << "You entered a wrong action. Try again" << std::endl;
			system("cls");
		}
	}
}

void showPossessions(std::string* username, bool* check) {
	std::fstream possessionFile;
	if (*check) {
		possessionFile.open("./files/" + *username + ".txt", std::ios::in | std::ios::out | std::ios::app);
	}
	std::string line;
	int lineCounter = 1;
	while (!possessionFile.eof()) {
		getline(possessionFile, line);
		switch (lineCounter)
		{
		case 1: std::cout << "USD: "; break;
		case 2: std::cout << "BTC: "; break;
		case 3: std::cout << "ETH: "; break;
		}
		std::cout << line << std::endl;
		lineCounter++;
	}
	possessionFile.close();
}

void enterCardInformation() {
	std::string cardNumber;
	std::string date;
	std::string cvv;
	std::cout << "Enter card number:" << std::endl;
	std::cin >> cardNumber;
	std::cout << "Enter your card validity: (MM/YY)" << std::endl;
	std::cin >> date;
	std::cout << "Enter your CVV/CVC (Card Verification Value/Code):" << std::endl;
	std::cin >> cvv;
	std::cout << "Authorization..." << std::endl;
	Sleep(3000);
	std::cout << "Card successfully added" << std::endl;
}

void enterBTCInformation() {
	std::string e_mailAddress;
	std::string firstName;
	std::string lastName;
	std::string pin;
	while (true)
	{
		std::cout << "Enter your E-mail Address: " << std::endl;
		std::cin >> e_mailAddress;
		if (checkE_mail(e_mailAddress))
		{
			break;
		}
		else
		{
			std::cout << "Your E-mail doesn't meet the requirements. Please try again!";
			Sleep(3000);
			system("cls");
		}
	}
	std::cout << "Enter your First Name: " << std::endl;
	std::cin >> firstName;
	std::cout << "Enter your Last Name: " << std::endl;
	std::cin >> lastName;
	std::cout << "Enter your PIN code: " << std::endl;
	std::cin >> pin;
	std::cout << "Authorization..." << std::endl;
	Sleep(3000);
	std::cout << "Card successfully added" << std::endl;
}


void enterE_WalletInformation() {
	std::string accountNumber;
	std::cout << "Enter wallet account No. :" << std::endl;
	std::cin >> accountNumber;
	std::cout << "Authorization..." << std::endl;
	Sleep(3000);
	std::cout << "Successfully added" << std::endl;
}

void addToPossessions(std::string* username, bool* check) {
	std::fstream possessionFile;
	if (*check) {
		possessionFile.open("./files/" + *username + ".txt", std::ios::in | std::ios::out | std::ios::app);
	}
	std::string addPossessions;
	std::string type;
	while (true) {
		std::cout << "To stop adding, write 'stop'" << std::endl;
		std::cout << "Types of possessions you can add:" << std::endl;
		std::cout << "[1] Money (in USD)" << std::endl;
		std::cout << "[2] BTC" << std::endl;
		std::cout << "[3] ETH" << std::endl;
		std::cout << "Select what type of funds you would like to add: ";
		std::cin >> type;
		if (type == "stop") {
			break;
		}
		else {
			std::cout << std::endl;
			std::cout << "Input the amount you would like to add: ";
			std::cin >> addPossessions;
			std::string line;
			std::vector<std::string> tempHold;
			while (getline(possessionFile, line))
			{
				tempHold.push_back(line);
			}
			possessionFile.close();
			tempHold[stoi(type) - 1] = std::to_string(stoi(tempHold[stoi(type) - 1]) + stoi(addPossessions));
			possessionFile.open("./files/" + *username + ".txt");
			for (size_t i = 0; i < tempHold.size(); i++)
			{
				possessionFile << tempHold[i] << std::endl;
			}
			possessionFile.close();
		}
		switch (stoi(type)){
		case 1:
			enterCardInformation();
			break;
		case 2: 
			enterBTCInformation();
			break;
		case 3:
			enterE_WalletInformation();
			break;
		}
	}
}

void transferPossessions(std::string* username, bool* check)
{
	std::fstream possessionFileSend;
	std::string receiveUsername;
	if (*check) {
		possessionFileSend.open("./files/" + *username + ".txt", std::ios::in | std::ios::app);
	}
	std::cout << "Enter the person that you want to transfer to's username: ";
	std::cin >> receiveUsername;
	std::cout << std::endl;
	std::fstream loginFile;
	std::string line;
	loginFile.open("./files/loginInfo.txt");
	bool usernameCheck = false;
	while (getline(loginFile, line))
	{
		if (line.find(receiveUsername) != std::string::npos)
		{
			usernameCheck = true;
			break;
		}
	}
	loginFile.close();
	if (usernameCheck)
	{
		std::fstream possessionFileReceive;
		possessionFileReceive.open("./files/" + receiveUsername + ".txt", std::ios::in | std::ios::app);
		std::cout << "Types of possessions you can trannsfer:" << std::endl;
		std::cout << "[1] Money (in USD)" << std::endl;
		std::cout << "[2] BTC" << std::endl;
		std::cout << "[3] ETH" << std::endl;
		std::cout << "Select what type of funds you would like to transfer to " << receiveUsername << ": ";
		std::string type;
		std::string amount;
		std::cin >> type;
		std::cout << "Input the amount you would like to transfer: ";
		std::cin >> amount;
		int counter = 1;
		bool checkAmount = false;
		while (getline(possessionFileSend, line))
		{
			if (counter == stoi(type))
			{
				break;
			}
			counter++;
		}
		if (stoi(line) < stoi(amount))
		{
			std::cout << "You don't have enough funds to transfer.";
			possessionFileSend.close();
			possessionFileReceive.close();
		}
		else
		{
			std::vector<std::string> sendHold;
			std::string lineSend;
			while (!possessionFileSend.eof())
			{
				getline(possessionFileSend, lineSend);
				sendHold.push_back(lineSend);
			}
			possessionFileSend.close();
			sendHold[stoi(type) - 1] = std::to_string(stoi(sendHold[stoi(type) - 1]) - stoi(amount));
			possessionFileSend.open("./files/" + *username + ".txt", std::ios::out);
			for (size_t i = 0; i < sendHold.size(); i++)
			{
				possessionFileSend << sendHold[i] << std::endl;
			}
			possessionFileSend.close();
			std::vector<std::string> receiveHold;
			std::string lineReceive;
			while (getline(possessionFileReceive, lineReceive))
			{
				receiveHold.push_back(lineReceive);
			}
			possessionFileReceive.close();
			receiveHold[stoi(type) - 1] = std::to_string(stoi(receiveHold[stoi(type) - 1]) + stoi(amount));
			possessionFileReceive.open("./files/" + receiveUsername + ".txt", std::ios::out);
			for (size_t i = 0; i < receiveHold.size(); i++)
			{
				possessionFileReceive << receiveHold[i] << std::endl;
			}
			possessionFileReceive.close();
		}
	}
	else
	{
		std::cout << "Username not found. Please try again!";
		transferPossessions(username, check);
	}
}

bool checkE_mail(std::string e_mail)
{
	bool checkSpaces = false;
	bool checkSpecial = false;
	bool checkPoint = false;


	if (e_mail.find(' ') != std::string::npos) checkSpaces = true;

	if (e_mail.find('@') != std::string::npos) checkSpecial = true;

	if (e_mail.find('.') != std::string::npos) checkPoint = true;

	if (checkSpecial && !checkSpaces && checkPoint)
		return true;
	else
		return false;
}