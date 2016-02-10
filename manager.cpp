#include "manager.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void manager::load_menu()
{
    menu_object = new menu_list;
    int size = 10;

    char type[size], menu_item[size];

    ifstream load;
    load.open("me.txt");
    if(load)
    {
        while(!load.eof())
        {
            load.getline(type, size, '\n');
            load.getline(menu_item, size, '\n');
            load.ignore(size, '\n');

            int t = (int)*type;
            menu_object->insert(t, menu_item);
            menu_object->display_all();

        }
        
    }
    load.close();
    return;

}

