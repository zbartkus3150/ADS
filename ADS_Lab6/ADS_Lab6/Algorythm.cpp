#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int Max(std::list<int> l) {
	if (l.size() == 0) return 0;
	if (l.size() == 1) return l.front();
	else
	{
		std::list<int> tmp = l;
		tmp.pop_front();
		return std::max(l.front(), Max(tmp));
	}
}

int Sum(std::list<int> l) {
	if (l.size() == 0) return 0;
	if (l.size() == 1) return l.front();
	else {
		std::list<int> tmp = l;
		tmp.pop_front();
		return l.front() + Sum(tmp);
	}
}

std::list<int> reverse(std::list<int> l) {
	std::list<int> rev, tmp = l;
	if (l.size() == 1) {
		rev.push_back(l.front());
		return rev;
	}
	else {
		tmp.pop_front();
		tmp = reverse(tmp);
		for (const auto i : tmp)
			rev.push_back(i);
		rev.push_back(l.front());
		return rev;
	}
}

int main() {
	std::list<int> l, rev;
	l.push_back(0);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	cout << "Max: " << Max(l) << endl;
	cout << "Sum: " << Sum(l) << endl;
	for (const auto i : l)
		cout << i << " ";
	cout << endl;
	rev = reverse(l);
	for (const auto i : rev)
		cout << i << " ";
	cout << endl;
	return 0;
}