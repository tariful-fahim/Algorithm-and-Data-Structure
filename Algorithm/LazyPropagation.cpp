/*
 * সেগমেন্ট ট্রি তে আমরা যখন কোন একটা নির্দিষ্ট পজিশনে মান পরিবর্তন করি তখন O(lgn) কমপ্লেক্সিটিতে করা যায়। 
 * কিন্তু যখন কোন একটা রেঞ্জের মধ্যে আমরা মান আপডেট করব তখন এটি O(nlgn) কমপ্লেক্সিটিতে পুছে যায় । সেই 
 * টাইম কমপ্লেক্সিটি কমানোর জন্য আমরা লেজি প্রোপাগেশন এর ব্যয়ভার করব। যেখানে সাম ভ্যালুর সাথে প্রোপাগেট 
 * ভ্যালু অ্যাড করব। যেটা ক্যারি দিয়ে বহন করে প্রত্যেক নোডের সাথে যোগ করে মান বের করতে হবে। */


#include<bits/stdc++.h>
using namespace std;
#define mx 10005
#define MX mx*4
int arr[mx];
struct info{
	int prop, sum;
	}tree[MX];
//initialize the segment tree
void init_segmentTree(int node, int beg, int end){
	if(beg == end){
		tree[node].sum = arr[beg];
		return;
	}
	int Left = node*2;
	int Right = node*2+1;
	int mid = (beg+end)/2;
	init_segmentTree(Left, beg, mid);
	init_segmentTree(Right, mid+1, end);
	tree[node].sum = tree[Left].sum+tree[Right].sum;
}
//Update data in a range
void Update(int node, int beg, int end, int i, int j, int newVal){
	if(i > end || j < beg)
		return;
	if(i <= beg && j >= end){
		tree[node].sum += ((end-beg+1)*newVal);
		tree[node].prop += newVal;
		return;
	}
	int Left = node*2;
	int Right = node*2+1;
	int mid = (beg+end)/2;
	Update(Left, beg, mid, i, j, newVal);
	Update(Right, mid+1, end, i, j, newVal);
	tree[node].sum = tree[Left].sum+tree[Right].sum+((end-beg+1)*tree[node].prop);
}
//Query
int Query(int node, int beg, int end, int i, int j, int carry){
	if(i > end || j < beg)
		return 0;
	if(i <= beg && j >= end){
		return tree[node].sum + (end-beg+1)*carry;
	}
	int Left = node*2;
	int Right = node*2+1;
	int mid = (beg+end)/2;
	int p1 = Query(Left, beg, mid, i, j, carry+tree[node].prop);
	int p2 = Query(Right, mid+1, end, i, j, carry+tree[node].prop);
	
	return p1+p2;
}
int main(){
	int n;
	cin >> n;
	//arr[0] = 0;
	memset(tree, 0,sizeof(tree));
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	
	init_segmentTree(1,1,n);
	Update(1, 1, n, 1, 5, 5);
	int res = Query(1 ,1 , n, 1, 6, 0);
	cout<<res<<endl;
	
	return 0;
}

