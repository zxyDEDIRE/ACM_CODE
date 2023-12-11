/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string rand_key()
{
	srand(time(0));
	string key;
	int key_len=0;
	while(key_len<40||key_len>256)
		key_len=rand();
	for(int i=0;i<key_len;i++)
	{
		int x=rand()%26;
		key=key+(char)(x+'a');
	}
	return key;
}
void change(vector<unsigned char>&exdata,string& data)
{
	for(auto i:data)
		exdata.push_back((unsigned char)(i));
}
void KSA(vector<int>&sbox,string key)
{
	int length=key.size();
	vector<int>kbox(256);
	sbox.resize(256);

	for(int i=0;i<256;i++)
	{
		sbox[i]=i;
		kbox[i]=(int)(key[i%length]);
	}
	int j=0;
	for(int i=0;i<256;i++)
	{
		j=(j+sbox[i]+kbox[i])%256;
		swap(sbox[i],sbox[j]);
	}
}
void PRGA(vector<int>&sbox,vector<int>&keystream,int length)
{
	int i=0,j=0,k=0,t;
	keystream.resize(256);
	for(k=0;k<length;k++)
	{
		i=(i+1)%256;
		j=(j+sbox[i])%265;
		swap(sbox[i],sbox[j]);
		t=(sbox[i]+sbox[j])%256;
		keystream[k]=sbox[t];
	}
}
void encryption(vector<unsigned char>&exdata,vector<int>keystream)
{
	for(int i=0;i<exdata.size();i++)
		exdata[i]^=keystream[i];
}
void solve()
{
	string key=rand_key();
	// string data="lsRJ@.0 lvf";
	string data;
	cout<<"Original text: \n";
	getline(cin,data);
	cout<<endl;
	vector<int>sbox,keystream;
	vector<unsigned char>exdata;


	int data_len=data.size();

	change(exdata,data);


	KSA(sbox,key);
	PRGA(sbox,keystream,data_len);


	//加密
	encryption(exdata,keystream);
	cout<<"ciphertext: \n";
	for(auto i:exdata)cout<<i;cout<<"\n\n";

	//解密
	encryption(exdata,keystream);
	cout<<"Original text: \n";
	for(auto i:exdata)cout<<i;cout<<"\n\n";
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}