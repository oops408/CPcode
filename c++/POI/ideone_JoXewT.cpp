	#include<bits/stdc++.h>
	using namespace std;
	#define fast ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
	#define N "\n";
	#define all(v) v.begin(),v.end()
	#define rall(v) v.rbegin(),v.rend()
	#define sz(s) s.size()
	typedef  long long ll;
	#define ull unsigned long long
	int MOD=1e9+7;
	ll mul(ll a,ll b){return (1ll*a*b)%MOD;}
	int sub(ll a,ll b){return ((a-b)%MOD+MOD)%MOD;}
	int add(ll a,ll b){return ((a%MOD)+(b%MOD))%MOD;}
	ll lcm(ll x, ll y) {return x / __gcd(x, y) * y;}
	bool iseven(ll n) {if ((n & 1)){return 0;}else {return 1;}}
	ll ncr(int n,int m){ll z=1;for(int i=0;i<m;i++){z=z*(n-i)/(i+1);}return z;}
	void swp(ll &a,ll &b){a^=b;b^=a;a^=b;}
	ll fp(int n,int p){if(!p){return 1;}ll rem=fp(n,p>>1);rem*=rem;if(p&1){rem*=n;}return rem;}
	const ll M=3e7+5;
	int main() {
		fast
			int t=1;
//			cin>>t;
			while(t--){
				int n;
				cin>>n;
				string s=to_string(n);
				vector<ll>v;
				for(int i=0;i<sz(s);i++){
					int m=s[i]-'0',m1=s[i]-'0';
					while(m<=1e9&&m!=0){
						v.push_back(m);
						m*=10;
						m+=m1;
					}
				}
				sort(all(v));
				for(int i=0;i<sz(v);i++){
					cout<<v[i]<<" ";
				}
			}
	}		 			  		  				  	 	 						 			 		   			  	 			    	   		   		  	  						 		