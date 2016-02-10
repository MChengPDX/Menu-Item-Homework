#include "manager.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void manager::load_menu()
{
    menu_object = new menu_list;
    int size = 30;

    char type[size], menu_item[size];

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
    menu_object->display_all();
    return;

}

