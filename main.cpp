/*
 * Michael Cheng
 * CS 202 Homework 2, Dynamic Binding
 * Winter 2016
 * Main.cpp
 *
 * The purpose of this file is to call the manager class to test functions of loading ingredidnts
 * into the balanced binary search tree. After the insertion of each ingredidnts, it will also
 * insert an object list of menu item per that node. 
 *
 * After all the files have been loaded into the data structure, test function will go through the
 * data structure and display out the function that has been tested and the result after the test.
 */


#include"manager.h"
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    manager handle;
    handle.load_menu();
}
