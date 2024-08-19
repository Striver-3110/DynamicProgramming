#include<bits/stdc++.h>
using namespace std;

#define inf (1<<30)




class Solution {
public:
    // Approach 1: O(sqrt(n))
    // O(1)
        // int minSteps(int n) {

        //     int ans = 0;
        //     while(n % 2 == 0){
        //         n/=2;
        //         ans+=2;
        //     }
        //     for(int i = 3; i <= sqrt(n); i+=2){
        //         while(n % i == 0){
        //             n/=i;
        //             ans+= i;
        //         }
        //     }
        //     if(n > 1)ans += n;
        //     return ans;
        // }
    
    // Approach :2 

    // int solve(int sc, int cb, int n, set<pair<int,int>> &st){
    //     if( sc == n ){
    //         return 0;
    //     }
    //     if(sc > n)return inf ;

    //     if(st.find({sc, cb}) != st.end()){
    //         return inf;
    //     }else{
    //         st.insert({sc, cb});
    //     }
    //     int copy = 1 + solve(sc, sc, n, st);
    //     int paste = 1 + solve(sc + cb, cb, n, st);

    //     return min(copy, paste);
    // }

    // int minSteps(int n) {
    //     set<pair<int,int>> st;
    //     int screen = 1;
    //     int clipBoard = 0;
    //     return solve(screen, clipBoard, n, st);
    // }

    int dp[1001][1001];
    int solve(int sc, int cb, int n){

        if(sc == n){
            return  dp[sc][cb] = 0;
        }
        if(sc > n)return inf;

        if(dp[sc][cb] != -1)return dp[sc][cb];
        int copyPlusPaste = 1 + 1 + solve(sc*2, sc, n);
        int paste = 1 + solve(sc+cb, cb, n);
        return dp[sc][cb]=  min(copyPlusPaste, paste);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        memset(dp,-1,sizeof(dp));
        int screen = 1;
        // copy 1st A initially 
        int clipBoard = 1;
        return 1 + solve(screen, clipBoard, n);
    }
};



int main() {
    Solution sol;
    int n = 5;  // Example input
    int result = sol.minSteps(n);
    cout << "Minimum steps to get " << n << " 'A's: " << result << endl;
    return 0;
}