#include<bits/stdc++.h>
using namespace std;
// #include<iostream>
/*
class B1        size(8):
        +---
 0      | {vbptr}
        +---
        +--- (virtual base A)
 4      | num_a
        +---

B1::$vbtable@:
 0      | 0
 1      | 4 (B1d(B1+0)A)
vbi:       class  offset o.vbptr  o.vbte fVtorDisp
               A       4       0       4 0
*/
class A{
public:
	// int num_a=18;
	__int128 x;
	void func1(){std::cout<<"a_f1\n";}
	void func2(){std::cout<<"a_f2\n";}
};

class B1: virtual public A{
public:
	void func1(){std::cout<<"b1_f1\n";}
};

class B2:virtual public A{

public:
	void func2(){std::cout<<"b2_f2\n";}
};


class C:public B1, public B2{

};


void solve()
{

}

class test{
	int a;
};
signed main(){
	test *x = new test();
	return 0;
}
