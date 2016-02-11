#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
using namespace std;

template <typename T>
class Compare {
public:
    bool operator() (const pair<T, int> & lhs,
                           const pair<T, int> & rhs) const
    { return lhs.first > rhs.first; }
};

template <typename T>
vector<T> merge_arrays(const vector<vector<T>> & files) {
    priority_queue<pair<T, int>, vector<pair<T, int>>, Compare<T>> min_heap;
    vector<int> idx(files.size(), 0);

    for (int i = 0; i < files.size(); ++i) {
        if (files[i].size() > 0) {
            min_heap.emplace(files[i][0], i);
            ++idx[i];
        }
    }

    vector<T> ret;
    while (!min_heap.empty()) {
        pair<T, int> p = min_heap.top();
        ret.emplace_back(p.first);

        if (idx[p.second] < files[p.second].size()) {
           min_heap.emplace(files[p.second][idx[p.second]++], p.second);
        }
        min_heap.pop();
        
    }
    return ret;
}

int main() {
    vector<vector<int>> files(3);
    files[0] = {4, 6, 8};
    files[1] = {1, 5, 7};
    files[2] = {2, 3, 9};
    
    vector<int> merged_file = merge_arrays(files);
    
    for (auto & trade : merged_file) 
        cout << trade << endl;
    
    return 0;
}
