#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
ll dp[105][105];
int g(int i,int j,vector<int>& v){
    ll result=0;
    for(int k=0;k<=j;k++){
        result+=(result%100+v[k]%100)%100;
    }
}

ll f(int i,int j,vector<int>& v){
if(i==j){
    return 0;
}
ll result=0;
for(int k=i;k<j;k++){
result=min(result,(f(i,k,v)+f(k+1,j,v)+g(i,k,v)*g(k+1,j,v)));
}

return result;

}