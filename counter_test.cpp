#include "counter.h"
#include <cstring>
#include <iostream>


// this can be useful in testing
void print_counter(std::ostream& os)
{
    os << '[';
    for (auto ptr = get_first(); ptr != nullptr; ptr = get_next(ptr))
    {
        os << "(" << ptr->name << " : " << ptr->count << ") ";
    }
    os << "]\n";
}

int main()
{
    print_counter(std::cout);
    for (unsigned int i = 1; i < 4; ++i)
    {
        unsigned int& return_reference = get_count("class");
        return_reference += 1;
        if (counter_size() != 1)
            std::cerr << "Error in \"class\" iteration #" << i << " - wrong size.\n";
        if (get_first()->count != i)
            std::cerr << "Error in \"class\" iteration #" << i << " - wrong count.\n";
        if (strcmp(get_first()->name, "class") != 0)
            std::cerr << "Error in \"class\" iteration #" << i << " - wrong name.\n";
        print_counter(std::cout);
    }

    counter_clear();
    get_count("cccc") = 3;
    if (counter_size() != 1)
        std::cerr << "Error in \"abcd\" iteration #1 - wrong size.\n";
    if (get_first()->count != 3)
        std::cerr << "Error in \"abcd\" iteration #1 - wrong count.\n";
    print_counter(std::cout);

    get_count("aaaa") = 1;
    if (counter_size() != 2)
        std::cerr << "Error in \"abcd\" iteration #2 - wrong size.\n";
    if (get_first()->count != 1)
        std::cerr << "Error in \"abcd\" iteration #2 - wrong count.\n";
    print_counter(std::cout);

    get_count("bbbb") = 2;
    if (counter_size() != 3)
        std::cerr << "Error in \"abcd\" iteration #3 - wrong size.\n";
    // "bbbb" should be the second element in the counter
    const counter_node* pnode = get_first();
    pnode = get_next(pnode);
    if (strcmp(pnode->name, "bbbb") != 0)
        std::cerr << "Error in \"abcd\" iteration #3 - wrong name in the second node.\n";
    print_counter(std::cout);

    get_count("dddd") = 4;
    if (counter_size() != 4)
        std::cerr << "Error in \"abcd\" iteration #4 - wrong size.\n";
    // "dddd" should be the fourth element in the counter
    pnode = get_first();
    pnode = get_next(pnode);
    pnode = get_next(pnode);
    pnode = get_next(pnode);
    if (strcmp(pnode->name, "dddd") != 0)
        std::cerr << "Error in \"abcd\" iteration #4 - wrong name in the fourth node.\n";
    print_counter(std::cout);

    // final pass - looks rather weird
    get_count("aaaa") *= 5;
    get_count("bbbb") *= 5;
    get_count("cccc") *= 5;
    get_count("dddd") *= 5;
    pnode = counter_find("aaaa");
    if (pnode->count != 5)
        std::cerr << "Error in final pass - wrong \"aaaa\" count.\n";
    pnode = counter_find("bbbb");
    if (pnode->count != 10)
        std::cerr << "Error in final pass - wrong \"bbbb\" count.\n";
    pnode = counter_find("cccc");
    if (pnode->count != 15)
        std::cerr << "Error in final pass - wrong \"cccc\" count.\n";
    pnode = counter_find("dddd");
    if (pnode->count != 20)
        std::cerr << "Error in final pass - wrong \"dddd\" count.\n";
    print_counter(std::cout);

    std::cerr << "End of tests.\n";
    return 0;
}


