#include<iostream>
#include<vector>
using namespace std;
int  main(){
    vector<int> v={1,5,9,8,3,1};
    for(int i=0;i<v.size()-1;i++){
        int max = v[i];
        int index =i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<max){
                index=j;
                max = v[j];
            }
        }
        swap(v[i],v[index]);
    }
    for (auto i:v){
        cout<<i<<" ";
;    }
}