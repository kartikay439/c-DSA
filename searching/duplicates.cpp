class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     vector<int> v(1000001,0);
    //     for(auto i:nums){
    //         if(v[i]==1){
    //             return i;
    //         }
    //         v[i]=1;
    //     }
    //     return -1;
 
    // }

    //Memory efficient  -->  X   number diplicate more than 1
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n=nums.size()-1;
//         n=n*(n+1)/2;
//         int sum = 0;
//         // vector<int> v(1000001,0);
//         for(auto i:nums){
//            sum+=i;
//         }
//         return -n+sum;
 
//     }
};