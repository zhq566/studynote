#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DDList.h"

int g_ddl_debug = 1;
int g_dataSize = 0;

Node* InitDDList(int dataSize)
{
    Node* head = malloc(sizeof(Node));
    if (head == NULL) {
        PRINT("[InitDDList] malloc failed!\n");
        return NULL;
    }
    head->val = NULL;
    head->pre = NULL;
    head->next = NULL;
    g_dataSize = dataSize;
    return head;
}

int FreeDDList(Node *head)
{
    if (head == NULL) {
        PRINT("[FreeDDList] input para is NULL!\n");
        return -1;
    }

    Node *needFree = head;
    Node *tmp = NULL;

    while (needFree != NULL) {
        tmp = needFree->next;
        /* 释放当前Node */
        free(needFree->val);
        free(needFree);

        needFree = tmp;
    }
    g_dataSize = 0;
    return 0;
}

int DDListAddInTail(Node *head, void *data)
{
    if (head == NULL || data == NULL) {
        PRINT("[DDListAddInTail] input para is NULL!\n");
        return -1;
    }
    Node *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    /* 申请Node空间 */
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        PRINT("[DDListAddInTail] malloc newNode failed!\n");
        return -1;
    }
    newNode->val = NULL;
    /* 申请Data空间 */
    newNode->val = malloc(sizeof(g_dataSize));
    if (newNode->val == NULL) {
        PRINT("[DDListAddInTail] malloc newNode->data failed!\n");
        free(newNode);
        return -1;
    }
    (void)memcpy(newNode->val, data, sizeof(g_dataSize));

    /* 处理指向关系 */
    tmp->next = newNode;
    newNode->pre = tmp;
    newNode->next = NULL;

    return 0;
}

int DDListDelInTail(Node *head)
{
    if (head == NULL) {
        PRINT("[DDListAddInTail] input para is NULL!\n");
        return -1;
    }
    Node *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    /* 删除前Node指向关系 */
    tmp->pre->next = NULL;

    /* 删除Node 释放空间 */
    if (tmp->val != NULL) {
        free(tmp->val); // 释放Data
    }
    if (tmp != NULL) {
        free(tmp);      // 释放Node
    }
    return 0;
}

int DDListDelInHead(Node *head)
{
    if (head == NULL) {
        PRINT("[DDListAddInTail] input para is NULL!\n");
        return -1;
    }
    Node *needRm = head->next;
    if (needRm == NULL) { // 保护
        return 0;
    }
    Node *next = needRm->next;

    /* 删除Node 释放空间 */
    if (needRm->val != NULL) {
        free(needRm->val); // 释放Data
    }
    if (needRm != NULL) {
        free(needRm);      // 释放Node
    }

    /* 处理指向关系 */
    head->next = next;
    next->pre = head;

    return 0;
}

int DDListAddInIdx(Node *head, void *data, int idx)
{
    if (head == NULL || data == NULL || idx <= 0) {
        PRINT("[DDListAddInIdx] input para is err!\n");
        return -1;
    }
    Node *tmp = head;
    int i = 0;
    while (tmp != NULL && i != idx) {
        tmp = tmp->next;
        i++;
    }
    if (i != idx) {
        PRINT("[DDListAddInIdx] idx:%d , but ListLenth:%d !\n", idx, DDListGetListLenth(head));
        return -1;
    }
    /* 申请Node内存 */
    Node *needAddNode = malloc(sizeof(Node));
    if (needAddNode == NULL) {
        PRINT("[DDListAddInIdx] needAddNode malloc failed!\n");
        return -1;
    }
    /* 申请data内存 */
    needAddNode->val = NULL;
    needAddNode->val = malloc(sizeof(g_dataSize));
    if (needAddNode->val == NULL) {
        PRINT("[DDListAddInIdx] needAddNode->val malloc failed!\n");
        free(needAddNode);
        return -1;
    }
    (void)memcpy(needAddNode->val, data, sizeof(g_dataSize));

    /* 处理指向关系 */
    tmp->pre->next = needAddNode;
    needAddNode->pre = tmp->pre;
    needAddNode->next = tmp;
    tmp->pre = needAddNode;

    return 0;
}

int DDListDelInIdx(Node *head,int idx)
{
    if (head == NULL || idx <= 0) {
        PRINT("[DDListDelInIdx] input para is err!\n");
        return -1;
    }
    Node *tmp = head;
    int i = 0;
    while (tmp != NULL && i != idx) {
        tmp = tmp->next;
        i++;
    }
    if (i != idx) {
        PRINT("[DDListDelInIdx] idx:%d , but ListLenth:%d !\n", idx, DDListGetListLenth(head));
        return -1;
    }
    if (tmp == NULL) {
        PRINT("[DDListDelInIdx] idx:%d , but ListLenth:%d !\n", idx, DDListGetListLenth(head));
        return -1;
    }
    /* 处理指向关系 */
    tmp->pre->next = tmp->next;
    if (tmp->next != NULL) {
        //PRINT("TEST Last Node Can't In This Func\n");
        tmp->next->pre = tmp->pre;
    }

    /* 释放资源 */
    if (tmp->val != NULL) {
        free(tmp->val);
    }
    free(tmp);

    return 0;
}

int DDListGetIdxData(Node *head, void *out, int idx)
{
    if (head == NULL || out == NULL || idx <= 0) {
        PRINT("[DDListGetNode] input para is err!\n");
        return -1;
    }
    Node *tmp = head;
    int i = 0;
    while (tmp != NULL && i != idx) {
        tmp = tmp->next;
        i++;
    }
    if (i == idx) {
        memcpy(out, tmp->val, sizeof(g_dataSize));
        return 0;
    }
    PRINT("[DDListAddInIdx] idx:%d , but ListLenth:%d !\n", idx, DDListGetListLenth(head));
    return -1;
}

int DDListGetListLenth(Node *head)
{
    if (head == NULL) {
        PRINT("[DDListGetListLenth] input para is err!\n");
        return -1;
    }
    Node *tmp = head;
    int i = 0;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        i++;
    }

    return i;
}

int DDListPopFstData(Node *head, void *out)
{
    if (head == NULL || out == NULL) {
        PRINT("[DDListPopFstData] input para err\n");
        return -1;
    }
    if (head->next == NULL) {
        PRINT("[DDListPopFstData] No Data in List\n");
        return -1;
    }
    Node *popData = head->next;

    /* 处理指向关系 */
    head->next = popData->next;
    if (popData->next != NULL) {
        popData->next->pre = head;
    }

    /* 弹出数据 */
    if (popData->val != NULL) {
        memcpy(out, popData->val, sizeof(g_dataSize));
        /* 释放List申请的 */
        free(popData->val);
        free(popData);
    } else {
        return -1;
    }
    return 0;
}

int DDListPopLstData(Node *head, void *out)
{
    if (head == NULL || out == NULL) {
        PRINT("[DDListPopLstData] input para is NULL!\n");
        return -1;
    }
    Node *popData = head;
    while (popData->next != NULL) {
        popData = popData->next;
    }

    /* 删除前Node指向关系 */
    popData->pre->next = NULL;

    /* 弹出数据 */
    if (popData->val != NULL) {
        memcpy(out, popData->val, sizeof(g_dataSize));
        free(popData->val); // 释放Data
    }
    if (popData != NULL) {
        free(popData);      // 释放Node
    }
    return 0;
}

/*
 * 打印节点回调函数
 * head：DDList 头节点
 * 回调函数：void *DDList(void *data)
 * 例如：
 *
 */

int ShowDDList(Node *head, void *DDList(void *data))
{
    if (head == NULL) {
        PRINT("[ShowDDList] input para err\n");
        return -1;
    }
    Node *now = head;

    while (now != NULL) {
        if (now->val != NULL) {

            DDList(now->val);
        }
        now = now->next;
    }
    return 0;
}

/*  TEST CASE:
int main(void)
{
    int data[5] = {11, 12, 13, 14, 15};
    //int out = 0;
    int ret;
    Node *head = InitDDList(sizeof(int));
    ret = DDListAddInTail(head, &data[0]);
    ret = DDListAddInTail(head, &data[1]);
    ret = DDListAddInTail(head, &data[2]);
    ret = DDListAddInTail(head, &data[3]);
    ret = ShowDDList(head, show);
    //ret = DDListDelInTail(head);
    //ret = DDListDelInHead(head);
    //ret = DDListDelInIdx(head, 4);
    //ret = DDListDelInIdx(head, 1);
    //ret = DDListPopLstData(head, &out);
    //ret = ShowDDList(head);
    //printf("out :%d \n", out);
    //Node *tmp = DDListGetNode(head, 1);
    //printf("TEST DDListGetNode:1 :%d \n", *(tmp->val));
    //printf("TEST DDListGetListLenth: %d \n", DDListGetListLenth(head));

    return ret;
}
*/

