#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace::std;

int nodes;
int rootNode;
vector<int> child[200001];
bool visited[200001];
int height[200001];
int arr[200001][18];
int ourLOG;
// floor( log2(200000) ) = 17;

void preProcess_dfs(int curNode, int curHeight){
	if(curNode == -1)	return;

	height[curNode] = curHeight;
	
	if(child[curNode][0]!=-1){
		preProcess_dfs(child[curNode][0], curHeight + 1);
	}
	if(child[curNode][1]!=-1){
		preProcess_dfs(child[curNode][1], curHeight + 1);
	}
}

void preProcess_bfs(){
	queue<int> q;
	int curHeight = 1;
	visited[rootNode] = true;
	arr[rootNode][0] = -1;
	q.push(rootNode);
	while(q.size()){
		int curSize = q.size();
		for(int i=0; i<curSize; ++i){
			int curNode = q.front();
			q.pop();
			visited[curNode] = true;
			height[curNode] = curHeight;
			for(int j=0; j<child[curNode].size(); ++j){
				if(visited[child[curNode][j]] == false){
					q.push(child[curNode][j]);
					visited[child[curNode][j]] = true;
					arr[child[curNode][j]][0] = curNode;
				}
			}	
		}
		curHeight+=1;
	}
}

void preProcess(){
	for(int j=1; j<=17; j++){
		for(int i=1; i<=nodes; ++i){
			int x = arr[i][j-1];
			if(x == -1)
				arr[i][j] = -1;
			else
				arr[i][j] = arr[x][j-1];
		}
	}
}

int jump(int node, int h){
    /*
    cout << "IN JUMP" << endl;
    cout <<" NODE: " << node << " h:" << h << endl;
    */
	int ans = node;
	for(int i=0; i<=ourLOG; ++i){
		if(h & 1<<i){
		    // cout << "IN jump i: " << i << endl;
			ans = arr[ans][i];
			if(ans == -1)	return -1;
		}
	}
	return ans;
}

int findLCA(int n1, int n2){
	if(n1 == n2)	return n1;
	if(height[n1] < height[n2]){
		n2 = jump(n2, height[n2] - height[n1]);
	}else{
		n1 = jump(n1, height[n1] - height[n2]);
	}
	// cout << "AFTER JUMPING, n1:" << n1 << "  n2:" << n2 << endl;
	// n1 and n2 are at the same height now
	if(n1 == n2)	return n1;
	for(int j=ourLOG; j>=0; --j){
		if(arr[n1][j]!=-1 && arr[n1][j]!=arr[n2][j]){
			n1 = arr[n1][j];
			n2 = arr[n2][j];
		}
	}

	return arr[n1][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	nodes = n;
	ourLOG = log2(nodes);

	int node1, node2;
	for(int i=1; i<nodes; ++i){
		cin >> node1 >> node2;
		child[node1].push_back(node2);
		child[node2].push_back(node1);
		visited[node1] = false;
		visited[node2] = false;
	}
	// Taking the last node2 as the ROOT
	rootNode = node2;
	preProcess_bfs();
	preProcess();
    
    /*
    cout << "rootNode: " << rootNode << endl;
	cout << "PRINTING arr" << endl;
	cout << "arr[1][0], arr[1][1], arr[1][2]: " << arr[1][0] << "  " << arr[1][1] << "  " << arr[1][2] << endl;
    cout << "arr[2][0], arr[2][1], arr[2][2]: " << arr[2][0] << "  " << arr[2][1] << "  " << arr[2][2] << endl;
    cout << "arr[3][0], arr[3][1], arr[3][2]: " << arr[3][0] << "  " << arr[3][1] << "  " << arr[3][2] << endl;
    cout << "arr[4][0], arr[4][1], arr[4][2]: " << arr[4][0] << "  " << arr[4][1] << "  " << arr[4][2] << endl;
    cout << "arr[5][0], arr[5][1], arr[5][2]: " << arr[5][0] << "  " << arr[5][1] << "  " << arr[5][2] << endl;
    */

	int a, b;
	for(int i=0; i<q; ++i){
		cin >> a >> b;
		int lca = findLCA(a, b);
		/*
		cout << "LCA:" << lca << endl;
		cout << "height[a]: " << height[a] << endl;
		cout << "height[b]: " << height[b] << endl;
		cout << "height[lca]: " << height[lca] << endl;
		*/
		cout << height[a] - height[lca] + height[b] - height[lca] << "\n";
	}

}
