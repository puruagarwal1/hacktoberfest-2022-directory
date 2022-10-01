#include <vector>
#include <iostream>

int main() {
    std::vector<int> queue = std::vector<int>({82,170,43,140,24,16,190});
    int head = 50;

    int m;
    int diff;
    int total_head_movement = 0;
    while (!queue.empty()) {
        m = queue[0];
        queue.erase(queue.begin());

        diff = head >= m ? head-m : m-head;
        total_head_movement += diff;
        head = m;
    }

    std::cout<<"Total Head Movement: "<<total_head_movement;
    return 0;
}
