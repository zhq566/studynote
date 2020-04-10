#include <stdio.h>
#include <stdlib.h>

#define  _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// �Զ�����������
typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(void* data)
{
	Person* p = (Person*)data;               // ����ǿת
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}

int main()
{
	LinkList* list = Init_LinkList();      // ��������

	Person p1 = { "aaa",18,0 };
	Person p2 = { "bbb",19,1 };
	Person p3 = { "ccc",20,2 };          // ��������
	Person p4 = { "ddd",17,3 };
	Person p5 = { "eee",16,4 };

	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);

	Print_LinkList(list, MyPrint);           // ��ӡ

	RemoveByPos_LinkList(list, 6);

	printf("------------\n");

	Person* p = (Person*)Front_LinkList(list);  // ���ص�һ�����
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);

	printf("------------\n");

	Print_LinkList(list, MyPrint);           // ��ӡ
	FreeSpace_LinkList(list);                // �������

}
