//
// Created by Natàlia Serarols Francino on 13/04/2020.
//

#ifndef EXERCICI4_POSITION_H
#define EXERCICI4_POSITION_H

#include "NodeList.h"

template <class Element>
class Position{
public:
    Position(NodeList<Element>* node); // Constructor amb paràmetres
    Position<Element> next() const; // retorna la següent posició
    Position<Element> previous() const; // retorna l’anterior posició
    const Element& element() const; // retorna el contingut de l’actual posició
    void setPrevious(NodeList<Element> * node) ; // assigna l’adreça de l’anterior node
    void setNext(NodeList<Element> * node) ; // assigna l’adreça del següent node
    NodeList<Element>* getNodePtr() const; //retorna atribut node actual

    Position<Element> operator++() const; // sobrecarrega operador ++
    bool operator==(const Position& other) const; // sobrecarrega operador ==
    bool operator!=(const Position& other) const; // sobrecarrega operador !=
    const Element& operator*() const; // sobrecarrega operador contingut


private:
    NodeList<Element>* _node;
};

template <class Element>
Position<Element>::Position(NodeList<Element> *node) {
    _node = node;
}

//falten
template <class Element>
Position<Element> Position<Element>::next() const { //retorna la seguent posicio
    return _node->getNext();

}

template <class Element>
Position<Element> Position<Element>::previous() const {
    return _node->getPrevious();
}

template <class Element>
const Element & Position<Element>::element() const {
    return _node->getElement();
}

template <class Element>
void Position<Element>::setPrevious(NodeList<Element> *node) {
    _node->setElement(node);
}

template <class Element>
void Position<Element>::setNext(NodeList<Element> *node) {
    _node->setNext(node);
}

template <class Element>
Position<Element> Position<Element>::operator++() const {
    return _node->getNext();

}

template <class Element>
bool Position<Element>::operator!=(const Position<Element> &other) const {
    return (_node != other._node);
}

template <class Element>
bool Position<Element>::operator==(const Position<Element> &other) const {
    return (_node == other._node);
}

template <class Element>
const Element & Position<Element>::operator*() const { //sobrecarrega l'operador contingut
    return this->_node->getElement();
}

template <class Element>
NodeList<Element>* Position<Element>::getNodePtr() const {
    return this->_node;
}

#endif //EXERCICI4_POSITION_H
