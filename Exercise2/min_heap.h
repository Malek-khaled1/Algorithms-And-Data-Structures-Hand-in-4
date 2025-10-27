#pragma once
#include<queue>
#include<utility>
using namespace std;

/**
 * @brief Min-Heap Class
 * 
 * @tparam T 
 */
template<typename T>
class MinHeap
{
public:
	/**
	 * @brief Inserts an element and updates the Heap
	 * 
	 * @param x Element to insert
	 */
	void insert(const T& x) 
	{
        Node* newnode = new Node(x);
        if (size == 0)
        {
            root = newnode; // head points on the first node of the heap
            size++; // increment size
            return;
        }
        queue<Node*> q; // create a queue
        q.push(root); // push the root
        
        while(!q.empty()) {
            
            Node* current = q.front(); // return reference to first element
            q.pop(); // remove front from queue

            if (!current->left) // if no left child
            {
                current->left = newnode;
                newnode->parent = current;
                size++;
                break;
            }
            else if (!current->right) // if no right child
            {
                current->right = newnode;
                newnode->parent = current;
                size++;
                break; 
            }
        
            q.push(current->left); // push the left child
            q.push(current->right); // push the right child
        
        }

        // Heapify Up: while parent and data les than parent data
        while(newnode->parent && newnode->data < newnode->parent->data)
        {
            std::swap(newnode->data, newnode->parent->data); // swap values
            newnode = newnode->parent;
        }
	}

	/**
	 * @brief Remove minimum (top) element and update Heap
	 * 
	 */
	void remove() 
	{
		if(size == 0){throw std::underflow_error("Heap is empty");}
        if(size == 1)
        {
            delete root; // delete the node
            root = nullptr; // head point at null
            size = 0;  // heap is empty
            return;
        }

        queue<Node*> q; // create queue
        q.push(root); // push the root
        
        Node* current = nullptr; // current node is null
        while (!q.empty()) // as long as the queue isnt empty
        {
            current = q.front(); // current point on the first element of the queue
            q.pop(); // remove element from queue
            if(current->left){q.push(current->left);} // if left child push to the queue 
            if(current->right){q.push(current->right);} // if right child, push to the queue
        }
        // Here current holds the last insterted element in the MinHeap

        std::swap(current->data, root->data); // swap the root and current data
        if (current->parent->left == current){current->parent->left = nullptr;} // if current is a left child
        else if (current->parent->right == current){current->parent->right = nullptr;} // if current is a right child
        delete current; // delete the minimum element/root
        size--;

        // Heapify down
        Node* temp = root; // temp points at root
        while(temp->left || temp->right) // while temp has children
        {
            
            Node* smallest = temp->left; 
            if(temp->right && temp->right->data < temp->left->data)
            {
                smallest = temp->right;
            }

            if(temp->data <= smallest->data)
                break;

            std::swap(temp->data, smallest->data);
            temp = smallest;
        }
	}

	/**
	 * @brief Inspect if Heap is empty 
	 * 
	 * @return true Heap is empty
	 * @return false Heap is not empty
	 */
	bool isEmpty() const
	{
		return size == 0;
	}

	/**
	 * @brief Access the minimum (top) element of the Heap
	 * 
	 * @return T Minimum element in Heap
	 */
	T peek()
	{
        if (size == 0)
            throw std::underflow_error("Heap is empty");
		
            return root->data;
	}

private:
    int size = 0;

    struct Node {
        T data;
        Node* parent;
        Node* left;
        Node* right;

        // Constructor
        Node(T value) {
            data = value;
            parent = left = right = nullptr;
        }
    };

    Node* root;
};
