#include "pch.h"
#include "Day4.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "HelpFunction.h"
#include <algorithm>    // std::sort

using namespace std;


void sleepTime(int asleep, int awake, int guard, unordered_map<int, int> &map, unordered_map<int, unordered_map<int, int>> &mostSleepTime) {
	
	if (asleep > awake) {
		map[guard] += (asleep - awake);
		for (int i = awake; i < asleep; i++) {
			mostSleepTime[guard][i]++;
		}
	}
	else {
		map[guard] += (awake - asleep);
		for (int i = asleep; i < awake; i++) {
			mostSleepTime[guard][i]++;
		}
	}
}
void Day4::partA() {
	unordered_map<int, int> map;
	unordered_map<int, unordered_map<int, int>> mostSleepTime;

	int guardNr = 0;
	int awake = 0;
	int asleep = 0;



	vector<string> input = HelpFunction::openFile("inputD4.txt");
	sort(input.begin(), input.end());
	for (auto a : input) {
		auto split = HelpFunction::splitString(a, " ");
		auto brack = HelpFunction::splitString(split[0], "[");
		auto y = HelpFunction::splitString(brack[1], "-");
		auto time = HelpFunction::splitString(split[1], ":");
		auto guard = HelpFunction::splitString(split[2], " ");


		int year = stoi(y[0]);
		int month = stoi(y[1]);
		int day = stoi(y[2]);

		int hour = stoi(time[0]);

		
		if (split[3].find('#') != std::string::npos) {
			//Find guard 
			auto guard = HelpFunction::splitString(split[3], "#");
			guardNr = 0;

			guardNr = stoi(guard[1]);
			unordered_map<int, int>::iterator it = map.find(guardNr);
			if (it == map.end()) {
				map[guardNr] = 0;
				mostSleepTime[guardNr] = unordered_map<int, int>();
			}
		}
		else {
			if (guard[0] == "falls") {
				asleep = stoi(time[1]);
			}
			else if (guard[0] == "wakes") {
				awake = stoi(time[1]);
				sleepTime(asleep, awake, guardNr, map, mostSleepTime);
			}
			
		}

	}

	int maxGuard = -1;
	int max = 0;
	for (auto m : map) {
		if (max < m.second) {
			max = m.second;
			maxGuard = m.first;
		}
	}
	int maxMinute = -1;
	max = 0;
	for (auto g : mostSleepTime[maxGuard]) {
		if (max < g.second) {
			max = g.second;
			maxMinute = g.first;
		}
	}


	cout << "Answer: " << (maxGuard * maxMinute) << endl;


}

void Day4::partB() {
	unordered_map<int, int> map;
	unordered_map<int, unordered_map<int, int>> mostSleepTime;

	int guardNr = 0;

	int awake = 0;
	int asleep = 0;

	vector<string> input = HelpFunction::openFile("inputD4.txt");
	sort(input.begin(), input.end());
	for (auto a : input) {
		auto split = HelpFunction::splitString(a, " ");
		auto brack = HelpFunction::splitString(split[0], "[");
		auto y = HelpFunction::splitString(brack[1], "-");
		auto time = HelpFunction::splitString(split[1], ":");
		auto guard = HelpFunction::splitString(split[2], " ");


		int year = stoi(y[0]);
		int month = stoi(y[1]);
		int day = stoi(y[2]);

		int hour = stoi(time[0]);


		if (split[3].find('#') != std::string::npos) {
			//Find guard 
			auto guard = HelpFunction::splitString(split[3], "#");
			guardNr = 0;

			guardNr = stoi(guard[1]);
			unordered_map<int, int>::iterator it = map.find(guardNr);
			if (it == map.end()) {
				map[guardNr] = 0;
				mostSleepTime[guardNr] = unordered_map<int, int>();
			}
		}
		else {
			if (guard[0] == "falls") {
				asleep = stoi(time[1]);
			}
			else if (guard[0] == "wakes") {
				awake = stoi(time[1]);
				sleepTime(asleep, awake, guardNr, map, mostSleepTime);
			}

		}

	}
	int maxGuard = -1;
	int max = 0;
	int min = 0;
	for (auto g : mostSleepTime) {
		for (auto k : g.second) {
			cout << "guard: " << g.first << " second: " << k.second << endl;
			if (max < k.second) {
				max = k.second;
				min = k.first;
				maxGuard = g.first;
			}
		}
	}
	cout << "Answer: " << (maxGuard * min) << endl;



}