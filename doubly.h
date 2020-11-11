#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _nd{

  struct _nd *next;

  struct _nd *previous;
  int data;

}nd_t;

typedef struct _l{

  nd_t* head;

  nd_t* sentinel;

}l_t;

static nd_t* _nodeInit(int);

static l_t* _lInit(int);

static void _destroyList(l_t*);

static void _destroyNode(nd_t*);

//actual API is defined here
static void addFront(l_t*,int);

static void addBack(l_t*,int);

static int deleteFront(l_t*);

static int deleteBack(l_t*);
