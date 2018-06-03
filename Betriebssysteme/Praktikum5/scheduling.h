#include "lists.h"
#include "global.h"

typedef struct DataNode{
	LIST_NODE_HEADER(struct DataNode);
	
	char name[32];
	size_t workingtime;
	size_t priority;
} DataNode;

typedef struct DataList {
	LIST_HEADER(DataNode);
} DataList;

void firtsComeFirstServe(DataList *list);
void shortestJobFirst(DataList *list);
void priorityScheduling(DataList *list);
void rrConstTime(DataList *list);
void rrPriorityTime(DataList *list);

void printListInOrder(DataList *list);


