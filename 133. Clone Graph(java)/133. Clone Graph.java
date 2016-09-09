/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node == null) {
            return null;
        }
        UndirectedGraphNode new_node = new UndirectedGraphNode(node.label);
        HashMap<UndirectedGraphNode, UndirectedGraphNode> hash = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        hash.put(node, new_node);
        ArrayList<UndirectedGraphNode> list = new ArrayList<UndirectedGraphNode>();
        list.add(node);
        while(!list.isEmpty()) {
            ArrayList<UndirectedGraphNode> tmp = new ArrayList<UndirectedGraphNode>();
            for(UndirectedGraphNode item : list) {
                ArrayList<UndirectedGraphNode> new_neighbors = new ArrayList<UndirectedGraphNode>();
                for(UndirectedGraphNode neighbor : item.neighbors) {
                    if(!hash.containsKey(neighbor)){
                        UndirectedGraphNode n = new UndirectedGraphNode(neighbor.label);
                        hash.put(neighbor, n);
                        tmp.add(neighbor);
                        new_neighbors.add(n);
                    } else {
                        new_neighbors.add(hash.get(neighbor));
                    }
                }
                hash.get(item).neighbors = new_neighbors; 
            }
            list = tmp;
        }
        return new_node;
    }
}
