#include<bits/stdc++.h>
using namespace std;
class BST
{
public:
    int value;
    BST* left;
    BST* right;
    BST(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }

    BST& insert(int val)
    {
        BST* currentNode = this;
        while(true)
        {
            if(val < currentNode-> value)
            {
                if(currentNode->left == NULL)
                {
                    BST* newNode = new BST(val);
                    currentNode->left = newNode;
                    break;
                }else{
                    currentNode = currentNode->left;
                }
            }else{
                if(currentNode->right == NULL){
                    BST* newNode = new BST(val);
                    currentNode->right = newNode;
                    break;
                }else{
                    currentNode = currentNode->right;
                }
            }
        }
        return *this;
    }
};
bool validateBstHelper(BST* tree, int minValue, int maxValue);
bool validateBst(BST* tree){
    return validateBstHelper(tree, INT_MIN, INT_MAX);
}
bool validateBstHelper(BST* tree, int minValue, int maxValue){
    if(tree == NULL){
        return true;
    }
    if(tree->value < minValue || tree->value >= maxValue){
        return false;
    }
    if(tree->left != NULL && !validateBstHelper(tree->left, minValue, tree->value)){
        return false;
    }
    if(tree->right != NULL && !validateBstHelper(tree->right, tree->value, maxValue)){
        return false;
    }
    return true;
}

int main()
{

    BST *root = new BST(10);
    root->left = new BST(5);
    root->right = new BST(15);
    root->left->left = new BST(2);
    root->left->left->left= new BST(1);
    root->left->right = new BST(5);
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);
    root->right->right = new BST(22);

    if(validateBst(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";
    return 0;
}
