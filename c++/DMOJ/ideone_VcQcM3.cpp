#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rfo(i, n) for(int i=n-1;i>=0;i--)
#define fo(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define PRINT(arr) for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) cout<<arr[i]<<" "; cout<<endl;
#define INPUT(arr,n) int n; cin>>n;int arr[n];for(int i=0;i<n;i++) cin>>arr[i];
#define FO(i,n) for(int i=0;i<n;i++)
#define DISPLAY(v)     for(auto i:v){cout<<i<<" ";} cout<<endl;
#define vi vector<int>


inline int nxt(){
int x;
cin>>x;
return x;}


void solve(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
  unordered_set<int> s;
        for(int num:nums){
            if(s.find(num)==s.end()){
                s.insert(num);
            }
            else{
                s.erase(num);
            }
        }
        vector<int> ans;
        for(int num:s){
            ans.push_back(num);
        }
        for(auto &i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
}






int32_t main(){
fast
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif




int t=1;
// cin>>t;
int x = 1;
while(t--){
cout<<"TEST #"<<x++<<endl;
solve();
}
return 0;
}
