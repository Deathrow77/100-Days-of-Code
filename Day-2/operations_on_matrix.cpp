// Link - https://www.codechef.com/OCT19B/problems/MARM
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void addRow(vector<ll> &A, int &row)
{
    for(ll i=0;i<n;i++)
    {
        A[row][i]++;
    }
}


void addColumn(vector<ll> &A, int &column)
{
    for(ll i=0;i<m;i++)
    {
        A[i][column]++;
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n, m, q;
    	cin>>n>>m>>q;
    	vector<vector<ll>> A(n, vector<ll>(m, 0));
        ll a, b;
        vector<pair<ll, ll>> queries;
        for(ll i=0;i<q;i++)
        {
            cin>>a>>b;
            queries.push_back(make_pair(a,b));
        }
        for(ll i=0;i<q;i++)
        {
            ll row = queries[i].first;
            ll column = queries[i].second;
            addRow(A, row);
            addColumn(A, column);
        }
        ll count = 0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(A[i][j]&1!=0)
                {
                    count++;
                }
            }
        }
        cout<<count<<endl;
	}
	
	return 0;
}
