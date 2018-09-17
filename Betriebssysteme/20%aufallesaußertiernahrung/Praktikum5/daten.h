#include "lists.h"
#include "global.h"

typedef struct ListNode{
	LIST_NODE_HEADER(struct ListNode);
	
	char name[64];
	int abzeit;
	int prio;
	
} ListNode;

typedef struct DataList{
	LIST_HEADER(ListNode);
}DataList;

void printListe(DataList *liste);
void firstComeFirstServe(DataList *liste);
void shortestJobFirst(DataList *liste);
void priority(DataList *liste);
void rrIndependentPrio(DataList *liste);
void rrWithPrio(DataList *liste);

int compareAbzeit(ListNode *node1, ListNode *node2, ListNode *nix);
int comparePrio(ListNode *node1, ListNode *node2, ListNode *nix);
