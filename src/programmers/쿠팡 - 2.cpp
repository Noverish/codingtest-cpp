#include "../common.hpp"

#include <unordered_map>

vector<tuple<int, vector<string>>> inputs = {
    {3, {"10/01 23:20:25 30", "10/01 23:25:50 26", "10/01 23:31:00 05", "10/01 23:33:17 24", "10/01 23:50:25 13", "10/01 23:55:45 20", "10/01 23:59:39 03", "10/02 00:10:00 10"}},
    {2, {"02/28 23:59:00 03","03/01 00:00:00 02", "03/01 00:05:00 01"}}
};

int outputs[] = {
    4, 2
};

int solution(int n, vector<string> customers) {
    vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    for(int i = 1; i < months.size(); i++) {
        months[i] += months[i - 1];
    }

    vector<pair<int, int>> arrive(customers.size());
    for(int i = 0; i < customers.size(); i++) {
        string s = customers[i];
        int month = stoi(s.substr(0, 2));
        int date = stoi(s.substr(3, 2));
        int hour = stoi(s.substr(6, 2));
        int min = stoi(s.substr(9, 2));
        int sec = stoi(s.substr(12, 2));
        int duration = stoi(s.substr(15, 2));
        arrive[i] = {
            (months[month - 1] * 86400) + (date * 86400) + (hour * 3600) + (min * 60) + sec,
            duration * 60
        };
    }

    vector<int> status(n);
    vector<int> people(n);
    for(int i = 0; i < arrive.size(); i++) {
        int now = arrive[i].first;
        int duration = arrive[i].second;

        int waiting_min = INT_MAX, working_min = INT_MAX;
        int waiting_mini = -1, working_mini = -1;
        for(int j = 0; j < n; j++) {
            if (status[j] <= now && waiting_min > status[j]) {
                waiting_min = status[j];
                waiting_mini = j;
            }
            if (status[j] > now && working_min > status[j]) {
                working_min = status[j];
                working_mini = j;
            }
        }

        // 대기중인 키오스크가 있다. 
        if (waiting_mini != -1) {
            status[waiting_mini] = now + duration;
            people[waiting_mini]++;
        } else {
            status[working_mini] += duration;
            people[working_mini]++;
        }
    }

    return *max_element(people.begin(), people.end());
}

int main() {
    string GREEN="\033[0;32m";
    string RED="\033[0;31m";
    string NO_COLOR="\033[0m";

    cout << "쿠팡 - 2" << endl;
    for (int i = 0; i < inputs.size(); i++) {
        auto input = inputs[i];
        auto expected = outputs[i];
        auto real = solution(get<0>(input), get<1>(input));

        if (real == expected) {
            cout << GREEN << "success" << NO_COLOR << endl;
        } else {
            cout << RED << "failed" << endl;
            cout << "  real:     "  << real << endl;
            cout << "  expected: " << expected << NO_COLOR << endl;
        }
    }
}