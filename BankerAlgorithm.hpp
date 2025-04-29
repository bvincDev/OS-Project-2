#ifndef BANKERALGORITHM_HPP
#define BANKERALGORITHM_HPP

#include <vector>

class Banker {
public:
    // P - processes
    // R -  resource types
    Banker(int P, int R,
           const std::vector<std::vector<int>>& alloc,
           const std::vector<std::vector<int>>& maxd,
           const std::vector<int>& avail);

    // Checks if the system is in a safe state
    bool isSafe();

    // Return the safe sequence that was found
    std::vector<int> getSequence() const;

private:
    int P, R;
    std::vector<std::vector<int>> alloc, maxd, need;
    std::vector<int> avail;
    std::vector<int> seq;
};

#endif