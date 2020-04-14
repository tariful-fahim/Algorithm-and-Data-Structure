/*
 * Finding the maximum sum of a sub array  in O(N) time complexity and O(1) space complexity */

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, max_sum = 0, max_end = 0;
	cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++)
		cin >> arr[i];
		
	for(int i = 0; i < n; i++){
		
		max_end = max(arr[i], max_end+arr[i]);// maximum of previous subarray and the current number of the indices
		if(i == 0)
			max_sum = max_end;
		else if(max_end > max_sum)
			max_sum = max_end;		
	}
	cout<<max_sum<<endl;
	
	return 0;
}

/*
 * 9
 * -2 1 -3 4 -1 2 1 -5 4 */
