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

class Production {

private:
	std::set<std::string> grammar_set;
	std::set<std::string> nonTerminal_set;
	std::set<std::string> terminal_set;
public:
	Production();
	void loadTerminals();
	void loadNonTerminals();
	void loadGrammarList();
	void First();
	void Follow();
	friend std::istream& operator >> (std::istream& inputStream, Production &);
	friend std::ostream& operator << (std::ostream& outputStream, Production &);
};
#endif