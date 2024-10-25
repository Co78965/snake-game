#ifndef _IUSERINPUT_H_
#define _IUSERINPUT_H_

#include <string>

class IUserInput{
public:
    virtual ~IUserInput() = default;
    virtual char userMove() = 0;
    virtual std::string userName() = 0;
};

#endif