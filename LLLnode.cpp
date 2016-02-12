/*
 * Michael Cheng
 * CS 202 Homework 2
 * Winter 2016
 *
 * LLLnode.cpp
 *
 * Holds class implementation to LLLnode.h
 *
 * Each list is a list of different object type
 * For efficinecy, will be inserted at head
 *
 */


#include "LLLnode.h"
#include<iostream>
#include<cstring>
using namespace std;


//Class entree_information implementation start


//constructor 
entree_information::entree_information():menu_item(NULL)
{

}

//destructor to deallocate dynamic memory
entree_information::~entree_information()
{
    delete [] menu_item;
    menu_item = NULL;

}


//copy constructor
entree_information::entree_information(const entree_information & from)
{
    menu_item = new char [(strlen(from.menu_item)+1)];
    strcpy(menu_item, from.menu_item);

}


//assignement constructor
entree_information::entree_information(char * menu_)
{
    menu_item = new char [(strlen(menu_)+1)];
    strcpy(menu_item, menu_);

}


//display function that is virutal
//will overwrite if object has display fucntion of same name
void entree_information::display()
{
    cout << menu_item << endl;
    cout << endl;

}


//returns menu_item content
char * entree_information::get_menu()
{
    return menu_item;

}


//Entree_information implementation ends


//Node class implementation start

//constructor
node::node():data(NULL),next(NULL)
{

}


//setting what type of object the node will be at its creating
node::node(int type, char * menu_item)
{
    set_menu_item(type, menu_item);

}


//copy the object type into the object
node::node(const node & from)
{
    data = from.data->copy();
}


// return next ptr
node*&node::get_next()
{
    return next;

}


//display a node
void node::display_node()
{
    data->display();

}


//set next to temp
void node::set_next(node * temp)
{
    next = temp;

}


//setting what tpye of item node is 
//0 -> apps
//1 -> drinks
//2 -> entreee
void node::set_menu_item(int type, char * menu_item)
{
   
    if(type == 0)
        data = new apps(menu_item);
    else if(type == 1)
        data = new entrees(menu_item);
    else if(type == 2)
        data = new drinks(menu_item);

}

//Class node implementation end

//menu_list implementtion start


//constructor
menu_list::menu_list():head(NULL)
{

}


//destructor class remove_all to deallcoate memory
menu_list::~menu_list()
{
   remove_all();
}


//remove all items from the linear linked list
void menu_list::remove_all()
{
    if(!head)
        return;
    node * temp = head;
    while(temp != NULL)
    {
        head = head->get_next();
        delete temp;
        temp = head;
    }
    head = NULL;
}


//get the menu item from the abc
char * node::get_info()
{
    return data->get_menu();

}


//inserting at head 
void menu_list::insert(int type, char * ing)
{
    node * temp = new node(type, ing);
    if(!head)
    {
        head = temp;
        head->set_next(NULL);
        return;

    }
    else
    {
        temp->set_next(head);
        head = temp;
        return;

    }

}


//remove one
//case 1
//if the item is in the middle
//case 2
//if the item is at the end of the list
void menu_list::remove_one(char * menu)
{
    node * temp = head;
    while(temp!=NULL)
    {
        if(temp->get_next() != NULL && strcmp(temp->get_next()->get_info(), menu)==0)
        {
            cout << "Item to be deleted from the MIDDLE linear linked list " << endl;
            cout << temp->get_next()->get_info() << endl;
            cout << endl; 
            node * current = temp;
            node * to_del = current->get_next();
            node * hold = to_del->get_next();
            current->get_next() = hold;
            to_del->get_next() == NULL;
            delete to_del;
            return;
        }
        if(temp->get_next()->get_next() == NULL && strcmp(temp->get_next()->get_info(), menu)==0)
        {
            cout << "Item to be deleted from the END linear linked list " << endl;
            cout << temp->get_next()->get_info() << endl;
            cout << endl;
            return;

        }
        temp = temp->get_next();

    }
    
}


//search for an item within the linear linked list
void menu_list::search_one(char * menu)
{
    node * temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->get_info(), menu)==0)
        {
            cout << "Item that was searched " << endl;
            cout << temp->get_info() << endl;
            cout << endl;
        }
        temp = temp->get_next();

    }

}


//display all items from the lienar linekd lsit
void menu_list::display_all()
{
    if(!head)
    {
        cout << "No more menu items" << endl;
        return;
    }
    node * current = head;
    cout << "Menu list per this ingredidnt" << endl;
    while(current != NULL)
    {
        current->display_node();
        current = current -> get_next();

    }
    cout << endl;

}

/*
 * Dynamic binding implementation of classes start
 *
 */

//appetizer implemntation


//constructor
apps::apps()
{

}


//copy constructor
apps::apps(const apps & from)
{

    menu_item = new char [(strlen(from.menu_item)+1)];
    strcpy(menu_item, from.menu_item);


}


//assignement constructor
apps::apps(char * m)
{
    menu_item = new char [(strlen(m)+1)];
    strcpy(menu_item, m);

}


//returns a ptr of this type of object
entree_information * apps::copy()
{
    return new apps(*this);

}


//display function that will overwite the abstract
//base class copy  constrctor
void apps::display()
{

    cout << "Appetizers " << endl;
    cout << menu_item << endl;
    cout <<"---------------------------" << endl;
}

//entrees implementation


//constructor
entrees::entrees()
{

}


//copy constructor
entrees::entrees(const entrees & from)
{
    menu_item = new char [(strlen(from.menu_item)+1)];
    strcpy(menu_item, from.menu_item);

}


//assignement constructor
entrees::entrees(char * m)
{
    menu_item = new char [(strlen(m)+1)];
    strcpy(menu_item, m);
}


//returns the pointer of this type to be used to display the
//correct inforation
entree_information * entrees::copy()
{
    return new entrees(*this);

}


//display, overwrite the virutal
void entrees::display()
{
    cout << "Entrees " << endl;
    cout << menu_item << endl;
    cout <<"---------------------------" << endl;
}

//drinks implementation 

//constructor
drinks::drinks()
{

}


//copy constructor
drinks::drinks(const drinks & from)
{
    menu_item = new char [(strlen(from.menu_item)+1)];
    strcpy(menu_item, from.menu_item);


}


//assignement operator constructor
drinks::drinks(char * mi)
{
    menu_item = new char [(strlen(mi)+1)];
    strcpy(menu_item, mi);

}


//display, overwrite the virtual
void drinks::display()
{

    cout << "Drinks " << endl;
    cout << menu_item << endl;
    cout <<"---------------------------" << endl;
}


//return a pointer of the drink object
entree_information * drinks::copy()
{
    return new drinks(*this);

}
