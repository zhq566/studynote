#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#pragma once

typedef struct LINKNODE LinkNode;
struct LINKNODE
{
	void* data;    // ָ���κ����͵�����
	LinkNode* next;
};

typedef struct LINKLIST LinkList;

struct LINKLIST
{
	LinkNode* head;         // ͷ�ڵ�
	int size;
};

// ��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);

LinkList* Init_LinkList();  // ��ʼ������
void Insert_LinkList(LinkList* list, int pos, void * data);     // ָ��λ�ò���
void RemoveByPos_LinkList(LinkList* list, int pos);             // ɾ��ָ��λ�õ�ֵ
int Size_LinkList(LinkList* list);                              // ��ȡ����ĳ���
void* Front_LinkList(LinkList* list);                           // ���ص�һ���ڵ�
void FreeSpace_LinkList(LinkList* list);                        // �ͷ�������ڴ�
int Find_LinkList(LinkList *list, void* data);                 // ����
void Print_LinkList(LinkList* list, PRINTLINKNODE print);       // ��ӡ����

#endif // LIST_H_INCLUDED
