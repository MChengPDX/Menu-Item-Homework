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
            if(*type == 'b')
                menu_object->insert(1, menu_item);
            if(*type == 'c')
                menu_object->insert(2, menu_item);

        }
        
    }
    load.close();
    
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
            balance_tree.display_all();
            return;
        }
    }
    load.close();
    return;

}

