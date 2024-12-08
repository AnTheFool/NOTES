#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<string> graph(1000);
vector<vector<char> > steps(1000, vector<char>(1000));
bool visited[1000][1000];
pair<ll, ll> start, dest;
stack<char> ans;
ll n, m;

// function to check whether the current cell is unvisited,
// unblocked and inside the grid
bool is_valid(ll x, ll y)
{
    return (x >= 0 && x < n && y >= 0 && y < m
            && graph[x][y] != '#'
            && visited[x][y] == false);
}

// Function to backtrack and extract the path from B to A
void backtrack(ll x, ll y)
{
    if (steps[x][y] != 'X') {
        char ch = steps[x][y];
        ans.push(ch);
        // Move one cell up
        if (ch == 'U')
            backtrack(x + 1, y);
        // Move one cell down
        else if (ch == 'D')
            backtrack(x - 1, y);
        // Move one cell left
        else if (ch == 'L')
            backtrack(x, y + 1);
        // Move one cell right
        else if (ch == 'R')
            backtrack(x, y - 1);
    }
}

// function to run bfs and find the shortest path from A to
// B
bool bfs(ll x, ll y)
{
    steps[x][y] = 'X';
    bool flag = false;
    // queue to run bfs across the grid
    queue<pair<ll, ll> > q;
    q.push({ x, y });
    while (!q.empty()) {
        pair<ll, ll> ele = q.front();
        x = ele.first;
        y = ele.second;
        q.pop();
        // If we have reached the destination
        if (graph[x][y] == 'B') {
            flag = true;
            break;
        }
        visited[x][y] = true;
        // Move Up
        if (is_valid(x - 1, y)) {
            visited[x - 1][y] = true;
            steps[x - 1][y] = 'U';
            q.push({ x - 1, y });
        }
        // Move Right
        if (is_valid(x, y + 1)) {
            visited[x][y + 1] = true;
            steps[x][y + 1] = 'R';
            q.push({ x, y + 1 });
        }
        // Move Down
        if (is_valid(x + 1, y)) {
            visited[x + 1][y] = true;
            steps[x + 1][y] = 'D';
            q.push({ x + 1, y });
        }
        // Move Left
        if (is_valid(x, y - 1)) {
            visited[x][y - 1] = true;
            steps[x][y - 1] = 'L';
            q.push({ x, y - 1 });
        }
    }
    // If there is a path from A to B, print the path
    if (flag) {
        backtrack(x, y);
        return true;
    }
    else
        return false;
}
int main()
{
    int n, m; cin >> n >> m;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'A')
                start = { i, j };
            else if (graph[i][j] == 'B')
                dest = { i, j };
        }
    }
    // Check if there is a path from A to B
    if (bfs(start.first, start.second)) {
        cout << "YES" << endl << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
    }
    else
        cout << "NO" << endl;
}
