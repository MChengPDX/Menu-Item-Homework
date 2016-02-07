
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
        virtual void display_content();
};

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

};

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

};

class apps : public entree_information
{
    public:
        apps();
        apps(const apps &);
        apps(char * menu_item);
        void display();
        entree_information * copy();

};

class entrees : public entree_information
{
    public:
        entrees();
        entrees(const entrees &);
        entrees(char * menu_item);
        void display();
        entree_information * copy();

};

class drinks : public entree_information
{
    public:
        drinks();
        drinks(const drinks &);
        drinks(char * menu_item);
        void display();
        entree_information * copy();


};

