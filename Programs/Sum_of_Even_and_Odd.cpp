#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int evenSum= 0, oddSum= 0;
	while(n != 0) {
		int digit= n%10;
		if(digit&1) {
			oddSum += digit;
		} else {
			evenSum += digit;
		}
		n /= 10;
	}

	cout << evenSum << " " << oddSum;
}