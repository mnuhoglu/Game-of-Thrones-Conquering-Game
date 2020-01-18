#include <iostream>
#include <string>	
#include "linkedlist.h"



using namespace std;

linkedlist::linkedlist(){
	head = NULL;
}

//this functon is used to get the head in the main
houseNode*linkedlist::kafacý(){
	return head;
}
/**** this function add new housenode at the end of the list ****/
void linkedlist ::addHouseNode(string hname)
{
	houseNode*ptr=head;
	houseNode*temp= new houseNode(hname, NULL, NULL);
	if(head==NULL)// list is empty
		head=temp;
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;	
	}
}
/**** this member function add neighbornode at the end of the given housename housenode***/	 
void linkedlist ::addNeighborNode (string hname, string nname)
{
	houseNode* ptr=head;
	
	while(ptr!=NULL)
	{
		if(ptr->houseName==hname)
		{
			neighborNode* p=new neighborNode(nname,NULL);
			neighborNode* pn=ptr->neighborListHead;
			
              if(pn==NULL){
				ptr->neighborListHead=p;
			  }
			  else
			  {
				  while(pn->next!=NULL)
					  pn=pn->next;

				  pn->next = p;
			  }
		}

		ptr=ptr->next;
	}
	
}
//this function prints all of the list to the console
void linkedlist ::printAll()
{
	houseNode*ptr=head;
		while(ptr!=NULL)
		{
			neighborNode*p;
			p=ptr->neighborListHead;
			cout<<ptr->houseName<< ": ";
		
			while(p!=NULL)
				{
					cout<< p->neighborName<<", ";
					p=p->next;
				}
			cout<< endl;
			ptr=ptr->next;
			
		}


}
//this function checks if the house name exist in the list
bool linkedlist:: hnExists(string hname)
{
		houseNode* ptr=head;

		while(ptr!=NULL)
		{
			if(ptr->houseName == hname)
				return true;
			ptr=ptr->next;
		}
		return false;
}
//this function checks if the given neighborname exists in the given housename
bool linkedlist:: nnExists(string hname, string nname)
{
		houseNode* ptr = head;
		
		while(ptr!=NULL)
		{neighborNode* pn=ptr->neighborListHead;
			if(ptr->houseName == hname)
			{
				if(pn==NULL)
					return false;
				else 
				{
					while(pn!=NULL)
					{
						if(pn->neighborName == nname)
							return true;
						pn=pn->next;
					}
				}
			}
			ptr=ptr->next;
		}
		return false;
}
//this function deletes all of the list
void linkedlist::deleteAll() 
{
	houseNode*ptr=head;
	while(head!=NULL)
	{
		ptr=head;
		head=head->next;
		delete ptr;
	}
}
//this function deletes the housename and all of its neighbors
void linkedlist::deleteByName(string hname) 
{
	//do nothing if list is empty
	if (head != NULL) {
		houseNode *ptr = head;
		//update head if the head contains the data requested for deletion
		if (head->houseName == hname) {
			head = head->next;
			delete ptr;
		}
		else {
			//search for the node with the correct data
			//ptr != NULL is necessary for the special case where the last element is deleted and ptr is updated
			//to NULL and the program crashes when ptr->next is executed in the while boolean expression.
			while (ptr != NULL && ptr->next != NULL) {
				if (ptr->next->houseName == hname) {
					houseNode * temp = ptr->next;
					ptr->next = ptr->next->next;
					delete temp;
				}
				ptr = ptr->next;
			}
		}
	}
}
//this function deletes the given neighbor of the given housename
void linkedlist::deleteneigh(string hname,string nname) 
{bool check=true;
	houseNode *ptr = head;
	int i = 0;
	while(ptr!=NULL&&check)
	{
		if(ptr->houseName==hname)
		{
			neighborNode *pýtýr= ptr->neighborListHead;
			neighborNode* kýtýr = pýtýr;
			if(pýtýr->neighborName==nname&& i==0)
			{
				ptr->neighborListHead=kýtýr->next;
				delete pýtýr;
				check = false;

			}
			
			while(pýtýr!=NULL&&check)
			{
				if(pýtýr->neighborName==nname&&pýtýr->next!=NULL)
				{ 
					kýtýr->next = pýtýr->next;
					delete pýtýr;
					check=false;
				}
				else if(pýtýr->neighborName==nname && pýtýr->next==NULL){
					check = false;
					delete pýtýr;
					kýtýr->next = NULL;
				}
				kýtýr = pýtýr;
				pýtýr=pýtýr->next;
			}i++;
			
		}
		ptr=ptr->next;
	}
}