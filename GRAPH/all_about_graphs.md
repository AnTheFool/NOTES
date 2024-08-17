# ***BFS (Breadth First Traversal)***

The ***Breadth First Traversal*** or ***BFS*** traversal of a graph is similar to that of the Level Order Traversal of Trees.

The BFS traversal of Graphs also traverses the graph in levels. It starts the traversal with a given vertex, visits all of the vertices adjacent to the initially given vertex and pushes them all to a queue in order of visiting. Then it pops an element from the front of the queue, visits all of its neighbours and pushes the neighbours which are not already visited into the queue and repeats the process until the queue is empty or all of the vertices are visited.

The BFS traversal uses an auxiliary boolean array say $visited[]$ which keeps track of the visited vertices. That is if $visited[i] = true$ then it means that the $i^{th}$ vertex is already visited.

## ***Complete Algorithm:***
1. Create a boolean array say visited[] of size V+1 where V is the number of vertices in the graph.
2. Create a Queue, mark the source vertex visited as visited[s] = true and push it into the queue.
3. Until the Queue is non-empty, repeat the below steps:
    - Pop an element from the queue and print the popped element.
    - Traverse all of the vertices adjacent to the vertex poped from the queue.
    - If any of the adjacent vertex is not already visited, mark it visited and push it to the queue.

## ***Versions***

### Given an undirected graph and a source vertex 's' ,print B.F.S. from given source.

```cpp
#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int V, int s) 
{ 
	bool visited[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false;
	queue<int>  q;
	visited[s] = true; 
	q.push(s); 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
} 

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);
	cout << "Following is Breadth First Traversal: "<< endl; 
	BFS(adj,V,0); 
	return 0; 
} 
```

### B.F.S on disconnected graphs.

```cpp
#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int s, bool visited[]) { 	
    queue<int>  q;
	visited[s] = true; 
	q.push(s); 
	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
}

void BFSDin(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            BFS(adj,i,visited);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);
	cout << "Following is Breadth First Traversal: "<< endl; 
	BFSDin(adj,V); 
	return 0; 
} 
```

### Print number of islands in a graph (or number of connected components in a graph).

```cpp
#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int s, bool visited[]) { 	
    queue<int>  q;
	visited[s] = true; 
	q.push(s); 
	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();	 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
}

int BFSDin(vector<int> adj[], int V){
    bool visited[V]; int count=0;
	for(int i = 0;i<V; i++) 
		visited[i] = false;	
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {BFS(adj,i,visited);count++;}
    }
    return count;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);
	cout << "Number of islands: "<<BFSDin(adj,V); 
	return 0; 
} 
```

# ***Applications of BFS***

1. Shortest path in an unweighted graph

2. Crawlers in search engines

3. Peer-to-peer networks

4. Social networking search

5. In Garbage collection (Cheney's algorithm)

6. Cycle detection

7. Ford Fulkerson Algorithm

8. Broadcasting

# ***DFS (Depth-First search)***