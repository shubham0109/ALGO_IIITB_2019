#include <iostream>
#include <ctime>
using namespace std;

struct node{
    int key;
    node* par;
    node *lc, *rc;
};

node* insertBST(node* root, node* parent, int num){
    if (root == NULL){
        node* newNode = new node();
        newNode->key = num;
        newNode->lc = NULL;
        newNode->rc = NULL;
        newNode->par = parent;
        root = newNode;
        
        return root;
    }
    
    if (num < root->key){
        root->lc = insertBST(root->lc, root, num);
    }else{
        root->rc = insertBST(root->rc, root, num);
    }
    
    return root;
}

void inorderTraversal(node* root){
    if (root == NULL){
        return;
    }
    
    inorderTraversal(root->lc);
    cout<<root->key<<" ";
    inorderTraversal(root->rc);
    
    return;
}

node* deleteNode(node* root, int del){
    node* delNode = NULL;
    node* temp = root;
    
    if (del < root->key){
        root->lc = deleteNode(root->lc, del);
        return root;
    }else if (del > root->key){
        root->rc = deleteNode(root->rc, del);
        return root;
    }else{
        // this is the node to delete
        if (root->lc == NULL){
            temp = root;
            root = root->rc;
            free(temp);
            return root;
        }
        
        if (root->rc == NULL){
            temp = root;
            root = root->lc;
            free(temp);
            return root;
        }
        
        // has 2 child
        temp = root->rc;
        while (temp->lc != NULL){
            temp = temp->lc;
        }
        
        root->key = temp->key;
        
        root->rc = deleteNode(root->rc, temp->key);
        return root;
    }
    
    return root;
}

int main(){
    srand(time(NULL));
    node* root = NULL;
    int n = 10;
    
    // INSERT A FEW NODES
    for (int i = 0; i < n; i++){
        int num = rand()%n;
        root = insertBST(root, NULL, num);
    }
    
    // INORDER TRAVERSAL
    cout<<"The inorder traversal of the BST is: ";
    inorderTraversal(root);
    cout<<endl;
    
    // DELETE A NODE
    int del = root->key;
    cout<<"To delete: "<<del<<endl;
    root = deleteNode(root, del);
    cout<<"The inorder traversal of the BST is: ";
    inorderTraversal(root);
    cout<<endl;
}
