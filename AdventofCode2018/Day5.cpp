#include "pch.h"
#include "Day5.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "HelpFunction.h"
#include <algorithm>    // std::sort


void Day5::partA() {
	//unordered_map<char, int> map;
	unordered_set<string> set;

	vector<string> input = HelpFunction::openFile("inputD5.txt");

	vector<string> units;
	bool run = true;
	//dabAcCaCBAcCcaDA
	for (auto in : input) {
		while (run) {
			set.insert(in);


			for (int i = 0; i < in.size(); i++) {
				if (isupper(in[i]) == islower(in[i + 1])) {
					char temp = tolower(in[i]);
					char temp2 = tolower(in[i + 1]);
					//cout << "temp: " << temp << " s " << temp2 << endl;
					if (temp == temp2) {
						in.erase(i, 2);
					}

				}
				else if (islower(in[i]) == isupper(in[i + 1])) {
					char temp = toupper(in[i]);
					char temp2 = toupper(in[i + 1]);
					//	cout << "temp: " << temp << " s " << temp2 << endl;
					if (temp == temp2) {
						in.erase(i, 2);
					}

				}
			}


			if (set.count(in)) {
				units.push_back(in);
				run = false;
			}

		}
	}
	for (auto c : units) {
		cout << "Units: " << c.length() << endl;
	}

}

void Day5::partB() {
	//unordered_map<char, int> map;
	unordered_set<string> set;

	vector<string> input = HelpFunction::openFile("inputD5.txt");

	vector<string> units;
	int min = 0;
	int max = 0;
	//Start with A
	int letterBig = 65;
	int letterSmall = 97;

	//dabAcCaCBAcCcaDA
	for (int i = 0; i < 25; i++) {
		int min = 0;
		for (auto in : input) {
			min = in.length();
			//	cout << "INNNNN";
			bool run = true;
			for (int i = 0; i < in.size(); i++) {
				//	cout << "Letter: " << letterBig << " Letter2: " << letterSmall << endl;
				if (in[i] == letterBig || in[i] == letterSmall) {
					in.erase(i, 1);
					i--;
				}
			}
			if (letterBig != 90 || letterSmall != 97) {
				letterBig++;
				letterSmall++;
			}

			while (run) {
				set.insert(in);

				for (int i = 0; i < in.size(); i++) {
					if (isupper(in[i]) == islower(in[i + 1])) {
						char temp = tolower(in[i]);
						char temp2 = tolower(in[i + 1]);
						if (temp == temp2) {
							in.erase(i, 2);
						}

					}
					else if (islower(in[i]) == isupper(in[i + 1])) {
						char temp = toupper(in[i]);
						char temp2 = toupper(in[i + 1]);
						if (temp == temp2) {
							in.erase(i, 2);
						}

					}
				}


				if (set.count(in)) {
					units.push_back(in);
					set.clear();
					for (auto c : units) {
						if (min < c.length()) {
							cout << "Units min: " << min;
						}
						else {
							min = c.length();
						}
						cout << "Units: " << c.length() << endl;
					}
					units.clear();
					run = false;

				}
			}
			min = 0;
		}
	}


}