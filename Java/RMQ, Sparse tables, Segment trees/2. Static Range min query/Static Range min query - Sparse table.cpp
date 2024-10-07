// Static Range Miminum Queries - CSES 
 
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
 
int arr[200001];
int m[18][200001];  // m[power][start];  power:[0, log2(200000)]
                    //                   power:[0...17]
int len;
int ourLog;
 
int rmq(int l, int r){
    int power = log2(r-l+1);
    return min(m[power][l], m[power][r+1-(1<<power)]);
}
 
void pre_processing(){
    // Here we have to fill the m sparse table
    for(int i=0; i<len; ++i){
        m[0][i] = arr[i];
    }
 
    for(int power=1; power<=ourLog; ++power){
        for(int start=0; (start + (1<<(power-1))) < len; ++start ){
            m[power][start] = min( m[power-1][start] , m[power-1][start + (1<<(power-1))] );
        }
    }
}
 
int main(){
    int n,t;
    cin >> n >> t;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
 
    len = n;
    ourLog = log2(n);
 
    pre_processing();   // This populates the m[][] 
 
    int l,r;
 
    for(int i=0; i<t; ++i){
        cin >> l >> r;
        cout << rmq(l-1, r-1) << "\n";
    }
 
    return 0;
}