#include "pch.h"
#include "Day2.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "HelpFunction.h"
using namespace std;
void Day2::readFileAndCount() {
	vector<string> input;
	unordered_map<char, int> map;
	string str;
	input = HelpFunction::openFile("inputD2.txt");
	int two = 0;
	int three = 0;
	
	for(const auto str : input) {
		int value = 0;
		bool hasTwo = true;
		bool hasThree = true;

		for (int i = 0; i < str.size(); i++) {
			char c = str[i];
			map[c]++;
		}

		unordered_map<char, int>::iterator it;
		for (it = map.begin(); it != map.end(); it++) {
			cout << "key: " << it->first << " Value: " << it->second << endl;
			if (it->second == 2 && hasTwo) {
				two++;
				hasTwo = false;
			}
			else if (it->second == 3 && hasThree) {
				three++;
				hasThree = false;
			}
		}
		map.clear();
	}
	cout << "Answer: " << (two * three) << endl;
}

void Day2::countDiffer() {
	vector<string> input;
	auto start = HelpFunction::start();
	string str1, str2;
	input = HelpFunction::openFile("inputD2.txt");
	int diff = 0;
	int index = 0;

	string savestring;
	int saveindex;
	for(const auto str : input) {
		for(const auto str2 : input){
			for (int i = 0; i < str.length(); i++) {
				if (str[i] != str2[i]) {
					diff++;
					index = i;
				}
			}
			if (diff == 1) {
				savestring = str;
				saveindex = index;
			}
			diff = 0;
			index = 0;
		}
	}
	auto stop = HelpFunction::stop();
	cout << "Time: " << HelpFunction::delta(start, stop);
	cout << " Answer: " << savestring.erase(saveindex,1) << endl;

}