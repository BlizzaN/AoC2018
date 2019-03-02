#include "pch.h"
#include "HelpFunction.h"
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
vector<string> HelpFunction::openFile(string file) {
	vector<string> input;
	ifstream is;
	string str;
	is.open(file);
	while (getline(is, str)) {
		input.push_back(str);
	}
	is.close();
	
	return input;
}
chrono::time_point<chrono::steady_clock> HelpFunction::start() {
	return chrono::high_resolution_clock::now();
}
chrono::time_point<chrono::steady_clock> HelpFunction::stop() {
	return chrono::high_resolution_clock::now();
}
double HelpFunction::delta(chrono::time_point<chrono::steady_clock> start, chrono::time_point<chrono::steady_clock> stop) {
	return chrono::duration_cast<chrono::milliseconds>(stop - start).count();
}

vector<string> HelpFunction::splitString(string s, string delimiter)
{
	auto start = 0U;
	auto end = s.find(delimiter);
	auto results = vector<string>();
	while (end != string::npos)
	{
		results.push_back(s.substr(start, end - start));
		start = end + delimiter.length();
		end = s.find(delimiter, start);
	}
	results.push_back(s.substr(start, end));

	return results;
}