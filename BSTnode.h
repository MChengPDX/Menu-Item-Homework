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
        entreeList * food;
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
        void insert_(BSTnode *& root, entreeList * food,  char * ing);
        void display_(BSTnode * root);
        int hashValue(char * ing);
    
    public:
        BST();
        ~BST();
<<<<<<< HEAD
        void insert(entreeList * food, char * ing);
        void display();
        
};
=======
        int hashVlue(char * ing);
        void insert(char * ing)

}
>>>>>>> 06eeb304fad5c031d913811b3efba3c15545ff6c
