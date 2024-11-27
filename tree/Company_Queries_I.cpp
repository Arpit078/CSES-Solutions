#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void init() {
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    // init();
    int n, q;
    cin >> n >> q;
    

    // // O(n) approach
    // for(int i=0;i<q;i++){
    //     int x, k;
    //     cin >> x >> k;
    //     int boss;
    //     while(k--){
    //         boss = bosses[x];
    //         x = boss;
    //     }
    //     cout<<boss<<endl;
    // }
    
    // Binary lifting 
    int height = ceil(log2(n));
    vector<vector<int>> up(n+1, vector<int>(height+1, -1));
    for(int i=2; i<=n; i++){
        cin>>up[i][0];
        
    }
    for(int node=2;node<=n;node++){
        for(int j=1; j<=height; j++){
            int i = node;
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=height;j++){
    //         cout<<up[i][j] << " ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        int x, k;
        cin >> x >> k;
        for (int j = height; j >= 0; j--) {
            if (k & (1 << j)) {
                x = up[x][j];
                if (x == -1) break; 
            }
        }
        cout<<x<<endl;
    }
    return 0;
    
}