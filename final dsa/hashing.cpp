#include<iostream>
using namespace std;
class node{
string name;
long num;
public :
node(){
    name="None";
    num=0;
}
node(string n,long no){
    name=n;
    num=no;
}
friend class hashtable1;
friend class hashtable2;
};
class hashtable1{
    node *n;
    public :
     int a;
     void display(){
         for(int i=0;i<8;i++){
             cout<<n[i].name<<"\t"<<n[i].num<<endl;
         }
     }
    void create(){
        cout<<"total no. of records are :";
        cin>>a;
        n=new node[a];
        cout<<"hashtable created succesfully\n";

    }
    int hashfum(string s){
        return (s[0]%a);
    }
    void insert(string s,long no){
        int index=hashfum(s);
        for(int i=0;i<a;i++){
            if(n[(index+i)%8].name=="None"){
                n[(index+i)%8].name=s;
                n[(index+i)%8].num=no;
                 cout<<"data inserted\n";
                return;
            } 
        }
       cout<<"hAshtablefull\n";
        return;

    }
    void search(string s){
        int index=hashfum(s);
        int count=0;
        for(int i=0;i<a;i++){
            count++;
            if(n[(index+i)%a].name==s){
                cout<<"key found with "<<count<<"comparisions"<<endl;
                return;
            }
    }}
};
class hashtable2{

   node *n;
    public :
     int a;
     void display2(){
         for(int i=0;i<8;i++){
             cout<<n[i].name<<"\t"<<n[i].num<<endl;
         }
     }
    void create2(){
        cout<<"total no. of records are :";
        cin>>a;
        n=new node[a];
        cout<<"hashtable created succesfully\n";

    }
    int hashfum2(string s){
        return (s[0]%a);
    }
    void insert2(string s,long no){
        int index=hashfum2(s);
        for(int i=0;i<a;i++){
            if(n[(index+i)%8].name=="None" || hashfum2(n[(index+i)%8].name)==index){
                n[(index+i)%8].name=s;
                n[(index+i)%8].num=no;
                 cout<<"data inserted\n";
                return;
            } 
            else{
                string nameu=n[index].name;
                long phone=n[index].num;
                n[index].name=s;
                n[index].num=no;
                insert2(nameu,phone);
            }
        }
       cout<<"hAshtablefull\n";
        return;

    }
    void search2(string s){
        int index=hashfum2(s);
        int count=0;
        for(int i=0;i<a;i++){
            count++;
            if(n[(index+i)%a].name==s){
                cout<<"key found with "<<count<<"comparisions"<<endl;
                return;
            }
    }}
};
int main(){
    string name;
    long ph;
    hashtable1 h;
    hashtable2 h2;
  h.create();
  h2.create2();
  h.display();
  h2.display2();
  int v=h.a;
  for(int i=0;i<8; i++){
    cout<<"enter name\n";
    cin>>name;
    cout<<"enter phone no.\n";
    cin>>ph;
    h.insert(name,ph);
    h2.insert2(name,ph);
  }
  
  cout<<"enter name to search \n";
    cin>>name;
    h.search(name);
    h2.search2(name);
    return 0;
}