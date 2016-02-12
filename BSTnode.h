/*
 * Michael Cheng
 * CS 202 Homework 2
 * Winter 2106
 *
 * BSTnode.h
 *
 * Holds prototypes and classes per BSTnode.cpp
 * A node is dervied from class ingredidnts
 * A BST has nodes of class ingredidnets
 * Within each node, there is a pointer to menu_list, which
 * is a list with a head pointer, pointing to the linear linked list.
 *
 */


#include"LLLnode.h"


//class ingredidents
class in
{
    private:
        int compare_value;
        char * ingredidents;

    public:
        in();
        in(char * ing, int cv);
        in(const in &);
        bool compare(int value);
        char * get_ingredidents();
        void display();

};


//class BSTnode, dervied from ingredidents. Every node is a ingredident
//Each node also has a pointer to a list of menu items that uses this ingredident
class bst_node:public in
{
    private:
        bst_node * left;
        bst_node * right;
        menu_list * alist;

    public:
        bst_node();

        bst_node(char * ing, int compare_value, menu_list *lll);
        bst_node(const bst_node &);
        bst_node *& get_left();
        bst_node *& get_right();
        void display_node();
        void display_lll();

};


//class BST, a BST has BST nodes
//to ensure a balance tree is implemented, each item will be inserted 
//into the bst through a hash value, this value wil always insure that
//the balance factor will never differ more than 1
class BST
{
    private:
        bst_node * root;
        int search_(char * ing, bst_node * root);
        int insert_(char * ing, int compare_value, menu_list * alist, bst_node *& root);
        int display_all_(bst_node * root);
        int remove_all_(bst_node * &root);

    public:
        BST();
        ~BST();
        int insert(char * ing, int compare_value, menu_list * alist);
        int search(char * ing);
        int hash_value(char * ing);
        int display_all();
        void remove_all();
    
};
