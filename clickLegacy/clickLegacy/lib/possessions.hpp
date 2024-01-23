#pragma once

void possessionsMenu(std::string* username, bool* check);

void showPossessions(std::fstream& possessionsFile);

void addToPossessions(std::fstream& possessionFile);

void transferPossessions(std::fstream& possessionFile);

void enterCardInformation();

void enterBTCInformation();

void enterE_WalletInformation();

bool checkE_mail(std::string e_mail);