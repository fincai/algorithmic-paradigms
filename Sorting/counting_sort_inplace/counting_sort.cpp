/* The general inplace counting sort by swapping (not stable) */
/* O(nlogk + klogk) time complexity with additional O(k) space */
/* The stable counting sort requires addtional O(n) space */
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

template <typename KeyType>
class Person {
public:
    Person(int i, string k) : id(i), key(k) { }
    int id;
    string key;
};

template <typename KeyType>
void counting_sort(vector<Person<KeyType>> & people) {
    map<KeyType, int> key_to_count;
    for (auto & p : people)
        ++key_to_count[p.key];

    map<KeyType, int> key_to_offset;
    int offset = 0;
    for (auto & p : key_to_count) {
        key_to_offset[p.first] = offset;
        offset += p.second;
    }

    while (key_to_offset.size()) {
        auto from = key_to_offset.begin();
        auto to = key_to_offset.find(people[from->second].key);
        swap(people[from->second], people[to->second]);
        if (--key_to_count[to->first])
            ++to->second;
        else
            key_to_offset.erase(to);
    }
}


int main() {
    vector<Person<string>> people;
    people.emplace_back(1, "Upper");
    for (int i = 1; i <= 3; ++i)
        people.emplace_back(i, "Middle");
    for (int j = 1; j <= 4; ++j)
        people.emplace_back(j, "Lower");
    people.emplace_back(2, "Upper");

    counting_sort(people);

    for (auto & p : people)
        cout << p.key << " class person "
             << p.id << endl;

    return 0;
}
