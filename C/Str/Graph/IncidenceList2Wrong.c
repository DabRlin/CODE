#include <stdio.h>
#include <stdlib.h>

// 结构体定义

// 节点结构体定义
typedef struct Vertex
{
    int data;
    struct ArcNode *first_in;
    struct ArcNode *first_out;
    struct Vertex *next;
} Vertex;

// 有向边结构体定义
typedef struct ArcNode
{
    struct Vertex *tail;
    struct Vertex *head;
    struct ArcNode *nextSameTail;
    struct ArcNode *nextSameHead;
} ArcNode;

// 图结构体定义
typedef struct Graph
{
    Vertex *vertex;
    int vertexNum;
    int arcNum;
} Graph;

// 函数声明
Vertex *createVertex(int value);
ArcNode *createArcNode(Graph *graph, int headValue, int tailValue);
Graph *createGraphEmpty();
void insertVertex(Graph *graph, int value);
void insertArc(Graph *graph, int headValue, int tailValue);
void removeVertex(Graph *graph, int value);
void removeArc(Graph *graph, int headValue, int tailValue);
Vertex *getVertex(Graph *graph, int value);
ArcNode *getArc(Graph *graph, int headValue, int tailValue);
void printGraph(Graph *graph);
void freeGraph(Graph *graph);

// 主函数
int main()
{
    Graph *graph = createGraphEmpty();
    insertVertex(graph, 1);
    insertVertex(graph, 2);
    insertArc(graph, 1, 2);
    printGraph(graph);
    removeVertex(graph, 1);
    printGraph(graph);
    freeGraph(graph);
    return 0;
}

// 函数实现

// 创建节点
Vertex *createVertex(int value)
{
    Vertex *newVertex = (Vertex *)malloc(sizeof(Vertex));
    newVertex->data = value;
    newVertex->first_in = NULL;
    newVertex->first_out = NULL;
    newVertex->next = NULL;
    return newVertex;
}

// 创建边
ArcNode *createArcNode(Graph *graph, int headValue, int tailValue)
{
    ArcNode *newArcNode = (ArcNode *)malloc(sizeof(ArcNode));
    Vertex *head = getVertex(graph, headValue);
    Vertex *tail = getVertex(graph, tailValue);
    newArcNode->head = head;
    newArcNode->tail = tail;
    newArcNode->nextSameHead = NULL;
    newArcNode->nextSameTail = NULL;
    return newArcNode;
}

// 创建空图
Graph *createGraphEmpty()
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->arcNum = 0;
    newGraph->vertexNum = 0;
    newGraph->vertex = NULL;
    return newGraph;
}

// 插入节点
void insertVertex(Graph *graph, int value)
{
    if (graph == NULL)
    {
        return;
    }
    if (getVertex(graph, value) != NULL)
    {
        return;
    }
    Vertex *newVertex = createVertex(value);
    newVertex->next = graph->vertex;
    graph->vertex = newVertex;
    graph->vertexNum++;
}

// 插入边
void insertArc(Graph *graph, int headValue, int tailValue)
{
    if (graph == NULL)
    {
        return;
    }
    Vertex *headVertex = getVertex(graph, headValue);
    Vertex *tailVertex = getVertex(graph, tailValue);
    if (headVertex == NULL || tailVertex == NULL)
    {
        return;
    }
    ArcNode *newArcNode = createArcNode(graph, headValue, tailValue);
    newArcNode->head = headVertex;
    newArcNode->tail = tailVertex;

    newArcNode->nextSameHead = headVertex->first_out;
    headVertex->first_out = newArcNode->nextSameHead;

    newArcNode->nextSameTail = tailVertex->first_in;
    tailVertex->first_in = newArcNode->nextSameTail;

    newArcNode->nextSameTail = NULL;
}

// 删除节点
void removeVertex(Graph *graph, int value)
{
    if (graph == NULL)
    {
        return;
    }
    Vertex *prev = NULL;
    Vertex *temp = graph->vertex;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (prev == NULL)
            {
                graph->vertex = temp->next;
            }
            else
            {
                prev->next = prev->next;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }

    // 删除该节点的所有出边
    ArcNode *arc = temp->first_out;
    ArcNode *current = NULL;
    while (arc != NULL)
    {
        current = arc;
        arc = arc->nextSameHead;
        removeArc(graph, current->head->data, current->tail->data);
    }

    // 删除该节点的所有入边
    arc = temp->first_in;
    current = NULL;
    while (arc != NULL)
    {
        current = arc;
        arc = arc->nextSameHead;
        removeArc(graph, current->head->data, current->tail->data);
    }
    free(temp);
    graph->vertexNum--;
}

// 删除边
void removeArc(Graph *graph, int headValue, int tailValue)
{
    if (graph == NULL)
    {
        return;
    }
    Vertex *headVertex = getVertex(graph, headValue);
    Vertex *tailVertex = getVertex(graph, tailValue);
    if (headVertex == NULL || tailVertex == NULL)
    {
        return;
    }
    // 删除头节点的出链表中的有向边
    ArcNode *prev = NULL;
    ArcNode *temp = headVertex->first_out;
    while (temp != NULL)
    {
        if (temp->tail == tailVertex)
        {
            if (prev == NULL)
            {
                headVertex->first_out = temp->nextSameHead;
            }
            else
            {
                prev->nextSameHead = temp->nextSameHead;
            }
        }
        prev = temp;
        temp = temp->nextSameHead;
    }

    // 删除尾节点的入链表中的有向边
    prev = NULL;
    temp = tailVertex->first_in;
    while (temp != NULL)
    {
        if (temp->head == headVertex)
        {
            if (prev == NULL)
            {
                tailVertex->first_in = temp->nextSameTail;
            }
            else
            {
                prev->nextSameTail = temp->nextSameTail;
            }
            free(temp);
        }
        prev = temp;
        temp = temp->nextSameTail;
    }
    graph->arcNum--;
}

// 获取节点
Vertex *getVertex(Graph *graph, int value)
{
    if (graph == NULL)
    {
        return NULL;
    }

    Vertex *current = graph->vertex;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 获取边
ArcNode *getArc(Graph *graph, int headValue, int tailValue)
{
    if (graph == NULL)
    {
        return NULL;
    }

    Vertex *headVertex = getVertex(graph, headValue);
    Vertex *tailVertex = getVertex(graph, tailValue);
    if (headVertex == NULL || tailVertex == NULL)
    {
        return NULL;
    }
    ArcNode *arcOut = headVertex->first_out;
    while (arcOut != NULL)
    {
        if (arcOut->tail->data == tailValue)
        {
            return arcOut;
        }
        arcOut = arcOut->nextSameHead;
    }
}

// 打印图
void printGraph(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }

    Vertex *vertex = graph->vertex;
    while (vertex != NULL)
    {
        printf("顶点%d: \n", vertex->data);
        ArcNode *arc = vertex->first_in;
        printf("入边: ");
        while (arc != NULL)
        {
            printf("%d->", arc->head->data);
            arc = arc->nextSameHead;
        }
        printf("\n");
        printf("出边: ");
        arc = vertex->first_out;
        while (arc != NULL)
        {
            printf("%d->", arc->tail->data);
        }
        vertex = vertex->next;
    }
}

// 释放图
void freeGraph(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }
    Vertex *vertex = graph->vertex;
    while (vertex != NULL)
    {
        Vertex *temp = vertex;
        vertex = vertex->next;
        ArcNode *arc = temp->first_in;
        while (arc != NULL)
        {
            ArcNode *current = arc;
            arc = arc->nextSameTail;
            free(current);
        }
        free(temp);
    }
    free(graph);
}