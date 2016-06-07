#include <map>
#include <string>
#include <vector>
#include <sstream>
#include "Factory.h"
#include "ABC.h"

using namespace std;

enum constants {
	showall, create
};

int main() {
	const map<string, constants> commands = { { "showall", constants::showall },{ "create", constants::create } };

	map<string, AbstractCreator<Base, int>*> factory;
	factory["A"] = new Creator<A, Base, int>;
	factory["B"] = new Creator<B, Base, int>;
	factory["C"] = new Creator<C, Base, int>;
	int n;
	cin >> n;
	string line, word;
	cin.get();
	
	
	vector<Base*> classes;

	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		istringstream ss(line);
		ss >> word;
		try {
			switch (commands.at(word)) {
			case constants::showall:
				for (auto el : classes)
					el->show();
				break;
			case constants::create:
				string classname;
				ss >> classname;
				int value = 0;
				ss >> value;
				
				auto it = factory.find(classname);
				if (it != factory.end())
					classes.push_back(it->second->create(value));
				else
					cout << "Unknown class" << endl;
				
				break;
			}
		}
		catch (...) {
			cout << "Unknown command" << endl;
		}
	}
	system("pause");
}
