#include <iostream>
#include <queue>
#include <stack>
#include <windows.h>

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int key)
    {
        this->val = key;
        this->left = this->right = NULL;
    }
};

void addValRoot(Node* root, int key)
{
    std::queue<Node*> tr;
    tr.push(root);

    while (!tr.empty())
    {
        Node* temp = tr.front();
        tr.pop();

        if (!temp->left)
        {
            temp->left = new Node(key);
            break;
        }
        else
            tr.push(temp->left);

        if (!temp->right)
        {
            temp->right = new Node(key);
            break;
        }
        else
            tr.push(temp->right);
    }
}
//---------------Задание 1--------------------
bool areSimilar(Node* root1, Node* root2) {
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;

    std::queue<Node*> tr1, tr2;
    tr1.push(root1);
    tr2.push(root2);

    while (!tr1.empty() && !tr2.empty()) {
        Node* node1 = tr1.front();
        Node* node2 = tr2.front();
        tr1.pop();
        tr2.pop();

        if (!node1 && !node2)
            continue;
        if (!node1 || !node2)
            return false;

        tr1.push(node1->left);
        tr1.push(node1->right);
        tr2.push(node2->left);
        tr2.push(node2->right);
    }

    return tr1.empty() && tr2.empty();
}
//---------------Задание 2--------------------
bool isSymertical(Node* root)
{
    std::stack<Node*> stackL = std::stack<Node*>();
    std::stack<Node*> stackR = std::stack<Node*>();

    Node* rootL = root->left;
    Node* rootR = root->right;

    if (!root || (rootL == NULL && rootR == NULL))
        return true;
    if (rootL == NULL || rootR == NULL)
        return false;

    while ((rootL && rootR) || (!stackL.empty() && !stackR.empty()))
    {
        if (!stackL.empty() && !stackR.empty())
        {
            rootL = stackL.top();
            rootR = stackR.top();
            stackL.pop();
            stackR.pop();
        }
        else if (!stackL.empty() || !stackR.empty())
            return false;

        while (rootL && rootR)
        {
            if (rootL->left && rootR->right)
            {
                stackL.push(rootL->left);
                stackR.push(rootR->right);
            }
            else if (rootL->left || rootR->right)
                return false;

            rootL = rootL->right;
            rootR = rootR->left;
        }

        if (rootL || rootR)
            return false;
    }
    return true;
}
//-----------Самый глубокий узел--------------
Node* findDeepestNode(Node* root)
{
    int level = 0;
    int deepestLevel = 0;
    Node* deepestNode = root;

    std::stack<Node*> stack = std::stack<Node*>();
    std::stack<int> levels = std::stack<int>();

    while (root || !stack.empty())
    {
        if (!stack.empty())
        {
            root = stack.top();
            level = levels.top();
            stack.pop();
            levels.pop();
        }

        while (root)
        {
            if (level > deepestLevel)
            {
                deepestLevel = level;
                deepestNode = root;
            }

            if (root->right)
            {
                stack.push(root->right);
                levels.push(level + 1);
            }

            root = root->left;
            level++;
        }
    }
    return deepestNode;
}
//---------------Задание 3--------------------
void findTwoFarestNodes(Node* root, Node*& node1, Node*& node2)
{
    if (!root)
    {
        node1 = NULL;
        node2 = NULL;
        return;
    }
    node1 = root;
    node2 = root;

    if (root->left)
        node1 = findDeepestNode(root->left);
    if (root->right)
        node2 = findDeepestNode(root->right);
}
//---------------Задание 4--------------------
void findOddEven(Node* root, int& numOfOdd, int& numOfEven)
{
    std::stack<Node*> stack = std::stack<Node*>();

    numOfEven = 0;
    numOfOdd = 0;

    while (root || !stack.empty())
    {
        if (!stack.empty())
        {
            root = stack.top();
            stack.pop();
        }

        while (root)
        {
            if (root->val % 2 == 0)
                numOfEven++;
            else
                numOfOdd++;

            if (root->right)
            {
                stack.push(root->right);
            }
            root = root->left;
        }
    }
}
//---------------Задание 5--------------------
void printTree(Node* root)
{
    int level = 0;

    std::stack<Node*> stack = std::stack<Node*>();
    std::stack<int> levels = std::stack<int>();

    while (root || !stack.empty())
    {
        if (!stack.empty())
        {
            root = stack.top();
            level = levels.top();
            stack.pop();
            levels.pop();
        }

        while (root)
        {
            for (int i = 0; i < level; i++)
                std::cout << "  ";
            std::cout << root->val << '\n';

            if (root->right)
            {
                stack.push(root->right);
                levels.push(level + 1);
            }

            root = root->left;
            level++;
        }
    }
}
//---------------Задание 6--------------------
Node* findCenter(Node* root) // +- на костылях
{
    if (!root)
        return NULL;

    std::stack<Node*> s;
    Node* current = root;
    int count = 0;
    int t = 0;

    std::queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        t++;
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    while (current || !s.empty())
    {
        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        count++;

        if (count == ((t + 1) / 2) - 1)
            return current;

        current = current->right;
    }
    return NULL;
}



int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Node* root1 = new Node(7);
    //addValRoot(root1, 5);
    //addValRoot(root1, 12);
    //addValRoot(root1, 6);
    //addValRoot(root1, 9);
    //addValRoot(root1, 21);
    //addValRoot(root1, 23);
    //addValRoot(root1, 3);

    //Node* root2 = new Node(7);
    //addValRoot(root2, 5);
    //addValRoot(root2, 12);
    //addValRoot(root2, 6);
    //addValRoot(root2, 9);
    //addValRoot(root2, 21);

    Node* root1 = new Node(7);
    addValRoot(root1, 4);
    addValRoot(root1, 12);
    addValRoot(root1, 6);
    addValRoot(root1, 5);



    //Node* root1 = new Node(7);
    //addValRoot(root1, 5);
    //addValRoot(root1, 12);
    //addValRoot(root1, 6);

    Node* root2 = new Node(17);
    addValRoot(root2, 5);
    addValRoot(root2, 122);
    addValRoot(root2, 12);

    std::cout << "Задание 5:\n";
    printTree(root1);

    std::cout << "\nЗадание 1:\n";
    if (areSimilar(root1, root2))
        std::cout << "ИСТИНА\n\n";
    else
        std::cout << "ЛОЖЬ\n\n";
    //std::cout << areSimilar(root1, root2) << "\n";

    std::cout << "Задание 2:\n";
    //std::cout << isSymertical(root1) << "\n\n";
    if (isSymertical(root1))
        std::cout << "ИСТИНА\n\n";
    else
        std::cout << "ЛОЖЬ\n\n";

    std::cout << "Задание 3:\n";
    std::cout << findDeepestNode(root1)->val << "\n";
    Node* n1, * n2;
    findTwoFarestNodes(root1, n1, n2);
    std::cout << n1->val << " " << n2->val << "\n\n";

    std::cout << "Задание 4:\n";
    int evenNum, oddNum;
    findOddEven(root1, oddNum, evenNum);
    std::cout << oddNum << " " << evenNum << "\n\n";

    std::cout << "Задание 6:\n";
    Node* center = findCenter(root1);
    if (center)
        std::cout << "Центр дерева: " << center->val << "\n\n";

}
