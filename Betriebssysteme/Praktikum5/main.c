#include "scheduling.h"

void createList(DataList *list) {
	List_init(list);
	
	DataNode *node = LIST_NEW_NODE(DataNode);
	strcpy(node->name, "a");
	node->workingtime = 33;
	node->priority = 3;
	List_append(list, node);
	
	node = LIST_NEW_NODE(DataNode);
	strcpy(node->name, "b");
	node->workingtime = 24;
	node->priority = 4;
	List_append(list, node);
	
	node = LIST_NEW_NODE(DataNode);
	strcpy(node->name, "c");
	node->workingtime = 22;
	node->priority = 2;
	List_append(list, node);
	
	node = LIST_NEW_NODE(DataNode);
	strcpy(node->name, "d");
	node->workingtime = 20;
	node->priority = 5;
	List_append(list, node);
	
	
	node = LIST_NEW_NODE(DataNode);
	strcpy(node->name, "e");
	node->workingtime = 28;
	node->priority = 1;
	List_append(list, node);
}

int main() {
	DataList list;
	createList(&list);
	
	firtsComeFirstServe(&list);
	shortestJobFirst(&list);
	priorityScheduling(&list);
	
	rrConstTime(&list);
	rrPriorityTime(&list);
}

