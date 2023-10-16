#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
    Node* left;
    Node* right;
    int data;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPosition(int in[], int ele, int n){
    for(int i = 0; i<n; i++){
        if(in[i] == ele) return i;  
    }
    return -1;
}

Node* solve(int in[], int preOrder[], int &index, int start, int end, int n){
    if(index >= n || start > end) return NULL;
    int element = preOrder[index++];
    Node* root = new Node(element);
    int pos = findPosition(in, element, n);

    //recurrsive calls
    root->left = solve(in, preOrder, index, start, pos-1, n);
    root->right = solve(in, preOrder, index, pos+1, end, n);

    cout<<root->data<<endl;
    return root;
}

Node* buildtree(int in[], int preOrder[], int n){
    int preOrderIndex = 0;
    Node* ans = solve(in, preOrder, preOrderIndex, 0, n-1, n);
    return ans;
}

int main(){
    int in[] = {3, 1, 4, 0, 5, 2};
    int preOreder[] = {0, 1, 3, 4, 2, 5};
    buildtree(in, preOreder, 6);
    return 0;
}