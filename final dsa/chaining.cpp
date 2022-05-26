#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class  node{
    string word;
    string mean;
    node *link;
    public:
    node(){
        word=" ";
        mean=" ";
        link=nullptr;
    }
    node(string word,string mean){
        this->word=word;
        this->mean=mean;
        link=nullptr;
    }
    friend class dictionary;
};
class dictionary{
    public:
node n[100];
void insert(string w,string m);
void search(string w);
void deletew(string w);
int hashfum(string w);
};
int dictionary::hashfum(const string w){
    return (w[0]-'0')%100;
}
void dictionary::insert(string w,string m){
    int index=hashfum(w);
    if(n[index].word==" "){
        n[index].word=w;
        n[index].mean=m;

    }
    
    else {
        node *ptr=new node(w,m);
            if(n[index].link==nullptr){
            n[index].link=ptr;

        }
        else{
            node *temp=n[index].link;
            while(temp->link!=nullptr){
                temp=temp->link;
            }
            temp->link=ptr;
        }
    }
}
void dictionary::search(string w){
    int count=0;
    int flag=0;
    int index=hashfum(w);
    if(n[index].word==w){
        count++;
        cout<<"key found in "<<count<<"comp \n";
        cout<<w<<"\t"<<n[index].mean<<endl;
        flag=1;
    }
    else{
        node *temp=n[index].link;
        if(!temp){
            cout<<"key  not found \n";

        }
        else{
            while(temp!=nullptr){
                count++;
                if(temp->word==w){
                    cout<<"key found in "<<count<<"comp \n";
        cout<<w<<"\t"<<n[index].mean<<endl;
        flag=1;
                }
                temp=temp->link;
            }
        }
    }
    if(flag==0){
        cout<<"key  not found \n";
        return;
    }
}
int main(){
    dictionary d;
    string w,m;
    for(int i=0; i<3;i++){
        cout<<"enter word\n";
        cin>>w;
        cout<<"enter mean\n";
        cin>>m;
        d.insert(w,m);
    }
 cout<<"enter word\n";
        cin>>w;
        d.search(w);

    return 0;
}
