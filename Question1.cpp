#include <iostream>
#include <vector>

// using the standard namespace
using namespace std;

// define a struct Node to hold the binary tree nodes
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int d){
    data = d;
    left = right = NULL;
    }
};

// function to print the preorder traversal of a binary tree
void printPreorder(Node *root)
{
    // if the root is not null
    if (root != NULL)
    {
    // print the current node
    cout << root->data << " ";

        // recursively print the left subtree
        printPreorder(root->left);

        // recursively print the right subtree
        printPreorder(root->right);
    }
}

// function to generate all binary trees with the same inorder traversal
vector<Node *> treesWithSameInorder( int arr[], int start, int end){
    // create a vector to hold all the generated trees
    vector<Node *> allTrees;

    // if start is greater than end, add null to the vector and return it
    if (start > end)
    {
        allTrees.push_back(NULL);
        return allTrees;
    }

    // loop through each element of the array
    for(int i = start; i <= end; i++){
        // recursively generate all possible left subtrees
        vector<Node *> lTrees = treesWithSameInorder(arr, start, i-1);

        // recursively generate all possible right subtrees
        vector<Node *> rTrees = treesWithSameInorder(arr, i+1, end);

        // loop through all possible combinations of left and right subtrees
        for (int j = 0; j<lTrees.size(); j++){
            for (int k = 0; k < rTrees.size(); k++)
            {
                // create a new node with the current element as data
                Node* newNode = new Node(arr[i]);

                // set the left and right subtrees to the ones generated recursively
                newNode->left = lTrees[j];
                newNode->right=rTrees[k];

                // add the new tree to the vector of all trees
                allTrees.push_back(newNode);
                
            }
            
        }
        
    }
    // return the vector of all generated trees
    return allTrees;
}

int main()
{
    // read the number of test cases
    int n;
    cin >> n;

    // loop through each test case
    for (int j = 0; j < n; j++)
    {
        // read the input array
        int in[INT16_MAX];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> in[i];
        }

        // generate all possible binary trees with the given inorder traversal
        vector<Node *> trees = treesWithSameInorder(in, 0, n-1);

        // print the total number of generated trees
        cout << "Total Binary trees are: " << trees.size() << endl;

        // print the preorder traversal of each generated tree
        cout << "Preorder traversals of different "
            << "possible Binary Trees are \n";
        for (int i = 0; i < trees.size(); i++)
        {
            printPreorder(trees[i]);
            cout << endl;
        }
    }
}