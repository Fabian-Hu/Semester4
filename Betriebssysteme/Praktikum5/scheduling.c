#include "scheduling.h"
#include <stdio.h>
#include <limits.h>

void copyList(DataList *toList, const DataList *fromList) {
	List_init(toList);
	DataNode *fromNode = fromList->head;
	DataNode *toNode = fromList->head;
	while(fromNode) {
		toNode = LIST_NEW_NODE(DataNode);
		strcpy(toNode->name, fromNode->name);
		toNode->workingtime = fromNode->workingtime;
		toNode->priority = fromNode->priority;
		List_append(toList, toNode);
		
		fromNode = fromNode->next;
	}
}

int cmpSJF(DataNode *node1, DataNode *node2, void *dummy) {
	if (node1->workingtime > node2->workingtime) {
		return 1;
	} else if (node1->workingtime < node2->workingtime) {
		return -1;
	} else {
		return 0;
	}
}

int cmpPS(DataNode *node1, DataNode *node2, void *dummy) {
	if (node1->priority < node2->priority) {
		return 1;
	} else if (node1->priority > node2->priority) {
		return -1;
	} else {
		return 0;
	}
}

void firtsComeFirstServe(DataList *list) {
	if(!list) {
		return;
	}
	DataList copiedList;
	copyList(&copiedList, list);
	printf("First come first serve:\n");
	printListInOrder(&copiedList);
	List_clear(&copiedList, NULL, NULL);
}

void shortestJobFirst(DataList *list){
	if(!list) {
		return;
	}
	DataList copiedList;
	copyList(&copiedList, list);
	printf("Shortest job first:\n");
	List_sort(&copiedList, (ListNodeCompareFunction)cmpSJF, NULL);
	printListInOrder(&copiedList);
	List_clear(&copiedList, NULL, NULL);
}

void priorityScheduling(DataList *list){
	if(!list) {
		return;
	}
	DataList copiedList;
	copyList(&copiedList, list);
	printf("Priority Scheduling:\n");
	List_sort(&copiedList, (ListNodeCompareFunction)cmpPS, NULL);
	printListInOrder(&copiedList);
	List_clear(&copiedList, NULL, NULL);
}

void rrConstTime(DataList *list) {
	if(!list) {
		return;
	}
	DataList copiedList;
	copyList(&copiedList, list);
	int size = List_count(list);
	int counter = size;
	float time = 0;
	float actual_time = 0;
	printf("Round Robin with constant timeslot regardless of priority:\n");
	
	while(counter) {
		//find shortets time
		printf("\nEs wird an den Jobs zu folgenden Anteilen gearbeitet:\n");
		DataNode *node = copiedList.head;
		size_t minTime = node->workingtime;
		while(node) {
			if (minTime > node->workingtime) {
				minTime = node->workingtime;
			}
			node = node->next;
		}
		
		//substract minTime
		node = copiedList.head;
		int roundWorkingTime = 0;
		int ready = 0;
		while(node) {
			if(node->workingtime != ULONG_MAX) {
				printf("Es wurde %lus an %s gearbeitet.\n", minTime, node->name);
				roundWorkingTime += minTime;
				node->workingtime -= minTime;
				if(node->workingtime == 0) {
					node->workingtime = ULONG_MAX;
					ready++;
					counter--;
				}
			}
			node = node->next;
		}
		actual_time += roundWorkingTime;
		time += ready * actual_time;
	}
	
	time /= (float)size;
	printf("Mittlere Verweilzeit: %.2fs\n\n", time);
	
}

void rrPriorityTime(DataList *list) {
	if(!list) {
		return;
	}
	DataList copiedList;
	copyList(&copiedList, list);
	int size = List_count(list);
	int counter = size;
	float time = 0;
	float actual_time = 0;
	printf("Round Robin with timeslot duration proportional to priority:\n");
	
	size_t roundWorkingTime[size];
	memset(roundWorkingTime, 0, sizeof(roundWorkingTime));
	while(counter) {
		DataNode *node = copiedList.head;
		int ready = 0;
		//one round
		int nodeIndex = 0;
		while(node) {
			if(node->workingtime != ULONG_MAX && node->workingtime >= node->priority) {
				actual_time += node->priority;
				roundWorkingTime[nodeIndex] += node->priority;
				node->workingtime -= node->priority;
			} else if(node->workingtime < node->priority) {
				actual_time += node->workingtime;
				roundWorkingTime[nodeIndex] += node->workingtime;
				node->workingtime = 0;
			}
			if (node->workingtime == 0) {
				ready++;
				counter--;
			}
			node = node->next;
			nodeIndex++;
		}
		
		time += actual_time * ready;
		if (ready) {
			node = copiedList.head;
			printf("\nEs wird an den Jobs zu folgenden Anteilen gearbeitet:\n");
			nodeIndex = 0;
			while(node) {
				if(node->workingtime != ULONG_MAX) {
					printf("Es wurde %lus an %s gearbeitet.\n", roundWorkingTime[nodeIndex], node->name);
				}
				if (node->workingtime == 0) {
					node->workingtime = ULONG_MAX;
				}
				node = node->next;
				roundWorkingTime[nodeIndex] = 0;
				nodeIndex++;
			}
			
		}
	}
	time /= (float)size;
	printf("Mittlere Verweilzeit: %.2fs\n\n", time);
	
}

void printListInOrder(DataList *list) {
	int size = List_count(list);
	int counter = size;
	float resident_time = 0;
	size_t actual_time = 0;
	
	DataNode *node = list->head;
	
	while (node && counter) {
		actual_time += node->workingtime;
		resident_time += actual_time;
		printf("%s wurde abgearbeitet (Aktuelle Zeit %lu)\n", node->name, actual_time);
		node = node->next;
	}
	resident_time /= (float)size;
	printf("Mittlere Verweilzeit: %.2fs\n\n", resident_time);
}
