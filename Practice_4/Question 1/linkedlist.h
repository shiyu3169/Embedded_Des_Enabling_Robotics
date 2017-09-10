using namespace std;
class Node {
private:
    int data;
    Node* next;
public:
    Node(){ }
    ~Node(){destroy_list(); }
    void operation_select();         //operation selection 
    int display();                   //show the linked list
    Node *insert_at_head(int data);  //insert the given data at the begining of the list 
    Node *insert_at_tail(int data);  //insert the given data at the end of the list
    Node *delete_at_head();          //delete the node at the head of the list
    Node *delete_at_tail();          //delete the node at the end of the list
    Node *delete_with_val(int val);  //find the given val and delete it from the list
    void find_element(int val);      //find the given val
    void  count_element();           //count the length if the list
    Node *destroy_list();            //delete the entire list
};