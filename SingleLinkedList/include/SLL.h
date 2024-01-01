#pragma once
#include<iostream>
template <typename dtype>
class SLL
{
private:
	struct Node
	{
		dtype data;
		Node* nextNode;
		Node() : data(), nextNode(nullptr) {}
		Node(dtype p_data) : data(p_data), nextNode(nullptr) {}
		Node(dtype p_data, Node* p_nextNode) : data(p_data), nextNode(p_nextNode) {}
	};
	Node* head;
	Node* tail;
public:
	SLL(): head(nullptr), tail(nullptr){}
	SLL(Node* p_head): head(p_head){}
	~SLL();
	void push_back(dtype p_data);
	void push_front(dtype p_data);
	void print();
	//void  print(int index);

};

