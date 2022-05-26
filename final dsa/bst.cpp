#include<iostream>
#include<string>
#include<cctype>

using namespace std;
class node{
     public:
 string word,meaning;
 node *left,*right;

 node(){
     word=meaning=" ";
     left=right=nullptr;
 }
 node(string w,string m){
     word=w;
     meaning =m;
     left=right=nullptr;
 }
 friend class bst;

};
class bst{
    public:
node *root,*p;
bst(){
    root=nullptr;
    p=nullptr;
}
void insert(node *p,string w,string m);
void disasc(node *p);
void disdes(node *p);
void updatemeaning(node *p, string w,string m);
void comp(node *p, string w);
node *finmin(node *curr);
void delw(node *p ,string w);
node *setroot(){
    node *p=root;
    return p;
}

};
void bst:: delw(node *p,string w){
    node *q;
    while(p!=nullptr){
    if(p->word<w){
        q=p;
        p=p->right;
    }
    else if(p->word>w){
        q=p;
        p=p->left;
    }
    else if(p->word==w){
        if( p->left==nullptr && p->right==nullptr){
            if(q->left == p ){
                q->left==nullptr;
                delete(p);
                cout<<"deleted succesfully "<<endl;
                return;
            }
            else if(q->right==p){
                q->right==nullptr;
                delete(p);
                cout<<"deleted succesfully "<<endl;
                return ;
            }
        }
        else if(p->left!=nullptr && p->right==nullptr)
        {
            if(q->left==p){
                q->left=p->left;
                delete(p);
                cout<<"deleted succesfully "<<endl;

            }
            else if(q->right==p){
                q->right=p->left;
                 delete(p);
                cout<<"deleted succesfully "<<endl;
            }
        }
        else if(p->right!=nullptr && p->left==nullptr){
            if(q->left==p){
                q->left=p->right;
                delete(p);
                cout<<"deleted succesfully "<<endl;

            }
            else if(q->right==p){
                q->right=p->right;
                 delete(p);
                cout<<"deleted succesfully "<<endl;
            }
        }
        else if(p->right!=nullptr && p->left !=nullptr){
            node *succ=finmin(p->right);
            string val=succ->word;
            string mean=succ->meaning;
            delw(root,succ->word);
            p->word=val;
            p->meaning=mean;
            cout<<"deleted succesfully"<<endl;
        }
    }
}}
node * bst::finmin(node *curr){
    while(curr->left!=nullptr){
        curr=curr->left;
    }
    return curr;
}
void bst ::comp(node *p, string w){
    int count=0;
    while(p!=nullptr){
         if(p->word<w){
        p=p->right;
        count++;
    }
    else if(p->word >w){
        p=p->left;
        count++;
    }
    else if(p->word==w){
        count++;
        cout<<w<< "no. of comparision : "<<count<<"\n";
        return;
    }
   
    }
}
void bst :: updatemeaning(node *p ,string w,string m){
    while(p!=nullptr){
    if(p->word<w){
        p=p->right;
    }
    else if(p->word >w){
        p=p->left;
    }
    else if(p->word==w){
        p->meaning=m;
        cout<<w<< "meaning updated\n";
        return;
    }
    else{
        cout<<"key not present\n";
    }
    }
}
void bst:: disdes(node *p){
    if(p->right!=nullptr)
        disdes(p->right);
        cout<<p->word<<"\t"<<p->meaning<<endl;
     if(p->left!=nullptr)
        disdes(p->left);
    
}
void bst:: disasc(node *p){
    if(p->left!=nullptr)
        disasc(p->left);
        cout<<p->word<<"\t"<<p->meaning<<endl;
    if(p->right!=nullptr)
        disasc(p->right);

    }

void bst::insert(node *p,string w,string m){
    node *n=new node(w,m);
    if(p->word<w){
        if(p->right==nullptr){
            p->right=n;
        }
        else{
            insert(p->right,w,m);
        }
    }
    else if(p->word>w){
        if(p->left==nullptr){
            p->left=n;
        }
        else{
            insert(p->left,w,m);
        }
    }
    else{
        cout<<"key already inserted "<<endl;
    }
}
int main(){
    bst t;
 
    string Word,Mean,UPMean;
    while(true){
    int ch;
    cout<<"---------------main menu------------------\n1. insert\n2. update \n3. display asc \n4. display desc \n5.count comp\n6.delete word \n7.exit\n enter choice : ";
    cin>>ch;
    switch(ch){
        case 1:{
          
            int a;
            cout<<"enter total no of word you eant to enter :"<<endl;
            cin>>a;
            for(int i=0;i<a;i++){
                cout<<"enter word "<<endl;
                cin>>Word;
                    Word[0]=toupper(Word[0]);
                    for(int i=1;i<Word.length();i++){
                        Word[i]=tolower(Word[i]);
                    }
                cout<<endl;
                cout<<"enter meaning "<<endl;
                cin>>Mean;
                cout<<endl;
                    Mean[0]=toupper(Mean[0]);
                    for(int i=1;i<Mean.length();i++){
                        Mean[i]=tolower(Mean[i]);
                    }
                if(t.root==nullptr){
                    t.root=new node(Word,Mean);
                }
                else{
                    t.insert(t.root,Word,Mean);
                }
            }
break;

        }
    case 2:
    {
         cout<<"enter word "<<endl;
                cin>>Word;
                    Word[0]=toupper(Word[0]);
                    for(int i=1;i<Word.length();i++){
                        Word[i]=tolower(Word[i]);
                    }
                cout<<endl;
                cout<<"enter new  meaning "<<endl;
                cin>>Mean;
                cout<<endl;
                    Mean[0]=toupper(Mean[0]);
                    for(int i=1;i<Mean.length();i++){
                        Mean[i]=tolower(Mean[i]);
                    }

        t.updatemeaning(t.root,Word,Mean);
        break;
    }
    case 3:
     cout<<"******************dispplay in ascending order ***********************"<<endl;
     t.disasc(t.root);
     break;
     case 4:{
         cout<<"******************dispplay in descending order ***********************"<<endl;
     t.disdes(t.root);
     break; 
     }
    case 5:
    {
         cout<<"enter word "<<endl;
                cin>>Word;
                    Word[0]=toupper(Word[0]);
                    for(int i=1;i<Word.length();i++){
                        Word[i]=tolower(Word[i]);
                    }
                cout<<endl;
        t.comp(t.root,Word);
        break;
    }
    case 6:
    {
          cout<<"enter word "<<endl;
                cin>>Word;
                    Word[0]=toupper(Word[0]);
                    for(int i=1;i<Word.length();i++){
                        Word[i]=tolower(Word[i]);
                    }
                cout<<endl;
                t.delw(t.root,Word);
    }
    case 7:
    {
        exit(0);
        break;
    }

    }}
    return 0;
}