//Problem Statement:- 
/*Beginning with an empty binary tree, Construct binary tree by inserting the values in the
 order given. After constructing a binary tree perform following operations on it- Perform
 inorder / preorder and post order traversal,Change a tree so that the roles of the left and 
 right pointers are swapped at every node, Find the height of tree,Copy this tree to another 
 [operator=], Count number of leaves, number of internal nodes. Erase all nodes in a binary tree. 
 (implement both recursive and non-recursive methods) */
#include<iostream>
using namespace std;
class node{
int data;
node *l;
node *r;
public:
node(){
    data=0;
    l=nullptr;
    r=nullptr;
}
node(int data){
    this->data=data;
    l=nullptr;
    r=nullptr;
}
friend class stack;
friend class bt;
};
class stack{
    node *s[50];
    int top;
    public:
    stack(){
        top=-1;
    }
    bool isempty(){
        if (top==-1){
            return true;
        }
        return false;
    }
    bool isfull(){
        if (top==49){
            return true;
        }
         return false;
    }
    void push(node *t){
        if(!isfull()){
            top++;
            s[top]=t;
        }
        else{
            cout<<"stack is full!!"<<endl;
        }
    }
    node *pop(){
        if(!isempty()){
            node *n=s[top];
            top--;
            return n;
        }
       return nullptr;
    }
    friend class bt;
};
class bt{
    node *root;
    stack s;
    public:
    bt(){
        root=nullptr;
    }
    void create();
    void insert(node *t,node *n);
    node* setroot();
    void inorder(node *t);
    void preorder(node *t);
    void postorder(node *t);
    void inorder_r(node *t);
    void preorder_r(node* t);
    void postorder_r(node *t);
    int heighttree(node *t);
    void operator =(bt &t);
    node *copytree(node *t);
    int internalnodes(node *t);
    int leafnodes(node *t);
    void deletetree(node *t);
};
int bt::leafnodes(node *t){
    int counter=0;
    if(t->l==nullptr && t->r==nullptr){
        counter++;
    }
    if(t->l!=nullptr){
    leafnodes(t->l);}
    if(t->r!=nullptr){
    leafnodes(t->r);}
    return counter;
}
void bt ::deletetree(node *t){
    deletetree(t->l);
    deletetree(t->r);
    delete t;
}
int bt::internalnodes(node *t){
    int count=0;
    if(t->l!=nullptr || t->r!=nullptr){
        count++;
    }
    if(t->l!=nullptr){
    internalnodes(t->l);}
    if(t->r!=nullptr){
    internalnodes(t->r);}
    return count;

}
void bt:: operator= (bt &t){
    node *rot=copytree(t.root);
}
node * bt:: copytree(node *t){
    node *rot;
    if(t==nullptr){
        return nullptr;
    }
    else{
        rot=new node();
        rot->data=t->data;
        rot->l=copytree(t->l);
        rot->r=copytree(t->r);

    }
    return rot;
}
int bt::heighttree(node *t){
    int lheight,rheight;
    if(root==nullptr){
        return 0;
    }
    else if(t->l==nullptr && t->r==nullptr){
        return 1;
    }
    else{
        lheight=heighttree(t->l);
        rheight=heighttree(t->r);
        if(lheight>rheight){
            return lheight+1;
        }
        return rheight+1;
    }

}
void bt::create(){
    int a;
    cout<<"enter the data you want to enter :"<<endl;
    cin>>a;
    cout<<endl;
    node *n=new node(a);
    if (root==nullptr){
        root=n;

    }
    else{
        insert(root,n);
    }
}
void bt::insert(node *t,node *n){
    cout<<"where you want to insert the node  of "<<t->data<<endl;
    char c;
    cin>>c;
    if(c=='R'||c=='r'){
        if(t->r==nullptr){
            t->r=n;
        }
        else{
            insert(t->r,n);
        }
    }
    else{
        if(t->l==nullptr){
            t->l=n;
        }
        else{
            insert(t->l,n);
        }
    }
}
void bt::inorder(node *t){
   
    if(t!=nullptr){
        inorder(t->l);
        cout<<t->data<<" ";
        inorder(t->r);
    }
   
}
void bt::preorder(node *t){
   
    if(t!=nullptr){
        cout<<t->data<<" ";
        preorder(t->l);
        preorder(t->r);
    }
    
}
void bt::postorder(node *t){
    
    if(t!=nullptr){
        postorder(t->l);
        postorder(t->r);
        cout<<t->data<<" ";
    }
    
}
void bt::inorder_r(node *t){
    stack s;
    while(t!=nullptr){
        s.push(t);
        t=t->l;
    }
    while(!s.isempty()){
        node *t=s.pop();
        cout<<t->data<<" ";
        t=t->r;
        while(t!=nullptr){
        s.push(t);
        t=t->l;
    }

    }
}
void bt::preorder_r(node *t){
    stack s;
    s.push(t);
    while(!s.isempty()){
        t=s.pop();
        cout<<t->data<<" ";
        if(t->r!=nullptr){
            s.push(t->r);
        }
        if(t->l!=nullptr){
            s.push(t->l);
        }
    }
}
void bt::postorder_r(node *t){
    stack a,b;
    a.push(t);
    while(!a.isempty()){
        t=a.pop();
        b.push(t);
        if(t->l!=nullptr){
            a.push(t->l);
        }
        if(t->r!=nullptr){
            a.push(t->r);
        }
    }
    while(!b.isempty()){
        t=b.pop();
        cout<<t->data<<" ";

    }
}

node * bt::setroot(){
    node *n =root;
    return n;
}
int main(){
    bt t;
    int ch;
    node *p;
    while(true){
    cout<<"----------------MAIN MENU-----------------------\n 1. create \n2. traversal \n 3.height of tree \n 4. copy tree \n 5.internal nodes \n 6.leafnodes \n 7. ddeletetree\n 8. exit\n";
    cin>>ch;
    switch(ch){
        case 1:
        {
        int n;
        cout<<"enter total no. of nodes ";
        cin>>n;
        for(int i=0;i<n;i++){
            t.create();
        }
        break;
        }

        case 2:
        {   p=t.setroot();
         cout<<"preorder traversal is "<<endl;
            t.preorder(p);
             cout<<endl;
             cout<<"post order traversal is "<<endl;
            t.postorder(p);
            cout<<endl;
             cout<<"inorder traversal is "<<endl;
            t.inorder(p);
            cout<<endl;
            cout<<"inorder recursive "<<endl;
            t.inorder_r(p);
            cout<<endl;
            cout<<"preorder recursive traversal is "<<endl;
            t.preorder_r(p);
             cout<<endl;
              cout<<"post order  recursive traversal is "<<endl;
            t.postorder_r(p);
            cout<<endl;

        break;
        }
        case 3:
        {
            p=t.setroot();
            int a=t.heighttree(p);
            cout<<"height of tree is "<<a <<endl;
            break;
        }
        case 4:
        {
            p=t.setroot();
            cout<<"orignal addressx of tree is"<<endl;
            cout<<p;
            cout<<endl;
            t.inorder(p);
            // node *q=p;
            node *q=t.copytree(p);
            cout<<"new addressx of tree is"<<endl;
            cout<<q;
            cout<<endl;
            t.inorder(q);
            break;

        }
        case 5:
        p=t.setroot();
        int count;
        count =t.internalnodes(p);
         cout<<"no . of internal nodes are "<<count;
         break;
         case 6:{
             p=t.setroot();
             int counter;
             counter=t.leafnodes(p);
             cout<<"keaf nodes are "<<counter<<endl;
            break;
         }
         case 7:{
              p=t.setroot();
             t.deletetree(p);
             cout<<"deleted tree"<<endl;
             t.heighttree(p);
             break;
         }
        case 8:

        {   exit(0);
            break;
        }
    }
    }
    return 0;
}
