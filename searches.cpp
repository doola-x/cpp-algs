#include <iostream>

using namespace std;

//implement dfs and bfs

class TestData{
public:
	int nodes [8][2];
	bool visited[8];

	TestData() {
	
	}

	~TestData(){
		//do some deletion?
	}

	void addNode(int node, int parent) {
		nodes[node][0] = node;
		nodes[node][1] = parent;
		visited[node] = false;
	}
};

int bfs(int* root){
	//same thing as dfs kind of right?
	//

	return 0;
}

void dfs(TestData data, int node){
	//implement this with recursion, pass the root node as an int pointer
	//check header node and set, while equal recursively pass pointer?
	//if 0, passes to 1, and 2, stops with 3, no action
	// before 2, 1 recursively passes to 3 and 4, 7 stops with no action
	// before 4, 3 recursively passes to 7, 5 sees no action
	// 4 passes nowhere
	// 5 passes nowehre 
	// 6 passes nowhere
	if (data.visited[node]){
		return;
	}

	data.visited[node] = true;
	cout << "visited node: " << node << endl;
	for (int i = 0; i < 8; i++){
		if (data.nodes[i][1] == node){
			dfs(data, data.nodes[i][0]);
		}
	}
}

int main(){
	cout << "beginning bfs and dfs implementation program." << endl;
	cout << "beep boop" << endl;

	cout << "beginning dfs test run..." << endl;
	TestData obj;
	obj.addNode(0, -1);
	obj.addNode(1, 0);
	obj.addNode(2, 0);
	obj.addNode(3, 1);
	obj.addNode(4, 1);
	obj.addNode(7, 3);
	obj.addNode(5, 2);
	obj.addNode(6, 2);

	dfs(obj, 0);

	return 0;
}