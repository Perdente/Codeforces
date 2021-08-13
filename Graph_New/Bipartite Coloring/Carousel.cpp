//https://codeforces.com/contest/1328/problem/D
/*A winner is just a loser who tried one more time*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl "\n"
const int MOD = 1e9+7;
const int mx  = 2e5+5;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// using namespace std;
// #define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
void Loser()    {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
#define inf 			LLONG_MAX
#define zero 			-LLONG_MAX
#define PI   			acos(-1.0)  // 3.1415926535897932
#define Case(J) 		printf("Case %lld: %lld\n",++count,J); ///print case
#define preci                   cout<<fixed<<showpoint<<setprecision(20);
#define gcd(a,b) 		__gcd(a,b)//int gcd(int a,int b){return b?gcd(b,a%b):a;}
#define lcm(a,b) 		(a*(b/__gcd(a,b) ))
#define MP 			make_pair
#define pb 			push_back
#define rev(v) 			reverse(v.begin(),v.end());
#define srt(v) 			sort(v.begin(),v.end());
#define grtsrt(v) 		sort(v.begin(),v.end(),greater<ll>());
#define full(v)			(v).begin(),(v).end()
#define hellyeah 		exit(0);
#define	debug(a) 		cout<<"*"<<a<<"$"<<endl;
#define	debug2(a,b) 		cout<<"$"<<a<<" "<<b<<"$"<<endl;
#define	debug3(a,b,c) 		cout<<"$"<<a<<" "<<b<<" "<<c<<"$"<<endl;
#define SET(X,D_type)		memset(X, D_type, sizeof(X))
#define groot(A)		{cout<<A<<endl;return;}
#define vins(V)			srt(V)V.resize(unique(V.begin(),V.end())-V.begin());
#define check           	cout<<"Avengers Assemble"<<endl;
#define	lol 			cout<<"\n";
#define meem(X) 		cout<<(X?"Yes":"No")<<endl;
#define joker(V) 		for(auto X:V)cout<<X<<" ";cout<<endl;
#define papiya(Mp) 		for(auto X:Mp)cout<<X.first<<" "<<X.second<<endl;
#define lp(i,a) 		for(int i=0; i<a;i++)
#define LP(it,S)		for(auto it:S)
#define lp1(i,a,b) 		for(int i=a; i<=b;i++)
#define rlp(i,b,a) 		for(int i=(b);i>=(a);--i) 
#define Mat(mat,N,M)		lp(i,N){lp(j,M)cout<<mat[i][j]<<" \n"[j==M-1];}
#define all(x)                  (x).begin(), (x).end()
#define sz(X)					X.size()
typedef long long ll;

int ncr(int n,int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
int mod(int M){return (M % MOD + MOD)%MOD;}
int ceil(int A,int B)   {if(A%B==0)return A/B;else return (A/B)+1LL;}
int middle(int a, int b, int c)  {if ((a <= b && b <= c) || (c <= b && b <= a)) return b;else if ((b <= a && a <= c) || (c <= a && a <= b))return a;else return c; } 
bool comp(const pair<int,int> &a, const pair<int,int> &b) {return (a.second < b.second); }

typedef deque<int> Dq;
typedef unordered_set<int> St;
typedef unordered_map<int,int> M;
typedef vector<int> V;
typedef vector<bool> VB;
typedef vector<V> VV;
typedef vector<pair<int,int>> VP;
typedef priority_queue<int,vector<int>,greater<int>> Pq;

string str,str1,str2,str3,str4,str5,str6,str7;
char ch,ch1,ch2,ch3;
bool flag,flag1,flag2;

int a,b,c,d,e,f,g,h,l,i,j,k,m,n,o,p,q,r,s,t,u,v,w,x,y,z,pos,res,res1,test,cnt,cnt1,cnt2,cnt3,cnt4,sum,sum1,sum2,sum3,ans,ans1,ans2,ans3,ma,ma1,ma2,ma3,mi,mi1,mi2,mi3,temp,temp1,temp2,temp3,temp4;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void SectumSempra()
{
	cin>>n;
	V v(n+1);
	lp1(i,1,n){
		cin>>v[i];
	}
	V adj[n+1],col(n+1,-1);
	VB vis(n+1);
	lp1(i,1,n){
		if(i>1){
			if(v[i]!=v[i-1]){//if two adjacent elements are dif. then they are in same connected component
				adj[i].pb(i-1);
				adj[i-1].pb(i);
			}
		}
	}
	if(v[1]!=v[n]){// as the 1st node is connected to nth node(cyclic)
		adj[1].pb(n);
		adj[n].pb(1);
	}

	function<void(int)>dfs=[&](int u)->void{
		vis[u]=true;
		LP(v,adj[u]){
			if(col[u]==col[v]){
				col[v]=2;//if the graph is not bipartite we are forced to use extra color
			}
			else if(!vis[v]){
				col[v]=col[u]^1;// if the graph is bipartite then it's just two colors
				dfs(v);
			}
		}
	};

	lp1(i,1,n){
		if(!vis[i]){
			col[i]=0;
			dfs(i);
		}
	}	
	cout<<*max_element(all(col))+1<<endl;
	lp1(i,1,n)cout<<col[i]+1<<" ";
	lol
}

signed main(){
	Loser();
	test=1;
	cin>>test;
	while(test--)SectumSempra();
	return 0;
}
