#include <bits/stdc++.h> 
using namespace std;

/* CodingNinjas */
void reverseArray(vector<int>& arr, int m) {
    for(int i= m+1, j= arr.size()-1; i<j; i++, j--)
        swap(arr[i], arr[j]);
}

/* GeeksForGeeks */
class Solution {
  public:
    void reverseArray(vector<int>& arr) {
        for(int i=0, j= arr.size()-1; i<j; i++, j--)
            swap(arr[i], arr[j]);
    }
};
