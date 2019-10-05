// Link - https://www.codechef.com/OCT19B/problems/MARM
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> solve(vector<ll> &A, ll &k, ll &n)
{
	for(int i=0;i<k;i++)
	{
		ll a = A[i%n];
		ll b = A[n-(i%n)-1];
		A[i%n] = a^b;
	}
	return A;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n, k;
    	cin>>n>>k;
    	vector<ll> A(n);
    	for(int i=0;i<n;i++)
    	{
    		cin>>A[i];
		}
		vector<ll> res = solve(A, k, n);
		for(int i=0;i<n;i++)
		{
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
