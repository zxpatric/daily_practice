#incldue <unordered_map>

struct Node
{
    int key_;
    int value_;
    Node* next_;
    Node(int key, int value): key_(key), value_(value), next_(nullptr) {}
};

class LRUCache {
    Node* head_;
    Node* tail_;  
    int capacity_;
    int count_;
    std::unordered_map<int, Node*> key_nodes;
public:
    LRUCache(int capacity) : count_(0), capacity_(capacity), head_(nullptr), tail_(nullptr){

    }
    
    int get(int key) {
        auto iter = key_nodes.find(key);
        if(iter != key_nodes.end())
        {
            move_to_end(iter->second);
            return iter->second->value_;
        }
        else
        {
            return -1;
        }
    }

    void move_to_end(Node* node_link)
    {
        if (node_link != tail_)
        {
            if (head_ == node_link)
            {
                head_ = node_link->next_;
            }
            node_link->next_ = node_link->next_->next_;
            tail_->next_ = node_link; 
            tail_ = node_link;
            tail_->next_ = nullptr;
        }
    }
    
    void add_new(int key, int value)
    {
        Node* node_link = nullptr;
        if (head_)
        {
            if (count_ < capacity_)
            {
                count_++;
                node_link = new Node(key, value);
                tail_->next_ = node_link;
                tail_ = node_link;
            }
            else
            {
                auto iter = key_nodes.find(head_->key_);
                key_nodes.erase(iter);
                node_link = head_;
                node_link->key_ = key;
                node_link->value_ = value;

                if(head_ != tail_)
                {
                    head_ = node_link->next_;
                    node_link->next_ = nullptr;
                    tail_->next_ = node_link;
                    tail_ = node_link;
                }
            }
        }
        else
        {
            count_++;
            node_link = new Node(key, value);
            head_ = node_link;
            tail_ = node_link;
        }
        key_nodes.emplace(key, node_link);
    }

    void put(int key, int value) {
        auto iter = key_nodes.find(key);
        if(iter != key_nodes.end())
        {
            iter->second->value_ = value;
            move_to_end(iter->second);
        }
        else
        {
            add_new(key, value);
        }
    }
};