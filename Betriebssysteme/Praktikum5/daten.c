#include "daten.h"
#include <stdio.h>

void printListe(DataList *liste) {
	ListNode *node = liste->head;
	for (int i = 0; i < List_count(liste); i++) {
		printf("%s,%i,%i\n", node->name, node->abzeit, node->prio);
		node = node->next;
	}
}

void firstComeFirstServe(DataList *liste) {
	//fertig
	if(liste == NULL) {
		printf("RIP\n");
		return;
	}
	printf("First Come First Serve:\n");
	ListNode *node = liste->head;
	int zeit = 0;
	float verweilZeit = 0;
	float counter = List_count(liste);
	float anzahl = counter;
	for (int i = 0; i < counter; counter--) {
		zeit = zeit + node->abzeit;
		verweilZeit = verweilZeit + (counter * node->abzeit);
		printf("%s wurde abgearbeitet (Aktuelle Zeit: %i).\n", node->name, zeit);
		node = node->next;
	}
	verweilZeit = verweilZeit / anzahl;
	printf("Mittlere Verweilzeit: %.2f s.\n\n",verweilZeit);
}

void shortestJobFirst(DataList *liste) {
	
	if(liste == NULL) {
		printf("RIP\n");
		return;
	}
	printf("Shortest Job First:\n");
	int zeit = 0;
	float verweilZeit = 0;
	float counter = List_count(liste);
	float anzahl = counter;
	List_sort(liste,(ListNodeCompareFunction)compareAbzeit, NULL);
	
	ListNode *node = liste->head;
	for (int i = 0; i < counter; counter--) {
		zeit = zeit + node->abzeit;
		verweilZeit = verweilZeit + (counter * node->abzeit);
		printf("%s wurde abgearbeitet (Aktuelle Zeit: %i).\n", node->name, zeit);
		node = node->next;
	}
	verweilZeit = verweilZeit / anzahl;
	printf("Mittlere Verweilzeit: %.2f s.\n\n",verweilZeit);
}

void priority(DataList *liste) {
	
	if(liste == NULL) {
		printf("RIP\n");
		return;
	}
	printf("Shortest Priority First:\n");
	int zeit = 0;
	float verweilZeit = 0;
	float counter = List_count(liste);
	float anzahl = counter;
	List_sort(liste,(ListNodeCompareFunction)comparePrio, NULL);
	
	ListNode *node = liste->head;
	for (int i = 0; i < counter; counter--) {
		zeit = zeit + node->abzeit;
		verweilZeit = verweilZeit + (counter * node->abzeit);
		printf("%s wurde abgearbeitet (Aktuelle Zeit: %i).\n", node->name, zeit);
		node = node->next;
	}
	verweilZeit = verweilZeit / anzahl;
	printf("Mittlere Verweilzeit: %.2f s.\n\n",verweilZeit);
	List_clear(liste, NULL, NULL);
}

void rrIndependentPrio(DataList *liste) {
	
}

void rrWithPrio(DataList *liste) {
	
}

int compareAbzeit(ListNode *node1, ListNode *node2, ListNode *nix) {
	if (node1->abzeit < node2->abzeit) {
		return -1;
	} else {
		return 1;
	}
}

int comparePrio(ListNode *node1, ListNode *node2, ListNode *nix) {
	if (node1->prio < node2->prio) {
		return 1;
	} else {
		return -1;
	}
}
