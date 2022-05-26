#include <iostream>
#include <fstream>
using namespace std;
class student
{
	int roll;
	char name[10];

public:
	void getdata()
	{
		cout << "enter name and roll no.\n";
		cin >> name >> roll;
	}
	void putdata()
	{
		cout << name << "\t" << roll << endl;
	}
	friend class file;
};
class file
{
public:
	void create()
	{
		fstream f;
		char ans;
		f.open("stud.dat", ios::out);
		do
		{
			student s;

			s.getdata();
			f.write((char *)&s, sizeof(s));
			cout << "do you want to add more(Y Or y)\n";
			cin >> ans;

		} while (ans == 'Y' || ans == 'y');
		f.close();
	}
	void append(){
		fstream f;
		char ans;
		f.open("stud.dat", ios::app);
		do
		{
			student s;

			s.getdata();
			f.write((char *)&s, sizeof(s));
			cout << "do you want to add more(Y Or y)\n";
			cin >> ans;

		} while (ans == 'Y' || ans == 'y');
		f.close();
	}
	void read(){
		fstream f;
		f.open("stud.dat",ios::in);
		while(!f.eof()){
			student s;
			f.read((char *)&s, sizeof(s));
			if(!f.eof()){
				s.putdata();
			}
		}
		f.close();
	}
	void search(){
		fstream f;
		student s;
		int a,flag=0;
		cout<<"enter the roll no to be search :";
		cin>>a;
		f.open("stud.data" ,ios ::in);
		while(!f.eof()){
			
			f.read((char *)&s,sizeof(s));
			if(!f.eof() && s.roll==a){
				cout<<"key found \n";
				cout<<s.name<<"\t"<<s.roll<<"\t";
				// s.putdata();
				flag=1;
				break;

				
			}
		}
		f.close();
		if(flag==0){
			cout<<"key not found \n";
		}
	}

};
int main()
{
	file f1;
	f1.create();
	cout<<"append data\n";
	// f1.append();
	f1.read();
	f1.search();
	return 0;
}
