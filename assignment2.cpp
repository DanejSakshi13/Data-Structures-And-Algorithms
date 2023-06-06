/*Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers*/

#include<iostream>
#include<string.h>
#define max 10
using namespace std;

struct client
{
	long long int phn;
	char name[20];

};	

class hashtable
{
	client ht[max];
	
	public:
		hashtable()
		{
			for(int i=0;i<max;i++)
			{
				ht[i].phn=0;
			}
		}		
		void insert();
		void display();
		int search(int);
		int del(int);
		int hash(long long int);
};

void hashtable::insert()
{
	client c;
	int iPos;
	char cAns;
	do
	{
		cout<<"\nEnter Phone Number : ";
		cin>>c.phn;
		cin.ignore();
		cout<<"\nEnter Name : ";
		cin.getline(c.name,20);
		iPos=hash(c.phn);
	
		if(ht[iPos].phn==0)
		{
			ht[iPos]=c;
		}
		else
		{
			for(int i=iPos+1;i%max!=iPos;i++)
			{
				ht[i]=c;
				break;
			}
		}
		cout<<"\nAdd More:";
		cin>>cAns;
	}while(cAns=='y' || cAns=='Y');	
}

int hashtable::hash(long long int key)
{
	return(key%max);
}

void hashtable::display()
{
	cout<<"------------------------------------";
	cout<<"\nSrno\tPhone number\t\t\n";
	cout<<"------------------------------------\n";
	for(int i=0;i<max;i++)
	{
		cout<<i<<"\t"<<ht[i].phn<<"\t\t"<<ht[i].name<<endl;
	}
	cout<<"------------------------------------\n";
}

int hashtable::search(int x)
{
	int iFlag=0; 
	cout<<"Enter Phone number to be searched:";
	cin>>x;
	for(int i=0;i<max;i++)
	{
		if(ht[i].phn==x)
		{
			cout<<"\n Phone Number Found at position "<<i;
			iFlag=1;
		}
	}
	if(iFlag==0)
	cout<<"\n Phone Number Not Found";
}

int hashtable::del(int s)
{
	int iF=0;
	cout<<"\n Enter phone number to be deleted:";
	cin>>s;
	for(int i=0;i<max;i++)
	{
		if(ht[i].phn==s)
		{
			
			ht[i].phn=0;
			cout<<"\n Phone number found and deleted";
			iF=1;
		}
	}
	if(iF==0)
	cout<<"\n Phone number not found";

}	

int main()
{
	int y,s,Ch;
	hashtable h;
	do
	{
		cout<<"\n---------------LIST---------------\n";
		cout<<"\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.DELETE\n5.EXIT\n\n";
		cout<<"Enter your choice:";
		cin>>Ch;
		cout<<"\n";
		
		switch(Ch)
		{
			case 1://to insert
				h.insert();
				cout<<"\n";
				break;
				
			case 2://to display 
				h.display();
				cout<<"\n";
				break;
				
			case 3://to search for a entry					
				h.search(y);
				cout<<"\n";
				break;
				
			case 4://to delete a entry from data
				h.del(s);
				cout<<"\n";
				break;
				
			case 5://exit
				break;
		}
	}while(Ch>0&&Ch<5);							
return 0;
}	
