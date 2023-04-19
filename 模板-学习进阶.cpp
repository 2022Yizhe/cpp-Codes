/* 注意细节，朱先生如是说道 */
#include <iostream>
#include <iomanip>
using namespace  std;

template <typename ElemType>
class  myArrayList {
private:
	int  mSize;
	int  mLen;
	ElemType* mpArr;
public:
	myArrayList(int  n) {
		this->mSize = n;
		this->mLen = 0;
		this->mpArr = new  ElemType[mSize];
	}
	myArrayList(ElemType* a, int  n) {
		mLen = n;
		mSize = n;
		int i;
		mpArr = new ElemType[n];
		for (i = 0; i < n; i++)
			mpArr[i] = a[i];
	}
	/* 拷贝构造函数建议修改形参为const类型，以免对形参的意外修改 */
	myArrayList(myArrayList<ElemType>& other) {
		this->mLen = other.mLen;
		this->mSize = other.mSize;
		this->mpArr = new  ElemType[this->mLen];
		for (int i = 0; i < this->mLen; i++)
			this->mpArr[i] = other.mpArr[i];
	}
	void  show() {
		for (int i = 0; i < mLen; i++)
			cout << mpArr[i] << "      ";
		cout << endl;
	}
	ElemType  getMax() {
		ElemType max;
		max = mpArr[0];
		for (int i = 1; i < mLen; i++)
			if (max < mpArr[i])
				max = mpArr[i];
		return max;
	}
	void  sort() {
		int i, j;
		for (i = 0; i < mSize; i++)
			for (j = 0; j < mSize - 1 - i; j++)
				if (mpArr[j] > mpArr[j + 1]) {
					ElemType c = mpArr[j];
					mpArr[j] = mpArr[j + 1];
					mpArr[j + 1] = c;
				}
	}
	~myArrayList() { delete[] mpArr; mpArr = NULL; }
};


class Student {
private:
	int mId;
	float height;
	int score;
public:
	Student(int id = 0, float h = 0, int s = 0) :height(h), mId(id), score(s) {}
	/* 重载 '>' '<' '=' '<<'等运算符，*/
	/* 使函数sort()，getMax()等能够正确兼容Student类, 以及按编者的想法输出数据格式 */
	bool operator >(const Student& other) const {
		return score > other.score;
	}
	bool operator <(const Student& other) const {
		return score < other.score;
	}
	Student operator = (const Student& a) {
		mId = a.mId;
		height = a.height;
		score = a.score;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Student& s) {
		os << "ID:" << s.mId << "  Height:" << s.height << " Score:" << s.score << endl;
		return os;
	}
};

int  main() {
	int  a[] = { 1,2,3,5,7,9,12,8 };
	double b[] = { 1,2.5,3.6,5,7,9,12.8,8 };
	myArrayList<int> list1(a, 8);
	list1.sort();
	list1.show();
	cout << "max=" << list1.getMax() << endl;
	myArrayList  <double>  list2(b, 8);
	list2.sort();
	list2.show();
	cout << "max=" << list2.getMax() << endl;
	Student s[3] = { Student(1,175,80),Student(2,178,90),Student(3,195,83) }, s1;
	myArrayList<Student>  list3(s, 3);
	list3.sort();
	list3.show();
	cout << "max=" << list3.getMax() << endl;
	return 0;
}
