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
//char -> 16
void char_2_Hex(char* Char, char* Hex)
{
	int length = strlen(Char);
	for (size_t i = 0; i < length; i++)
	{
		int tmp = int(Char[i]);
		if(Char[i] < 0)
			tmp = (-1) * Char[i] + 128;
		int high = tmp / 16;
		int low = tmp % 16;
		char HIHG;
		char LOW;

		if(high >= 10)
			HIHG = char(high - 10 + 65);
		else
			HIHG = char(high + 48);

		if(low >= 10)
			LOW = char(low - 10 + 65);
		else
			LOW = char(low + 48);

		Hex[2*i] = HIHG;
		Hex[2*i+1] = LOW;
	}
}

//16 -> char 
void Hex_2_char(char*Hex, char* Char)
{
	int length = strlen(Hex) / 2;
	for (size_t i = 0; i < length; i++)
	{
		int high;
		int low;
		if(int(Hex[2*i])>=65)
			high = int(Hex[2*i] - 65 + 10);
		else
			high = int(Hex[2*i]- 48);

		if(int(Hex[2*i+1])>=65)
			low = int(Hex[2*i+1] - 65 + 10);
		else
			low = int(Hex[2*i+1] - 48);

		Char[i] = char(high*16 + low);
	}
}



char* RC4(char* C,char* key)
{
	int S[256];
	int T[256];

	int  count = 0;
	count = strlen(key);

	for(int i = 0; i < 256; i++)
	{
		S[i] = i;
		int tmp = i % count;
		T[i] = key[tmp];
	}

	int i=0,j = 0;

	for(int  i = 0; i < 256; i++)
	{
		j = (j + S[i] + T[i]) % 256;
		int tmp;
		tmp = S[j];
		S[j] = S[i];
		S[i] = tmp;
	}

	int length = 0;
	length = strlen(C);


	for(int p = 0; p < length; p++)
	{

		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		int tmp;
		tmp = S[j];
		S[j] = S[i];
		S[i] = tmp;

		int k = S[(S[i] + S[j]) % 256];
		C[p]=C[p]^k;
	}

	return C;
}
void solve()
{
	char A[1000] = "aaaaaaaaaaa";
	cout << "C =" << A <<endl;
	char key[256] = "abcde";
	cout << "key = " << key <<endl;
	size_t  count = 0;
	count = strlen(A);


	char* B = RC4(A,key);

	char* M = new char[2*count]; 

	char_2_Hex(B,M);

	cout<<"M = " << M<<endl;

	char* C = RC4(B,key);

	cout <<"C' =  "<<C<<endl;

	system("pause");
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