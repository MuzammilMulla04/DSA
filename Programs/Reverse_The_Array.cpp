#include <bits/stdc++.h> 
using namespace std;

void reverseArray(vector<int>& arr, int m) {
    for(int i= m+1, j= arr.size()-1; i<j; i++, j--)
        swap(arr[i], arr[j]);
}