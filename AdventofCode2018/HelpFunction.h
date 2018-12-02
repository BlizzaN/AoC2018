#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
class HelpFunction {
public:
	static vector<string> openFile(string file);
	static vector<string> splitString(string &s, string &delimiter);
	static chrono::time_point<chrono::steady_clock> start();
	static chrono::time_point<chrono::steady_clock> stop();
	static double delta(chrono::time_point<chrono::steady_clock> start, chrono::time_point<chrono::steady_clock> stop);
};