#include<bits/stdc++.h>
using namespace std;
void A(string T,map<char,int>mp,int tmp,string &data)
{
	for(auto &i:data)
		i=T[(mp[i]+tmp)%T.size()];
}
void B(string T,map<char,int>mp,int tmp,string &data)
{
	for(auto &i:data)
		i=T[(mp[i]-tmp+T.size())%T.size()];
}
void solve()
{
	string T;
	map<char,int>mp;
	for(char i=(char)(32);i<='~';i++)  // 创建字符表T
		T=T+i,mp[i]=T.size()-1;
	srand(time(0));//随机种子

	int tmp=0;                 //移位
	while(tmp==0)tmp=rand()%52;//防止移位后和移位前一样

	string data;
	cout<<"Message:\n";
	getline(cin,data);
	cout<<endl;


	A(T,mp,tmp,data);
	cout<<"ciphertext: \n";
	cout<<data<<endl;
	cout<<endl;

	B(T,mp,tmp,data);
	cout<<"Message:\n";
	cout<<data<<endl;
}
signed main(){
		solve();
	return 0;
}