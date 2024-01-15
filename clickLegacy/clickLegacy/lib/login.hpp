#pragma once

void loginMenu(std::string* username, bool* check, bool* checkClose);

void login(std::fstream& loginFile, std::string* username, bool* check, bool* checkClose);

void register1(std::fstream& loginFile, std::string* username, bool* check, bool* checkClose);

bool checkPassword(std::string password);