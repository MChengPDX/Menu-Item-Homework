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

BSTnode::BSTnode():left(NULL),right(NULL)
{

}

BSTnode::BSTnode(const ingre & obj):ingre(obj)
{

}

BSTnode::BSTnode(char * in, int h):ingre(in, h)
{

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

int BST::hashValue(char * ing)
{
<<<<<<< HEAD
    int precision = 1;
    return (*(int*)ing) >> precision; 

}

void BST::insert(entreeList * food, char * ing)
{
    insert_(root, food, ing);
}

void BST::insert_(BSTnode *& root, entreeList * food, char * ing)
{
    if(!root)
    {
        int hV = hashValue(ing);
        root = new BSTnode(ing, hV);
        root->getLeft() = NULL;
        root->getRight() = NULL;
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
=======
    int i = (int)strlen(ing);
    cout << "This is i " << i << endl;
    int k = 0;
    for(int j = 0; j < 1; j++)
    {
        k += ing[j];

    }
    return k/5;

}

void BST::insert(char * ing)

{
    BSTnode * temp = new BSTnode(ing);
    temp->getLeft() = NULL;
    temp->getRight() = NULL;
    if(!root)
    {
        root = temp;
        return ;
    }


}











>>>>>>> 06eeb304fad5c031d913811b3efba3c15545ff6c












