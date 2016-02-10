#include "LLLnode.h"
#include<iostream>
#include<cstring>
using namespace std;

entree_information::entree_information():menu_item(NULL)
{

}

entree_information::~entree_information()
{

}

entree_information::entree_information(const entree_information & from)
{
    menu_item = new char [(strlen(from.menu_item)+1)];
    strcpy(menu_item, from.menu_item);

}

entree_information::entree_information(char * menu_)
{
    menu_item = new char [(strlen(menu_)+1)];
    strcpy(menu_item, menu_);

}

void entree_information::display()
{
    cout << menu_item << endl;

}


//Node class implementation

node::node():data(NULL),next(NULL)
{

}

node::node(int type, char * menu_item)
{
    set_menu_item(type, menu_item);

}

node::node(const node & from)
{
    data = from.data->copy();
}

node*&node::get_next()
{
    return next;

}

void node::display_node()
{
    data->display();

}

void node::set_next(node * temp)
{
    next = temp;

}

void node::set_menu_item(int type, char * menu_item)
{
    if(type == 0)
        data = new apps(menu_item);
    else if(type == 1)
        data = new entrees(menu_item);
    else if(type == 2)
        data = new drinks(menu_item);

}

//menu_list implementtion

menu_list::menu_list():head(NULL)
{

}

menu_list::~menu_list()
{
    remove_all();
}

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

void menu_list::display_all()
{
    if(!head)
        return;
    node * current = head;
    while(current != NULL)
    {
        current->display_node();
        current = current -> get_next();

    }

}

/*
 * Dynamic binding implementation of classes
 *
 */

//appetizer implemntation

apps::apps()
{

}

apps::apps(const apps & from)
{

    menu_item = new char [(strlen(from.menu_item)+1)];
    strcpy(menu_item, from.menu_item);


}

apps::apps(char * m)
{
    menu_item = new char [(strlen(m)+1)];
    strcpy(menu_item, m);

}

entree_information * apps::copy()
{
    return new apps(*this);

}

void apps::display()
{
    cout << "Appetizers " << endl;
    cout << menu_item << endl;

}

//entrees implementation

entrees::entrees()
{

}

entrees::entrees(const entrees & from)
{
    menu_item = new char [(strlen(from.menu_item)+1)];
    strcpy(menu_item, from.menu_item);

}

entrees::entrees(char * m)
{
    menu_item = new char [(strlen(m)+1)];
    strcpy(menu_item, m);
}

entree_information * entrees::copy()
{
    return new entrees(*this);

}

void entrees::display()
{
    cout << "Entrees " << endl;
    cout << menu_item << endl;

}

//drinks implementation 

drinks::drinks()
{

}

drinks::drinks(const drinks & from)
{
    menu_item = new char [(strlen(from.menu_item)+1)];
    strcpy(menu_item, from.menu_item);


}

drinks::drinks(char * mi)
{
    menu_item = new char [(strlen(mi)+1)];
    strcpy(menu_item, mi);

}

void drinks::display()
{
    cout << "Drinks " << endl;
    cout << menu_item << endl;

}

entree_information * drinks::copy()
{
    return new drinks(*this);

}
