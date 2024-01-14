#pragma once

void possessionsMenu(std::string* username, bool* check);

void showPossessions(std::fstream& possessionsFile);

void addToPossessions(std::fstream& possessionsFile);