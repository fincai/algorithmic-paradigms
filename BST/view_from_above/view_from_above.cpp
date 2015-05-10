#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


typedef enum {
    Blue, Black, Red
} Color;

template <typename XaxisType, typename ColorType, typename HeightType>
class LineSegment {
public:
    LineSegment(XaxisType l, XaxisType r, ColorType c, HeightType h) :
    left(l), right(r), color(c), height(h) { }
    XaxisType left, right;
    ColorType color;
    HeightType height;


    const bool operator<(const LineSegment & rhs) const
    { return height < rhs.height; }
};


template <typename XaxisType, typename ColorType, typename HeightType>
class Endpoint {
public:
    bool isLeft;
    const LineSegment<XaxisType, ColorType, HeightType> *l;

    Endpoint(bool isleft, const LineSegment<XaxisType, ColorType, HeightType> *line) :
    isLeft(isleft), l(line) { }

    const bool operator<(const Endpoint & rhs) const {
        return val() < rhs.val();
    }

    const XaxisType & val() const 
    { return isLeft ? l->left : l->right; }
};



template <typename XaxisType, typename ColorType, typename HeightType>
void view_from_above(const vector<LineSegment<XaxisType, ColorType, HeightType>> & S) {
    vector<Endpoint<XaxisType, ColorType, HeightType>> E;
    for (auto & line : S) {
        E.emplace_back(Endpoint<XaxisType, ColorType, HeightType>{true, &line});
        E.emplace_back(Endpoint<XaxisType, ColorType, HeightType>{false, &line});
    }
    sort(E.begin(), E.end());
    
    XaxisType prev_axis = E.front().val();
    shared_ptr<LineSegment<XaxisType, ColorType, HeightType>> prev = nullptr;
    map<HeightType, const LineSegment<XaxisType, ColorType, HeightType>*> T;   // BST store the current overlapping segments
    for (auto & e : E) {
        if (!T.empty() && prev_axis != e.val()) {
            if (prev == nullptr) {  // Found first segment
                prev = shared_ptr<LineSegment<XaxisType, ColorType, HeightType>>(
                        new LineSegment<XaxisType, ColorType, HeightType>{ 
                                     prev_axis, e.val(), T.crbegin()->second->color,
                                     T.crbegin()->second->height });
            } else {
                if (prev->height == T.crbegin()->second->height
                    && prev->color == T.crbegin()->second->color)
                    prev->right = e.val();
                else {
                    cout << "[" << prev->left << ", " << prev->right << "] "
                         << "color = " << prev->color << ", height = " 
                         << prev->height << endl;
                    *prev = {prev_axis, e.val(), T.crbegin()->second->color,
                                                 T.crbegin()->second->height};
                }
            }
        }

        if (e.isLeft) 
            T.emplace(e.l->height, e.l);
        else
            T.erase(e.l->height);
        prev_axis = e.val();
    }

    if (prev) {
        cout << "[" << prev->left << ", " << prev->right << "] "
             << "color = " << prev->color << ", height = " 
             << prev->height << endl;
    }
}

int main() {
    vector<LineSegment<int, Color, int>> overlapped_segments;
    overlapped_segments.emplace_back(1, 4, Blue, 3);
    overlapped_segments.emplace_back(3, 7, Red, 5);
    overlapped_segments.emplace_back(9, 13, Black, 3); 

    view_from_above(overlapped_segments);
    
    return 0;
}
