#include<iostream>
using namespace std;
class node {
    int data;
    int lbit,rbit;
    node *left;
    node *right;
    public:
    node(){
        data=0;
        lbit=rbit=0;
        left=right=nullptr;
    }
    node(int data){
        this->data=data;
         lbit=rbit=0;
        left=right=nullptr;
    }
    friend class tbt;
};
class tbt{
    public:
    node *root;
    node *header;
    
    tbt(){
        root=nullptr;
        header=new node(999);
        header->lbit=header->rbit=1;
        header->left=header->right=header;
    }
    void insert(node *p,int data);
    void inorder(node *p);
    void preorder(node *p);
    
};
void tbt:: insert(node *p,int data){
        node *n=new node(data);
        if (root==nullptr){
            root=n;
            root->left=root->right=header;
            root->lbit=root->rbit=1;
            header->left=root;
            header->lbit=1;

        }
        else{
            if(data<p->data){
                if(p->lbit==1){
                    n->left=p->left;
                    n->lbit=n->rbit=1;
                    n->right=p;
                    p->left=n;
                    p->lbit=0;

                }
                else{
                    insert(p->left,data);
                
                }}
           
               else if(data>p->data){
                    if(p->rbit==1){
                        n->right=p->right;
                        n->left=p;
                        n->lbit=n->rbit=1;
                        p->right=n;
                        p->rbit=0;
                    }
                    else{
                        insert(p->right,data);
                    }
                }
            }
            }
void tbt::inorder(node *p){
    while(p->lbit==0)
        p=p->left;
    
    while(p!=header){
        cout<<p->data<<" ";
        if(p->rbit==0){
            p=p->right;
             while(p->lbit==0){
             p=p->left;
    }
        }
        else{
            p=p->right;
        }
    }
}
void tbt::preorder(node *p){
    while(p!=header){
        
        while(p->lbit==0){
            cout<<p->data<<" ";
            p=p->left;
        }
        
        cout<<p->data<<" ";
        while(p->rbit==1){
            p=p->right;
            if(p==header){
                return;
            }
        }
        p=p->right;
    }
}
    
int main(){
    tbt t;
    for(int i=0;i<6;i++){
        int n;
        cout<<"enter the data :"<<endl;
        cin>>n;
        t.insert(t.root,n);
        cout<<endl;
    }
    cout<<"inorder traversa; \n";
    t.inorder(t.root);
    cout<<"preorder traversal \n";
    t.preorder(t.root);
    return 0;
}