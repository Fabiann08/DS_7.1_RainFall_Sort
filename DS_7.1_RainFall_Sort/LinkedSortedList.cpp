//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// PARITALLY COMPLETE.

/** Implementation file for the class LinkedSortedList.
 @file LinkedSortedList.cpp */

#include "LinkedSortedList.h"  // Header file
#include <cassert>

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
}  // end copy constructor

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
}

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* prevPtr = getNodeBefore(newEntry);

	if (isEmpty() || (prevPtr == nullptr)) // Add at beginning
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else // Add after node before
	{
		Node<ItemType>* aftPtr = prevPtr->getNext();
		newNodePtr->setNext(aftPtr);
		prevPtr->setNext(newNodePtr);
	} // end if

	itemCount++;
} // end insertSorted

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
	Node<ItemType>* nodeToRemovePtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;

	// Traverse the list to find the node to remove and its previous node
	while (nodeToRemovePtr != nullptr && nodeToRemovePtr->getItem() != anEntry) {
		prevPtr = nodeToRemovePtr;
		nodeToRemovePtr = nodeToRemovePtr->getNext();
	}

	if (nodeToRemovePtr == nullptr) { // Node not found
		return false;
	}
	else { // Node found, remove it
		if (prevPtr == nullptr) { // Node to remove is the first node
			headPtr = nodeToRemovePtr->getNext();
		}
		else { // Node to remove is not the first node
			prevPtr->setNext(nodeToRemovePtr->getNext());
		}

		nodeToRemovePtr->setNext(nullptr);
		delete nodeToRemovePtr;
		nodeToRemovePtr = nullptr;

		itemCount--;
		return true;
	}
}  // end removeSorted

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	int position = 1;

	while (curPtr != nullptr && curPtr->getItem() < anEntry) {
		curPtr = curPtr->getNext();
		position++;
	}

	if (curPtr == nullptr || curPtr->getItem() != anEntry) {
		// Entry not found, return the negative position where it should be inserted
		return -position;
	}
	else {
		// Entry found, return its position
		return position;
	}
}

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
	if (position < 1 || position > itemCount) { // Invalid position
		return false;
	}
	else {
		Node<ItemType>* nodeToRemovePtr = headPtr;
		Node<ItemType>* prevPtr = nullptr;

		// Traverse the list to find the node to remove and its previous node
		for (int i = 1; i < position; i++) {
			prevPtr = nodeToRemovePtr;
			nodeToRemovePtr = nodeToRemovePtr->getNext();
		}

		if (prevPtr == nullptr) { // Node to remove is the first node
			headPtr = nodeToRemovePtr->getNext();
		}
		else { // Node to remove is not the first node
			prevPtr->setNext(nodeToRemovePtr->getNext());
		}

		nodeToRemovePtr->setNext(nullptr);
		delete nodeToRemovePtr;
		nodeToRemovePtr = nullptr;

		itemCount--;
		return true;
	}
}

template<class ItemType>
void LinkedSortedList<ItemType>::clear()
{
	while (!isEmpty()) {
		remove(1);
	}
}

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
	if (position < 1 || position > itemCount) { // Invalid position
		string message = "getEntry() called with an invalid position.";
		throw PrecondViolatedExcep(message);
	}
	else {
		Node<ItemType>* nodePtr = headPtr;

		// Traverse the list to find the node at the given position
		for (int i = 1; i < position; i++) {
			nodePtr = nodePtr->getNext();
		}

		return nodePtr->getItem();
	}
}

// Private Methods:

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr)
{
	Node<ItemType>* copiedChainPtr;
	if (origChainPtr == nullptr)
	{
		copiedChainPtr = nullptr;
	}
	else
	{
		// Build new chain from given one
		copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
	}  // end if

	return copiedChainPtr;
}  // end copyChain

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;

	while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	} // end while

	return prevPtr;
} // end getNodeBefore

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeAt(int position) const
{
	Node<ItemType>* currentPtr = headPtr;

	for (int i = 1; i < position; i++) 
	{
		currentPtr = currentPtr->getNext();
	}

	return currentPtr;
}
