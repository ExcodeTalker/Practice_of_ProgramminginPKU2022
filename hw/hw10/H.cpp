#include <set>
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码

class myComp{
    public:
    bool operator() (const pair<int, int> a, const pair<int, int> b) const {
        if ((a.first > 0) && (b.first > 0) && (a.second > 0) && (b.second > 0)) {
            a.first < b.first && a.second > b.second;
        } else if ((a.first < 0) || (b.first < 0)) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
             
    }
};

int main() {
	string cmd;
	set<pair<int, int>, myComp> S;
	while (cin >> cmd) {
		if (cmd == "A") {
			int x, y;
			cin >> x >> y;
			S.insert(make_pair(x, y));
		} else if (cmd == "Qx") {
			int x;
			cin >> x;
			cout << S.lower_bound(make_pair(x, -1))->second << endl;
		} else if (cmd == "Qy") {
			int y;
			cin >> y;
			cout << S.lower_bound(make_pair(-1, y))->first << endl;
		} else {
			int x, y;
			cin >> x >> y;
			S.erase(make_pair(x, y));
		}
	}
	return 0;
}