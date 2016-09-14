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

Production::Production() {

}

void Production::loadTerminals() {

}

void Production::loadNonTerminals() {

}

void Production::loadGrammarList() {

}

void Production::First() {
	
}

void Production::Follow() {

}
std::istream&  operator >> (std::istream& inputStream, Production &testProduction) {
	return inputStream;
}
std::ostream& operator << (std::ostream& outputStream, Production &testProduction) {
	return outputStream;
}