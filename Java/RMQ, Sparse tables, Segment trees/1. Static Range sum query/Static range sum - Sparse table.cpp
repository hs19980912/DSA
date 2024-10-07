#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
 
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