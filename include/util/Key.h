template <typename T>
class Key
{
private:
    <T> key;

public:
    Key() {}
    Key(T key) { this->key = key; }
    ~Key() {}
};
