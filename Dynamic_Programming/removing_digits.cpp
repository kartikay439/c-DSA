#include<iostream>
#include<climits>
#include<vector>
using namespace std;
vector<int> countDigits(int n){
vector<int> ans;
while(n>0){
    if(n%10 != 0)
    ans.push_back(n%10);
    n/=10;
}
return ans;
}
int steps(int n,vector<int> &memo){
if(n==0)return 0;

if(n<=9)return 1;
if(memo[n]!=-1)return memo[n];
int min_step=INT_MAX;
for(int i :countDigits(n))
min_step=min(1+steps(n-i,memo),min_step);
return memo[n]=min_step;
}

int stepsTabulation(int nums){
vector<int> dp(1000005,-1);
dp[0]=0;
for(int i=1;i<10;i++){
    dp[i]=1;
}

for(int n=10;n<=nums;n++){
int min_step=INT_MAX;

for(int i :countDigits(n)){
   min_step=min(dp[n-i],min_step); 
}

dp[n]=1+min_step;
}
return dp[nums];
}

int main(){
    int x;
    cin>>x;
    vector<int> memo(1000005,-1);
    cout<<stepsTabulation(27);
}