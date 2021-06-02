#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long pow(int a, int b)
{
	if(b == 0) return 1;

	if(b&1) // odd
		return (a*pow(a, b-1))%MOD;
	else
	{
		long long temp = pow(a, b/2);
		return (temp*temp)%MOD;
	}
}

vector<int> soln(vector<int>& A, vector<int>& B)
{
	sort(A.begin(), A.end());
	int n = A.size();
	for(int i=0;i<n;++i)
	{
		int root = sqrt(A[i]);
		int f = 0; // factors

		for(int j=1;j<=root;++j)
			if(A[i]%j == 0)
				f += (j == A[i]/j) ? 1 : 2;

		long long prod = pow(A[i], f/2)%MOD;
		if(f&1) // (odd) perf square number
			prod = (root * prod)%MOD;

		A[i] = prod;
	}

	vector<int> G;
	for(int i=n-1;i>=0;--i)
		for(int j=0;j<=i;++j)
			G.push_back(A[i]);

	sort(G.begin(), G.end(), greater<int>());

	for(int i=0;i<B.size();++i)
		B[i] = G[B[i] - 1];

	return B;
}



#define ll long long
#define MAX 100010
#define mod 1000000007

ll prod[MAX]; // To store product of divisor.

void preCompute(){
    if(prod[1] != 0){ // => function has already been called before.
        return;
    }
    for(ll i=1; i<MAX; i++){
        prod[i] = i;
    }
    for(ll i=2; i<MAX; i++){
        for(ll j=2*i; j<MAX; j+=i){
            prod[j] = (prod[j]*i)%mod;
        }
    }
}

vector<int> solve(vector<int> &a, vector<int> &b)
{
    preCompute(); // To store poduct of divisors of each element.
    
    ll i,j,k,n=a.size(),m=1e9+7;
    
    // Step 1
    vector<ll> freq(n);
    stack<ll> st;
    st.push(0);
    for(ll i=1;i<n;i++){
        while(!st.empty() && a[st.top()]<=a[i]){
            ll index=st.top();
            st.pop();
            ll left = index+1;
            ll right = (i-index);
            
            if(!st.empty()){
                left = index - st.top();
            }
            freq[index] = left*right;
        }
        st.push(i);
    }
    
    while(!st.empty()){
        ll index=st.top();
        st.pop();
        ll left = index+1;
        ll right = (n-index);
        
        if(!st.empty()){
            left = index - st.top();
        }
        freq[index] = left*right;
    }
    
    // Step 2
    vector<pair<ll, ll> > store(n);
    for(i=0;i<n;i++){
        ll x=prod[a[i]];
        store[i]=make_pair(prod[a[i]],freq[i]);
    }
    
    // Step 3
    sort(store.begin(), store.end());
    reverse(store.begin(), store.end());
    
    // Step 4
    for(i=1;i<n;i++) {
        store[i].second= store[i-1].second+ store[i].second;
    }
    
    // step 5
    vector<int> ans(b.size());
    for(i=0;i<b.size();i++){
        int l=1,r=n-1;
        if(store[0].second>=b[i]){
             ans[i]=store[0].first;
             continue;
        }
        while(l<=r){
            int mid=(l+r)/2;
            if(store[mid].second>=b[i] && store[mid-1].second<b[i]){
                ans[i] = store[mid].first;
                break;
            }
            else if(store[mid].second<b[i]) l=mid+1;
            else r=mid-1;
        }
    }
    return ans;
}

int main()
{
	vector<int> A = {39, 99, 70, 24, 49, 13, 86, 43, 88, 74, 45, 92, 72, 71, 90, 32, 19, 76, 84, 46, 63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45};
	vector<int> B = {1221, 360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838};
	vector<int> ans = soln(A, B);

	for(auto i : ans)
		cout << i << " ";
	cout << endl;

	// cout << ans[1220] << endl;

    return 0;
}	