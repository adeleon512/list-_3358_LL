//
// Created by Adam on 2/26/2017.
//
/*
 * 		File name: list_3358_LL.cpp
 *  	Date: Feb 17, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structors
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 2
 *      Description: This file is a doubly linked list that uses a cursor to
 *      perform various list functions. The header file that this
 *      implementation refers to for its declarations is list_3358_LL.h The
 *      output can be generated using a separate .cpp test driver.
 */
#include <iostream>
#include <cassert>
#include "list_3358_LL.h"

using namespace std;

List_3358::List_3358() {
    head = NULL;        //Set head, tail, and cursor to NULL for empty list.
    tail = NULL;
    cursor = NULL;
}

List_3358::List_3358(const List_3358 &src) {
    head = NULL;    //Initialize had, tail and cursor to NULL for empty list.
    tail = NULL;
    cursor = NULL;

    //to construct a copy of the list
    for (Node *p = src.head; p != NULL; p = p->next) {
        insert(p->value);
    }
    //to put this->cursor in the right position:
    if (src.cursor) {
        //then list isn't empty and cursor isn't NULL
        cursor = head;
        for (Node *p = src.head; p != src.cursor; p = p->next) {
            advance();
        }
    }
}

List_3358::~List_3358() {
    Node *n;
    Node *p = head;
    while (p != NULL) {
        n = p->next;
        delete p;
        p = n;
    }
}

void List_3358::insert(const int &item) {
    assert(!isFull());            //Test for precondition

    Node *newNode = new Node; //Create new node passing it value from driver.
    newNode->value = item;
    newNode->next = NULL;        //Set both ends of new node to NULL
    newNode->previous = NULL;


    if (isEmpty())            //if list is empty insert first node.
    {
        head = newNode;
        tail = newNode;
        cursor = newNode->next;


    } else if (cursor != NULL)    //list not empty cursor not at NULL
    {
        if (cursor == head)    //insert newNode after resetFront has been called.
        {
            head->previous = newNode;
            newNode->next = head;
            newNode->previous = NULL;
            head = newNode;
        } else        //insert for cursor at any position except head and NULL.
        {
            Node *n = cursor->previous;
            newNode->next = cursor;
            newNode->previous = n;
            n->next = newNode;
            cursor->previous = newNode;
        }
    } else        //cursor is at EOL insert and update tail.
    {
        tail->next = newNode;
        newNode->previous = tail;
        newNode->next = cursor;
        tail = newNode;
    }

}

void List_3358::remove() {
    assert(!atEOL() && !isEmpty());

    Node *before = cursor->previous; //points to node before cursor
    Node *after = cursor->next;        //points to node after cursor

    //reset before's next pointer
    if (before == NULL)                //cursor is on first item
    {
        head = after;
    } else {
        before->next = after;
    }
    //reset after's previous pointer
    if (after == NULL) {
        tail = before;
    } else {
        after->previous = before;
    }

    Node *p = cursor;            //save for delete
    cursor = after;

    //deallocate the node we removed
    delete p;
//	Node *x = cursor;
//	assert(!isEmpty() || !atEOL());  //Test for preconditions
//
//	if(x == head && x == tail)	//If only one node exists delete it.
//	{
//		head = x->previous;
//		tail = x->next;
//		cursor = x->next;
//		delete x;
//	}
//	else if(x != head && x != tail) //If cursor is not at head or tail.
//	{
//		Node *before = cursor->previous;
//		Node *after = cursor->next;
//
//		before->next = x->next;
//		after->previous = x->previous;
//		advance();				//set cursor to successor.
//		delete x;
//	}
//	else if(x == head)	//if cursor at head delete head node and update head.
//	{
//		head = x->next;
//		head->previous = x->previous;
//		advance();								//set cursor to successor.
//		delete x;
//	}
//	else if(x == tail)	//if cursor at tail delete tail node and update tail.
//	{
//		tail = x->previous;
//		tail->next = x->next;
//		delete x;
//	}					//cursor at EOL after last node deleted.
}

void List_3358::resetFront() {
    cursor = head;                    //set cursor to head of list.
}

void List_3358::resetBack() {
    cursor = tail;                    //set cursor to tail of list.
}

void List_3358::advance() {
    cursor = cursor->next;            //move the cursor forward.
}

void List_3358::backup() {
    cursor = cursor->previous;        //move the cursor back.
}

bool List_3358::isEmpty() const {
    if (head == NULL && tail == NULL) //if head and tail are NULL list is empty.
    {
        return true;
    }

    return false;
}

bool List_3358::atEOL() const {
    if (cursor == NULL)    //if cursor equals NULL then it is at EOL
    {
        return true;
    }
    return false;
}

bool List_3358::isFull() const {
    return false;        //List is never full.
}

int List_3358::getCurrent() const {
    assert(!atEOL());    //test for precondition then return value at cursor.
    return cursor->value;
}

void List_3358::diagnose() {
    Node *h;
    Node *t;

    cout << "forwards: ";
    for (h = head; h != NULL; h = h->next) {
        cout << h->value << "  ";
    }
    cout << endl;
    cout << "backwards: ";
    for (t = tail; t != NULL; t = t->previous) {
        cout << t->value << "  ";
    }
    cout << endl;
    cout << "head: " << (head ? head->value : -11) << endl;
    cout << "tail: " << (tail ? tail->value : -11) << endl;
    cout << "cursor: " << (cursor ? cursor->value : -11) << endl;

}




