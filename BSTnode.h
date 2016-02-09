#include"LLLnode.h"

class ingre
{
    private:
        char * ing;
        int hashV;
    public:
        ingre();
        ingre(const ingre &);
        ingre(const char * i, int h);
        ~ingre();
        void display();


};

class BSTnode : public ingre
{
    private:
        menu_list * food;
        BSTnode * left;
        BSTnode * right;


    public:
        BSTnode();
        BSTnode(const ingre & );
        BSTnode(char * in, int h);
        ~BSTnode();
        BSTnode *& getLeft();
        BSTnode *& getRight();

        void display();

};

class BST
{
    private:
        BSTnode * root;
        void insert_(BSTnode *& root, menu_list * food,  char * ing);
        void display_(BSTnode * root);
        int hashValue(char * ing);
    
    public:
        BST();
        ~BST();
        void insert(menu_list * food, char * ing);
        void display();
        
        void insert(char * ing);

};
