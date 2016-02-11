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

bool in::compare(int value)
{
    if(value <= compare_value)
    {
        return true;

    }
    else
        return false;

}

char *in::get_ingredidents()
{
    return ingredidents;
}

void in::display()
{
    cout <<"----Ingredident----"<< endl;
    cout <<"----" << ingredidents << "----"<< endl;
}

//Class ingredidents implementation end

//Class BSTnode implementation start

bst_node::bst_node():left(NULL),right(NULL),alist(NULL)
{

}

bst_node::bst_node(char * ing, int cv, menu_list * lll):in(ing, cv)
{
    alist = lll;


}

bst_node::bst_node(const bst_node & from):in(from)
{
    alist = from.alist;
}

bst_node *& bst_node::get_left()
{
    return left;
}

bst_node *& bst_node::get_right()
{
    return right;
}

void bst_node::display_lll()
{
    alist->display_all();

}

//Class BSTnode implementation end

//Class BST implementation

BST::BST():root(NULL)
{

}

int BST::insert(char * ing, int compare_value, menu_list * alist)
{
    insert_(ing, compare_value, alist, root);

}



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

int BST::search(char * ing)
{
    search_(ing, root);

}

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

int BST::display_all()
{
    display_all_(root);

}

int BST::display_all_(bst_node * root)
{
    if(!root)
        return 0;
    root->display();
    root->display_lll();
    display_all_(root->get_left());
    display_all_(root->get_right());
    

}

int BST::hash_value(char * ing)
{
    int value = 0;
    for(int i = 0; i<strlen(ing); i++)
        value = (value+(int)ing[i] * 17);
    value = value % 3;
    return value;

}

