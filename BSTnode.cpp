#include"BSTnode.h"
#include<iostream>
#include<cstring>
using namespace std;

/*
 * ingre Implementation start
 *
 */

ingre::ingre():ing(NULL), hashV(0)
{

}


ingre::ingre(const ingre & object)
{
    ing = new char [(strlen(object.ing)+1)];
    strcpy(ing, object.ing);

    hashV = object.hashV;

}



ingre::ingre(const char * in, int h)
{
    ing = new char [(strlen(in)+1)];
    strcpy(ing, in);

    hashV = h;

}

ingre::~ingre()
{
    if(ing)
    {
        delete [] ing;
        ing = NULL;
    }

    hashV = 0;

}

void ingre::display()
{
    cout << ing << endl;

}

/*
 * ingre Implementation end
 *
 */

/*
 * BSTnode implementation starts
 *
 */

BSTnode::BSTnode():left(NULL),right(NULL),food(NULL);
{

}

BSTnode::BSTnode(const ingre & obj):ingre(obj)
{
    food = obj.food;

}

BSTnode::BSTnode(char * in, int h, menu_list * food_obj):ingre(in, h)
{
    food = food_obj;

}

BSTnode :: ~BSTnode()
{


}

BSTnode *& BSTnode::getLeft()
{
    return left;

}

BSTnode *& BSTnode::getRight()
{
    return right;
}

void BSTnode::display()
{
    ingre::display();


}

/*
 * BSTnode implementation end
 *
 */

/*
 * BST implementation start
 *
 */

BST::BST():root(NULL)
{

}
BST::~BST()
{

}



void BST::insert_(BSTnode *& root, menu_list * food, char * ing, int value)
{
    if(!root)
    {
        root = new BSTnode(ing, value, food);

    }

}


void BST::display()
{
    display_(root);

}

void BST::display_(BSTnode * root)
{
    if(!root)
        return;
    display_(root->getLeft());
    display_(root->getRight());
    root->display();


}
























