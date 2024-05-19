#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <Windows.h>

class Graph
{
    int m;
    int n;
    int** a;
    int** T;
    int** H;

public:
    Graph(int m, int n, bool directed);
    ~Graph();

    std::list<int> PathOnWidth(int v);
    std::list<int> PathOnDepth(int v);
    std::list<int> connectedComponent(int v);
 /*   void findCycle(std::vector<bool>& visited, std::vector<int>& path, int v);*/
    void addEdge(int from, int to, int weight = 1);
    //int getSize() { return m; }
};

Graph::Graph(int m, int n, bool directed)
{
    if (m <= 0 || n <= 0) throw 1;
    this->m = m; this->n = n;
    a = new int* [m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[m];
        for (int j = 0; j < m; j++)
            a[i][j] = i == j ? 0 : INT_MAX;
    }

    T = new int* [m];
    H = new int* [m];
    for (int i = 0; i < m; i++)
    {
        T[i] = new int[m];
        H[i] = new int[m];
    }

    if (!directed)
        n *= 2;
}

Graph::~Graph()
{
    for (int i = m - 1; i >= 0; i--)
    {
        delete[] T[i];
        delete[] H[i];
        delete[] a[i];
    }
    delete[] a;
    delete[] T;
    delete[] H;
}

std::list<int> Graph::PathOnWidth(int v)
{
    std::vector<bool> labels;
    for (int i = 0; i < m; i++)
        labels.push_back(false);

    std::queue<int> q;
    std::list<int> res;
    q.push(v); labels[v] = true;
    while (!q.empty())
    {
        v = q.front(); q.pop();
        res.push_back(v + 1);
        for (int i = 0; i < m; i++)
            if (!labels[i] && i != v && a[v][i] != INT_MAX)
            {
                q.push(i); labels[i] = true;
            }
    }
    return res;
}

std::list<int> Graph::PathOnDepth(int v)
{
    std::vector<bool> labels;
    for (int i = 0; i < m; i++)
        labels.push_back(false);

    std::stack<int> s;
    std::list<int> res;
    s.push(v); labels[v] = true;
    res.push_back(v + 1);

    while (!s.empty())
    {
        v = s.top(); s.pop();

        for (int i = 0; i < m; i++)
        {
            if (!labels[i] && i != v && a[v][i] != INT_MAX)
            {
                s.push(i); labels[i] = true;
                res.push_back(i + 1);
            }
        }
    }
    return res;
}

void Graph::addEdge(int from, int to, int weight)
{
    if (from < 0 || from >= m || to < 0 || to >= m) throw 1;
    a[from][to] = weight;
}

std::list<int> Graph::connectedComponent(int v)
{
    std::vector<bool> visited(m, false);
    std::list<int> component;
    std::queue<int> q;

    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        component.push_back(u);

        for (int n = 0; n < m; n++) {
            if (!visited[n] && a[u][n] != INT_MAX) {
                q.push(n);
                visited[n] = true;
            }
        }
    }
    return component;
}

//void Graph::findCycle(std::vector<bool>& visited, std::vector<int>& path, int v) - неверно
//{
//    visited[v] = true;
//    path.push_back(v);
//
//    for (int u = 0; u < m; ++u) {
//        if (a[v][u] != INT_MAX && !visited[u]) 
//            findCycle(visited, path, u);
//        else if (a[v][u] != INT_MAX && visited[u]) 
//        {
//            path.push_back(u);
//            std::cout << "Цикл найден: ";
//            for (int i = path.size() - 1; i >= 0; --i) {
//                std::cout << path[i] + 1 << " ";
//            }
//            std::cout << "\n";
//            return;
//        }
//    }
//
//    path.pop_back();
//    visited[v] = false;
//}


int main() 
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Graph directedGraph(5, 7, true);
    Graph undirectedGraph(5, 7, false);

    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 2);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(1, 3);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 4);
    directedGraph.addEdge(4, 0);

    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 2);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(1, 3);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(3, 4);
    undirectedGraph.addEdge(4, 0);

    //------------------------ 1 Задача -----------------------------------------
    std::cout << "Обход вершин в ориентированном графе:\n";
    std::list<int> directedPath = directedGraph.PathOnWidth(0);
    for (std::list<int>::iterator it = directedPath.begin(); it != directedPath.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    //------------------------ 2 Задача -----------------------------------------
    std::cout << "Обход вершин в неориентированном графе:\n";
    std::list<int> undirectedPath = undirectedGraph.PathOnWidth(0);
    for (std::list<int>::iterator it = undirectedPath.begin(); it != undirectedPath.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    //------------------------ 3 Задача -----------------------------------------
    std::cout << "Обход вершин в ориентированном графе (поиск в глубину):\n";
    std::list<int> directedDepthPath = directedGraph.PathOnDepth(0);
    for (std::list<int>::iterator it = directedDepthPath.begin(); it != directedDepthPath.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    //------------------------ 4 Задача -----------------------------------------
    std::cout << "Обход вершин в неориентированном графе (поиск в глубину):\n";
    std::list<int> undirectedDepthPath = undirectedGraph.PathOnDepth(0);
    for (std::list<int>::iterator it = undirectedDepthPath.begin(); it != undirectedDepthPath.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    //------------------------ 5 Задача -----------------------------------------
    std::cout << "Введите количество вершин и ребер для неориентированного графа:\n";
    int V, E;
    std::cin >> V >> E;

    Graph connectGraph(V, E, false);

    std::cout << "Введите ребра (пары вершин):\n";
    for (int i = 0; i < E; ++i) {
        int from, to;
        std::cin >> from >> to;
        connectGraph.addEdge(from - 1, to - 1);
        connectGraph.addEdge(to - 1, from - 1);
    }

    int SVO;
    std::cout << "Введите номер вершины для нахождения компоненты связности:\n";
    std::cin >> SVO;

    std::list<int> component = connectGraph.connectedComponent(SVO - 1);

    std::cout << "Компонента связности, содержащая вершину " << SVO << ":\n";
    for (std::list<int>::iterator it = component.begin(); it != component.end(); ++it) {
        std::cout << *it + 1 << " ";
    }
    std::cout << "\n";

    //------------------------ 8 Задача ----------------------------------------- // неверно
    //std::cout << "Циклы в неориентированном графе:\n";
    //std::vector<bool> visited(undirectedGraph.getSize(), false);
    //std::vector<int> path;
    //for (int v = 0; v < undirectedGraph.getSize(); ++v) {
    //    if (!visited[v]) {
    //        undirectedGraph.findCycle(visited, path, v);
    //        path.clear();
    //    }
    //}

}