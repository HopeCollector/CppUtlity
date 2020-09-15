#include <vector>
#include <iostream>
#include <memory>

template<typename T>
class Graph {
public:
    struct Node {
        using Ptr = std::shared_ptr<Node>;
        T data;
        size_t idx;
        std::vector<std::pair<Ptr, int>> children;
        Node() {}
        Node(size_t i) : idx(i) , data(), children() {}
    };

    std::vector<typename Node::Ptr> nodes;
    Graph(){}
    Graph(size_t n) : nodes(n) {
        for (size_t i = 0; i < n; i++)
        {
            nodes[i] = std::make_shared<Node>(i);
        }
        
    }
};

int main() {
    int m, n, T;
    std::cin >> n >> m >> T;

    Graph<size_t> g(n);
    auto& nodes = g.nodes;
    

    int x, y, d;
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> x >> y >> d;
        nodes[x-1]->children.emplace_back(nodes[y-1], d);
    }

    for(auto node : nodes) {
        std::cout << node->idx << ": ";
        for(auto [child, d] : node->children)
            std::cout << "(" << child->idx << ", " << d << ") ";
        std::cout << std::endl;
    }

    return 0;
}