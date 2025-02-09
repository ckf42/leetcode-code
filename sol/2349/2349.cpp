#include <unordered_map>

struct NumberContainers {
    unordered_map<int, int> m_map;
    unordered_map<int, vector<int>> m_indexHeap;

    NumberContainers() {}
    
    void change(int index, int number) {
        m_map[index] = number;
        m_indexHeap[number].push_back(-index);
        ranges::push_heap(m_indexHeap[number]);
    }
    
    int find(int number) {
        if (!m_indexHeap.contains(number)){
            return -1;
        }
        while (!m_indexHeap[number].empty()){
            int idx = -m_indexHeap[number][0];
            if (m_map[idx] == number){
                return idx;
            }
            ranges::pop_heap(m_indexHeap[number]);
            m_indexHeap[number].pop_back();
        }
        return -1;
    }
};

