/* The general stable counting sort with additional O(n) space
 * The time complexity is O(nlogk + klogk)
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


template <typename KeyType>
class Person {
public:
    Person() { }
    Person(KeyType k, int i): key(k), id(i) { }
    KeyType key;
    int id;
};


template <typename KeyType>
void counting_sort(vector<Person<KeyType>> & people, 
                   vector<Person<KeyType>> & result) {
    map<KeyType, int> key_to_count, key_to_offset;
    for (auto & person : people)
        ++key_to_count[person.key];
    int offset = 0;
    for (auto & p : key_to_count) {
        key_to_offset[p.first] = offset;
        offset += p.second;
    }

    for (auto & person : people) {
        result[key_to_offset[person.key]] = person;
        ++key_to_offset[person.key];
    }
}

int main() {
   vector<Person<string>> people;
   people.emplace_back("c", 1);
   people.emplace_back("f", 1);
   people.emplace_back("d", 1);
   people.emplace_back("a", 1);
   people.emplace_back("c", 2);
   people.emplace_back("d", 2);

   vector<Person<string>> result(people.size());
   counting_sort(people, result);
   
   for (auto & p : result) 
       cout << p.key << p.id << endl;

   return 0;
}
