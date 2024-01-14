#include "../lib/precompile.hpp"

void possessionsMenu(std::string* username, bool* check)
{
	std::fstream possessionFile;
	if (*check) {
		possessionFile.open("./files/" + *username + ".txt", std::ios::in | std::ios::out | std::ios::app);
	}

	
	while (true)
	{
		int action;
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "[1] Show your current possessions" << std::endl;
		std::cout << "[2] Add to your possessions" << std::endl << std::endl;
		std::cout << "Enter the number of the action you would like to do: ";
		std::cin >> action;

		switch (action)
		{
		case 1:
			showPossessions(possessionFile);
			std::cout << std::endl << std::endl;
			break;
		case 2:
			addToPossessions(possessionFile);
			system("cls");
			break;
		default:
			std::cout << "You entered a wrong action. Try again" << std::endl;
			system("cls");
		}
	}
	possessionFile.close();
}

void showPossessions(std::fstream& possessionFile) {
	
	std::string line;
	while (!possessionFile.eof()) {
		getline(possessionFile, line);
		std::cout << line << std::endl;
	}
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

void enterE_WalletInformation() {
	std::string accountNumber;
	std::cout << "Enter wallet account No. :" << std::endl;
	std::cin >> accountNumber;
	std::cout << "Authorization..." << std::endl;
	Sleep(3000);
	std::cout << "Successfully added" << std::endl;
}

void addToPossessions(std::fstream& possessionFile) {
	std::string addPossessions;
	std::string type;
	std::string currentLineContents;
	while (true) {
		std::cout << "To stop adding, write 'stop' on either on of the spaces" << std::endl;
		std::cout << "Types of possessions you can add:" << std::endl;
		std::cout << "[1] Money (in USD)" << std::endl;
		std::cout << "[2] BTC" << std::endl;
		std::cout << "[3] ETH" << std::endl;
		std::cout << "Select what type of funds you would like to add: ";
		std::cin >> type;
		switch (stoi(type)){
		case 1:
			enterCardInformation();
		case 2:
			enterE_WalletInformation();
		}
		std::cout << std::endl;
		std::cout << "Input the amount you would like to add: ";
		std::cin >> addPossessions;
		if (addPossessions == "stop" || type == "stop") {
			break;
		}
		else {
			int lineCounter = 1;
			while (true)
			{
				if (lineCounter == stoi(type))
				{
					possessionFile >> currentLineContents;
					currentLineContents = std::to_string(stof(currentLineContents) + stof(addPossessions));
					possessionFile << currentLineContents;
					break;
				}
				lineCounter++;
			}
			system("cls");
		}
	}
}