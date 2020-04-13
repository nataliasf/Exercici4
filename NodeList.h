//
// Created by Natàlia Serarols Francino on 13/04/2020.
//

#ifndef EXERCICI4_NODELIST_H
#define EXERCICI4_NODELIST_H

template <class Element>
class NodeList {
public:
    NodeList(Element e);
    NodeList(const NodeList& orig);
    //virtual ~NodeList();
    NodeList<Element>* getNext() const; // estrelleta punter
    NodeList<Element>* getPrevious() const;
    void setNext(NodeList<Element>* ptr);
    void setPrevious(NodeList<Element>* ptr);

    const Element&  getElement() const;
    void setElement(Element e);
private:
    Element element;
    NodeList* next;
    NodeList* prev;
};

template <class Element>
NodeList<Element>::NodeList(Element e) {
    this->element = e;
    this->next = nullptr;
    this->prev = nullptr;
}

/*template <class Element>
NodeList<Element>::~NodeList(){
    //si no fem news no cal implementar res.
}*/

template <class Element>
NodeList<Element> * NodeList<Element>::getNext() const {
    return this->next;
}

template <class Element>
NodeList<Element> * NodeList<Element>::getPrevious() const {
    return this->prev;
}

template <class Element>
void NodeList<Element>::setNext(NodeList<Element>* ptr) {
    this->next = ptr;
}

template <class Element>
void NodeList<Element>::setPrevious(NodeList<Element> *ptr) {
    this->prev = ptr;
}

template <class Element>
const Element & NodeList<Element>::getElement() const {
    return this->element;
}

template <class Element>
void NodeList<Element>::setElement(Element e) {
    this->element = e;
}

#endif //EXERCICI4_NODELIST_H
