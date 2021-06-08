//https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;

typedef int item;

struct segtree{
    int size;
    vector<item>vec;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        vec.resize(2*size);
    }
    
    item NEUTRAL_ELEMENT=0;
    
    item single(int v){
        return v;
    }
    
    item merge(item a,item b){
        return a+b;
    }
    
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            vec[x]=single(v);
            return;
        }
        int m=lx+(rx-lx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        vec[x]=merge(vec[2*x+1],vec[2*x+2]);
    }
    
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                vec[x]=single(a[lx]);
            }
            return;
        }
        int m=lx+(rx-lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        vec[x]=merge(vec[2*x+1],vec[2*x+2]);
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    
    item find(int k,int x,int lx,int rx){
        if(rx-lx==1) return lx;
        int m=lx+(rx-lx)/2;
        int s=vec[2*x+1];
        if(k<s){
            return find(k,2*x+1,lx,m);
        }else{
            return find(k-s,2*x+2,m,rx);
        }
    }
    
    item find(int k){
        return find(k,0,0,size);
    }
};

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	segtree st;
	st.init(n);
	vector<int>a(n);
	for(int i=0;i<n;++i)
	    cin>>a[i];
	st.build(a);
	while(m--){
	   int op;cin>>op;
	   if(op==1){
	       int i;cin>>i;
	       a[i]=1-a[i];
	       st.set(i,a[i]);
	   }else{
	       int k;cin>>k;
	       cout<<st.find(k)<<"\n";
	   }
    }
	return 0;
}

