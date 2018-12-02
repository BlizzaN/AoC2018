#include "pch.h"
#include "Day1.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_set>
#include <string>
#include "HelpFunction.h"
using namespace std;
void Day1::readFile() {
	unordered_set<int> freq;
	vector<string> input;
	string str;
	int value = 0;
	freq.insert(value);
	auto start = HelpFunction::start();
	bool run = true;
	while (run) {
		input = HelpFunction::openFile("inputD1.txt");
		for(const auto str : input) {
			value += atoi(str.c_str());

			auto pos = freq.find(value);
			if (pos == freq.end()) {
				freq.insert(value);
			}
			else {
				cout << "pos " << *pos << endl;

				auto stop = HelpFunction::stop();

				cout << "time " << HelpFunction::delta(start, stop);
				run = false;
			}
		}
	}
}