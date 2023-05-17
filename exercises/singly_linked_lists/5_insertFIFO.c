node *insert_fifo (node *l, int d){
    node *newNode;
    newNode = (node*) malloc (sizeof (node));
    newNode->data = d;
    newNode->next = NULL;  //bc now it's the last node
    if (l == NULL){
        return newNode;
    }
    node *temp = l;
    while (temp->next != NULL){
        temp = temp->next;
    }
    // now temp is the last node
    temp->next = newNode;
    return l;
}