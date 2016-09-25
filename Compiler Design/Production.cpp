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
	//::string R_Holder = "";

	std::map<std::string, std::string> first_map;
	std::vector <std::string>::iterator i = tempVar.begin();
	std::string temp = "";
	for (auto item :nonTerminal_set) {
		temp = item;
		L_Holder = item;
		for (int i = 0;i <= 62;i++) {
			if (lhs[i].compare(temp)==0) {
				if (std::any_of(terminal_set.begin(), terminal_set.end(), bind2nd(std::equal_to<std::string>(), rhs[i]))) {
					
					if (std::any_of(tempVar.begin(), tempVar.end(), bind2nd(std::equal_to<std::string>(), rhs[i]))){
					
					}
					else {
						tempVar.push_back(rhs[i]);
					}
						
					//first_map.insert(std::pair<std::string, std::string>(lhs[i], rhs[i]));
					
				}
				else if (lhs[i].compare(rhs[i])==0) {
					//i += 1;
					if (lhs[i].compare(temp) == 0) {
						if (std::any_of(terminal_set.begin(), terminal_set.end(), bind2nd(std::equal_to<std::string>(), rhs[i]))) {
							tempVar.push_back(rhs[i]);
						}
						else { temp = rhs[i]; }

					}	
				}
				else {
					auto it = first_map.find(rhs[i]);
					if (it != first_map.end()) {
						//first_map[rhs[i]] = it->second;
						//first_map.insert(std::pair<std::string, std::string>(rhs[i], it->second));
						tempVar.push_back(it->second);
						
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
	//std::cout<<first_map

}

void Production::Follow() {

}
