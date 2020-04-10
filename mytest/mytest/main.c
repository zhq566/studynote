#include <stdio.h>
#include <stdlib.h>

#define  _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// 自定义数据类型
typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(void* data)
{
	Person* p = (Person*)data;               // 类型强转
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}

int main()
{
	LinkList* list = Init_LinkList();      // 创建链表

	Person p1 = { "aaa",18,0 };
	Person p2 = { "bbb",19,1 };
	Person p3 = { "ccc",20,2 };          // 创建数据
	Person p4 = { "ddd",17,3 };
	Person p5 = { "eee",16,4 };

	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);

	Print_LinkList(list, MyPrint);           // 打印

	RemoveByPos_LinkList(list, 6);

	printf("------------\n");

	Person* p = (Person*)Front_LinkList(list);  // 返回第一个结点
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);

	printf("------------\n");

	Print_LinkList(list, MyPrint);           // 打印
	FreeSpace_LinkList(list);                // 清空链表

}
