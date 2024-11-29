#include<iostream>
#include <climits>
using namespace std;
int helper(int n){
    if(n==1)return 0;
    if(n==2 or n==3)return 1;
    int res=min(n%2==0?helper(n/2):INT_MAX,n%3==0?helper(n/3):INT_MAX);
    return 1+min(res,helper(n-1));
}
int main(){
cout<<helper(10);
}