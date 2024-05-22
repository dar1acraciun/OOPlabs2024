#include <iostream>
#include <tuple>

using namespace std;

template <typename K, typename V>
class map {
public:
    struct list {
        K key;
        V value;
        int index;
        list* next;
        list(const K& key, const V& value, int index) : key(key), value(value), index(index), next(nullptr) {}
    };

    list* first;

    map() {
        first = nullptr;
    }

    ~map() {
        Clear();
    }

    void Set(const K& key, const V& value) {
        list* node = FindNode(key);
        if (node) {
            node->value = value;
        }
        else {
            list* newNode = new list(key, value, Count());
            if (!first) {
                first = newNode;
            }
            else {
                list* aux = first;
                while (aux->next) {
                    aux = aux->next;
                }
                aux->next = newNode;
            }
        }
    }

    V& operator[](const K& key) {
        list* node = FindNode(key);
        if (!node) {
            Set(key, V());
            node = FindNode(key);
        }
        return node->value;
    }

    bool Get(const K& key, V& value)
    {
        list* aux = first;
        while (aux != nullptr&&aux->key!=key)
            aux = aux->next;
        if (aux == nullptr)
            return 0;
        else {
            value = aux->value;
            return 1;
        }
    }

    int Count()
    {
        list* aux = first;
        int count = 0;
        while (aux != nullptr)
        {
            aux = aux->next;
            count++;
        }
        return count;
    }
    void Clear() {
        list* current = first;
        while (current) {
            list* next = current->next;
            delete current;
            current = next;
        }
        first = nullptr;
    }

    bool Delete(const K& key)
    {
        V value;
        if (Get(key, value) == 0)
            return 0;
        list* aux = first;
        if (first->key == key)
            first = first->next;
        while (aux->next->key != key)
            aux = aux->next;
        aux->next = aux->next->next;
        return 1;

    }

    bool Includes(const map<K, V>& other) const {
        list* current = other.first;
        while (current) {
            list* node = FindNode(current->key);
            if (!node || node->value != current->value) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    class iterator {
    public:
        list* current;

        iterator(list* node) : current(node) {}

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        void operator++() {
            current = current->next;
        }

        std::tuple<K, V, int> operator*() const {
            return std::make_tuple(current->key, current->value, current->index);
        }
    };

    iterator begin() const {
        return iterator(first);
    }

    iterator end() const {
        return iterator(nullptr);
    }
    list* FindNode(const K& key) const {
        list* aux = first;
        while (aux!=nullptr) {
            if (aux->key == key) {
                return aux;
            }
            aux = aux->next;
        }
        return nullptr;
    }


};

int main() {
    map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
