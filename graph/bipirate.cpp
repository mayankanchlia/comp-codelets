#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > graph(1123);
bool bipartite(int n){
	int visited[n];
	for(int i =0 ; i < n ; i++)visited[i] =-1;
	for(int source =0 ; source < n ; source++ ){
	queue<pair<int,int> > q;
	q.push(make_pair(source,0));
	while(!q.empty()){
		pair<int,int>temp = q.front();q.pop();
		visited[temp.first] = temp.second;
		cout << temp.first << " " << temp.second << endl;
		for(int i =0 ; i < graph[temp.first].size();i++){
			if(visited[graph[temp.first][i]]==-1){
				pair<int , int>  temp1;
				temp1.first = graph[temp.first][i];
				//cout << temp1.first << " ";
				temp1.second = temp.second == 0 ? 1 :0;
				q.push(temp1);
			}
			else{
				if(visited[graph[temp.first][i]] == temp.second) cout << " not"<< endl;
			}
		}
	}
}
	return false;
}
int main(int argc ,char ** argv){
	int n, m;
	cin >> n >> m;

	for(int i = 0 ; i < m ; i++){
		int a , b ;cin >> a>> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	//cout << graph[0].size()<<endl;
	bipartite(0,n);
}