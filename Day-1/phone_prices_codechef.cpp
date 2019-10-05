// https://www.codechef.com/OCT19B/problems/S10E

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	vector<ll> A(n);
    	ll minimum = INT_MAX;
    	int count = 1;
    	for(int i=0;i<n;i++)
    	{
    		cin>>A[i];
		}
		deque<ll> q;
		q.push_back(A[0]);
		minimum = A[0];
		for(int i=1;i<5;i++){
			if(A[i]<minimum){
				count++;
				minimum = A[i];
			}
			q.push_back(A[i]);
		}
		for(int i=5;i<n;i++){
		    minimum = *min_element(q.begin(), q.end());
			if(A[i]<minimum){
				count++;
			}
			q.pop_front();
			q.push_back(A[i]);
		}
		cout<<count<<endl;
	}
	return 0;
}
