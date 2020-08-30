#include <vector>
#include <memory>

struct Graph {
    struct Node
    {
        using Ptr = std::shared_ptr<Node>;
        int val, idx;
        std::vector<Ptr> parents, children;
    };
    
    struct Edge
    {
        using Ptr = std::shared_ptr<Edge>;
        Node::Ptr from, to;
        int val;
    };
    
    std::vector<Node::Ptr> nodes;
    std::vector<Edge::Ptr> edges;

    Graph(int nodeNum = 0, int edgeNum = 0)
    : nodes(nodeNum)
    , edges(edgeNum) {
        for (size_t i = 0; i < nodeNum; i++)
        {
            nodes[i] = std::make_shared<Node>();
            nodes[i]->idx = i;
        }
        
        for (size_t i = 0; i < edgeNum; i++)
        {
            edges[i] = std::make_shared<Edge>();
        }
    }

};