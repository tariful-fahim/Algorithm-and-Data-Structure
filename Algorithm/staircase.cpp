/*
 * problem link: https://leetcode.com/problems/climbing-stairs/
 * 			
 * 					3
 * 				  /	  \
 * 				 2     1
 * 				/ \   / \
 * 			   1   0  0  -1
 * 			  / \ 
 * 			 0   -1 
 */



#include<bits/stdc++.h>
using namespace std;
int dp[50];
int fibo(int n){
	if(n == 0 || n == 1)
		return 1;
	else if(dp[n] != -1)
		return dp[n];
	else
		return dp[n] = fibo(n-1)+fibo(n-2);
}
int main(){
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	
	cout<<fibo(n)<<endl;
}
