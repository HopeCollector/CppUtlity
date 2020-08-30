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
            nodes[i]->val = 0;
        }
        
        for (size_t i = 0; i < edgeNum; i++)
        {
            edges[i] = std::make_shared<Edge>();
            edges[i]->val = 0;
        }
    }

    Node::Ptr addNode(int val = 0) {
        int idx = 0;
        if(!nodes.empty()) idx = nodes.back()->idx+1;
        
        nodes.push_back(std::make_shared<Node>());
        auto ptr = nodes.back();
        ptr->idx = idx;
        ptr->val = val;

        return ptr;
    }

    Edge::Ptr addEdge(Node::Ptr from, Node::Ptr to, int val = 0) {
        edges.push_back(std::make_shared<Edge>());
        auto ptr = edges.back();

        ptr->from = from;
        ptr->to = to;
        ptr->val = val;

        return ptr;
    }

    inline Edge::Ptr addEdge(int from, int to, int val = 0) {return addEdge(nodes[from], nodes[to], val);}

};