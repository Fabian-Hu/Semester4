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
	if(liste == NULL) {
		printf("RIP\n");
		return;
	}	
	float counter = List_count(liste);
	float anzahl = counter;
	printf("Round Robin mit konstanter Zeitscheibe unabhängig von der Priorität:\n");
	List_sort(liste,(ListNodeCompareFunction)compareAbzeit, NULL);
	float verweilZeit=0;
	float gesamtZeit=0;
	ListNode *node;
	node = liste->head;	
	while(!List_isEmpty(liste)){
		counter = List_count(liste);
		gesamtZeit = gesamtZeit + (liste->head->abzeit*counter);
		verweilZeit = verweilZeit + gesamtZeit;
		node = liste->head;
		int abzug = node->abzeit;
		for(int i=0;i<counter;i++){
			node->abzeit = node->abzeit - abzug;
			printf("Es wurde %is an %s gearbeitet.\n",abzug ,node->name);
			node = node->next;
		}	
		printf("%s wurde abgearbeitet (Aktuelle Zeit: %.2f).\n", liste->head->name, gesamtZeit);
		List_remove(liste,liste->head);
	}
	printf("Mittlere Verweilzeit: %.2f s.\n\n",verweilZeit/anzahl);
}

void rrWithPrio(DataList *liste) {
	if(liste == NULL) {
		printf("RIP\n");
		return;
	}	
	float counter = List_count(liste);
	float anzahl = counter;
	printf("Round Robin mit Zeitscheibendauer proportional zur Priorität:\n");
	List_sort(liste,(ListNodeCompareFunction)comparePrio, NULL);
	float verweilZeit=0;
	float gesamtZeit=0;
	ListNode *node;
	node = liste->head;	
	while(!List_isEmpty(liste)){
		node = liste->head;
		for(int i=0;i<counter;i++){
			node->abzeit = node->abzeit - node->prio;			
			gesamtZeit = gesamtZeit + node->prio;
			printf("Es wurde %is an %s gearbeitet.\n",node->prio,node->name);
			node = node->next;
		}		
		printf("\n");
		node = liste->head;
		for(int i=0;i<counter;i++){
			if(node->abzeit <= 0){
				gesamtZeit = gesamtZeit + node->abzeit;
				verweilZeit = verweilZeit + gesamtZeit;
				printf("%s wurde abgearbeitet (Aktuelle Zeit: %.2f).\n", liste->head->name, gesamtZeit);
				List_remove(liste,node);
				counter--;		
			}
			node = node->next;
		}
	}	
	printf("Mittlere Verweilzeit: %.2f s.\n\n",verweilZeit/anzahl);
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
