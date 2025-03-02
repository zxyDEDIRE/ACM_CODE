#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ gen.cpp -o gen.exe");
	system("g++ std.cpp -o std.exe");

	// for(int i=1;i<=50;i++)
	// {
	// 	char tmp[100];
	// 	int n;

	// 	n=5;

	// 	sprintf(tmp,"./gen.exe %d > ./data/%d.in",n,i);
	// 	cout<<tmp<<endl;
	// 	system(tmp);
	// }

	for(int i=1;i<=50;i++)
	{
		char tmp[100];
		sprintf(tmp,"./std.exe < ./data/%d.in > ./data/%d.out",i,i);
		cout<<tmp<<endl;
		system(tmp);
	}
	return 0;
}
