1. Static Range Sum query
2. Static Range Min query


### Sparse table
Basically a 2D matrix m[power][start]
```cpp
int arr[200001];
long long int m[18][200001]; // m[power][start]
int len;
 
long long int RangeSum(int l, int r){
    int curLen = r - l + 1;
    int start = l;
    long long int sum = 0l;
    for(int i=0; i<=17 && curLen>0; ++i){
        if(curLen & 1){
            sum += m[i][start];
            start += (1 << i);
        }
        curLen = curLen>>1;
    }
    return sum;
}
 
void pre_processing(){
    for(int i=0; i<len; ++i){
        m[0][i] = arr[i];
    }
 
    for(int power=1; power<=log2(len); ++power){
        for(int start=0; start+(1<<(power-1)) < len; ++start){
            m[power][start] = m[power-1][start] + m[power-1][start + (1<<(power-1))];
        }
    }
}
 
int main(){
    int n, t;
    cin >> n >> t;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    len = n;
 
    pre_processing();
 
    int l, r;
    for(int i=0; i<t; ++i){
        cin >> l >> r;
        long long int ans = RangeSum(l-1, r-1);
        cout << ans << "\n";
    }
 
    return 0;
}
```


### Segment Tree

Implemented using an array, index of the array start from [1... 2*n-1] eg, for 8 elements, our arr will of size 16, but will contain elements from index 1 to 15.

1. Pad 0's in the original array to make len in form 2^n.
2. make the Segment tree.

```cpp
vector<long long int> tree;

long long int f(int node, int node_low, int node_high, int query_low, int query_high){
	if(query_low <= node_low && query_high >= node_high){
		return tree[node];
	}
	if(query_high < node_low || node_high < query_low){
		return 0;
	}
	int last_to_left = (node_low + node_high)/2;

	return f(2*node, node_low, last_to_left, query_low, query_high)
		 + f(2*node + 1, last_to_left+1, node_high, query_low, query_high);
}


int main(){
	int n, t;
	cin >> n >> t;
	vector<int> arr(n);
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}

	while(__builtin_popcount(n) != 1){
		arr.push_back(0);
		n++;
	}

	tree.resize(2*n);

	for(int i=0; i<n; ++i){
		tree[n+i] = arr[i];
	}

	for(int i=n-1; i>=1; i--){
		tree[i] = tree[2*i] + tree[2*i+1];
	}

	for(int i=0; i<t; ++i){
		int low, high;
		cin >> low >> high;
		low--;
		high--;
		cout << f(1, 0, n-1, low, high) << "\n";
	}
}
```