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
//不声明继承方式，则默认为私有继承.
class Derived1 :public Base {
private:
	int data2 = 81;
protected:
	int data_2 = 82;
public:
	void showData() { cout << "Derived1::data2(pri) = " << data2 << endl; }
	//派生类无法访问到基类的私有数据成员.
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
	//同名覆盖原则.
	test1.showData();
	//通过基类类名去访问.
	test1.Base::showData();
	test1.display(); 

	cout << "2." << endl;
	Derived2 test2;
	//保护继承会将基类成员变成保护类型，派生对象无法访问基类的公有成员和保护成员.
	/*test2.showData();*/
	test2.display(); 

	cout << "3." << endl;
	Base B;
	Derived1 D;
	//赋值兼容原则:狗可以是动物
	B =(Base) D;
	//因此使用Base的成员.
	B.showData();
	//但动物不一定是狗.
	/*D = B;*/

	cout << "4." << endl;
	//指针和引用仅指向基类的成员.
	Base& ref_b = D;
	ref_b.showData(); 
	Base* pointer_b = &D;
	pointer_b->showData(); cout << endl;

	return 0;
}

//Summary1: 继承方式和数据属性类似，均控制类和类成员的访问属性的。不过后者处理类的成员，而前者处理类(基类).
//bing大小姐的补充:继承方式还有一个作用,就是决定派生类是否是基类的子类型。只有公共继承才能使派生类成为基类的
//子类型，这样才能实现多态性.
//Summary2:赋值兼容原则指派生类对象可以赋值给基类对象，反之不可.
//Yizhe的补充:若出现切片问题，则应使用强制类型转换，不然没有多余的栈空间去存放派生对象传递来的其他成员的空间.