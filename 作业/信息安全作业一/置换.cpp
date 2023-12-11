#include<bits/stdc++.h>
using namespace std;
vector<int> init(int len)
{
	srand(time(0));
	vector<int>v;
	for(int i=0;i<(len+3)/4;i++)
		v.push_back(i);
	len=v.size();
	int t=sqrt(len)+2;
	while(t--)
	{
		int x=rand()%len;
		int y=rand()%len;
		while(x==y){
			x=rand()%len;
			y=rand()%len;
		}
		swap(v[x],v[y]);
	}
	return v;
}
void Change(string&data ,vector<int>key)
{
	vector<string>Data_mp;
	for(int i=0;i<data.size();i+=4)
		Data_mp.push_back(data.substr(i,4));
	vector<string>ExData_mp;
	for(auto i:key)
		ExData_mp.push_back(Data_mp[i]);
	string ans;
	for(int i=0;i<4;i++)
		for(int j=0;j<ExData_mp.size();j++)
			ans=ans+ExData_mp[j][i];
	data=ans;
}
void ExChange(string &data,vector<int>key)
{
	int len=data.size();
	len/=4;
	vector<string>mp(len);
	vector<string>exmp(len);
	for(int i=0;i<data.size();i++)
		mp[i%len]=mp[i%len]+data[i];
	for(int i=0;i<key.size();i++)
		exmp[key[i]]=mp[i];
	string ans;
	for(auto i:exmp)
		ans=ans+i;
	data=ans;
}
void solve()
{
	string data;
	int len;
	cout<<"Message:\n";
	getline(cin,data);
	while((int)(data.size())%4!=0)data=data+" ";
	vector<int>key=init((int)(data.size()));
	
	Change(data,key);
	cout<<"ciphertext: \n";
	cout<<data<<endl;

	ExChange(data,key);
	cout<<"Message:\n";
	cout<<data<<endl;

}	
signed main(){
		solve();
	return 0;
}