#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int solve(vector<int> &coins,int sum){
    if(sum==0)return 0;
    int result=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(sum-coins[i]<0)continue;
        result=min(result,solve(coins,sum-coins[i]));
    }
    return result+1;
}

int main(){
    vector<int> coins={1,5,7};
    cout<<solve(coins,11);
}