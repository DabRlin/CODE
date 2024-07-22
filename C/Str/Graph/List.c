#include <stdio.h>
#include <stdlib.h>

// 结构体定义

// 邻接节点
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// 图结构
typedef struct Graph
{
    int numVertices;
    Node **adjLists;
} Graph;

// 函数声明
Node *createNode(int value);
Graph *createGraph(int num);
void addEdge(Graph *graph, int src, int dest);
void removeEdge(Graph *Graph, int src, int dest);
void printGraph(Graph *graph);
void freeGraph(Graph *graph);
void addVertices(Graph *graph, int num);
void deleteVertices(Graph *graph, int value);
Node *getVertex(Graph *graph, int value);

// 主函数
int main()
{
    Graph *graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    removeEdge(graph, 1, 4);

    printf("\nAfter removing edge 1-4:\n");
    printGraph(graph);

    addVertices(graph, 5);
    printf("\nAfter adding vertex 5:\n");
    printGraph(graph);

    deleteVertices(graph, 3);
    printf("\nAfter deleting vertex 3:\n");
    printGraph(graph);

    Node *vertex = getVertex(graph, 2);
    if (vertex)
    {
        printf("\nVertex 2 adjacency list: ");
        while (vertex)
        {
            printf("%d -> ", vertex->vertex);
            vertex = vertex->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("\nVertex 2 not found\n");
    }

    freeGraph(graph);

    return 0;
}

// 函数实现

// 创建节点
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->vertex = value;
    return newNode;
}

// 创建图
Graph *createGraph(int num)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = num;
    graph->adjLists = (Node **)malloc(num * sizeof(Node *));
    for (int i = 0; i < num; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// 添加边
void addEdge(Graph *graph, int src, int dest)
{
    if (graph == NULL)
    {
        return;
    }
    Node *temp = graph->adjLists[src];
    while (temp != NULL)
    {
        if (temp->vertex == dest)
        {
            return;
        }

        temp = temp->next;
    }

    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// 删除边
void removeEdge(Graph *graph, int src, int dest)
{
    if (graph == NULL)
    {
        return;
    }

    Node *temp = graph->adjLists[src];
    Node *prev = NULL;
    while (temp != NULL && temp->vertex != dest)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        if (prev != NULL)
        {
            prev->next = temp->next;
        }
        else
        {
            graph->adjLists[src] = temp->next;
        }
        free(temp);
    }

    temp = graph->adjLists[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        if (prev != NULL)
        {
            prev->next = temp->next;
        }
        else
        {
            graph->adjLists[dest] = temp->next;
        }
        free(temp);
    }
}

// 打印图
void printGraph(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        printf("Vertex%d: ", i);
        while (temp != 0)
        {
            printf("%d->", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// 释放图
void freeGraph(Graph *graph)
{
    if (graph == NULL)
    {
        free(graph);
        return;
    }

    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp)
        {
            Node *next = temp->next;
            free(temp);
            temp = temp->next;
        }
    }
    free(graph->adjLists);
    free(graph);
}

// 添加节点
void addVertices(Graph *graph, int num)
{

    if (graph == NULL)
    {
        return;
    }
    int newNumVertices = graph->numVertices + num;
    graph->adjLists = (Node **)realloc(graph->adjLists, newNumVertices * sizeof(Node *));
    for (int i = graph->numVertices; i < newNumVertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    graph->numVertices = newNumVertices;
}

// 删除顶点
void deleteVertices(Graph *graph, int num)
{
    if (graph == NULL)
    {
        return;
    }

    if (num >= graph->numVertices)
    {
        freeGraph(graph);
        return;
    }
    Node *temp = graph->adjLists[num];
    while (temp)
    {
        Node *next = temp->next;
        removeEdge(graph, num, temp->vertex);
        temp = next;
    }
    for (int i = 0; i < graph->numVertices; i++)
    {
        removeEdge(graph, num, i);
    }
    free(graph->adjLists[num]);
    if (num != graph->numVertices - 1)
    {
        graph->adjLists[num] = graph->adjLists[graph->numVertices - 1];
        for (int j = 0; j < graph->numVertices; j++)
        {
            Node *temp1 = graph->adjLists[j];
            while (temp1)
            {
                if (temp1->vertex == graph->numVertices - 1)
                {
                    temp1->vertex = num;
                }

                temp1 = temp1->next;
            }
        }
    }

    graph->numVertices--;
    graph->adjLists = (Node **)realloc(graph->adjLists, graph->numVertices * sizeof(Node *));
}

// 获取节点
Node *getVertex(Graph *graph, int index)
{
    if (graph == NULL)
    {
        return NULL;
    }

    if (index > graph->numVertices)
    {
        return NULL;
    }
    return graph->adjLists[index];
}
