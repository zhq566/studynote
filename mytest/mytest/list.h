#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#pragma once

typedef struct LINKNODE LinkNode;
struct LINKNODE
{
	void* data;    // 指向任何类型的数据
	LinkNode* next;
};

typedef struct LINKLIST LinkList;

struct LINKLIST
{
	LinkNode* head;         // 头节点
	int size;
};

// 打印函数指针
typedef void(*PRINTLINKNODE)(void*);

LinkList* Init_LinkList();  // 初始化链表
void Insert_LinkList(LinkList* list, int pos, void * data);     // 指定位置插入
void RemoveByPos_LinkList(LinkList* list, int pos);             // 删除指定位置的值
int Size_LinkList(LinkList* list);                              // 获取链表的长度
void* Front_LinkList(LinkList* list);                           // 返回第一个节点
void FreeSpace_LinkList(LinkList* list);                        // 释放链表的内存
int Find_LinkList(LinkList *list, void* data);                 // 查找
void Print_LinkList(LinkList* list, PRINTLINKNODE print);       // 打印链表

#endif // LIST_H_INCLUDED
