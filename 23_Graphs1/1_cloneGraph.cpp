class Solution {
public:
    vector <Node*> nodeRegister;

    void dfs(Node* actual, Node* clone){
        // actual->neighbour yaani Node* wale vector se ek ek karke neighbor nodes laake dega...
        for (auto neighbor: actual->neighbors){
            if (not nodeRegister[neighbor->val]){   // NULL ke alawa kucch aur hoga tabhi condition true hogi..

                // create the neighbor for the first time...
                Node* newNode = new Node(neighbor->val);
                nodeRegister[newNode -> val] = newNode;
                clone->neighbors.push_back(newNode);
                dfs(neighbor, newNode);
            }
            else{   // agar already created hai to nodeRegistr mai se leke aa jaunga..
                clone->neighbors.push_back(nodeRegister[neighbor->val]);
            }
        }

    }


    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* clone = new Node(node->val);

        nodeRegister.resize(110, NULL); // kyuki constraint 100 size tak hi hai node size
        nodeRegister[clone->val] = clone;   // nodeRegistry mai index node ki value and and nodeRegistry mai value us node ka address stored hai....

        // traverse and create
        dfs(node, clone);

        return clone;

    }
};

/*
jaha se start kar rahe hai.. wo node to banayenge hi....... 
uske alawa then uske neighbours par iterate karenge..... agar wo neghbour pehle se created hoga to bas ek edge connect kar denge....
else 
     us node ko new create karke edge connect kar denge....


index denoting node->value   and   value at index denotes the address of the node in nodeRegistry.....


capital N wala Node class ka naam hai...and usme se leke node naam mene ek object banaya...


*/