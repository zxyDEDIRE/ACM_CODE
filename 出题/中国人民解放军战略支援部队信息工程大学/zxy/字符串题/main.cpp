#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ gen.cpp -o gen.exe");
	system("g++ std.cpp -o std.exe");

	for(int i=1;i<=50;i++)
	{
		char tmp[100];
		int n,r,T;

		if(i<=10)n=10,r=10,T=2;
		else if(i<=20)n=100,r=100,T=5;
		else if(i<=30)n=10000,r=10000,T=1234;
		else n=1000000,r=1000000,T=1231;

		sprintf(tmp,"./gen.exe %d %d %d > ./data/%d.in",n,r,T,i);
		cout<<tmp<<endl;
		system(tmp);
	}

	for(int i=1;i<=50;i++)
	{
		char tmp[100];
		sprintf(tmp,"./std.exe < ./data/%d.in > ./data/%d.out",i,i);
		cout<<tmp<<endl;
		system(tmp);
	}
	return 0;
}
