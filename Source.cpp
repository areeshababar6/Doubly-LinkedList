#include<iostream>
using namespace std;

struct node
{
	node *prev;
	int data;
	node *next;
};

node *insert_list(node *head, int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	head = temp;
	return head;
}

node *insert_start_list(node *head, int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
	return head;
}

node *insert_end_list(node *head, int data)
{
	node *temp, *pnew;
	temp = (node *)malloc(sizeof(node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	pnew = head;

	while (pnew->next != NULL)
	{
		pnew = pnew->next;
	}
	pnew->next = temp;
	temp->prev = pnew;
	return head;
}

node *insert_btw_list(node *head, int data, int pos)
{
	node *temp = head;
	node *pnew = NULL;
	node *temp2 = NULL;

	pnew = insert_list(pnew, data);

	//while (pos != 1)      //=>for certain postion in list
	while (pos > 1)         //=>for specific postion in list
	{
		temp = temp->next;
		pos--;
	}

	//if (temp->next == NULL)     //adding at last node
	//{
	//	temp->next = pnew;
	//	pnew->prev = temp;
	//}

	if (pos == 1)          //Adding at first node
	{
		head = insert_start_list(head, data);
	}
	else
	{
		temp2 = temp->next;
		temp->next = pnew;
		temp2->prev = pnew;
		pnew->next = temp2;
		pnew->prev = temp;
	}

	return head;
}

void print(node *head)
{
	node *ptr = head;

	while (ptr != NULL) {
		cout << ptr->data << endl;
		ptr = ptr->next;
	}

}

node *create_doubly_list(node *head)
{
	int n, data ;

	cout << "Enter the no of the nodes:" << endl;
	cin >> n;

	if (n == 0)
	{
		return head;
	}

	cout << "Enter the data for Node 1" << endl;
	cin >> data;
	head = insert_list(head, data);

	for (int i = 1; i < n; i++)
	{
		cout << "Enter the data for the nodes " << i + 1 << endl;
		cin >> data;
		head = insert_end_list(head, data);
	}
	return head;
}

node *delete_first_node(node *head)
{
	node *temp = head;
	head = head->next;
	free(temp);
	temp = NULL;
	head->prev = NULL;
	return head;
}

node *delete_last_node(node *head)
{
	node *temp = head;
	node *temp2;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->prev;
	temp2->next = NULL;
	free(temp);

	return head;
}

node *delete_intermediate_node(node *head, int pos)
{
	node *temp = head;
	node *temp2 = NULL;

	if (pos == 1) {
		head = delete_first_node(head);
		return head;
	}
	while (pos > 2)
	{
		temp = temp->next;
		pos--;
	}
	if (temp->next == NULL)
	{
		head = delete_last_node(head);
	}
	else
	{
		temp2 = temp->prev;
		temp2->next = temp->next;
		temp->next->prev = temp2;
		free(temp);
		temp = NULL;
	}
	return head;
}

node *reverse_list(node *head)
{
	node *ptr1 = head;
	node *ptr2 = ptr1->next;

	ptr1->next = NULL;
	ptr1->prev = ptr2;

	while (ptr2 != NULL)
	{
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->prev;
	}
	head = ptr1;
	return head;
}

int main()
{
	node *head = NULL;
	node *ptr;
	int pos = 1;

	//head = create_doubly_list(head);
   
	head = (node *)malloc(sizeof(node));
	head->prev = NULL;
	head->data = 10;
	head->next = NULL;

	//cout << "Inserting the Element in the list" << endl;
	head = insert_list(head, 20);

	//cout << "Inserting the Element at the start of the list" << endl;
	head = insert_start_list(head, 10);
	
	//cout << "Inserting the Element at the start of the list" << endl;
	head = insert_end_list(head, 40);

	//cout << "Inserting the Element at the center of the list" << endl;
	head = insert_btw_list(head, 30, pos);

	//cout << "Printing the list" << endl;
	print(head);

	//cout << "Deleting the first node of the list" << endl;
	head = delete_first_node(head);
	cout << "After Deletion!" << endl;
	print(head);

	//cout << "Deleting the last node of the list" << endl;
	head = delete_last_node(head);
	cout << "Delete after last node" << endl;
	print(head);

	//cout << "Deleting the intermediate node of the list" << endl;
	head = delete_intermediate_node(head,pos);
	cout << "After Deletion Intermediate node!" << endl;
	print(head);

	//cout << "Reversing of the list" << endl;
	cout << "Before reversing the list!" << endl;
	print(head);
	head = reverse_list(head);
	cout << "After reversing the list!" << endl;
	print(head);

	return 0;
}