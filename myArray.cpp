#include <iostream>
#include "myArray.h"
using namespace std;

int main() {
	Array<int> a(10);
	int count = 0;

	int n;
	cout << "����������ѯ����>=2��:";
	cin >> n;
	for (int i = 2; i <= n; i++) {
		//��������
		bool isprime = 1;
		for (int j = 2; j < i; j++)
			if (i % j == 0) {
				isprime = 0;
				break;
			}
		//д������
		if (isprime) {
			if (count == a.getSize())
				a.resize(count * 2);
			a[count++] = i;
		}
	}
	for (int i = 0; i < count; i++)
		cout << a[i] << " ";
	return 0;
}