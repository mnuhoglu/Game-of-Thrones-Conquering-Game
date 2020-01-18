#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "linkedlist.h"

using namespace std;

int main()
{
	string filename, s;											
	ifstream i;
	cout << "Please enter a file name." << endl;				//file name taken as input
	cin >> filename;
	i.open(filename.c_str());

	while (i.fail()) //checks if the file opened correctly
	{
		cout << "Unable to open file " << filename;
		cout << endl <<"Please enter a different file name."<< endl;
		cin >> filename;
		i.open(filename.c_str());
	}
	cout << "Successfully opened file "<<filename << endl<<endl;
	cout << "######## TOPOLOGY ########" << endl << endl;
	linkedlist mylist; // list created here
	while (getline(i, s)) //inside this loop text file read and added to the list
	{
		istringstream is(s);
		string name1, name2;
		is >> name1 >> name2;
		cout << "Processing " << name1 << ", " << name2 << endl;
		if(mylist.nnExists(name1,name2) && mylist.nnExists(name2,name1))//checks if the names are added before
			cout << "Redundant information! An entry with " << name1 << " and " << name2 << " is already processed." <<endl << endl;
		else{//if not adds them to the list
		cout << "Topology information successfully added."<< endl << endl;
		if(!mylist.hnExists(name1))
			mylist.addHouseNode(name1);
		if(!mylist.hnExists(name2))
			mylist.addHouseNode(name2);
		if(!mylist.nnExists(name1,name2))
			mylist.addNeighborNode(name1,name2);
		if(!mylist.nnExists(name2,name1))
			mylist.addNeighborNode(name2,name1);
		}
	}cout << "######## MAP ######## " << endl ;
	mylist.printAll();//prints the list 
	int input;
	bool check = true;
	cout << endl;
	while(check)//if option 3 is not chosen,loop keeps running
	{
	cout << endl << "Please select an option [1-2-3]. " << endl<< "1. Annexation! War for the iron throne continues... " << endl;
	cout << "2. Tyrion must travel, do a path check for the famous imp." << endl << "3. Exit " << endl;
	cin >> input;//game mode taken as an input here
	bool check3=true;
	if(input==1 && check3)
	{
		string s2,s3;
		cout << "Please enter two houses first the annexer and the annexed. (ex: Tyrell Stark). " << endl;
		cin >> s2 >> s3;			//for the first mode 2 string input taken
		bool checkk = true;
		if(s2==s3)//if theyre same uptade fails.
		{
			cout << "A House cannot conquer itself! " << endl << "Uptade failed." << endl;
			check3=false;
			checkk=false;
		}
		else if(!mylist.hnExists(s2) && check3)//if one of them does not exist update fails
		{
			cout << s2 << " does not exist!" << endl << "Uptade failed." << endl;
			check3=false;
			checkk=false;
		}
		else if(!mylist.hnExists(s3) && check3)
		{
			cout << s3 << " does not exist!" << endl << "Uptade failed." << endl;
			check3=false;
			checkk=false;
		}
		if(mylist.nnExists(s2,s3))
		{
			houseNode*head=mylist.kafacý();
			
		bool check4 = true;
			while(head!=NULL&&check4)//this loop adds the losers neighbors to the winners
			{
				if(head->houseName == s3)
				{
					while(head->neighborListHead!=NULL)
					{
						while(!mylist.nnExists(s2,head->neighborListHead->neighborName)&& head->neighborListHead->neighborName!=s2)
							mylist.addNeighborNode(s2,head->neighborListHead->neighborName);
						head->neighborListHead=head->neighborListHead->next;
					}
					mylist.deleteByName(s3);
					check4=false;
				}
				head=head->next;
			}
			cout << s2 << " conquered " << s3 << "!" << endl << "######## MAP ######## " << endl ;
			houseNode*ptr=mylist.kafacý();
			while(ptr!=NULL)
			{   //this statement is for the situation which loser is neighbor of a house but winner is not
				if(mylist.nnExists(ptr->houseName,s3) && !mylist.nnExists(ptr->houseName,s2) && ptr->houseName!=s2)
					{   
						mylist.addNeighborNode(ptr->houseName,s2);
						mylist.deleteneigh(ptr->houseName,s3);
					}
				else if(mylist.nnExists(ptr->houseName,s3) && mylist.nnExists(ptr->houseName,s2))//this statement deletes loser if both are neighbor of one node
					mylist.deleteneigh(ptr->houseName,s3);
				if(mylist.nnExists(s2,s3))//this statement deletes the loser from winner if it exists
					mylist.deleteneigh(s2,s3);
				ptr=ptr->next;
			}mylist.printAll();
		}
		else if(checkk)//if they are not neighbor
			cout << "A house can only conquer a neighboring house! " << s3 << " is not a neighbor of " << s2 <<"." <<endl << "Update failed." <<endl;
	}
	bool check1=true;
	if(input==2 && check1)
		{
		string q,first,second;	
		cout << "Please enter a path. (ex: Tyrell Martell Tully) " << endl;//input taken for the 2nd mode
		cin.ignore();
		getline(cin,q,'\n');
		istringstream çek(q);
		çek >> first >> second;//takes the first to string of the input
		do
		{bool chek = true;
			if(first==second){//checks if the inputs are same
				cout << "You are already in " << first << endl;
			chek=false;}
			if(mylist.hnExists(first)&&chek)
			{
				if(mylist.nnExists(first,second))//checks if inputs are neighbor
					cout << "Path found between " << first << " and " << second << endl;
				else//else theyre not neighbor
				{
					cout << second << " is not a neighbor of " << first << endl;
					cout << "Path search failed!"<< endl;	
					check1=false;
				}
			}
			else if(check1&&chek)
			{//if theyre not neighbor and not same they do not exist in the map
				cout << first << " does not exist in the map." << endl;
				cout << "Path search failed!" << endl;
				check1=false;
			}first=second;
		}while(çek>>second&&check1);//this while executes as long as there are strings in the input
		if(check1)
		cout << "Path search succeeded. " <<endl;
		check1 = false;
		}
	if(input==3)
		{//if input is 3 list is deleted and program ended
			mylist.deleteAll();
			cout <<"List deleted and program ended.";
			check=false;
		}
	if(input!=1 && input!=2 && input !=3)//if input is rather than 1,2 or 3 program asks for new input
		cout << "Invalid option please select from the menu. " << endl;
	}
}