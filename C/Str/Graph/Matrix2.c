#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// 结构体定义
typedef struct Graph
{
    int numVertices;
    int **adjMatrix;
} Graph;

// 函数声明
Graph *createGraph(int verticesNum);
void addEdge(Graph *graph, int src, int dest);
void removeEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void destroyGraph(Graph *graph);
void addVertices(Graph *graph, int addNum);
void removeVertices(Graph *graph, int removeNum);

// 主函数
int main()
{
    int vertices = 5;
    Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Adjacency matrix of the graph:\n");
    printGraph(graph);

    addVertices(graph, 2);
    printf("\nAdjacency matrix after adding 2 vertices:\n");
    printGraph(graph);

    removeVertices(graph, 3);
    printf("\nAdjacency matrix after removing 3 vertices:\n");
    printGraph(graph);
    destroyGraph(graph);

    return 0;
}

// 函数实现

// 创建图
Graph *createGraph(int verticesNum)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = verticesNum;
    graph->adjMatrix = (int **)malloc(verticesNum * sizeof(int *));
    for (int i = 0; i < verticesNum; i++)
    {
        graph->adjMatrix[i] = (int *)malloc(verticesNum * sizeof(int));
        for (int j = 0; j < verticesNum; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// 添加边
void addEdge(Graph *graph, int src, int dest)
{
    if (graph == NULL)
    {
        printf("图为空\n");
        return;
    }
    if (src >= 0 && dest >= 0 && src < MAX_VERTICES && dest < MAX_VERTICES)
    {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
    }
}

// 删除边
void removeEdge(Graph *graph, int src, int dest)
{
    if (graph == NULL)
    {
        printf("图为空");
        return;
    }
    if (src >= 0 && dest >= 0 && src < graph->numVertices && dest < graph->numVertices)
    {
        graph->adjMatrix[dest][src] = 0;
        graph->adjMatrix[src][dest] = 0;
    }
}

// 打印图
void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("vertices%d :", i);
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d-", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// 删除节点
void destroyGraph(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }
    for (int i = 0; i < graph->numVertices; i++)
    {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// 添加节点
void addVertices(Graph *graph, int addNum)
{
    if (graph == NULL)
    {
        return;
    }
    int newNumVertices = graph->numVertices + addNum;
    graph->adjMatrix = (int **)realloc(graph->adjMatrix, newNumVertices * sizeof(int *));
    for (int i = 0; i < newNumVertices; i++)
    {
        graph->adjMatrix[i] = (int *)realloc(graph->adjMatrix[i], newNumVertices * sizeof(int));
        if (i >= graph->numVertices)
        {
            for (int j = 0; j < newNumVertices; j++)
            {
                graph->adjMatrix[i][j] = 0;
            }
        }
        else
        {
            for (int k = graph->numVertices; k < newNumVertices; k++)
            {
                graph->adjMatrix[i][k] = 0;
            }
        }
    }
    graph->numVertices = newNumVertices;
}

// 删除节点
void removeVertices(Graph *graph, int removeNum)
{
    if (graph == NULL)
    {
        return;
    }

    int newNumVertices = graph->numVertices - removeNum;
    if (newNumVertices < 0)
    {
        newNumVertices = 0;
    }
    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->adjMatrix[i] = (int *)realloc(graph->adjMatrix[i], newNumVertices * sizeof(int));
    }
    graph->adjMatrix = (int **)realloc(graph->adjMatrix, newNumVertices * sizeof(int *));
    graph->numVertices = newNumVertices;
}

