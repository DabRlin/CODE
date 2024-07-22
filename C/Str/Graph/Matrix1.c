#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// 结构体定义
typedef struct Graph
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]
} Graph;

// 函数声明
Graph *createGraph(int verticesNum);
void addEdge(Graph *graph, int src, int dest);
void removeEdge(Graph *graph, int src, int dest);
void printfGraph(Graph *graph);
void destoryGraph(Graph *graph);
Graph *addVertices(Graph **graph);
Graph *removeVertices(Graph **graph, int index);


// 主函数
int main()
{
    return 0;
}

// 函数实现

// 创建图
Graph *createGraph(int verticesNum)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = verticesNum;
    for (int i = 0; i < verticesNum; i++)
    {
        for (int j = 0; i < verticesNum; j++)
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
        printf("图为空");
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
        return 0;
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
        printf("vertices：%d", i);
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d-", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// 销毁树
void destoryGraph(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }
    free(graph);
}

// 添加节点
Graph *addVertices(Graph **graph)
{
    int newVerticesNum = (*graph)->numVertices + 1;
    int newAdjMatrix[newVerticesNum][newVerticesNum];
    for (int i = 0; i < newVerticesNum - 1; i++)
    {
        for (int j = 0; j < newVerticesNum - 1; j++)
        {
            newAdjMatrix[i][j] = (*graph)->adjMatrix[i][j];
        }
    }
    for (int k = 0; k < newVerticesNum; k++)
    {
        newAdjMatrix[k][newVerticesNum - 1] = 0;
        newAdjMatrix[newVerticesNum][k] = 0;
    }
    destoryGraph(*graph);
    *graph = createGraph(newVerticesNum);
    for (int i = 0; i < newVerticesNum; i++)
    {
        for (int j = 0; j < newVerticesNum; j++)
        {
            (*graph)->adjMatrix[i][j] = newAdjMatrix[i][j];
        }
    }
    return *graph;
}

// 删除节点
Graph *removeVertices(Graph **graph, int index)
{
    int newVerticesNum = (*graph)->numVertices - 1;
    int newAdjMatrix[newVerticesNum][newVerticesNum];
    for (int i = 0; i < newVerticesNum; i++)
    {
        for (int j = 0; j < newVerticesNum; j++)
        {
            if (i < index && j < index)
            {
                newAdjMatrix[i][j] = (*graph)->adjMatrix[i][j];
            }
            if (i < index && j > index)
            {
                newAdjMatrix[i][j - 1] = (*graph)->adjMatrix[i][j];
            }
            if (i > index && j < index)
            {
                newAdjMatrix[i - 1][j] = (*graph)->adjMatrix[i][j];
            }
            if (i > index && j > index)
            {
                newAdjMatrix[i - 1][j - 1] = (*graph)->adjMatrix[i][j];
            }
        }
    }
    destoryGraph(*graph);
    *graph = createGraph(newVerticesNum);
    for (int i = 0; i < newVerticesNum; i++)
    {
        for (int j = 0; j < newVerticesNum; j++)
        {
            (*graph)->adjMatrix[i][j] = newAdjMatrix[i][j];
        }
    }
    return *graph;
}