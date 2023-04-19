#include <iostream>
#include <vector>


using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout <<" "<< node->data;
    printInorder(node->right);
}

void mergeVector(vector<Node *> vector1, vector<Node *> vector2){
    for (int i = 0; i < vector2.size(); i++)
    {
        vector1.push_back(vector2[i]);
    }
}

vector<Node *> inorderBinaryTree(Node* root){
    vector<Node *> inorderBinaryTreeNodes;
    if (root==NULL){
        return inorderBinaryTreeNodes;
    }
    mergeVector(inorderBinaryTreeNodes, inorderBinaryTree(root->left));
    inorderBinaryTreeNodes.push_back(root);
    mergeVector(inorderBinaryTreeNodes, inorderBinaryTree(root->right));
}
int comparator(const struct Node* n1, const struct Node* n2){
    return n1->data < n2->data;
}
void treeFromInorder(vector<Node *> inorderTree, Node* root, int* index_ptr){
    if (root == NULL)
        return;
 
    treeFromInorder(inorderTree, root->left, index_ptr);
 
    root->data = inorderTree[*index_ptr]->data;
    (*index_ptr)++;
    treeFromInorder(inorderTree, root->right, index_ptr);
}
void BinarySearchTreeFromBinaryTree(Node* root){
    vector<Node *> inorderTree = inorderBinaryTree(root);
    Node* arr[] = {};
    for (int i = 0; i < inorderTree.size(); i++)
    {
        arr[i] = inorderTree[i];
    }
    sort(inorderTree.begin(), inorderTree.end());
    treeFromInorder(inorderTree, root, 0);
}

int main(){
    
}
