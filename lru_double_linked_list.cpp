#include <unordered_map>

struct Node
{
    int key_;
    int value_;
    Node* next_;
    Node* prev_;
    Node(int key, int value): key_(key), value_(value), prev_(nullptr), next_(nullptr) {}
};

class LRUCache {
    Node* head_;
    Node* tail_;  
    int capacity_;
    std::unordered_map<int, Node*> key_nodes;
public:
    LRUCache(int capacity) : capacity_(capacity){
        head_ = new Node(-1, -1);
        tail_ = new Node(-1, -1);
        head_->next_ = tail_;
        tail_->prev_ = head_;
    }
    
    int get(int key) {
        auto iter = key_nodes.find(key);
        if(iter != key_nodes.end())
        {
            erase_node(iter->second);
            add_node(iter->second);
            return iter->second->value_;
        }
        else
        {
            return -1;
        }
    }

    void erase_node(Node* node_link)
    {
        node_link->prev_->next_ = node_link->next_;
        node_link->next_->prev_ = node_link->prev_;
        node_link->prev_ = nullptr;
        node_link->next_ = nullptr;
    }
    
    void add_node(Node* node_link)
    {
        node_link->prev_ = tail_->prev_;
        tail_->prev_->next_ = node_link;
        node_link->next_ = tail_;
        tail_->prev_ = node_link;        
    }

    void put(int key, int value) {
        auto iter = key_nodes.find(key);
        if(iter != key_nodes.end())
        {
            iter->second->value_ = value;
            erase_node(iter->second);
            add_node(iter->second);
        }
        else
        {   
            Node* node_link (nullptr);
            if (key_nodes.size() == capacity_)
            {
                auto iter = key_nodes.find(head_->next_->key_);
                erase_node(iter->second);
                node_link = iter->second;
                key_nodes.erase(iter);
                node_link->key_ = key;
                node_link->value_ = value;
            }
            else
            {
                node_link = new Node(key, value);
            }
            add_node(node_link);
            key_nodes.emplace(key, node_link);
        }
    }
};