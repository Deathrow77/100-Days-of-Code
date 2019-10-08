// New Implementation using Sieve

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void countSieve(vector<ll> &A, vector<pair<ll, ll>> &cnt, vector<ll> &ans, int n) 
{ 
    int MAX = *max_element(A.begin(), A.end()); 
    for (int i = 0; i < n; ++i){ 
        ++cnt[A[i]].first; 
        cnt[A[i]].second = i;
    }
    for (int i = 1; i <= MAX; ++i) 
        for (int j = i; j <= MAX; j += i) 
            if(cnt[j].second<i)
                ans[i]+=cnt[j].first;
    return; 
} 
void solve()
{
    ll n;
	cin>>n;
	vector<ll> A(n);
	ll max_ele = INT_MIN;
    for(ll i=0;i<n;i++)
    {
        cin>>A[i];
        max_ele = max(max_ele, A[i]);
    }
    int MAX = *max_element(A.begin(), A.end());
    vector<ll> ans(MAX+1, 0);
    vector<pair<ll, ll>> cnt(MAX+1, make_pair(0,0));
    countSieve(A, cnt, ans, A.size());
    cout<<*max_element(ans.begin(), ans.end())<<endl;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    	solve();
	}
	
	return 0;
}