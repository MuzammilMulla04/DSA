#include<iostream>
using namespace std;

/* CodingNinjas */
#include<vector>
#include<limits.h>

int findSecondLargest(int n, vector<int>& arr) {
    int max1= INT_MIN;
    int max2= INT_MIN;
    
    for(int& num: arr) {
        if(num > max1) {
            max2= max1;
            max1= num;
        } else if(max1 > num && num > max2) {
            max2= num;
        }
    }
    
    return max2 == INT_MIN? -1: max2;
}


/* GeeksForGeeks */
#include<vector>

class Solution {
public:
    int getSecondLargest(vector<int>& arr) {
        int max1= -1;
        int max2= -1;
        
        for(int& num: arr) {
            if(num > max1) {
                max2= max1;
                max1= num;
            } else if(max1 > num && num > max2) {
                max2= num;
            }
        }
        
        return max2;
    }
};
