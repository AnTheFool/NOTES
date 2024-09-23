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



The Depth-First Traversal or the DFS traversal of a Graph is used to traverse a graph depth wise. That is, it in this traversal method, we start traversing the graph from a node and keep on going in the same direction as far as possible. When no nodes are left to be traversed along the current path, backtrack to find a new possible path and repeat this process until all of the nodes are visited.

We can implement the DFS traversal algorithm using a recursive approach. While performing the DFS traversal the graph may contain a cycle and the same node can be visited again, so in order to avoid this we can keep track of visited array using an auxiliary array. On each step of the recursion mark, the current vertex visited and call the recursive function again for all the adjacent vertices.

## Code for DFS

```cpp
#include<bits/stdc++.h> 
using namespace std; 

void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    cout<< s <<" ";
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

void DFS(vector<int> adj[], int V, int s){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    DFSRec(adj,s,visited);
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
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);

	cout << "Following is Depth First Traversal: "<< endl; 
	DFS(adj,V,0); 

	return 0; 
} 
```

## Code DFS for disconnected graphs

```cpp
#include<bits/stdc++.h> 
using namespace std; 

void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    cout<< s <<" ";
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

void DFS(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            DFSRec(adj,i,visited);
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
	addEdge(adj,3,4);

	cout << "Following is Depth First Traversal for disconnected graphs: "<< endl; 
	DFS(adj,V); 

	return 0; 
} 
```

## Code for counting components in an undirected graph

```cpp
#include<bits/stdc++.h> 
using namespace std; 

void DFSRec(vector<int> adj[], int s, bool visited[]) 
{ 	
    visited[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

int DFS(vector<int> adj[], int V){
    int count=0;
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {DFSRec(adj,i,visited);count++;}
    }
    return count;
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
	addEdge(adj,3,4);

	cout << "Number of connected components: "<< DFS(adj,V); 

	return 0; 
} 
```

## Applications with DFS

1. Detecting cycle in a graph 
A graph has cycle if and only if we see a back edge during DFS. So we can run DFS for the graph and check for back edges. (See [this](/https://people.csail.mit.edu/thies/6.046-web/recitation9.txt) for details) 

2. Path Finding 
We can specialize the DFS algorithm to find a path between two given vertices u and z.

i. Call DFS(G, u) with u as the start vertex. 

ii. Use a stack S to keep track of the path between the start vertex and the current vertex. 

iii. As soon as destination vertex z is encountered, return the path as the 
contents of the stack 

See [this]() for details. 

3. [Topological Sorting](/https://www.geeksforgeeks.org/topological-sorting/)

Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers. 

4. To test if a graph is [bipartite](/https://en.wikipedia.org/wiki/Bipartite_graph)
We can augment either BFS or DFS when we first discover a new vertex, color it opposite its parents, and for each other edge, check it doesn’t link two vertices of the same color. The first vertex in any connected component can be red or black! See this for details. 

5. Finding Strongly Connected Components of a graph A directed graph is called strongly connected if there is a path from each vertex in the graph to every other vertex. (See [this](/https://www.geeksforgeeks.org/strongly-connected-components/) for DFS-based algo for finding Strongly Connected Components) 

6. Solving puzzles with only one solution, such as mazes. (DFS can be adapted to find all solutions to a maze by only including nodes on the current path in the visited set.)

## Lowest Common Ancestor of a binary tree

![image](https://github.com/user-attachments/assets/a9917b61-74f9-45fc-839f-98c89f3009e5)

Output: 30

### Naive solution

The naive solution to finding the LCA (Least Common Ancestor) of a binary tree using a two-path array approach involves storing the paths from the root to each of the nodes whose lowest common ancestor is to be computed. Once these paths are obtained, we can traverse the paths and find the last node that is common to both paths. This node will be the LCA of the given nodes.

For example:

![image](https://github.com/user-attachments/assets/45db29c8-a247-498a-8bd0-187d2dd4ee7b)

Path from root to 5 = { 1, 2, 5 }
Path from root to 6 = { 1, 3, 6 }

We start checking from the 0 index. As both of the value matches (`pathA[0]` = `pathB[0]`), we move to the next index. `pathA[1]` is not equal to `pathB[1]`, there’s a mismatch so we consider the previous value. 

Detailed steps:

1. Find a path from the root to n1 and store it in a vector or array. 
2. Find a path from the root to n2 and store it in another vector or array. 
3. Traverse both paths till the values in arrays are the same. Return the common element just before the mismatch.

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    struct Node *left, *right;
};
 
Node* newNode(int k){
    Node* temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
 
bool findPath(Node* root, vector<int>& path, int k){
    if (root == NULL)
        return false;
 
    path.push_back(root->key);
 
    if (root->key == k)
        return true;
 
    if ((root->left && findPath(root->left, path, k))
        || (root->right && findPath(root->right, path, k)))
        return true;
 
    path.pop_back();
    return false;
}
int findLCA(Node* root, int n1, int n2){
    vector<int> path1, path2;
 
    if (!findPath(root, path1, n1)
        || !findPath(root, path2, n2))
        return -1;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}
 
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
```

## Efficient solution

This solution would just need one traversal and $O(h)$ extra space for recursive traversal. Also, it assumes that both $n_1$ and $n_2$ exist in the tree. It will not give the correct answer when only $n_1$ or $n_2$ exist.

### Idea

The idea is to traverse the tree starting from the root. If any of the given keys (n1 and n2) matches with the root, then the root is LCA (assuming that both keys are present). If the root doesn't match with any of the keys, we recur for the left and right subtree. 

- The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. 
- If both keys lie in the left subtree, then the left subtree has LCA also, 
- Otherwise, LCA lies in the right subtree.

### Illustration

![image](https://github.com/user-attachments/assets/27085222-5fed-4503-a058-b197e96eff06)

Find the LCA of 5 and 6

**Root** is pointing to the node with value 1, as its value doesn't match with { 5, 6 }. We look for the key in left subtree and right subtree.

- Left Subtree :
	- New Root = { 2 } ≠ 5 or 6, hence we will continue our recursion
	- New Root = { 4 } , it's left and right subtree is null, we will return NULL for this call
 	- New Root = { 5 } , value matches with 5 so will return the node with value 5
	- The function call for root with value 2 will return a value of 5
- Right Subtree :
	- Root = { 3 } ≠ 5 or 6 hence we continue our recursion
	- Root = { 6 } = 5 or 6 , we will return the this node with value 6 
	- Root = { 7 } ≠ 5 or 6, we will return NULL
	- So the function call for root with value 3 will return node with value 6
- As both the left subtree and right subtree of the node with value 1 is not NULL, so 1 is the LCA

### How to solve

Follow the steps below to solve the problem:

- We pass the root to a helper function and check if the value of the root matches any of n1 and n2. 
	- If YES, return the root
	- else recursive call on the left and right subtree
- Basically, we do pre-order traversal, at first we check if the root->value matches with n1 or n2. Then traverse on the left and right subtree.
- If there is any root that returns one NULL and another NON-NULL value, we shall return the corresponding NON-NULL value for that node.
- The node that returns both NON-NULL values for both the left and right subtree, is our Lowest Common Ancestor.

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

Node *lca(Node *root, int n1, int n2){
    if(root==NULL)return NULL;
    if(root->key==n1||root->key==n2)
        return root;
    
    Node *lca1=lca(root->left,n1,n2);
    Node *lca2=lca(root->right,n1,n2);
    
    if(lca1!=NULL && lca2!=NULL)
        return root;
    if(lca1!=NULL)
        return lca1;
    else
        return lca2;
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=20,n2=50;
	
	Node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
}
```
