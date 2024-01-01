#include "SLL.h"

template <typename dtype>
void SLL<dtype>::push_back(dtype p_data)
{
	if (head == nullptr)
	{
		head = new Node(p_data);
	}
	else
	{
		Node* temp = head;
		while (temp->nextNode != nullptr)
		{
			temp = temp->nextNode;
		}
		temp->nextNode = new Node(p_data);
	}
}

template <typename dtype>
void SLL<dtype>::push_front(dtype p_data)
{
	if (head == nullptr)
	{
		head = new Node(p_data);
	}
	else
	{
		Node* temp = new Node(p_data);
		temp->nextNode = head;
		head = temp;
	}
}

template <typename dtype>
SLL<dtype>::~SLL()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* nextNode = temp->nextNode;
		delete temp;
		temp = nextNode;
	}
	head = nullptr;
}


template <typename dtype>
void SLL<dtype>::print()
{
	Node* temp = head;
	std::cout << "\n[";
	while (temp != nullptr)
	{
		std::cout << temp->data;
		if (temp->nextNode != nullptr)
			std::cout << ", ";
		temp = temp->nextNode;
	}
	std::cout << "]\n";
}
//template <typename dtype>
//void SLL<dtype>::print(int index)
//{
//
//}