/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(!head) return nullptr;
       unordered_map<Node*,Node*> mp;
       Node dummy(0);
    //    Node* copy = &dummy;
       auto init = head;
       auto copy = new Node(head->val);
       mp[head]=copy;
       auto res = copy; 
    
       while(head->next)
       {
            copy->next=new Node(head->next->val);
            mp[head->next]=copy->next;
            head=head->next;
            copy=copy->next;
       }
       copy=res;
       while(init)
       {
        res->random = mp[init->random];
        init=init->next;
        res=res->next;
       }
        return copy;

    }
};
