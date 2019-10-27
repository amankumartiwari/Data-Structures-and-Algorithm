#include <bits/stdc++.h>
using namespace std;

void buildTree(int* arr , int *tree , int start, int last, int treeNode){

if(start==last){
    tree[treeNode] = arr[start];
    return;
}

int mid= (start+last)/2;

buildTree(arr,tree,start,mid,2*treeNode);
buildTree(arr,tree,mid+1,last,2*treeNode+1);

tree[treeNode] = tree[2*treeNode] + tree[2*treeNode +1];

}

int main()
{
    int n;//size of array
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int*tree= new int[2*n];
    buildTree(arr,tree,0,n-1,1);
cout<<"tree is\n";
for(int i=1;i<2*n;i++)
    cout<<tree[i]<<"\n";
}
