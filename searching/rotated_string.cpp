#include<iostream>
using namespace std;
int main(){
     int arr[] = {1,2};
     int low=0;
     int target = 8;
     int high=1;
     int pivot = -1;
     int n=2;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(mid==0)low=1;
        else if(mid==n-1)high=n-2;
        else if(arr[mid]<arr[mid-1] &&  arr[mid]<arr[mid+1]){
            pivot = mid;
            break;
        }
        else if(arr[mid]>arr[mid-1] &&  arr[mid]>arr[mid+1]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
     }
     cout<<pivot;

     //now you can search in pivot-->high  and   low-->pivot-1   because they both are sorted

}