#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagListElement
{
struct tagListElement*next;
int data;
}ListElement;
typedef struct tagList
{
ListElement*head;
ListElement*tail;
int size;
}List;

/* inicjalizacja listy */
void init(List*list)
{
list->head=0;
list->tail=0;
list->size=0;
}
/* Dodawanie danych do listy */
void push_front(List*list, int data)
{
ListElement*element =
 (ListElement*)malloc(sizeof(ListElement));
element->next=list->head;
element->data=data;
if(list->head!=0){
 list->head=element;
 }else{
 list->head=list->tail=element;
 }
 list->size++;
}

void push_back(List*list, int data)
{
ListElement*element =
 (ListElement*)malloc(sizeof(ListElement));
element->next=0;
element->data=data;
if(list->tail!=0){
 list->tail->next=element;
 list->tail=element;
}else{
 list->head=list->tail=element;
}
 list->size++;
}

/* Usuwanie pierwszego elementu */
void delete_front(List*list){
 ListElement*toDelete;
 if(list->head==0)return;
 toDelete = list->head;
 list->head=list->head->next;
 if(list->head==0)list->tail=0;
 free(toDelete);
 list->size--;
}
/* Zwalnianie ca³ej listy */
void freeList(List*list)
{
while(list->head){
delete_front(list);
}
printf("\nTRACE: stan listy %p %p %d\n",
list->head, list->tail, list->size);
}

/* Wypisanie zawartoœci listy, iteracja po elementach listy */
void dumpList(const List*list)
{
ListElement*i;
for(i=list->head; i!=0; i=i->next){
printf("%d ",i->data);
}
printf("\n");
}

int main(int argc, char *argv[])
{
 int i;
 List list;
 init(&list);
 for(i=0;i<10;i++){
 push_front(&list,i);
 push_back(&list,i);
 }
 dumpList(&list);

 for(i=100;i<105;i++){
 delete_front(&list);
 push_back(&list,i);
 }
 dumpList(&list);

 freeList(&list);
 return 0;
}

