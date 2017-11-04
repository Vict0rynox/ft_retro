#ifndef DAY02_LIST_HPP
#define DAY02_LIST_HPP

#include <stdexcept>
#include "ListNode.hpp"
#include "IIterrator.hpp"

namespace Utils {
	template < class T >
	class List : public Utils::IIterrator<T> {
	protected:
		ListNode<T> *node;
		ListNode<T> *current;
	public:
		List();
		List(const List &rst);
		List &operator=(const List &rst);
		virtual ~List();
		bool isEmpty();
		void pushNode(T node);
		T popNode();
		T popFrontNode();

		//iterator
		T curr();
		void next();
		void prev();
		void reset();
		bool isEnd();
	};
}

template <class T>
void Utils::List<T>::pushNode(T node) {
	if(this->node == nullptr) {
		this->node = new ListNode<T>(node);
	} else {
		this->node->setNext(new ListNode<T>(node));
		this->node->getNext()->setPrev(this->node);
		this->node = this->node->getNext();
	}
}

template <class T>
T Utils::List<T>::popNode() {
	if(node == nullptr) {
		throw std::length_error("List is empty");
	}
	ListNode<T> *node;
	node = this->node;
	this->node = this->node->getPrev();
	if(this->node != nullptr) {
		this->node->setNext(nullptr);
	}
	T val = node->getValue();
	delete node;
	return val;
}

template <class T>
Utils::List<T>::List() {
	node = nullptr;
	current = nullptr;
}

template <class T>
Utils::List<T>::~List()
{
	ListNode<T> *listNode;
	while(node != nullptr){
		listNode = node;
		node = listNode->getPrev();
		delete listNode;
	}
}

template <class T>
Utils::List<T>::List(const Utils::List<T> &rst)
{
	node = rst.node;
	current = rst.current;
}

template <class T>
Utils::List<T> &Utils::List<T>::operator=(const Utils::List<T> &rst)
{
	node = rst.node;
	current = rst.current;
	return *this;
}

template <class T>
bool Utils::List<T>::isEmpty()
{
	return node == nullptr;
}

template <class T>
T Utils::List<T>::popFrontNode()
{
	T val;
	ListNode<T> *tmp = nullptr;

	if(node == nullptr) {
		throw std::length_error("List is empty");
	}
	if(node->getPrev() == nullptr) {
		val = node->getValue();
		delete node;
		node = nullptr;
		return val;
	}
	tmp = node;
	while (tmp->getPrev() != nullptr) {
		tmp = tmp->getPrev();
	}
	if(tmp->getNext() != nullptr){
		tmp->getNext()->setPrev(nullptr);
	}
	val = tmp->getValue();
	delete tmp;
	return val;
}

template <class T>
T Utils::List<T>::curr()
{
	if(current == nullptr) {
		throw std::length_error("iterator is end");
	}
	return current->getValue();
}

template <class T>
void Utils::List<T>::next()
{
	if(current == nullptr) {
		throw std::length_error("iterator is end");
	}
	current = current->getNext();
}

template <class T>
void Utils::List<T>::reset()
{
	current = node;
}

template <class T>
void Utils::List<T>::prev()
{
	if(current == nullptr) {
		throw std::length_error("iterator is end");
	}
	current = current->getPrev();
}

template <class T>
bool Utils::List<T>::isEnd()
{
	return current == nullptr;
}


#endif //DAY02_LIST_HPP
