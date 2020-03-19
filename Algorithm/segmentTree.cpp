#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx*3];
//intialize the tree
void init(int b, int e, int node){
	//leaf node
	if(b == e){
		tree[node] = arr[b];
		return;
	}

	int Left = node*2;
	int Right = node*2+1;
	int mid = (b+e)/2;

	init(b, mid, Left);
	init(mid+1, e, Right);
	tree[node] = tree[Left]+tree[Right];
}
//query function
int query(int node, int b, int e, int i, int j){
	//when range doesnt intersect within the range
	if(i > e || j < b)
		return 0;
	//when the range intersect inside the query
	if(i <= b && j >= e)
		return tree[node];
	//when it will intersect with one side
	int Left = node*2;
	int Right = node*2+1;
	int mid = (b+e)/2;
	int p1 = query(Left, b, mid, i, j);
	int p2 = query(Right, mid+1, e, i, j);

	return p1+p2;

}
//update function
void Update(int node, int b, int e, int i, int newValue){
	if(i > e || i < b)
		return;
	if(i <= b && i >= e){
		tree[node] = newValue;
		return;
	}
		//return tree[node] = newValue;
	int Left = node*2;
	int Right = node*2+1;
	int mid = (b+e)/2;
	Update(Left, b, mid, i, newValue);
	Update(Right, mid+1, e, i, newValue);

	tree[node] = tree[Left] + tree[Right];
}
int main(){
	int i, j, n;
	cin >> n;

	for(i = 1; i <= n; i++){
		cin >> arr[i];
	}
	init(1, n, 1);
	int res = query(1,1,n,3,5);
	Update(1,1,n,5,9);
	res = query(1,1,n,3,5);

	cout<<res<<endl;

	return 0;
}
