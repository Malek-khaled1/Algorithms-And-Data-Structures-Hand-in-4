#include <vector>
#include "binary_search_tree.h"

using namespace std;

template<typename Comparable>
class OrderedSet {
  private:
	size_t theSize;
	BinarySearchTree<Comparable> tree;

  public:
	OrderedSet() { }

	~OrderedSet() { clear(); }

	OrderedSet(const OrderedSet& s) {
		
		// iterate through s and create copy of old set
		for (auto it = s.begin(); it != s.end(); ++it) {
        insert(*it); // insert element
    	}
	}

	void clear() {
		// clear and reset size
        tree.makeEmpty();
        theSize = 0;
	}

	size_t size() const {
		
		// return size
		return theSize;
	}

	bool empty() const {
		
		// check if empty
		return tree.isEmpty();
	}

	void push(const Comparable& t) {
        insert(t); // insert element
    }


	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const {
		// return iterator to the smallest element
		return tree.findMin();
	}

	iterator end() const {
		
		// return iterator at one position after last element
		return iterator(nullptr);
	}

    iterator insert(const Comparable& t) {
        
		// if the element is not in the set
        if (!tree.contains(t)) {
			// insert and get iterator
            auto it = tree.insert(t);
            ++theSize; // increase size
            return it; // return iterator
        }
		// if element exists -> return iterator to the existing element
        return tree.find(t);   //
    }

    iterator find(const Comparable& t) {

		// If the element exsists
		if (tree.contains(t))
		{
			// return iterator to element
			return tree.find(t);
		}
		// else return nullptr
        return end();
    }

	iterator erase(iterator& itr) {
		
        // if itr --> nullptr
		if (itr == end())
        {
            return itr; // return iterator
        }
        
		// safe position
		iterator next = itr;
        // position after the element
		next++;
        // remove the element
        tree.remove(*itr);
		// decrease size
        --theSize;
		// return position of the next element
        return next; 
	}
};
