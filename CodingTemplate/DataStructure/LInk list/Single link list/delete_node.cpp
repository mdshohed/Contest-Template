
void delete_node( int x ) {

    Node *current_node = head;
    Node *previous_node = NULL;

    while( current_node->data != x ) {

        previous_node = current_node;
        current_node = current_node->next;
    }
    if ( current_node == head) {
        Node *temp = head;
        head = head->next;
        delete(temp);
    }
    else {
        previous_node->next = current_node->next;
        delete(current_node);
    }
}
