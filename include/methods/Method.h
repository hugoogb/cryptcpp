#include "../../include/util/Message.h"

class Method
{
private:
    Message message;

public:
    Method();
    ~Method();

    virtual void encrypt(Message message) = 0;
    virtual void decrypt(Message message) = 0;
};
