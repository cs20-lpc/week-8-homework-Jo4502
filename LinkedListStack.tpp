template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    
    while (!isEmpty()) {             // loop until stack is empty
        pop();                      
    }

}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    
    if (copyObj.isEmpty()) {         // if empty return
        return;                     
    }

    Node<T>* srcPtr = copyObj.top;     
    top = new Node<T>(srcPtr->data);    // copy the first node
    Node<T>* destPtr = top;             
    srcPtr = srcPtr->next;   
    
    while (srcPtr != nullptr) {                     // copy the rest of the nodes
        destPtr->next = new Node<T>(srcPtr->data); 
        destPtr = destPtr->next;                
        srcPtr = srcPtr->next;                 
    }

    this->length = copyObj.length;         
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if (isEmpty()) {
        throw string("Stack is empty!\n");
    }

    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) {
        throw string("Stack empty!\n");
    }

    Node<T>* temp = top;
    top = top->next;
    delete temp;
    this->length--;

}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;            

}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate

    if (isEmpty() || top->next == nullptr) {
        return; 
    }

    if (dir == Stack<T>::RIGHT) {
        
        Node<T>* temp = top;
        top = top->next;
                                    //// move top to bottom
        Node<T>* curr = top;
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = temp;
        temp->next = nullptr;
    }
    else { // LEFT
        Node<T>* curr = top;
        while (curr->next->next) {          // move bottom to top
            curr = curr->next;
        }

        Node<T>* last = curr->next;
        curr->next = nullptr;
        last->next = top;
        top = last;
    }

}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
