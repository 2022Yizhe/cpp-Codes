#pragma once
#include <cassert>

template <class T>
class Array {
private:
	T* list;
	int size;
public:
	Array(int size = 50);//构造函数
	Array(const Array<T>& a);//复制构造函数
	~Array();//析构函数
	Array<T>& operator = (const Array<T>& rhs);//重载 = 
	T& operator	[](int n);//重载 []
	const T& operator [](int n) const;//常重载 []
	operator T* ();//重载 T*
	operator const T* () const;//常重载 T*
	int getSize() const;//取数组大小
	void resize(int sz);//修改数组大小 
};

template <class T>//构造函数
Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];
}
template <class T>//复制构造函数
Array<T>::Array(const Array<T>& a) {
	size = a.size;
	list = new T[size];
	for (int i = 0; i < size; i++)
		list[i] = a.list[i];
}
template <class T>//析构函数
Array<T>::~Array() {
	delete[]list;
	list = NULL;
}
template <class T>//重载 =
Array<T>& Array<T>::operator = (const Array<T>& rhs) {
	if (&rhs != this) {
		if (size != rhs.size) {
			delete[]list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	}
	return *this;
}
template <class T> //重载 []
T& Array<T>::operator [](int n) {
	assert(n >= 0 && n < size);
	return list[n];
}
template <class T> //常重载 []
const T& Array<T>::operator [](int n)const {
	assert(n >= 0 && n < size);
	return list[n];
}
/*隐式类型转换运算符只是一个样子奇怪的成员函数：operator + 类型符号。
你不用定义函数的返回类型，因为返回类型就是这个函数的名字*/
template <class T>//重载 T*
Array<T>::operator T* () {
	return list;
}
template <class T>//常重载 T*
Array<T>::operator const T* () const {
	return list;
}
template <class T>//取数组大小
int Array<T>::getSize() const {
	return size;
}
template <class T>
void Array<T>::resize(int sz){
	assert(sz >= 0);
	if (sz == size)
		return;
	T* newList = new T[sz];
	int n = (sz < size)?sz:size;
	for (int i = 0; i < n; i++)
		newList[i] = list[i];
	delete[]list;
	list = newList;
	size = sz;
}