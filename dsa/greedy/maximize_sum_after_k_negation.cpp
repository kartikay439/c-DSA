#include "iostream"
#include "cmath"
using namespace std;

// Brute Force
void fun(int arr[],int &maxSum,int current_sum,int index,int n,int k){
    // if(index>=sizeof(arr)/sizeof(arr[0])){
    if(index>=n){

        maxSum=max(maxSum,current_sum);
        return;
    }
    if(index!=n-k){
    fun(arr,maxSum,current_sum+arr[index],index+1,n,k);
    }
    else{
    arr[index]=arr[index]*-1;
    fun(arr,maxSum,current_sum+arr[index],index+1,n,k-1);
    }
    if(k>0){
    for(int i=1;i<=k;i++){
    arr[index]=arr[index]*pow(-1,i);
    fun(arr,maxSum,current_sum+arr[index],index+1,n,k-i);
    }
    }
}

//2,-3,-1,5,-4   ->   13

int main(){
    int maxSum=0;
    int arr[] = {2,-3,-1,5,-4};
    cout <<"MAX SUM : "<<maxSum;

    fun(arr,maxSum,0,0,5,2);
    cout <<"MAX SUM : "<<maxSum;
    // return 0;
}