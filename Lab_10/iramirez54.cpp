#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <limits>

using namespace std;

vector<int> adjacent[500], rev[500], sequenceNum;
vector< vector<int> > SCC;
bool visit[500] = {false};

void DFS(vector<int> graph[], vector<int> &sequenceNum, int i){
	visit[i] = true;
	for(int j = 0; j < graph[i].size(); j++){
		if(!visit[graph[i][j]]){
            DFS(graph, sequenceNum, graph[i][j]);
        }
		
	}
	sequenceNum.push_back(i);
}

void setFalse(int num_vertices){
	for (int i = 0; i < num_vertices; i++)
		visit[i] = false;
}

void graph(int edges){
	int u;
    int v;
	for(int i = 0; i < edges; i++){
        cin >> u;
        cin >> v;  
		adjacent[u].push_back(v);
	}
}

void traverse(int num_vertices){
	for(int i = 0; i < num_vertices; i++){
		for(int j = 0; j < adjacent[i].size(); j++){
			rev[adjacent[i][j]].push_back(i);
		}
	}
}

void reverse_traverse(){
	for(int i = 0; i < sequenceNum.size(); i++){
		if(!visit[sequenceNum[i]]) {
			vector<int> component;
			DFS(rev, component, sequenceNum[i]);
			SCC.push_back(component);
		}
	}
}

void output(int arr_vertices[],int num_vertices){
	for(int i = 0; i < num_vertices; i++){
		cout << arr_vertices[i] <<endl;
	}
}

int main(){
	int num_vertices;
    int edges; 
    int compare;

    cin >> num_vertices;
    cin >> edges;

	int arr_vertices[num_vertices];

	for(int i = 0; i < num_vertices; i++){
		arr_vertices[i] = i;
	}

	graph(edges);

	setFalse(num_vertices);

	for(int i = 0; i < num_vertices; i++){ 
		if(!visit[i]){
			DFS(adjacent, sequenceNum, i);
		}
	}

	traverse(num_vertices);

	setFalse(num_vertices);

	reverse(sequenceNum.begin(), sequenceNum.end());

	reverse_traverse(); 

	for(int i = 0; i < SCC.size(); i++){
		for(int j = 0; j < SCC[i].size(); j++){
			compare = SCC[i][j];
			for(int k = 0; k < num_vertices; k++){
				if(arr_vertices[k] == compare){
					arr_vertices[k] = *min_element(SCC[i].begin(), SCC[i].end());
				}
			}
		}
	}

	output(arr_vertices, num_vertices);
	
	return 0;
}