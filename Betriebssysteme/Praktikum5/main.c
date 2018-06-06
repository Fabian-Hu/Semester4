#include "daten.h"

void listeErstellen(DataList *liste){
	List_init(liste);
	
	ListNode *node = LIST_NEW_NODE(ListNode);
	strcpy(node->name, "a");
	node->abzeit = 30;
	node->prio = 2;
	List_append(liste,node);
	
	node = LIST_NEW_NODE(ListNode);
	strcpy(node->name, "b");
	node->abzeit = 20;
	node->prio = 1;
	List_append(liste,node);
	
	node = LIST_NEW_NODE(ListNode);
	strcpy(node->name, "c");
	node->abzeit = 25;
	node->prio = 5;
	List_append(liste,node);
	
	node = LIST_NEW_NODE(ListNode);
	strcpy(node->name, "d");
	node->abzeit = 28;
	node->prio = 4;
	List_append(liste,node);
	
	node = LIST_NEW_NODE(ListNode);
	strcpy(node->name, "e");
	node->abzeit = 18;
	node->prio = 3;
	List_append(liste,node);
}

void main(){
	DataList liste;
	DataList liste2;
	
	listeErstellen(&liste);
	listeErstellen(&liste2);
	//printListe(&liste);
	firstComeFirstServe(&liste);
	shortestJobFirst(&liste);
	priority(&liste);
	
	
	
}


