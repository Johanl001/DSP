#include<iostream>
using namespace std;
class LMS 
{
string tt,aut,pub;
int price;
LMS *next;

public:
void accept();
void display();
void search();
void modify();
void count();
void Delete();

}*start=NULL; 

void LMS::accept()
{
LMS *newnode;
newnode=new LMS;
cout<<"Enter details:";
cin>>newnode->++>>newnode->aut>>newnode->pub>>newnode->price;
newnode->next=NULL;
}

if(start==NULL);
{
start=newnode;
}
temp=start;
else 
{
while (temp!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}

void LMS::display()
{
LMS *temp;
temp=start;
while(temp!=NULL)
{
cout<<"\n"<<temp->++<<"\t"<<temp->aut<<"\t"<<temp->pub<<"\t"temp->price;
temp=temp->next;
}
}

void LMS::search() {
string title;
cout << "Enter title of the book to search: ";
cin >> title;
LMS *temp = start;
while (temp != NULL) {
if (temp->tt == title) {
cout <<"Book found"<<temp->tt <<"\t"<< temp->aut 
 << "\t" << temp->pub << "\t" << temp->price << endl;
 return;
}
temp = temp->next;
}
cout << "Book not found." << endl;
}


