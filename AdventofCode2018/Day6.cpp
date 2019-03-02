#include "pch.h"
#include "Day6.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "HelpFunction.h"
using namespace std;

void Day6::partA() {
	//unordered_map<char, int> map;
	//unordered_set<int> set;

	vector<string> input = HelpFunction::openFile("inputD6.txt");
	int maxX = 0;
	int maxY = 0;
	int **grid = new int *[9];
	for (int i = 0; i < 9; i++) {
		grid[i] = new int[9];
		fill_n(grid[i], 9, 0);
	}
	for (auto str : input) {
		auto split = HelpFunction::splitString(str,",");
		int x = stoi(split[0]);
		int y = stoi(split[1]);

		if (maxX < x) {
			maxX = x;
		}

		if (maxY < y) {
			maxY = y;
		}

		cout << "x: " << x << " y: " << y << endl;
	
	}
	cout << "X: " << maxX << " Y: " << maxY << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
void Day6::partB(){
	//unordered_map<char, int> map;
	//unordered_set<int> set;

	vector<string> input = HelpFunction::openFile("inputD6.txt");


}