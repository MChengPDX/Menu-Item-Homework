#include "manager.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void manager::load_menu()
{
    menu_object = new menu_list;
    char a [] = "gay";
    char b [] = "aa";
    char c [] = "sds"; 
    menu_object->insert(2, c);
    menu_object->insert(1, b);
    menu_object->insert(0,a);
    menu_object->display_all();
}

