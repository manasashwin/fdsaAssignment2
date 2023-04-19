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

void printPreorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

vector<Node *> treesWithSameInorder( int arr[], int start, int end){
    vector<Node *> allTrees;

    if (start > end)
    {
        allTrees.push_back(NULL);
        return allTrees;
    }

    for(int i = start; i <= end; i++){
        vector<Node *> lTrees = treesWithSameInorder(arr, start, i-1);
        vector<Node *> rTrees = treesWithSameInorder(arr, i+1, end);

        for (int j = 0; j<lTrees.size(); j++){
            for (int k = 0; k < rTrees.size(); k++)
            {
                Node* newNode = new Node(arr[i]);
                newNode->left = lTrees[j];
                newNode->right=rTrees[k];
                allTrees.push_back(newNode);
                
            }
            
        }
        
    }
    return allTrees;
} 


int main()
{
    int n;
    cin >> n; 
    for (int j = 0; j < n; j++)
    {
        int in[INT16_MAX];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> in[i];
        }
        vector<Node *> trees = treesWithSameInorder(in, 0, n-1);
        cout << "Total Binary trees are: " << trees.size() << endl;
        cout << "Preorder traversals of different "
            << "possible Binary Trees are \n";
        for (int i = 0; i < trees.size(); i++)
        {
            printPreorder(trees[i]);
            cout << endl;
        }
    }
    
    
}