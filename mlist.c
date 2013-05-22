#include "mlist.h"

#include <stdlib.h>

/**
Struct definition
**/
typedef struct _mnode
{
	struct _mnode *next;
	//void *info;
	int info;
} MNode;

typedef struct _mlist
{
	MNode *head;
	MNode *tail;
	int size;
} MList;

/**
Private methods declaration
**/
MNode *create_node(int);

/**
List handling methods
**/
MList *create_list()
{
	MList *new_list = malloc(sizeof(MList));
	new_list->size = 0;
	new_list->head = new_list->tail = create_node(NULL);

	return new_list;
}

void delete_list(MList *list)
{
	free(list);
}

void add_element(MList *list, int element)
{
	int i;
	MNode *node = create_node(element);

	list->tail->next = node;
	list->tail = node;
	list->size = list->size+1;
}

int retrieve_element(MList *list, int element)
{
	int i;
	MNode *node = list->head;

	for(i=0; i<element+1; i++)
	{
		node = node->next;
	}

	if(list->head == node)
	{
		return -1;
	}

	return node->info;
}

int get_first_element(MList *list)
{
	return retrieve_element(list, 1);
}

int get_size(MList *list)
{
	return list->size;
}

/****/
MNode *create_node(int element)
{
	MNode *node = malloc(sizeof(MNode));
	node->info = element;
	node->next = NULL;

	return node;
}
