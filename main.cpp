#include "BSTnode.h"
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    BST ab;
    entreeList obj;
    char a[]= "helo";
    char b[]= "gay";
    obj.insert(a);
    obj.insert(b);
    obj.display();
    ab.insert(a);
    ab.display();

}
