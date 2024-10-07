#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> tree;

int f(int node, int node_low, int node_high, int query_low, int query_high){
	if(node_low >= query_low && node_high <= query_high){
		return tree[node];
	}
	if(node_high < query_low || query_high < node_low){
		return INT_MAX;
	}

	int last_to_left = (node_low + node_high)/2;

	return min( f(2*node, node_low, last_to_left, query_low, query_high),  f(2*node+1, last_to_left+1, node_high, query_low, query_high) );
}

int main(){
	int n, t;
	cin >> n >> t;
	vector<int> arr(n);
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}

	while(__builtin_popcount(n)!=1){
		arr.push_back(INT_MAX);
		++n;
	}

	tree.resize(2*n);

	for(int i=0; i<n; ++i){
		tree[n+i] = arr[i];
	}

	for(int i=n-1; i>=1; --i){
		tree[i] = min(tree[2*i], tree[2*i + 1]);
	}

	for(int i=0; i<t; ++i){
		int low, high;
		cin >> low >> high;
		low--;
		high--;
		cout << f(1, 0, n-1, low, high) << "\n";
	}
}