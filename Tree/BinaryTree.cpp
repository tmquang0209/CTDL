#include <bits/stdc++.h>
using namespace std;

struct node
{
    int keyValue;
    node *right;
    node *left;
};

class BinaryTree
{
private:
    node *root;
    void destroyTree(node *leaf)
    {
        if (leaf)
        {
            destroyTree(leaf->right);
            destroyTree(leaf->left);
            delete leaf;
        }
    }

    void insert(int key, node *leaf)
    {
        if (key < leaf->keyValue)
            if (leaf->left != NULL)
                insert(key, leaf->left);
            else
            {
                leaf->left = new node;
                leaf->left->keyValue = key;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        else if (key >= leaf->keyValue)
            if (leaf->right != NULL)
                insert(key, leaf->right);
            else
            {
                leaf->right = new node;
                leaf->right->keyValue = key;
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
    }

    node *search(int key, node *leaf)
    {
        if (leaf)
            if (key == leaf->keyValue)
                return leaf;
            else if (key < leaf->keyValue)
                return search(key, leaf->left);
            else
                return search(key, leaf->right);

        return NULL;
    }

    void printPreOrder(node *r)
    {
        if (!r)
            return;

        cout << r->keyValue << " ";
        printPreOrder(r->left);
        printPreOrder(r->right);
    }

    void printPostOrder(node *r)
    {
        if (!r)
            return;

        printPostOrder(r->left);
        printPostOrder(r->right);
        cout << r->keyValue << " ";
    }

    void printInOrder(node *r)
    {
        if (!r)
            return;

        printInOrder(r->left);
        cout << r->keyValue << " ";
        printInOrder(r->right);
    }

public:
    BinaryTree() { root = NULL; }
    ~BinaryTree() { destroyTree(); }
    void insert(int key)
    {
        if (root)
            insert(key, root);
        else
        {
            root = new node;
            root->keyValue = key;
            root->left = NULL;
            root->right = NULL;
        }
    }
    node *search(int key)
    {
        return search(key);
    }
    void PreOrder()
    {
        printPreOrder(root);
    }

    void InOrder()
    {
        printInOrder(root);
    }

    void PostOrder()
    {
        printPostOrder(root);
    }

    void destroyTree()
    {
        destroyTree(root);
    }
};

int main()
{
    BinaryTree t1;
    t1.insert(7);
    t1.insert(9);
    t1.insert(3);
    t1.insert(8);
    t1.insert(4);
    cout << "Post:";
    t1.PostOrder();
    cout << endl
         << "Pre:";
    t1.PreOrder();
    cout << endl
         << "In:";
    t1.InOrder();
    cout << endl;
    return 0;
}