#pragma once

void loginMenu(std::string* username, bool* check);

void login(std::fstream& loginFile, std::string* username, bool* check);

void register1(std::fstream& loginFile);
