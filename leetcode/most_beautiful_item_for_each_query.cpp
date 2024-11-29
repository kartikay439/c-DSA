#include<iostream>
#include<vector>
using namespace std;

int quick_sort_helper(vector<vector<int>> &price, int i, int j) {
        vector<int> pivot = price[j];
        int c = i - 1;
        for (int s = i; s < j; s++) {
            if (price[s][0] < pivot[0] || (price[s][0] == pivot[0] && price[s][1] < pivot[1]) ) {
                c++;
                swap(price[c],price[s]);
            } 
        }
        // till c all are less
        swap(price[c+1],price[j]);
        return c + 1;
    }

    // Quick sort for two-dimensional vector
    void quick_sort(vector<vector<int>> &price, int i, int j) {
        if (i < j) {
            // Divide index
            int p = quick_sort_helper(price, i, j);
            quick_sort(price, i, p - 1);
            quick_sort(price, p + 1, j);
        }
    }

    int binarySearch(vector<vector<int>> &price, int target) {
    int i = 0;
    int j = price.size() - 1;
    int mid = 0;
    int lastOccurrence = -1;  // Tracks the last occurrence of the target
    int nearestLessIndex = -1;  // Tracks the nearest less value index if target not found

    while (i <= j) {
        mid = i + (j - i) / 2;

        if (price[mid][0] == target) {
            lastOccurrence = mid;  // Update last occurrence of target
            i = mid + 1;  // Move right to find the last occurrence
        } else if (price[mid][0] < target) {
            nearestLessIndex = mid;  // Update nearest less index
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

    if (lastOccurrence != -1) {
        cout << "Last occurrence of target found at index: " << lastOccurrence << " ";
        return lastOccurrence;
    } else if (nearestLessIndex != -1) {
        cout << "Target not found. Nearest less found at index: " << nearestLessIndex << " ";
    } else {
        cout << "No element less than target found. ";
    }

    return nearestLessIndex;
}

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        quick_sort(items, 0, items.size() - 1);
        for (int i = 0; i < queries.size(); i++) {
            queries[i] = items[binarySearch(items, queries[i])][1];
        }
        return queries;
    }

int main(){
    vector<vector<int>> v = {{1,2}} ;
    vector<int> queries = {1};
    //2 4 5 5 6 6
     for(auto i : v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"   ";
    }
    cout<<endl;
    // quick_sort(v,0,4);

    for(auto i : v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"   ";
    }
    maximumBeauty(v,queries);
    for(auto i:queries){
        cout<<i<<"  ";
    }
}



