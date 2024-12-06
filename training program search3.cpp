#include<iostream>
using namespace std;
int i, n;
class student
{
public:
int rno;
string name, add;
int Q1, Q2, Q3, Q4, Q5;
void accept();
void display();
void Lsearch();
void Bsearch();
}a[100];

void student::accept()
{
cout<<"\nEnter the student name ,address , rollno: ";
cin>>name>>add>>rno;	
}

void student::display()
{
cout << "\n" << name << "\t" << rno << "\t" << add ;
}
void student::Lsearch() 
{
int r;
bool found = 0;
cout << "Enter the roll no. you want to search:";
cin >> r;
for (i = 0; i < n; i++) 
{
 if (a[i].rno == r) 
{ 
found = 1;
cout << "\nRoll No. " << r << " was present in training program.";
break;
}
}
if (!found) 
{
cout << "\nRoll No. " << r << "  not present in training program. ";;
}
}
void student::Bsearch()
{
int r;
cout << "Enter  roll no. you want to search: ";
cin >> r;    	
for(i = 0; i < n-1; i++)
{
for(int j = 0; j < n; j++)
{
if(a[i].rno > a[j].rno)
{
student temp = a[j];
a[j] = a[i];
a[i] = temp;
}
}
}   	
    	int mid, low = 0, high = n-1;
    	bool found = 0;
    	while(low <= high)
    	{
    	   mid = (low+high) / 2;
    	   
    	   if(a[mid].rno == r)
    	   {
    	     found = 1;
    	     cout <<"\nRoll No. " << r << " is present in training program.";
    	     
    	     break;
    	   }
    	   
    	   else if(a[mid].rno > r)
    	   {
    	    high = mid-1;
    	   }
    	   
    	   else
    	   {
    	    low = mid+1;
    	   }
    	 }
    	 
    	 if(!found)
    	 {
    	  cout << "\nRoll No. " << r << " is not present in training program. ";;
    	 }  	 
    	 void student::Feedback accept()
    	 cout<<"Was the session helpful to you?";
    	 cout<<"1. Good\n2. Satisfactory\n 3 
 }

int main()
{
    int ch=0;
    while(true)
    {
    cout << "\nMenu.\n1.Accept student record.\n2.Display record.\n3.Find rollno. (Linear Search).\n4.Find rollno.  (Binary Search).";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch)
        {
        case 1:
            cout << "Enter the number of records you want to create: ";
            cin >> n;
            for(i = 0; i < n; i++)
            {
               a[i].accept();
            }
            break;
        case 2:
            cout << "\nName\tRollNo\tAddress";
            for(i = 0; i < n; i++)
            {
                a[i].display();
            }
            break;
            
        case 3:
        	a[0].Lsearch();
        	break;
        	
        case 4:
        	a[i].Bsearch();
        	break;
            
            }

        cout << "\n\nDo you want to continue (1/0): ";
        cin >> ch;
        if (ch == 0) break;
    }

    return 0;
}
