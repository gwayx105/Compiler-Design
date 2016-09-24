#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>
#include "Production.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iterator>
/*
	Author :	Sylvester Zowonu
Description:	Producing the First and Follow of a given grammar

*/

int main(int argc, char* argv[]) {
	Production testProduction;
	std::ifstream inFile,inFileTerminals,inFileNonTerminals,inFileGrammarList;
	std::string fileName = "";
	std::string lhsGrammarList[63];
	std::string rhsGrammarList[63];
	//std::cout << "Please enter input file : ";
	//std::getline(std::cin, fileName);
	inFileTerminals.open("terminalList.txt");
	inFileNonTerminals.open("nonTerminalList.txt");
	inFileGrammarList.open("GrammarList.txt");
	//inFile.open(fileName);
	if (inFileTerminals.fail()|| inFileNonTerminals.fail()|| inFileGrammarList.fail()) {
		std::cerr << "\n\nNo such file found!!!\n";
		
		//system("pause");
		return 0;
	}
	int i = 0;
	std::string rhs="", lhs="",delim="";
	//reading grammar into array
	for (std::string line; std::getline(inFileGrammarList, line); )
	{
		
		//std::cout << line;		
		std::stringstream ss(line);
		//ss >> std::noskipws;
		ss >> lhs >> delim >> rhs;
		lhsGrammarList[i] = lhs;
		rhsGrammarList[i] = rhs;
		std::cout << lhs << " -> " << rhs<<std::endl;	
		i += 1;
		
		
	}
	std::cout << "Total: " << i << std::endl;
	//reading terminals into array
	std::string terms="";
	//std::cout << "Terminals" << std::endl;
	for (std::string line; std::getline(inFileTerminals, line); ) {
		std::stringstream ss(line);
		ss >> terms;
		testProduction.loadTerminals(terms);		
		//std::cout << terms << std::endl;
	
	}
	//reading non terminals into array
	std::string nonTerms = "";
	//std::cout << "Non Terminals" << std::endl;
	for (std::string line; std::getline(inFileNonTerminals, line); ) {
		std::stringstream ss(line);
		ss >> nonTerms;
		testProduction.loadNonTerminals(nonTerms);		
		//std::cout << nonTerms << std::endl;
	}
	std::cout << "\n\n----------------First------------------------\n";
	testProduction.First(lhsGrammarList, rhsGrammarList);
	inFileNonTerminals.close();
	inFileTerminals.close();
	inFileGrammarList.close();
	inFile.close();
	return 0;
}