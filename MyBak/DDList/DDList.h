#ifndef DOUDIRLIST_H
#define DOUDIRLIST_H

#include <stdio.h>
#include <stdlib.h>

#ifndef PRINT
#define PRINT    \
    if (g_ddl_debug) \
    printf
#endif // PRINT

typedef struct NODE_S {
    void *val;
    struct NODE_S *pre;
    struct NODE_S *next;
} Node;

/* 外部声明 */
Node* InitDDList(int dataSize);
int FreeDDList(Node *head);
int ShowDDList(Node *head, void *DDList(void *data));

int DDListAddInTail(Node *head, void *data);
int DDListDelInTail(Node *head);
int DDListDelInHead(Node *head);

int DDListAddInIdx(Node *head, void *data, int idx);
int DDListDelInIdx(Node *head, int idx);

int DDListGetIdxData(Node *head, void *out, int idx);
int DDListGetListLenth(Node *head);

int DDListPopFstData(Node *head, void *out);
int DDListPopLstData(Node *head, void *out);


#endif // DOUDIRLIST_H