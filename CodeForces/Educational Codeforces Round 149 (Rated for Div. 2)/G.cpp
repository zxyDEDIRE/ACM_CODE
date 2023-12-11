#include<iostream>
using namespace std;


class A{
public:
	void func1(){
		cout<<1<<endl;
	}
protected :
	int a;
	void func2(){
		cout<<2<<endl;
	}
};

class B : protected A{
public :
	void test(){
		func1();
		func2();
	}
};

class C:public B{
public:
	void doit()
	{
		func1();
		func2();
	}
}

int main()
{
	B b;
	b.test();
	std::cout<<&b.test<<endl;
	return 0;
}