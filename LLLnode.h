/*
 * Michael Cheng
 * CS 202 Homework 2
 * Winter 2106
 *
 * LLLnode.h
 *
 * Holds class templates and prototypes for LLLnode.cpp
 * This will be a list of different object types, determine
 * at run time through dynamic binding
 */


//class entree information
//an abstract base class wth dynamic memory to hold
//menu item information
//Also ha a virutal pure fuction of copy, which returns a type of entree_information
class entree_information
{
    protected:
        char * menu_item;
        virtual ~entree_information();

    public:
        entree_information();
        entree_information(char * menu_item);
        entree_information(const entree_information & from);
        virtual entree_information * copy() = 0;
        virtual void display();
        char * get_menu();
};


//class node
//has an pointer object to entree_information
class node
{
    protected:
        entree_information * data;
        node * next;
    public:
        node();
        node(int type, char * menu_item);
        node(const node & from);
        node *& get_next();
        void set_next(node * head);
        void display_node();
        void set_menu_item(int type, char * in);
        char * get_info();

};


//class menu_list
//base class for each menu type to be dervied from
class menu_list
{
    protected:
        node * head;

    public:
        menu_list();
        ~menu_list();
        void insert(int type, char * ing);
        void remove_all();
        void display_all();
        void remove_one(char * ing);
        void search_one(char * ing);

};


//class apps
//derveid from menu list
class apps : public entree_information
{
    public:
        apps();
        apps(const apps &);
        apps(char * menu_item);
        void display();
        entree_information * copy();

};


//class entrees dervied from menu list
class entrees : public entree_information
{
    public:
        entrees();
        entrees(const entrees &);
        entrees(char * menu_item);
        void display();
        entree_information * copy();

};


//class drinks dervied from menu list
class drinks : public entree_information
{
    public:
        drinks();
        drinks(const drinks &);
        drinks(char * menu_item);
        void display();
        entree_information * copy();


};

