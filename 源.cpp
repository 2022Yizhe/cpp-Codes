#include <iostream>
using namespace std;

class Base {
private:
	int data1 = 9;
protected:
	int data_1 = 10;
public:
	void showData() { cout << "Base::data1(pri) = " << data1 << endl; }
};
//�������̳з�ʽ����Ĭ��Ϊ˽�м̳�.
class Derived1 :public Base {
private:
	int data2 = 81;
protected:
	int data_2 = 82;
public:
	void showData() { cout << "Derived1::data2(pri) = " << data2 << endl; }
	//�������޷����ʵ������˽�����ݳ�Ա.
	/*void showAlldata() { cout << "Base::data_1(pro) data1(pri) = " << data_1 << data1 << endl; }*/
	void display() {
		cout << "data_1 + data_2 = " << data_1 + data_2 <<" - Checked: 92" << endl;
	}
};
class Derived2 :protected Base {
private:
	int data2 = 81;
protected:
	int data_2 = 82;
public:
	void display() {
		cout << "data_1 + data_2 = " << data_1 + data_2 << " - Checked: 92" << endl;
	}
};

int main() {
	cout << "1." << endl;
	Derived1 test1;
	//ͬ������ԭ��.
	test1.showData();
	//ͨ����������ȥ����.
	test1.Base::showData();
	test1.display(); 

	cout << "2." << endl;
	Derived2 test2;
	//�����̳лὫ�����Ա��ɱ������ͣ����������޷����ʻ���Ĺ��г�Ա�ͱ�����Ա.
	/*test2.showData();*/
	test2.display(); 

	cout << "3." << endl;
	Base B;
	Derived1 D;
	//��ֵ����ԭ��:�������Ƕ���
	B =(Base) D;
	//���ʹ��Base�ĳ�Ա.
	B.showData();
	//�����ﲻһ���ǹ�.
	/*D = B;*/

	cout << "4." << endl;
	//ָ������ý�ָ�����ĳ�Ա.
	Base& ref_b = D;
	ref_b.showData(); 
	Base* pointer_b = &D;
	pointer_b->showData(); cout << endl;

	return 0;
}

//Summary1: �̳з�ʽ�������������ƣ�������������Ա�ķ������Եġ��������ߴ�����ĳ�Ա����ǰ�ߴ�����(����).
//bing��С��Ĳ���:�̳з�ʽ����һ������,���Ǿ����������Ƿ��ǻ���������͡�ֻ�й����̳в���ʹ�������Ϊ�����
//�����ͣ���������ʵ�ֶ�̬��.
//Summary2:��ֵ����ԭ��ָ�����������Ը�ֵ��������󣬷�֮����.
//Yizhe�Ĳ���:��������Ƭ���⣬��Ӧʹ��ǿ������ת������Ȼû�ж����ջ�ռ�ȥ����������󴫵�����������Ա�Ŀռ�.