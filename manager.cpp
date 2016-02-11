#include "manager.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

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
            else if(*type == 'b')
                menu_object->insert(1, menu_item);
            else
                menu_object->insert(2, menu_item);
         
            
        }
        test_tree(menu_object);
    }
    load.close();
    
    
    /*
    load.open("in.txt");
    if(load)
    {
        while(!load.eof())
        {
            load.get(ingre, size, '\n');
            load.ignore(size+1, '\n');
            load.ignore(size+1, '\n');
            int compare = balance_tree.hash_value(ingre);
            balance_tree.insert(ingre, compare, menu_object);
        }
        
    }
    load.close();
    return;
*/
}
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
            cout << "This is hash_value" << z <<  endl;
            balance_tree.insert(ing, z, menu_object);            
        }
    }
    balance_tree.display_all();
    
}

