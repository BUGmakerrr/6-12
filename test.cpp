#include<iostream>
#include<string>

using namespace std;
void TestString(){
	string s1;
	string::iterator it = s1.begin();
	while (it != s1.end()){
		cout << *it << " ";
		++it;
	}
}