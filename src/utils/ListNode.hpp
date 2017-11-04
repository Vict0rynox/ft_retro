
#ifndef UTILS_LISTNODE_HPP
#define UTILS_LISTNODE_HPP


namespace Utils{
	template < class T >
	class ListNode {
	private:
		T _val;
		ListNode *_next;
		ListNode *_prev;
	public:
		ListNode();
		ListNode(const ListNode &rhs);
		~ListNode();
		ListNode &operator=(const ListNode &rhs);
		explicit ListNode(T val);
		void setNext(ListNode *node);
		void setPrev(ListNode *node);
		ListNode *getNext();
		ListNode *getPrev();
		void setValue(T val);
		T getValue();
	};

}

template <class T>
Utils::ListNode<T> *Utils::ListNode<T>::getNext() {
	return _next;
}

template <class T>
Utils::ListNode<T>::ListNode(T val) {
	_val = val;
	_next = nullptr;
	_prev = nullptr;
}

template <class T>
Utils::ListNode<T> *Utils::ListNode<T>::getPrev() {
	return _prev;
}

template <class T>
void Utils::ListNode<T>::setValue(T val) {
	_val = val;
}

template <class T>
T Utils::ListNode<T>::getValue() {
	return _val;
}

template <class T>
void Utils::ListNode<T>::setPrev(Utils::ListNode<T> *node) {
	_prev = node;
}

template <class T>
void Utils::ListNode<T>::setNext(Utils::ListNode<T> *node) {
	_next = node;
}

template <class T>
Utils::ListNode<T> &Utils::ListNode<T>::operator=(const Utils::ListNode<T> &rhs)
{
	if(_prev != nullptr) {
		_prev->_next = _next;
	}
	if(_next != nullptr) {
		_next->_prev = _prev;
	}

	_next = rhs._next;
	_prev = rhs._prev;
	_prev->_next = this;
	_next->_prev = this;
	_val = rhs._val;
	return *this;
}

template <class T>
Utils::ListNode<T>::ListNode(const Utils::ListNode<T> &rhs)
{
	if(_prev != nullptr) {
		_prev->_next = _next;
	}
	if(_next != nullptr) {
		_next->_prev = _prev;
	}
	_next = rhs._next;
	_prev = rhs._prev;
	_val = rhs._val;
}

template <class T>
Utils::ListNode<T>::ListNode()
{
	_next = nullptr;
	_prev = nullptr;
}

template <class T>
Utils::ListNode<T>::~ListNode()
{
	if(_prev != nullptr) {
		_prev->_next = _next;
	}
	if(_next != nullptr) {
		_next->_prev = _prev;
	}
}

#endif //DAY02_LISTNODE_HPP
