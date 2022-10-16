//(1) How to create a linked list?
//(2) How to use gdb to debug a program? see line 42
#include <iostream>
#include <assert.h>
#include <cstdlib>
using namespace std;

struct node {
  int data;
  node *next;
};

typedef node* nodePtr;

void insertNode(nodePtr& root, int info);
//Another possible prototype
//void insertNode(nodePtr& root, nodePtr newNodePtr);

void printList(nodePtr root);

int main()
{
  nodePtr head;       
  nodePtr current;  // This will point to each node as it traverses the list

  cout << "I am here\n";

  head = NULL; //Initially, it is an empty list
  printList(head);

  insertNode(head, 8);
  insertNode(head, 3);
  insertNode(head, 15);
  printList(head);
    
  return 0;
}

void printList(nodePtr root) {
  nodePtr cur;
  
  if (root = NULL) 
    cout << "This is an empty list\n";

  cur = root;
  while (cur != NULL) {
    cout << cur->data << endl;
    cur = cur->next;
  }
}

void insertNode(nodePtr& root, int info) {
  nodePtr cur;

  cur = new node; //Do not use this: new nodePtr
  assert(cur != NULL); //Ensure that memory is allocatd 
  
  cur->data = info;
  cur->next = NULL;

  if (root == NULL) //If the list is empty, cur becomes the root
    root = cur;
  else { //Insert cur as the root of the list
    cur->next = root;
    root = cur;
  }
}
     
