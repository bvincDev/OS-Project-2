#include "BankerAlgorithm.hpp"
#include <fstream>
#include <iostream>

// constructor
Banker::Banker(int P, int R,
               const std::vector<std::vector<int>>& alloc_,
               const std::vector<std::vector<int>>& maxd_,
               const std::vector<int>& avail_)
    : P(P), R(R), alloc(alloc_), maxd(maxd_), avail(avail_) {
    need.resize(P, std::vector<int>(R));
    for (int i = 0; i < P; ++i)
        for (int j = 0; j < R; ++j)
            need[i][j] = maxd[i][j] - alloc[i][j];
}

bool Banker::isSafe() {
    std::vector<bool> done(P, false); // finished processes
    std::vector<int> work = avail; // available resources
    int finished = 0;

    // keep picking processes until all are finished
    while (finished < P) {
        bool found = false;
        for (int i = 0; i < P; ++i) {
            if (done[i]) continue;
            // check if need[i][*] <= work[*]
            bool ok = true;
            for (int j = 0; j < R; ++j) {
                if (need[i][j] > work[j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            // process i can proceed
            for (int j = 0; j < R; ++j)
                work[j] += alloc[i][j];
            done[i] = true;
            seq.push_back(i);
            found = true;
            break;
        }
        if (!found) {
            // if no process can proceed it is an unsafe state
            return false;
        }
        ++finished;
    }
    return true;
}

std::vector<int> Banker::getSequence() const { return seq; }

int main() {
    std::ifstream in("input.txt");
    int P, R; in >> P >> R;

    // Read allocation and max demand matrices
    std::vector<std::vector<int>> alloc(P, std::vector<int>(R));
    for (auto& row : alloc)
        for (int& x : row) in >> x;

    std::vector<std::vector<int>> maxd(P, std::vector<int>(R));
    for (auto& row : maxd)
        for (int& x : row) in >> x;

    std::vector<int> avail(R);
    for (int& x : avail) in >> x;



    // Run the Banker algorithm
    Banker banker(P, R, alloc, maxd, avail);
    if (banker.isSafe()) {
        std::cout << "Safe state. Sequence: ";
        for (int i : banker.getSequence())
            std::cout << "P" << i << ' ';
        std::cout << '\n';
    } else {
        std::cout << "Not a safe state!\n";
    }
    return 0;
}