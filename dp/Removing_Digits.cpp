#include<bits/stdc++.h>
using namespace std;

int slow(int n){
    int ans = 0;
    while(n > 0){
        int maxi = n%10;
        int x = n;
        while(x > 0){
            maxi = max(maxi, x%10);
            x /= 10;
        }
        n -= maxi;
        ans++;
    }
    return ans;
}

int main(){
    int n;  
    cin>> n;
    cout<<slow(n)<<endl;
}