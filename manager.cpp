#include "manager.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

/*
 * void load_menu()
 *
 * Load menu items per an ingredident
 * Creates an object type of that ingredident 
 * then insert it into the linear linked list.
 * Thus, this linear linked list will be a list of
 * different object type.
 * This object is then pass into test_tree to insert 
 * to the node, thus making the tree a binary search tree
 * of linear linked list.
 *
 */

void manager::load_menu()
{
    menu_object = new menu_list;
    int size = 30;

    char type[size], menu_item[size], ingre[size];

   ifstream load;
   load.open("me.txt");
    if(load)
    {
        while(!load.eof())
        {
            load.get(type, size, '\n');
            load.ignore(size+1, '\n');
            load.get(menu_item, size, '\n');
            load.ignore(size+1, '\n');

            if(*type == 'a')
                menu_object->insert(0, menu_item);
            if(*type == 'b')
                menu_object->insert(1, menu_item);
            if(*type == 'c')
                menu_object->insert(2, menu_item);
         
            
        }
        test_tree(menu_object);
        test_lll(menu_object);
    }
    load.close();
}

/*
 * void test_lll(menu_list * menu_object)
 * Test functions within the Linear Linked list
 * Display one/Search tested/works
 * display all tested/works
 * remove at front, middle and end tested/works
 * load and insert tested/works
 */

void manager::test_lll(menu_list * menu_object)
{
    cout <<"Testing function on this Linear Linked list " << endl;
    menu_object->display_all();
    cout << "Searching for item : Beef Juice " << endl;
    char b [] = "Beef Juice";
    char c [] = "Beef Pho Smoothie";
    menu_object->search_one(b);
    menu_object->remove_one(b);
    cout << "Displaying after removing : " << b << endl;
    menu_object->display_all();
    cout << "Display after removing : " << c << endl;
    menu_object->remove_one(c);
    menu_object->display_all();
    menu_object->remove_all();
    cout << "Displaying after removing all" << endl;
    menu_object->display_all();
}

/*
 * void test_tree(menu_lust * menu_object)
 *
 * Takes an objuect of menu_list, which is the linear linked
 * list of different objects of menu items. Insert this into
 * the bst node along with the ingredident per that node.
 *
 * BST node will be inserted based on a hash value. doing this
 * will always keep the tree balance, thus the balance factor 
 * Should never be more than 1.
 *
 * Functions to test witin the BST:
 * Display All Tested/Works
 * Retrieve a node Tested/Works
 * Insert - Tested/Works
 * Remove all - Tested/Works
 *
 */


void manager::test_tree(menu_list * menu_object)
{
    int size = 100;
    int z = 0;
    char ing[size];
    cout << "Display from test_tree" << endl;
    menu_object->display_all();
    ifstream load;
    load.open("in.txt");
    if(load)
    {
        while(!load.eof())
        {
            load.get(ing, size, '\n');
            load.ignore(size, '\n');
            load.ignore(size, '\n');
            z = balance_tree.hash_value(ing);
            balance_tree.insert(ing, z, menu_object);            
        }
    }
    balance_tree.display_all();
    
    cout <<"Test retieve function of BST" << endl;
    cout << "Searching for salt " << endl;
    char a[] ="salt";
    balance_tree.search(a);
    
    cout <<"Testing remove all function of BST" << endl;
    balance_tree.remove_all();
    int check = balance_tree.display_all();
    if(check == 0)
        cout << "No more ingredidents left " << endl;
 
}

