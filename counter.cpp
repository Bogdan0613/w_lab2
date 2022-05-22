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
    counter_node* new_node = new counter_node;
    new_node->name = new char[strlen(name)+1];
    strcpy(new_node->name, name);
    new_node->count = 0;
    new_node->next = counter_head;
    counter_head = new_node;
    return new_node->count;
}

