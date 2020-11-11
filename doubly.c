#include "u1.h"

static nd_t *_nodeInit(int d) {

  nd_t* n = malloc(sizeof(nd_t));

  n->data = d;

  return n;
}

static l_t* _lInit(int d) {

  l_t* lst = malloc(sizeof(l_t));

  nd_t* n = _nodeInit(d);

  lst->head = n;

  lst->sentinel = n;

  return lst;

}

static void addFront(l_t* list, int  data){

  nd_t* nn = _nodeInit(data);

  nn->next = list->head;

  list->head->previous = nn;

  list->head = nn;

}
static void printList(l_t*);

static void addBack(l_t* list, int data){

  nd_t *nn = _nodeInit(data);

  nn->previous = list->sentinel;

  list->sentinel->next = nn;

  list->sentinel = list->sentinel->next;

}

static int deleteFront(l_t* list){

  nd_t* tmp = list->head;

  int item = tmp->data;

  list->head = tmp->next;

  if (list->head == NULL) list->sentinel = list->head;

  else list->head->previous = NULL;

  free(tmp);

  return item;

}

static int deleteBack(l_t* list){

  nd_t* tmp = list->sentinel;

  int data = tmp->data;

  if(list->sentinel == NULL)list->head = list->sentinel;

  else list->sentinel->next = NULL;

  free(tmp);

  return data;

}


//driver that handles the test cases
int main(){

  printf("TEST CASES: \n\n");
  printf("ADD FROM THE FRONT: \n\n");

  l_t* list = _lInit(0);

  addFront(list, 1);
  addFront(list, 2);
  addFront(list, 3);
  addFront(list, 4);

  assert(list->head->next->data == 3);

  printf("PASSED! \n\n");


  printf("DELETE FROM THE FRONT: \n\n");

  int test =deleteFront(list);
  assert(test == 4);
  printf("PASSED! \n\n");
  printf("ADD FROM THE BACK: \n\n");

  addBack(list, 5);

  assert(list->head->next->next->next->next->data  == 5 );

  printf("PASSED! \n\n");

  printf("DELETE FROM THE BACK: \n\n");

  test = deleteBack(list);

  assert(test == 5);
  printf("PASSED! \n\n"); printf("BASIC TESTS PASSED! \n\n");

  return 0;

}
