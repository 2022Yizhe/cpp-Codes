#include <iostream>
#include "myArray.h"
using namespace std;

int main() {
	Array<int> a;
	for (int i = 0; i < a.getSize(); i++)
		a[i] = i;
	for (int i = 0; i < a.getSize(); i++)
		cout << a[i]<<" ";
	cout << endl;
	a.resize(100);
	for (int i = 0; i < a.getSize(); i++)
		a[i] = i;
	for (int i = 0; i < a.getSize(); i++)
		cout << a[i] << " ";
	return 0;
}