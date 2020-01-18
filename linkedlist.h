#include <iostream>
#include <string>

using namespace std;
//neighbor node struct
struct neighborNode
{
	string neighborName;
	neighborNode * next;
	// constructors 
	neighborNode::neighborNode ()
	{
		neighborName="";
		next=nullptr;
	}

	neighborNode::neighborNode (string Nname, neighborNode * Nlink)
		: neighborName(Nname), next (Nlink)
	{}
};
//house node struct
struct houseNode
{
	string houseName;
	neighborNode * neighborListHead;
	houseNode * next;
	 // constructors 
	 houseNode::houseNode ()
		 :houseName(""),neighborListHead(NULL),next(NULL)
	 {}
	 
	 houseNode::houseNode (string Hname, neighborNode *NlistHead,houseNode *Hlink)
		 : houseName(Hname), neighborListHead(NlistHead), next (Hlink)
	 {}
};
class linkedlist
{
public:
	linkedlist();
	houseNode* kafacý();//returns head
	void addHouseNode(string hname);  //adds the given house name to the list
	void addNeighborNode (string hname, string nname);//adds the given neighbor name to given house name
	void printAll();   //prints the list
	bool hnExists(string hname);  //checks if the house name exists in the list
	bool nnExists(string hname, string nname);  //checks if the given neighbor name exists in the given house name
	void deleteAll();  //deletes all the list
	void deleteByName(string hname);//deletes given house name from the list
	void deleteneigh(string hname,string nname);//deletes given neighbor name from the given house name
private:
	houseNode * head;
};