#include <iostream>
#include <vector>
#include <string>
using namespace std;

class stack {
public:
	vector<int> s;
	int size = 0;

	stack() {

	}
	int top() {
		if (size > 0) return s[size - 1];
		else return -1;
	}
	int empty() {
		if (size == 0) return 1;
		return 0;
	}
	int sizee() {
		return size;
	}
	void push(int n) {
		s.push_back(n);
		size++;
	}
	int pop() {
		if (size > 0) {
			int tmp = s[--size];
			s.pop_back();
			return tmp;
		}
		else return -1;

	}
};

int main() {
	int n, a;
	string str;
	stack s;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push") {
			cin >> a;
			s.push(a);
		}
		else if (str == "pop") {
			cout << s.pop() << endl;
		}
		else if (str == "top") {
			cout << s.top() << endl;
		}
		else if (str == "empty") {
			cout << s.empty() << endl;
		}
		else if (str == "size") {
			cout << s.sizee() << endl;
		}
	}
}