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

/* A helper function that stores inorder
   traversal of a tree rooted with node */
void storeInorder(struct Node* node, int inorder[], int* index_ptr)
{
    // Base Case
    if (node == NULL)
        return;
 
    /* first store the left subtree */
    storeInorder(node->left, inorder, index_ptr);
 
    /* Copy the root's data */
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry
 
    /* finally store the right subtree */
    storeInorder(node->right, inorder, index_ptr);
}
 
/* A helper function to count nodes in a Binary Tree */
int countNodes(struct Node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
 
// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
 
/* A helper function that copies contents of arr[]
   to Binary Tree. This function basically does Inorder
   traversal of Binary Tree and one by one copy arr[]
   elements to Binary Tree Nodes */
void arrayToBST(int* arr, struct Node* root, int* index_ptr)
{
    // Base Case
    if (root == NULL)
        return;
 
    /* first update the left subtree */
    arrayToBST(arr, root->left, index_ptr);
 
    /* Now update root's data and increment index */
    root->data = arr[*index_ptr];
    (*index_ptr)++;
 
    /* finally update the right subtree */
    arrayToBST(arr, root->right, index_ptr);
}
 
// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct Node* root)
{
    // base case: tree is empty
    if (root == NULL)
        return;
 
    /* Count the number of Nodes in Binary Tree so that
    we know the size of temporary array to be created */
    int n = countNodes(root);
 
    // Create a temp array arr[] and store inorder
    // traversal of tree in arr[]
    int* arr = new int[n];
    int i = 0;
    storeInorder(root, arr, &i);
 
    // Sort the array using library function for quick sort
    qsort(arr, n, sizeof(arr[0]), compare);
 
    // Copy array elements back to Binary Tree
    i = 0;
    arrayToBST(arr, root, &i);
 
    // delete dynamically allocated memory to
    // avoid memory leak
    delete[] arr;
}
 
/* Utility function to create a new Binary Tree Node */
struct Node* newNode(int data)
{
    struct Node* temp = new struct Node(data);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void EulerTour(Node* root, int* sum){
    if (root == NULL){
        return;
    }
    (*sum)+= root->data;
    if(root->left!= NULL){
        EulerTour(root->left, sum);
        (*sum)+= root->data;
    }
    if(root->right!= NULL){
        EulerTour(root->right, sum);
        (*sum)+= root->data;
    }
}
int main(){
    int n;
    cin >> n;
    vector<Node *> arr;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        Node* newNode = new Node(l);
        arr.push_back(newNode);
    }
    for (int i = 0; i < n-1; i++)
    {
        int index, edge;
        cin >> index;
        cin >> edge;
        index--; edge--;
        if(arr[index]->left != NULL){
            arr[index]->right = arr[edge];
        }else{
            arr[index]->left = arr[edge];
        }
    }
    // for (Node* v : arr)
    // {
    //     if(v->left)
    //         cout << v->left->data << " ";
    // }
    
    // printInorder(arr[0]);
    binaryTreeToBST(arr[0]);
    // cout << endl << endl;
    printInorder(arr[0]);
    cout << endl;
    int sum = 0;
    EulerTour(arr[0], &sum);
    cout << sum << endl;
}
