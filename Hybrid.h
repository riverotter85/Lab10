/*
	Filename: Hybrid.h
	Modified By: Logan Davis & Autumn Ferree
	Last Date Modified: 11/04/2016
*/

#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"

#include "DoubleNode.h"

template < class T >
class Hybrid
{

   private:
      QueueLinked< DoubleNode<T> >* q;
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   q = new QueueLinked< DoubleNode<T> >();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove

template < class T >
bool Hybrid<T>::isEmpty()
{
	return sldl->isEmpty();
}

template < class T >
void Hybrid<T>::enqueue(T* item)
{
	if (item == NULL) { return; } // Nothing to add
	
	DoubleNode<T>* itemDN = NULL;
	
	itemDN = sldl->addDN(item);
	q->enqueue(itemDN);
}

template < class T >
T* Hybrid<T>::dequeue()
{	
	DoubleNode<T>* itemDN = NULL;
	T* item = NULL;
	
	if (!isEmpty())
	{
		itemDN = q->dequeue();
		item = sldl->remove(itemDN);
	}
	
	return item;
}

template < class T >
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
	return sldl->iterator();
}

#endif
