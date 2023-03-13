#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

#include <exception>


//struct SortedIndexedList::DLLNode	{
//    TComp info;
//    PNode next;
//    PNode prev;
//    DLLNode(TComp e, PNode n, PNode p);
//};

SortedIndexedList::DLLNode::DLLNode(TComp e, PNode n, PNode p) {
    info = e;
    next = n;
    prev = p;
    //current_index = i;
} // Theta(1)

SortedIndexedList::SortedIndexedList(Relation r) {
    //TODO - Implementation
    head = nullptr;
    tail = nullptr;
    relation = r;
    total_size = 0;
} // Theta(1)

int SortedIndexedList::size() const {
    return total_size;

} // Theta(1)

bool SortedIndexedList::isEmpty() const {
    return total_size == 0;
} // Theta(1)

TComp SortedIndexedList::getElement(int i) const {
    //TODO - Implementation
//    ListIterator it= ListIterator(*this);
//    it.first();
//    while(it.valid()){
//        //TComp cur_head = it.getCurrent();
//        if(i == cur_head->current_index){
//            return cur_head->info;
//        }
//    }
    PNode cur_head = this->head;
    int contor =0;
    while (cur_head != nullptr) {
        if (i == contor) {
            return cur_head->info;
        }
        contor++;
        cur_head = cur_head->next;
    }
    throw exception();

} // O(n)

TComp SortedIndexedList::remove(int i) {
    if (i < 0 || i >= this->total_size) {
        throw exception();
    }
    PNode cur_head = this->head;
    int contor = 0;
    while (cur_head != nullptr and contor < i) {
        cur_head = cur_head->next;
        contor++;
    }
    if (cur_head == nullptr) {
        return NULL_TCOMP;
    }

    PNode prev_node;
    if(i==0)     ///!
        prev_node = nullptr;
    else
        prev_node = cur_head->prev;
    PNode next_node = cur_head->next;

    if (prev_node == nullptr) { // head current node  DeleteBeforeHead
        this->head = next_node;
        //this->head->prev = nullptr;

    } else if (next_node == nullptr) { // tail  DeleteLast

        this->tail = prev_node;
        this->tail->next = nullptr; ///
    }
//    else if(cur_head==this->tail){ // DeleteLast
//        this->tail = cur_head->prev; // tail becomes the before last elem
//        this->tail->next = nullptr;
//    }
    else { // in between delete;;;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
    TComp val = cur_head->info;
    free(cur_head);
    this->total_size--;
    return val;
} // O(n)

int SortedIndexedList::search(TComp e) const {
    //TODO - Implementation
    PNode cur_head = this->head;
    int contor = 0;
    while (cur_head != nullptr) {
        if (e == cur_head->info) {
            return contor;
        }
        contor++;
        cur_head = cur_head->next;
    }
    return -1;

} // o(n) - return somewhere

void SortedIndexedList::add(TComp e) {
    PNode cur_head = this->head;
    while (cur_head != nullptr && this->relation(cur_head->info, e)) {
        cur_head = cur_head->next;
        if(cur_head!= nullptr and cur_head->info == e){
            break;
        }
    }
    if (cur_head == nullptr) {
        PNode new_node = new DLLNode(e, nullptr, this->tail);
        if(this->tail!= nullptr) // new_tail, add to the end
            this->tail->next = new_node;
        else
            this->head = new_node; // empty list
        this->tail = new_node;
    } else { // prima pozitie
        PNode prev_node = cur_head->prev;
        PNode next_node = cur_head->next;
        if (prev_node == nullptr) { // add before head
            PNode new_node = new DLLNode(e, cur_head, nullptr);
            cur_head->prev = new_node;
            this->head = new_node;

//        } else if (next_node == nullptr) { // tail last el
//            PNode new_node = new DLLNode(e, nullptr, cur_head);
//            cur_head->next = new_node;
//            this->tail = new_node;
        } else {
//            PNode new_node = new DLLNode(e, cur_head, prev_node);
            PNode new_node = new DLLNode(e, nullptr, nullptr);

//            prev_node->next = new_node;
//            new_node->prev=prev_node; // ca si sus
//            ///next_node->prev = new_node;
//            cur_head->prev = new_node;
//            new_node->next = cur_head; // ca si sus

             cur_head->prev->next = new_node;
             new_node->prev = cur_head->prev;
             cur_head->prev = new_node;
             new_node->next = cur_head;
        }
    }
    this->total_size++;
} // Thetao(n)

ListIterator SortedIndexedList::iterator() {
    return ListIterator(*this);
} // Theta(1)

//destructor
SortedIndexedList::~SortedIndexedList() {
    //TODO - Implementation
    while (head != nullptr) {
        PNode p = head;
        head = head->next;
        delete p;
    }
} // Theta(n)
