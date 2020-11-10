/*print element*/
void Print(Node *head)
{
    Node *current = head;

    while (current != NULL) {
        cout << current -> data << endl;
        current = current -> next;
    }
}
