#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>
#include "Production.h"

int main(int argc, char* argv[]) {
	Production testProduction;
	std::ifstream inFile,inFileTerminals,inFileNonTerminals,inFileGrammarList;
	std::string fileName = "";
	std::cout << "Please enter the document you want to query : ";
	std::getline(std::cin, fileName);
	inFileTerminals.open("terminalList.txt");
	inFileNonTerminals.open("nonTerminalList.txt");
	inFileGrammarList.open("GrammarList.txt");
	inFile.open(fileName);
	if (inFile.fail()|| inFileTerminals.fail()|| inFileNonTerminals.fail()|| inFileGrammarList.fail()) {
		std::cerr << "\n\nNo such file found!!!\n";
		
		//system("pause");
		return 0;
	}

	std::cout << "\n\n----------------First------------------------\n";
	testProduction.First();
	

	return 0;
}