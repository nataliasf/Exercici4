//
// Created by Natàlia Serarols Francino on 13/04/2020.
//

#ifndef EXERCICI4_LINKEDLIST_H
#define EXERCICI4_LINKEDLIST_H

#include "iostream"
using namespace std;
#include "NodeList.h"
#include "Position.h"

template <class Element>
class LinkedList
{
public:
    LinkedList();
    LinkedList(std::initializer_list<Element> elements);
    LinkedList(const LinkedList<Element>& list);
    virtual ~LinkedList();

    int size() const;
    bool isEmpty() const;

    const Position<Element> begin() const; // return first position
    Position<Element> end() const; // return last position
    void insertFront(const Element & element);
    void insertBack(const Element & element);
    void insertAfter(const Position<Element>& position, const Element & element);
    void insertBefore(const Position<Element>& position, const Element & element);
    void print() const;

private:
    NodeList<Element>*_head;
    NodeList<Element>*_rear;
    int _size;
    //NodeList<Element> *_headSentinel;
    //NodeList<Element> *_rearSentinel;
};

template <class Element>
LinkedList<Element>::LinkedList(){ //constructor
    //inicialitzem tot a 0:
    cout << "constructor linkedlist" << endl;

    NodeList<Element>* _headSentinel = new NodeList<Element>(NULL);
    NodeList<Element>* _rearSentinel = new NodeList<Element>(NULL);

    _head = _headSentinel;
    _rear = _rearSentinel;

    _head->setNext(_rear);
    _rear->setPrevious(_head);

    _head->setPrevious(nullptr);
    _rear->setNext(nullptr);
    this->_size = 0;
}

template <class Element>
LinkedList<Element>::~LinkedList(){

}

template <class Element>
int LinkedList<Element>::size() const {
    return this->_size;
}

template <class Element>
bool LinkedList<Element>::isEmpty() const {
    cout << _head->getNext() << " ..." <<_rear << endl;
    return (_head->getNext()==_rear);
}

template <class Element>
const Position<Element> LinkedList<Element>::begin() const {
    return _head->getNext(); //crec que sense getElement per poder iterar.
}

template <class Element>
Position<Element> LinkedList<Element>::end() const {
    return _rear;

}

template <class Element>
void LinkedList<Element>::insertFront(const Element &element) {

    NodeList<Element> *new_node = new NodeList<Element>(element);
    new_node->setNext(_head->getNext());
    new_node->setPrevious(_head);
    _head->getNext()->setPrevious(new_node);
    _head->setNext(new_node);

    //insertAfter(_head, element);

    this->_size++;
}

template <class Element>
void LinkedList<Element>::insertBack(const Element &element) { //insert before
    cout << "insert back" << endl;
    /*NodeList<Element> *new_node = new NodeList<Element>(element);
    new_node->setNext(_rear);
    new_node->setPrevious(_head->getPrevious());
    _rear->getPrevious()->setNext(new_node);
    _rear->setPrevious(new_node);
    this->_size++;*/



    insertBefore(end(), element);
    this->_size++;
}

template <class Element>
void LinkedList<Element>::insertAfter( const Position<Element> &position, const Element &element) {
    NodeList<Element> *new_node = new NodeList<Element>(element);
    NodeList<Element> *node_position = position.getNodePtr(); //node de la posició donada per parametre
    new_node->setNext(node_position->getNext());
    new_node->setPrevious(node_position);
    node_position->getNext()->setPrevious(new_node);
    node_position->setNext(new_node);

    this->_size++;

}

template <class Element>
void LinkedList<Element>::insertBefore(const Position<Element> &position, const Element &element) {
    NodeList<Element> *new_node = new NodeList<Element>(element); //nou node que volem insertar
    NodeList<Element> *node_position = position.getNodePtr(); //node de la posició donada per parametre

    new_node->setNext(node_position);
    new_node->setPrevious(node_position->getPrevious());

    node_position->getPrevious()->setNext(new_node);
    node_position->setPrevious(new_node);
    this->_size++;
}

template <class Element>
void LinkedList<Element>::print() const {
    cout << " \nRegistry after insert:  \n";
    for(Position<Element> itr= begin(); itr != end(); itr=++itr){
        cout << itr.operator*()<< endl;
        //break;

    }

}


#endif //EXERCICI4_LINKEDLIST_H
