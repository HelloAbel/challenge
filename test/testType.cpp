#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int i = 0, j = 1;
	float f = 0;
	long l = 0;
	if(typeid(i)==typeid(j))
		cout << "True\t";
	else
		cout << "False\t";
	if(typeid(i)==typeid(f))
		cout << "True\t";
	else
		cout << "False\t";
	if(typeid(i)==typeid(l))
		cout << "True\t";
	else
		cout << "False\t";
	if(typeid(i)==typeid(int))
		cout << "True\t";
	cout << endl;

	return 0;
}
