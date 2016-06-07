#include <iostream>
#include <sstream>
#include <string>
#include "List.h"
#include <map>

enum constants {
	add, get, del
};

using namespace std;
int main()
{
	const map<string, constants> comands = { { "add", constants::add }, { "get", constants::get }, { "del", constants::del } };
	int n;
	cin >> n;
	string line, word;
	List<int> lst;
	cin.get();
	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		istringstream ss(line);
		ss >> word;
		int index = 0;
		ss >> index;
		try {
			switch (comands.at(word)) {
			case constants::add:
				int value;
				ss >> value;
				lst.AddNth(value, index);
				break;
			case constants::get:
				try {
					cout << lst.GetNth(index) << endl;
				}
				catch (exception e) {
					cout << e.what() << endl;
				}
				break;
			case constants::del:
				lst.DeleteNth(index);
				break;
			}
		}
		catch (...) {
			cout << "Unknown command" << endl;
		}
	}

	return 0;
}
