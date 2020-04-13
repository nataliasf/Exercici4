//
// Created by Natàlia Serarols Francino on 13/04/2020.
//

#ifndef EXERCICI4_REGISTRY_H
#define EXERCICI4_REGISTRY_H

#include "LinkedList.h"
#include "iostream"
#include <string>
using namespace std;

template <class Element>
class Registry : public LinkedList<Element>{
public:
    Registry(); //constructor
    Registry(const Registry& orig);

    void insert(const Element & element); //inserta ordenant l'ordre alfabètic
    void merge(const Registry& other); //barreja un altre registre mantenint l'ordre
    bool operator==(const Registry& other) const; //mira si dos registres són iguals

    //opcional
};

template <class Element>
Registry<Element>::Registry():LinkedList<Element>() {

}

template <class Element>
void Registry<Element>::insert(const Element &element) {

    bool positionFound = false;


    for(Position<Element> itr= this->begin(); itr != this->end(); itr=++itr){
        /* funcio compara */
        int j=0;
        char c;
        char e;


        while (itr.operator*()[j] || element[j]){

            c=tolower(itr.operator*()[j]);
            e=tolower(element[j]);

            //comprovar ordre alfabetic:
            if(e < c){
                this->insertBefore(itr, element);
                positionFound = true;
                break;
            } else if (e > c){
                break;
            }else{
                j++;
            }
        }
        if(positionFound){
            break;
        }
    }
}

template <class Element>
void Registry<Element>::merge(const Registry &other) {

    for(Position<Element> other_itr = other.begin(); other_itr != this->end(); other_itr=++other_itr){
        this->insert(other_itr.element());
    }


}

template <class Element>
bool Registry<Element>::operator==(const Registry &other) const {

}
#endif //EXERCICI4_REGISTRY_H
