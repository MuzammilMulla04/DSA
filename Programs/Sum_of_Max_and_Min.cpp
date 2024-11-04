#include<bits/stdc++.h>
using namespace std;

// CodingNinjas
// 1. Ternary Operator
int sumOfMaxMin(int arr[], int n) {
	int minimum= INT_MAX;
	int maximum= INT_MIN;

	for(int i=0; i<n; i++) {
		minimum= arr[i] < minimum? arr[i]: minimum;
		maximum= arr[i] > maximum? arr[i]: maximum;
	}
	return minimum+maximum;
}

// 2. Built-in Functions
int sumOfMaxMin(int arr[], int n) {
	int minimum= INT_MAX;
	int maximum= INT_MIN;

	for(int i=0; i<n; i++) {
		minimum= min(minimum, arr[i]);
		maximum= max(maximum, arr[i]);
	}
	return minimum+maximum;
}