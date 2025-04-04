#ifndef TREES_H
#define TREES_H
typedef struct timestamp{
    int date;
    int month;
    int year;
    int hour;
    int minutes;
}TS;
typedef struct Transaction_Node{
    char* transaction_id;
    char* buyer_id;
    char* seller_id;
    float energy_bought;
    float price;
    TS time;
    int height;
    struct Transaction_Node* left;
    struct Transaction_Node* right;
}tr_node;

typedef struct Buyer_List_Node{
    char* buyer_id;
    double total_energy;
    tr_node* transaction_tree;
    int height;
    struct Buyer_List_Node* left;
    struct Buyer_List_Node* right;
}b_list_node;

typedef struct loyal_buyers_node{
    b_list_node* buyer;
    struct loyal_buyers_node* next;
}loyal_buyers;

typedef struct Seller_List_Node{
    char* seller_id;
    double total_energy;
    tr_node* transaction_tree;
    loyal_buyers* buyers_list;
    int height;
    struct Seller_List_Node* left;
    struct Seller_List_Node* right;
}s_list_node;

typedef struct buyer_seller_node{
    char* buyer_id;
    char* seller_id;
    int no_of_transactions;
    int height;
    struct buyer_seller_node* left;
    struct buyer_seller_node* right;
}bs_node;

int getHeight(tr_node* root);

int getBalance(tr_node* root);

tr_node* rightRotate(tr_node* y);

tr_node* leftRotate(tr_node* x);

tr_node* insertTransaction(tr_node* root, char* transaction_id, char* buyer_id, char* seller_id, float energy_bought, float price);

b_list_node* insertBuyer(b_list_node* root, char* buyer_id, double total_energy, tr_node* transaction_tree);

s_list_node* insertSeller(s_list_node* root, char* seller_id, double total_energy, tr_node* transaction_tree, loyal_buyers* buyers_list);



#endif