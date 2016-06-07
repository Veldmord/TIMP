#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "Interface.h"


enum constants {
	add, get, del
};

using namespace std;

int main() {
	const map<string, constants> comands = { { "add", constants::add },{ "get", constants::get },{ "del", constants::del } };

	wstring libName;
	wcin >> libName;
	LPCWSTR wLibName = libName.c_str();
	HINSTANCE lib = LoadLibrary(wLibName);
	if (!lib) {
		cout << "Library not found" << endl;
		return 0;
	}
	int n;
	cin >> n;
	string line, word;
	IQ<> *(*getQueue)() = (IQ<> *(*)())GetProcAddress(lib, "GetSomeIQ");
	if (!getQueue)
		return 0;
	IQ<> *pQueue = getQueue();
	if (!pQueue)
		return 0;
	cin.get();
	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		istringstream ss(line);
		ss >> word;
		try {
			switch (comands.at(word)) {
			case constants::add:
				int value;
				ss >> value;
				pQueue->push(value);
				break;
			case constants::get:
				try {
					cout << pQueue->top() << endl;
				}
				catch (...) {
					cout << "Queue is empty" << endl;
				}
				break;
			case constants::del:
				pQueue->pop();
				break;
			}
		}
		catch (...) {
			cout << "Unknown command" << endl;
		}
	}
	FreeLibrary(lib);
	system("pause");
	return 0;
}
