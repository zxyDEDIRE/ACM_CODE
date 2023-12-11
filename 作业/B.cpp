/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define char unsigned char
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
//原始数据的十六进制表示
void hexdump(char *puc_data, int length)
{
    int i = 0;
 
    for (i = 0; i < length; i++) {
        printf("%02X", puc_data[i]);
        if (i && (i + 1) % 16 == 0) {
            putchar('\n');
        }
    }
    printf("\n");
}
void KSA(char *sbox,char *key,int length)
{
	char kbox[256];
	for(int i=0;i<256;i++)
	{
		sbox[i]=i;
		kbox[i]=key[i%length];
	}
	int j=0;
	for(int i=0;i<256;i++)
	{
		j=(j+sbox[i]+kbox[i])%256;
		swap(sbox[i],sbox[j]);
	}
}
void PRGA(char *sbox,char *keystream,int length)
{
	int i=0,j=0,k=0,t;
	for(k=0;k<length;k++)
	{
		i=(i+1)%256;
		j=(j+sbox[i])%265;
		swap(sbox[i],sbox[j]);
		t=(sbox[i]+sbox[j])%256;
		keystream[k]=sbox[t];
	}
}
void encryption(char *data,char *keystream,int length)
{
	for(int i=0;i<length;i++)
		data[i]^=keystream[i];
}
void solve()
{
	char sbox[256];
	char key[]="abcdefghijklmnopqrstuvwxyz";
	char data[] = "lsRJ@.0 lvf";
	char keystream[256];
	// hexdump(p,strlen(p));

	KSA(sbox,key,26);
	PRGA(sbox,keystream,11);

	cout<<data<<endl;
	encryption(data,keystream,11);
	cout<<data<<endl;
	encryption(data,keystream,11);
	cout<<data<<endl;
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
/*
Hello World C++ !
*/