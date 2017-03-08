#include<iostream>
#include<string>

using namespace std;

bool one_away(string str1, string str2) {

	bool diff = false;
	int index1 = 0, index2 = 0;
	if ((str1.length() - str2.length()) > 1) {
		return false;
	}
	string s1 = str1.length() < str2.length() ? str1 : str2;
	string s2= str1.length() < str2.length() ? str2 : str1;

	
	while (index1 < s1.length() && index2 < s2.length()) {
		if (s1[index1] != s2[index2]) {
			if (diff) {
				return false;
			}
			diff = true;
			if (s1.length() == s2.length()) {
				index1++;
			}
		}
			else { index1++; }
		
		index2++;
	}
	return true;
}

int main() {

	string string1, string2;
	cout << "Enter string 1: " << "\t";
	cin >> string1;
	cout << "Enter string 2: " << "\t";
	cin >> string2;
	cout << "Are the strings only one letter differed: " << endl;
	if (one_away(string1, string2)) {
		cout << "True" << endl;

	}
	else {
		cout << "false"<<endl;
	}
	
return 0;
}