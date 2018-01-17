#include <iostream>
#include <vector>
using namespace std;
int n , m ;
vector<vector<int> > graph(11234) ;
struct subset{
	int parent , rank;
};

subset arr[11234];
int find(int a){
	if(arr[a].parent != a){
		arr[a].parent = find( arr[a].parent);
	}
	return arr[a].parent;
}
void Union(int a , int b) {
	int x = find(a);
	int y = find(b);
	if(x == y) return ;
	if(arr[x].rank < arr[y].rank){
		arr[x].parent = y;
	}
	else if (arr[x].rank > arr[y].rank){
		arr[y].parent = x ;
	}
	else {
		arr[y].parent = x;
		arr[x].rank ++;
	}
}
int main (int argc ,char ** argv){
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int a , b ; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}	
	for(int i =0 ; i < n ; i++){
		arr[i].parent = i;
		arr[i].rank = 0;
	}

}