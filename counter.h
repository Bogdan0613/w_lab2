#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED

// Rajmund Kozuszek (121528)

struct counter_node {
    char *name;
    unsigned int count;
    counter_node *next;
};


extern counter_node* counter_head;

const counter_node* get_first();
// returns pointer to the first element of the counter

const counter_node* get_next(const counter_node* current);
// returns pointer to the next element of the counter where
// current is a node in the counter

bool counter_is_empty();
// returns true if list is empty, i.e. contains no elements

int counter_size();
// returns number of elements in list

void counter_clear();
// removes all elements from the list
// returns pointer to the new head of the list

const counter_node* counter_find(const char* name);
// looks for element with the given name
// returns pointer to the element (counter_node) found
// or nullptr if the element is not found

// you have to implement this function

unsigned int& get_count(const char* name);
// returns reference to count member of counter node with given name
// if name is not present in the counter creates the new node
// with this name and count member set to 0
// IMPORTANT: counter preserves lexicographical order according to names
// IMPORTANT: counterHead should be properly modified if necessary

#endif // SLLIST_H_INCLUDED
