/*
 * Michael Cheng
 * CS 202 Homework 2
 * Winter 2106
 *
 * BSTnode.cpp
 *
 * Class implementation from BSTnode.h
 *
 */


#include"BSTnode.h"
#include<iostream>
#include<cstring>
using namespace std;


//Class in (ingredidents) implementation start

//Constructor for class in
//Intialize ing to NULL and cv to 0
in::in():ingredidents(NULL),compare_value(0)
{

}


//assignment constructor
//assigning values to varibles within the class
in::in(char * ing, int cv)
{
    ingredidents = new char[(strlen(ing)+1)];
    strcpy(ingredidents, ing);
    compare_value = cv;
}


//copy constructor for class ing
//copys all dynamic memory
in::in(const in & from)
{
    ingredidents = new char [(strlen(from.ingredidents)+1)];
    strcpy(ingredidents, from.ingredidents);

    compare_value = from.compare_value;

}


//Returns a value that will be compared with incoming value through the
//hash function to determine where to insert. 
bool in::compare(int value)
{
    if(value <= compare_value)
    {
        return true;

    }
    else
        return false;

}


//returns ingredidnts information to be used to class further down the 
//hireachy and classes with has a reletionships
char *in::get_ingredidents()
{
    return ingredidents;
}


//displays out the items within this class
void in::display()
{
    cout <<"----------------------------------------------------------"<<endl;;
    cout <<"Ingredidents Type : " << ingredidents << "**********"<< endl;
    cout <<"----------------------------------------------------------"<<endl;;
    cout << endl;
}

//Class ingredidents implementation end

//Class BSTnode implementation start


//Bst_node constructor, intializes left, right and linear linked list "alist" to
//NULL
bst_node::bst_node():left(NULL),right(NULL),alist(NULL)
{

}


//Assignement constructor
bst_node::bst_node(char * ing, int cv, menu_list * lll):in(ing, cv)
{
    alist = lll;
}


//copy constructor for bst_node
bst_node::bst_node(const bst_node & from):in(from)
{
    alist = from.alist;
}


//return left value;
bst_node *& bst_node::get_left()
{
    return left;
}


//return right value
bst_node *& bst_node::get_right()
{
    return right;
}


//display the lll that is contained within the bst_node
void bst_node::display_lll()
{
    alist->display_all();

}

//Class BSTnode implementation end

//Class BST implementation


//BST constructor
BST::BST():root(NULL)
{

}


//BST destructor, calls the remove all function to remove everything
BST::~BST()
{
    remove_all();

}


//insert wrapper
int BST::insert(char * ing, int compare_value, menu_list * alist)
{
    insert_(ing, compare_value, alist, root);

}


//insert function
//insert by hash value to keeps tree balance
int BST::insert_(char * ing, int compare_value, menu_list * alist, bst_node *& root)
{
    if(!root)
    {
        root = new bst_node(ing, compare_value, alist);
        root->get_left() = NULL;
        root->get_right() = NULL;
        return 0;
    }
    else if(root->compare(compare_value) == true)
    {
        insert_(ing, compare_value, alist, root->get_left());

    }
    else
        insert_(ing, compare_value, alist, root->get_right());

}


//search for an item in the bst wrapper
int BST::search(char * ing)
{
    search_(ing, root);

}


//search for a function base on the item to search
int BST::search_(char * ing, bst_node * root)
{
    if(!root)
        return 0;
   search_(ing, root->get_left());
   search_(ing, root->get_right());
   if(strcmp(root->get_ingredidents(), ing)==0)
   {
       root->display();
       root->display_lll();
       return 1;
   }

}


//display all wrapper
int BST::display_all()
{
    display_all_(root);

}


//display the whole tree
int BST::display_all_(bst_node * root)
{
    if(!root)
    {
        return 0;
    }
    root->display();
    root->display_lll();
    display_all_(root->get_left());
    display_all_(root->get_right());
    

}


//return the hash value of the item to be inserted
//within the binary search
//With a hash value, this bst will be perfectly balanced
//with balance factor not differing more than 1
int BST::hash_value(char * ing)
{
    int value = 0;
    for(int i = 0; i<strlen(ing); i++)
        value = (value+(int)ing[i] * 17);
    value = value % 3;
    return value;

}


//remove all wrapper
void BST::remove_all()
{
    remove_all_(root);

}


//remove all items within a binary search tree
int BST::remove_all_(bst_node*&root)
{
    if(!root)
        return 0;
    if(root->get_left()!=NULL)
        remove_all_(root->get_left());
    if(root->get_right()!=NULL)
        remove_all_(root->get_right());

    delete root;
    //root->get_left()=NULL;
    //root->get_right()=NULL;

}
