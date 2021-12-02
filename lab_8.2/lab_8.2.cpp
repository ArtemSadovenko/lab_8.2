#include <iostream>
#include <string>

using namespace std;

int min_length(string s);
void print_line(string s);


void main() {
	string s;
	int size;

	cout << "Enter: "; getline(cin, s);

	print_line(s);

	size = min_length(s);
	cout << size;
}

int min_length(string s) {
	int size = s.size() - 1;
	int i1 = 0;
	int i2 = 0;
	int min_length = size;
	int _length = 0;

	while (s.find_first_of(" ./,<>1234567890=\"\';:[]{}()*&^%$#@!?", i1) != -1) {
		i2 = s.find_first_of(" ./,<>1234567890=\"\';:[]{}()*&^%$#@!?", i1);
		_length = i2 - i1;
		if (_length < min_length && _length != 0) {
			min_length = _length;
		}
		i1 = i2+1;
	}

	if (size - i1 + 1 < min_length && size - i1 + 1 != 0) {
		min_length = size - i1 + 1;
	}

	return min_length;
}

void print_line(string s){
	cout << "Line: ";
	for (int i = 0; s[i] != '\0'; i++) {
		cout << s[i];
	}
	cout << endl;
}