#include<iostream>
#include<string>

using namespace std;

bool isUnique(string str) {
	//This is for ASCII string.
	
	bool char_set[256];
	bool result = true;
	for (int i = 0; i < str.length(); i++) {
		int val = str[i];
		if (char_set[val] == true) {
			result =  false;
			break;
		}
		char_set[val] = true;
	}
	return result;
}

int main() {
	string strng;
	cout << "Enter the string: " << endl;
	cin >> strng;
	if (isUnique(strng)) { 
		cout<<"String is unique."<<endl; }
	else{ cout << "String not unique." << endl; }
	return 0;
}