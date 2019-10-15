#include<bits/stdc++.h>
using namespace std;

class Set {

public:
	int parent;
	int rank;
};

class Edge {

public:
	int src;
	int dest;
	int weight;
};

// use to find the parent worst case complexity O(log N)
int find(Set*set, int i) {
	if (set[i].parent != i) {
		set[i].parent = find(set, set[i].parent);
	}
	return set[i].parent;
}

void Union(Set* set, int x, int y) {
	int x_parent = find(set, x);
	int y_parent = find(set, y);
	cout << "Union-check";
	//setting parent of the node
	if (set[x_parent].rank > set[y_parent].rank)
		set[y_parent].parent = x_parent;

	else if (set[x_parent].rank < set[y_parent].rank)
		set[x_parent].parent = y_parent;

	//for Same rank choose any one...
	else {
		set[y_parent].parent = x_parent;
		set[x_parent].rank++;
	}
}

bool mycomp(Edge v1, Edge v2) {

	return v1.weight < v2.weight;
}

void KrushalAlgo(Edge *input, int n, int e) {

	sort(input, input + e, mycomp);

	Edge* output = new Edge[n - 1];
	Set* set = new Set[n];

	for (int i = 0; i < n; ++i)
	{
		set[i].rank = 0;
		set[i].parent = i;
	}
	// for(int k = 0;k<e;k++){
	// cout<<input[k].src<<" -> "<<input[k].dest<<endl;
	// }
	int counter = 0, i = 0;

	while (counter < n - 1) {
		Edge curEdge = input[i];
		int srcParent = find(set, curEdge.src);
		int destParent = find(set, curEdge.dest);

		if (srcParent != destParent) {
			output[cnt] = curEdge;
			Union(set, srcParent, destParent);
			cnt++;
		}
		i++;
	}
	int totalWeight = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		totalWeight += output[i].weight;
	}
	cout << totalWeight;
}



int main() {
	int n, e;
	cin >> n >> e;
	Edge*input = new Edge[e];

	for (int i = 0; i < e; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		input[i].src = s;
		input[i].dest = d;
		input[i].weight = w;
	}


	KrushalAlgo(input, n, e);

	return 0;
}