#include <iostream>
#include <map>

using namespace std;

template <class K, class V>
class ChacheMemory
{
public:
    void erase(const K &key);
    void add(const K &key, const V &value);
    shared_ptr<V> get(const K &key);
    struct DuplicateKeyException : public exception {
        const char * what () const throw () {
            return "Duplicate Key Exception";
        }
    };
    struct ObjectNotExistException : public exception {
        const char * what () const throw () {
            return "Object Not Exist Exception";
        }
    };
private:
    map<K, shared_ptr<V> > variables;
    map<K, weak_ptr<V> > cache;
};
template <class K,class V>
void ChacheMemory<K,V>::erase(const K &key)
{
    if ( variables.find(key) != variables.end())
        throw ObjectNotExistException();
}
template <class K,class V>
void ChacheMemory<K,V>::add(const K &key , const V &value)
{
    if ( variables.find(key) != variables.end()) {
        throw DuplicateKeyException();
    } else {
        shared_ptr<V> ptr = make_shared<V>(value);
        variables.insert(std::pair<K,shared_ptr<V> >(key, ptr));
    }
}
template <class K, class V>
shared_ptr<V> ChacheMemory<K, V>::get(const K &key) {
    if ( cache.find(key) == cache.end()) {
        if ( variables.find(key) == variables.end()) {
            return nullptr;
        }
        shared_ptr<V> ptr = variables.at(key);
        cache.insert(std::pair<K,weak_ptr<V> >(key, weak_ptr<V>(ptr) ));
        return ptr;
    
    } else {
        weak_ptr<V> ptr = cache.at(key);
        if(ptr.expired()) {
            cache.erase(cache.find(key));
            return nullptr;
        }
        return ptr.lock();
    }
}
