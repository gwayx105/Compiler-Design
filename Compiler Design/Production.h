#ifndef PRODUCTION_H
#define PRODUCTION_H
#include "Production.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <cctype>
#include <sstream> 
#include <iterator> //inserter
#include <fstream>
#include <vector>

class Production {

private:
	
	//std::string lhsProduction[63];
	//std::string rhsProduction[63];
	std::vector<std::string> nonTerminal_set;
	std::vector<std::string> terminal_set;
public:
	Production();
	void loadTerminals(std::string &);
	void loadNonTerminals(std::string &);
	void loadGrammarList(std::string &,std::string &);
	void First(std::string [],std::string[]);
	void Follow();
	friend std::istream& operator >> (std::istream& inputStream, Production &);
	friend std::ostream& operator << (std::ostream& outputStream, Production &);
};
#endif