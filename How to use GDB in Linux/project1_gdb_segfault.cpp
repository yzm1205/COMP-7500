/*
 * This program demonstrates: 
 *   (1) how to create a linked list?
 *   (2) how to use gdb to debug a program?
 * 
 * Xiao Qin <xqin@auburn.edu>
 *
 * Samuel Ginn College of Engineering
 * Auburn University, AL 36849-5347 
 * http://www.eng.auburn.edu/~xqin/
 *
 */ 

#include <iostream>
#include <assert.h>
#include <cstdlib>
using namespace std;
#define BUG_INJECTED

struct Node {
  int data;
  Node *next;
};

typedef Node* NodePtr;

void InsertNode(NodePtr& root, int info);
//Another possible prototype
//void insertNode(nodePtr& root, nodePtr newNodePtr);

void PrintList(NodePtr root);

int main()
{
  NodePtr head;       
  NodePtr current;  // This will point to each node as it traverses the list

  cout << "I am here\n";

  head = NULL; //Initially, it is an empty list
  PrintList(head);

  InsertNode(head, 8);
  InsertNode(head, 3);
  InsertNode(head, 15);
  PrintList(head);
    
  return 0;
}

void PrintList(NodePtr root) {
  NodePtr cur;
  
  if (root == NULL) 
    cout << "This is an empty list\n";

  cur = root;
  while (cur != NULL) {
    cout << cur->data << endl;
    cur = cur->next;
  }
}

#ifdef BUG_INJECTED
void InsertNode(NodePtr& root, int info) {
  NodePtr cur;

  cur = new Node; //Do not use this: new nodePtr
  assert(cur != NULL); //Ensure that memory is allocatd 
  
  cur->data = info;
  cur->next = NULL;
  cur->next->next = NULL;  

  if (root == NULL) //If the list is empty, cur becomes the root
    root = cur; //bug: cur=root
  else { //Insert cur as the root of the list
    cur->next = root; 
    root = cur;
  }
}

/* bug fixed */
#else 
void InsertNode(NodePtr& root, int info) {
  NodePtr cur;

  cur = new Node; //Do not use this: new nodePtr
  assert(cur != NULL); //Ensure that memory is allocatd 
  
  cur->data = info;
  cur->next = NULL; //bug fixed

  if (root == NULL) //If the list is empty, cur becomes the root
    root = cur; //bug fixed
  else { //Insert cur as the root of the list
    cur->next = root; 
    root = cur;
  }
}
#endif
