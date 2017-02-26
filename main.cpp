/*
 * list_3358_LL_ADT.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: Adam
 */
#include <iostream>

using namespace std;

#include "list_3358_LL.h"

void showList(List_3358 myList);

void showbackwards(List_3358 &myList);

bool search(List_3358 &myList, int target);

int main() {

    List_3358 myList;

    myList.insert(42);

    myList.insert(52);

    myList.insert(12);

    myList.resetFront();

    myList.insert(-42);

    myList.resetBack();

    myList.insert(2);

    cout << "test inserts" << endl;
    showList(myList);  // -42 42 52 2 12

    cout << endl;
    myList.resetFront();
    cout << "ResetFront, current is " << myList.getCurrent() << endl;

    cout << endl;
    myList.resetBack();
    cout << "ResetBack, current is " << myList.getCurrent() << endl;

    myList.advance();  // to eol
    myList.insert(88);

    cout << "test insert at end" << endl;
    showList(myList);


    cout << "test getCurrent at EOL" << endl;
    while (!myList.atEOL()) {
        myList.advance();
    }
    //remove the comment marker, calling next function should fail
    //  cout << myList.getCurrent() << endl;


    myList.resetFront();
    myList.advance();
    myList.advance();

    int value = myList.getCurrent();
    cout << "mylist current value is: " << value << endl;

    //myList.resetBack();
    //myList.resetFront();
    // myList.remove();
    //cout << "myList is now: ";
    //showList(myList);

    List_3358 myList2 = myList; //copy constructor
    cout << "show mylist2 (copy constr)" << endl;
    showList(myList2);

    value = myList2.getCurrent();
    cout << "mylist2 current value is: " << value << endl;

    myList.resetBack();


    cout << " test search" << endl;
    int target = 42;
    if (search(myList, target))
        cout << myList.getCurrent() << endl;
    else
        cout << target << " not found" << endl;

    myList.remove();

    cout << " test remove after search" << endl;
    showList(myList);

    cout << "show other list (test copy constructor) still has 42" << endl;
    showList(myList2);

    cout << "showlist forwards. " << endl;
    showList(myList);
    cout << endl;

    cout << "showList backwards." << endl;
    showbackwards(myList);

    myList.diagnose();

    myList2.diagnose();

    return 0;
}

//***********************************************************
// showList: displays the list, first to last element
// myList the list to display
// note that the list is passed by value, so the cursor remains unchanged
//  in the argument passed to this function.
//***********************************************************

void showList(List_3358 myList) {
    myList.resetFront();

    while (!myList.atEOL()) {
        cout << myList.getCurrent() << " ";
        myList.advance();
    }
    cout << endl;

}

void showbackwards(List_3358 &myList) {
    myList.resetBack();

    while (!myList.atEOL()) {
        cout << myList.getCurrent() << " ";
        myList.backup();
    }
    cout << endl;
}
//***********************************************************
// search: finds target in list and moves the cursor to that element
// myList the list to search
// target: the value to find
// returns true if found, false if not.
// list is passed by reference so that it can change the cursor
//  (if not found, cursor will be EOL)
//***********************************************************

bool search(List_3358 &myList, int target) {
    myList.resetFront();

    while (!myList.atEOL() && (target != myList.getCurrent()))
        myList.advance();

    if (!myList.atEOL())
        return true; //found it and cursor is placed on it
    else
        return false; //not found and cursor at end

}



