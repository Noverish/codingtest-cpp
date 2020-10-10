#include "../common.hpp"

#define CITY_MAX 10000
#define MODULO 10007
#include <unordered_map>

vector<tuple<string, string, string, vector<vector<string>>>> inputs = {
    {"SEOUL", "DAEGU", "YEOSU", {{"ULSAN","BUSAN"},{"DAEJEON","ULSAN"},{"DAEJEON","GWANGJU"},{"SEOUL","DAEJEON"},{"SEOUL","ULSAN"},{"DAEJEON","DAEGU"},{"GWANGJU","BUSAN"},{"DAEGU","GWANGJU"},{"DAEGU","BUSAN"},{"ULSAN","DAEGU"},{"GWANGJU","YEOSU"},{"BUSAN","YEOSU"}}},
    {"ULSAN", "SEOUL", "BUSAN", {{"SEOUL","DAEJEON"},{"ULSAN","BUSAN"},{"DAEJEON","ULSAN"},{"DAEJEON","GWANGJU"},{"SEOUL","ULSAN"},{"DAEJEON","BUSAN"},{"GWANGJU","BUSAN"}}}
};

int outputs[] = {
    9,
    0
};

vector<int> rel[CITY_MAX];
vector<int> visit;

long long backtracking(int n, int dest) {
    if (n == dest) {
        return 1;
    }
    visit[n] = 1;
    long long sum = 0;
    for(int next: rel[n]) {
        if (!visit[next]) {
            sum = (sum + backtracking(next, dest)) % MODULO;
        }
    }
    visit[n] = 0;
    return sum;
}

int solution(string depar, string hub, string dest, vector<vector<string>> roads) {
    fill(visit.begin(), visit.end(), 0);
    for(int i = 0; i < CITY_MAX; i++) {
        rel[i].clear();
    }

    unordered_map<string, int> map;
    for(vector<string> &road: roads) {
        string from = road[0];
        string to = road[1];

        int fromi = 0;
        if (map.count(from) == 0) {
            fromi = map.size();
            map.emplace(from, fromi);
        } else {
            fromi = map.at(from);
        }

        int toi = 0;
        if (map.count(to) == 0) {
            toi = map.size();
            map.emplace(to, toi);
        } else {
            toi = map.at(to);
        }

        rel[fromi].push_back(toi);
    }
    int city_num = map.size();
    visit.resize(city_num);

    long long cnt1 = backtracking(map.at(depar), map.at(hub)) % MODULO;
    long long cnt2 = backtracking(map.at(hub), map.at(dest)) % MODULO;

    return (cnt1 * cnt2) % MODULO;
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "쿠팡 - 4" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(get<0>(input), get<1>(input), get<2>(input), get<3>(input));

        if (real == expected) {
            cout << GREEN << "success" << NO_COLOR << endl;
        } else {
            cout << RED << "failed" << endl;
            cout << "  real:     "  << real << endl;
            cout << "  expected: " << expected << NO_COLOR << endl;
        }
    }
}