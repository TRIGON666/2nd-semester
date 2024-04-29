#include <iostream>
#include <queue>
#include <Windows.h>

struct Node 
{
    int info;
    Node* left, * right;
    Node(int pinfo, Node* pleft = NULL, Node* pright = NULL) 
    {
        info = pinfo;
        left = pleft;
        right = pright;
    }
};

//1
void addNode(Node*& root, int info)
{
    if (root == NULL) 
    {
        root = new Node(info);
        return;
    }

    if (info < root->info)
    {
        if (root->left == NULL) 
            root->left = new Node(info);

        else 
            addNode(root->left, info);
    }
    else if (info > root->info)
    {
        if (root->right == NULL)
            root->right = new Node(info);

        else
            addNode(root->right, info);
    }
}

//2
void deleteNode(Node*& root, int info)
{
    if (root == NULL) return;

    if (root->info == info) 
    {
        Node* tmp = root;
        if (root->left == NULL && root->right == NULL) 
        {
            delete tmp;
            root = NULL;
        }
        else if (root->left == NULL) 
        {
            tmp = root;
            root = root->right;
            delete tmp;
        }
        else if (root->right == NULL) 
        {
            tmp = root;
            root = root->left;
            delete tmp;
        }
        else {
            Node* p = root->right;
            while (p->left != NULL)
                p = p->left;
            root->info = p->info;
            deleteNode(root->right, p->info);
        }
    }
    else 
    {
        deleteNode(root->left, info);
        deleteNode(root->right, info);
    }
}

//3
void printTree(Node* root) 
{
    if (root == NULL)
        return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        Node* p = q.front();
        q.pop();
        std::cout << p->info << " ";

        if (p->left != NULL) 
            q.push(p->left);
        if (p->right != NULL)
            q.push(p->right);
    }
    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "RU"); 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* root = new Node(7);
    root->left = new Node(5);
    root->right = new Node(12);

    std::cout << "До: ";
    printTree(root);

    addNode(root, 6);

    std::cout << "После: ";
    printTree(root);

    std::cout << "До: ";
    printTree(root);

    deleteNode(root, 6);

    std::cout << "После: ";
    printTree(root);

}