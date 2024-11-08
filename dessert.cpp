#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> friends(N);
    vector<int> requiredFriends(N);
    vector<bool> ordered(N, false);
    vector<int> friendsOrderedCount(N, 0);

    for (int i = 0; i < N; i++) {
        int Mi, Li;
        cin >> Mi >> Li;
        requiredFriends[i] = Li;

        for (int j = 0; j < Mi; j++) {
            int friend_id;
            cin >> friend_id;
            friends[i].push_back(friend_id);
        }
    }

    queue<int> orderQueue;

    for (int i = 0; i < N; i++) {
        if (requiredFriends[i] == 0) {
            orderQueue.push(i);
            ordered[i] = true;
        }
    }

    while (!orderQueue.empty()) {
        int current = orderQueue.front();
        orderQueue.pop();

        for (int friend_id : friends[current]) {
            friendsOrderedCount[friend_id]++;

            if (!ordered[friend_id] && 
                friendsOrderedCount[friend_id] >= requiredFriends[friend_id]) {
                orderQueue.push(friend_id);
                ordered[friend_id] = true;
            }
        }
    }

    int dessertCount = 0;
    for (bool status : ordered) {
        if (status) {
            dessertCount++;
        }
    }

    cout << dessertCount << endl;

    return 0;
}