#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {10, 4, 6, 3, 66, 41};

    auto maxp = max_element(v.begin(), v.end());
    int maxIndex = distance(v.begin(), maxp);
    int max = *maxp;
    cout << "max index: " << maxIndex << ", value: " << max << endl;

    auto minp = min_element(v.begin(), v.end());
    int minIndex = distance(v.begin(), minp);
    int min = *minp;
    cout << "min index: " << minIndex << ", value: " << min << endl;

    auto minmaxp = minmax_element(v.begin(), v.end());
    int minIndex2 = distance(v.begin(), minmaxp.first);
    int maxIndex2 = distance(v.begin(), minmaxp.second);
    int min2 = *minmaxp.first;
    int max2 = *minmaxp.second;
    cout << "max index: " << maxIndex2 << ", value: " << max2 << endl;
    cout << "min index: " << minIndex2 << ", value: " << min2 << endl;

    return 0;
}
