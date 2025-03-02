#include<iostream>

using namespace std;

void Swap(int& left, int& right)
{
	cout<<"first"<<endl;
	int temp = left;
	left = right;
	right = temp;
}
void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
// void Swap(char& left, char& right)
// {
// 	char temp = left;
// 	left = right;
// 	right = temp;
// }

template<typename T>
void Swap(T& left, T& right)
{
	cout<<"second"<<endl;
	T temp = left;
	left = right;
	right = temp;
}



template<class K, class V> //两个模板参数
void Func(const K& key, const V& value)
{
	cout << key << ":" << value << endl;
}



void solve()
{
	int a1=2,a2=3;
	Swap(a1,a2);
	cout<<a1<<" "<<a2<<endl;

	char b1='a', b2='b';
	Swap(b1,b2);
	cout<<b1<<" "<<b2<<endl;
}

int main()
{
	solve();
	return 0;
}