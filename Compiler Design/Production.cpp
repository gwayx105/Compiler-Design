#include "Production.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <cctype>
#include <sstream> 
#include <vector>
#include <iterator> //inserter
#include <fstream>
#include <map>
Production::Production() {

}

void Production::loadTerminals(std::string &temp) {
	terminal_set.push_back(temp);
}

void Production::loadNonTerminals(std::string &temp) {
	nonTerminal_set.push_back(temp);
}

void Production::loadGrammarList(std::string &lhs, std::string &rhs) {

}

void Production::First(std::string lhs[],std::string rhs[]) {
	std::vector<std::string> tempVar;
	std::string L_Holder = "";
	std::string R_Holder = "";
	std::string inner_L_Holder = "";
	std::string inner_R_Holder = "";
	//int loop = 0;
	std::map<std::string, std::string> first_map;
	std::vector <std::string>::iterator i = tempVar.begin();
	std::string temp = "";
	for (auto item :nonTerminal_set) {
		temp = item;
		L_Holder = item;
		for (int i = 0;i <= 62;i++) {
			if (lhs[i].compare(temp)==0) {
				if (std::any_of(terminal_set.begin(), terminal_set.end(), bind2nd(std::equal_to<std::string>(), rhs[i]))) {
					tempVar.push_back(rhs[i]);	
					//first_map.insert(std::pair<std::string, std::string>(lhs[i], rhs[i]));
				}
				else {
					auto it = first_map.find(rhs[i]);
					if (it != first_map.end()) {
						//first_map[rhs[i]] = it->second;
						//first_map.insert(std::pair<std::string, std::string>(rhs[i], it->second));
						tempVar.push_back(it->second);
						//std::cout << it->second<<"\n";
						//std::cout << it->first << "\n";
						//system("pause");
						//continue;
					}
					
					temp = rhs[i];
				}
				
			}
			
		}
		//std::cout << "First( " << L_Holder << " ) = { ";
		temp = "";
		for (auto n : tempVar) {
			temp += n + " ";
			//std::cout << n << " ";
		}
		first_map[L_Holder] = temp;
		temp = "";
		//std::cout << "}" << std::endl;
		tempVar.clear();
		
	}
	for (auto p : first_map) {
		std::cout << "First[" << p.first << "] = " << p.second << '\n';
	}

}

void Production::Follow() {

}
std::istream&  operator >> (std::istream& inputStream, Production &testProduction) {
	return inputStream;
}
std::ostream& operator << (std::ostream& outputStream, Production &testProduction) {
	return outputStream;
}