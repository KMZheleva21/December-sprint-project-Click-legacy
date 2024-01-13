#include "../lib/precompile.hpp"
void showPossessions(std::string* username, bool* check) {
	
	std::string line;
	std::fstream possessionfile;
	if (*check) {
		possessionfile.open("./files/" + *username + ".txt", std::ios::in | std::ios::out | std::ios::app);
	}
	while (!possessionfile.eof()) {
		getline(possessionfile, line);
		std::cout << line << std::endl;
	}
}
void addToPossessions() {
	std::string addPossessions;
	std::string answer;
	std::string type;
	std::cout << "Would you like to add anything to your possessions?" << std::endl;
	std::cin >> answer;
	if (answer == "yes" || answer == "Yes") {
		std::cout << "To stop adding, write stop" << std::endl;
		while (true) {
			getline(std::cin, addPossessions);
			if (addPossessions == "stop") {
				break;
			}
			else {
				
			}
		}
	}
	else {
		return;
	}
}