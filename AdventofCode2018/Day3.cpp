#include "pch.h"
#include "Day3.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "HelpFunction.h"
using namespace std;

void Day3::partA() {
	auto start = HelpFunction::start();
	//unordered_map<char, int> map;
	//unordered_set<int> set;

	vector<string> input = HelpFunction::openFile("inputD3.txt");
	int sum = 0;

	int **grid = new int *[1300];
	for (int i = 0; i < 1300; i++){
		grid[i] = new int[1300];
		fill_n(grid[i], 1300, 0);
	}
	int count = 0;
	for (auto str : input) {
		auto split = HelpFunction::splitString(str, " ");
		auto num = HelpFunction::splitString(split[2], ",");
		auto wh = HelpFunction::splitString(split[3], "x");

		auto x = stoi(wh[0]); 
		auto y = stoi(wh[1]);

		auto w = stoi(num[0]);
		auto h = stoi(num[1]);
		
		
		for (int w2 = w; w2 < (w + x); w2++) {
			for (int h2 = h; h2 < (h + y); h2++) {
				grid[w2][h2]++;	
			}
		}	
	}
	for (int w = 0; w < 1300; w++) {
		for (int h = 0; h < 1300; h++) {
			if (grid[w][h] > 1) {
				count++;
			}
		}
	}

	cout << "Answer: " << count << endl;
	auto stop = HelpFunction::stop();
	cout << "Time: " << HelpFunction::delta(start, stop);


}

void Day3::partB() {
	auto start = HelpFunction::start();
	unordered_map<int, int> map;
	unordered_set<int> set;

	vector<string> input = HelpFunction::openFile("inputD3.txt");
	int sum = 0;

	int **grid = new int *[1300];
	for (int i = 0; i < 1300; i++) {
		grid[i] = new int[1300];
		fill_n(grid[i], 1300, 0);
	}
	int count = 0;
	int claimId = 0;
	for (auto str : input) {
		auto split = HelpFunction::splitString(str, " ");
		auto hash = HelpFunction::splitString(split[0], "#");
		auto num = HelpFunction::splitString(split[2], ",");
		auto wh = HelpFunction::splitString(split[3], "x");

		claimId = stoi(hash[1]);
		//set.insert(claimId);

		auto x = stoi(wh[0]);
		auto y = stoi(wh[1]);

		auto w = stoi(num[0]);
		auto h = stoi(num[1]);


		for (int w2 = w; w2 < (w + x); w2++) {
			for (int h2 = h; h2 < (h + y); h2++) {
				grid[w2][h2]++;
			}
		}
	}

	for (int w = 0; w < 1300; w++) {
		for (int h = 0; h < 1300; h++) {
			if (grid[w][h] > 1) {
				count++;
			}
		}
	}

	if (count == 1) {
		cout << "Claim: " << claimId << endl;
	}
		
	auto stop = HelpFunction::stop();
	cout << "Time: " << HelpFunction::delta(start, stop);
	
}