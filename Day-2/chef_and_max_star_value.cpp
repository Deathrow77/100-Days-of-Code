#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<ll> &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    int i =0, j= n-1;
    vector<ll> res(n, 0);
    unordered_set<ll> s; 
    int max_ele = INT_MIN;
    for (int i = 0; i < n; i++) { 
        s.insert(A[i]); 
        max_ele = max(max_ele, A[i]); 
    } 
    for (int i = 0; i < n; i++) { 
        if (A[i] != 0) { 
            for (int j = A[i] * 2; j <= max_ele; j += A[i]) { 
                if (s.find(j) != s.end()) 
                    res[i]++; 
            } 
        } 
    } 
    cout<<*max_element(res.begin(), res.end())<<endl;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	vector<ll> A(n);
        for(ll i=0;i<n;i++)
        {
            cin>>A[i]; 
        }
        solve(A);
	}
	
	return 0;
}
