#include <bits/stdc++.h>

using namespace std;

class Node{//linked list node

	public:		int data;

		Node* next;

};

int loopLength(Node *head){

	Node* slow=head,*fast=head; //initialize

	while(slow && fast && fast->next){

		slow=slow->next; //slow pointer moves slowly

		fast=fast->next->next; //fast pointer moves fast

		if(fast==slow){//there is loop

			//count loop length

			Node* temp=slow;

			temp=temp->next;

			int count=1;

			while(temp!=slow){

				count++;

				temp=temp->next;

			}

			return count; //return loop length

		}

	}

	return 0;//if there is no loop

}

Node *newNode(int k){ //defining new node

	Node *temp = (Node*)malloc(sizeof(Node)); 

	temp->data = k; 

	temp->next = NULL; 

	return temp; 

} 

/* Driver program to test above function*/

int main() { 

	cout<<"linked list is built like the example\n";

	cout<<"1->2->3->4->5->6->7->8->3->4->....\n";

	Node *head = newNode(1); 

	head->next = newNode(2); 

	head->next->next = newNode(3); 

	head->next->next->next = newNode(4); 

	head->next->next->next->next = newNode(5);

	head->next->next->next->next->next = newNode(6);

	head->next->next->next->next->next->next = newNode(7);

	head->next->next->next->next->next->next->next = newNode(8);

	/* Create the loop  */

	//the next pinter of node having value 8 coonected to node having value 3

	head->next->next->next->next->next->next->next->next = head->next->next ; 

	printf("loop length: %d \n", loopLength(head)); 

	return 0; 

} 
