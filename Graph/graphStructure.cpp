#include <vector>
#include <memory>

class Graph {
public:
    struct Node
    {
        using Ptr = std::shared_ptr<Node>;
        int val;
        std::vector<Ptr> parents, children;
    };
    
};