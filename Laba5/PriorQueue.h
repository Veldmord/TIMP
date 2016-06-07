#pragma once
#include <vector>
template <class T>
class PriorQueue {
	std::vector<T> data;
	bool changeVal(T &father, T &son) {
		if (son < father) {
			std::swap(son, father);
			return true;
		}
		return false;
	}
public:
	void push(const T &val) {
		data.push_back(val);
		int i = data.size() - 1;
		while (i > 0) {
			int j = (i - 1) / 2;
			if (!changeVal(data[j], data[i]))
				break;
			i = j;
		}
	}
	T &top() {
		return data[0];
	}
	void pop() {
		data[0] = data[data.size() - 1];
		data.pop_back();
		int i = 0;
		while (i < ((data.size() - 1) / 2)) {
			int j = data[2 * i + 1] < data[2 * i + 2] ? (2 * i + 1) : (2 * i + 2);
			if (!changeVal(data[i], data[j]))
				break;
			i = j;
		}
	}
};
