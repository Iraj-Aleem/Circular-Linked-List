#include <iostream>
#include "node.h"
#include "cirlink.h"
#include <stdlib.h>


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(cirlink);

int main() {
	
	cirlink a1;
	menu(a1);	
	
	return 0;
}

void menu(cirlink a1) {
	int choice,n,i,position;
	long	long	int m;

	while(1)
	{
		cout<<"1. Create List"<<endl;
		cout<<"2. Add at beginning"<<endl;
		cout<<"3. Add after"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Quit"<<endl;

		cout<<"Enter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"How many phone	numbers u want:"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter the total	number	amount"<<endl;
					cin>>m;
					a1.create_list(m);
					
				}
				break;
			case 2:
				cout<<"Enter the number"<<endl;
				cin>>m;
				a1.addatbeg(m);
				break;
			case 3:
				cout<<"Enter the number"<<endl;
				cin>>m;
				cout<<"Enter the position after which this number is inserted"<<endl;
				cin>>position;
				a1.addafter(m,position);
				break;
			case 4:
				if(a1.last==NULL)
				{
					cout<<"List is empty"<<endl;
					continue;
				}
				cout<<"Enter the number for deletion"<<endl;
				cin>>m;
				a1.del(m);
				break;
			case 5:
				a1.display();
				break;
			case 6:
				exit(1);
			default:
				cout<<"Wrong choice"<<endl;
		}
	}
}
