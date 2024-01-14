#include "../lib/precompile.hpp"

void possessionsMenu(std::string* username, bool* check)
{
	std::fstream possessionFile;
	if (*check) {
		possessionFile.open("./files/" + *username + ".txt", std::ios::in | std::ios::out | std::ios::app);
	}

	int action;
	while (true)
	{
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