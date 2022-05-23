#include "counter.h"
#include <cstring>

counter_node* counter_head = nullptr;


// returns pointer to the first element of the counter
const counter_node* get_first()
{
    return counter_head;
}

// returns pointer to the next element of the counter where
// current is a node in the counter
const counter_node* get_next(const counter_node* current)
{
    return current->next;
}

// returns true if list is empty, i.e. contains no elements
bool counter_is_empty()
{
    return get_first() == nullptr;
}

// returns number of elements in list
int counter_size()
{
    int node_count = 0;
    for (auto pnode = get_first(); pnode != nullptr; pnode = get_next(pnode))
        ++node_count;
    return node_count;
}

// removes all elements from the list
// returns pointer to the new head of the list
void counter_clear()
{
    while (!counter_is_empty())
    {
        auto toDelete = counter_head;
        counter_head = counter_head->next;
        delete [] toDelete->name;
        delete toDelete;
    }
}

// looks for element with the given name
// returns pointer to the element (counter_node) found
// or nullptr if the element is not found
const counter_node* counter_find(const char* name)
{
    for (auto pnode = get_first(); pnode != nullptr; pnode = get_next(pnode))
    {
        int comparison_result = strcmp(pnode->name, name);
        if (comparison_result == 0)
            return pnode;
        if (comparison_result > 0)
            break;
    }
    // name not found
    return nullptr;
}

// you have to implement this function

// returns reference to count member of counter node with given name
// if name is not present in the counter creates the new node
// with this name and count member set to 0
// IMPORTANT: counter preserves lexicographical order according to names
// IMPORTANT: counter_head should be properly modified if necessary

unsigned int& get_count(const char* name)
{
counter_node* curr = counter_head;
while(curr != nullptr){
    if(strcmp(name, curr->name) == 0){
        return curr->count;
    }
    curr = curr->next;
}

    counter_node* new_node = new counter_node;
    new_node->count = 0;
    int name_length = strlen(name);
    new_node->name = new char[name_length + 1]; // + 1 for '\0'
    strcpy(new_node->name, name);

    if(strcmp(name, counter_head->name) < 0 || counter_head == nullptr) {
        new_node->next = counter_head;
        counter_head = new_node;

    }else {
        counter_node* temp = counter_head;
        counter_node* prev = counter_head;

        while (temp != nullptr) {
            if (strcmp(name, temp->name) < 0) {
                prev->next = new_node;
                new_node->next = temp;
                break;
            }
            if(temp->next == nullptr){
                temp->next = new_node;
                new_node->next = nullptr;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return new_node->count;
}
