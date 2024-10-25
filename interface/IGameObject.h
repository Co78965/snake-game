#ifndef _IGAMEOBJECT_H_
#define _IGAMEOBJECT_H_

class IGameObject {
public:
    virtual void move() = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual char getSymbol() const = 0; 
    virtual ~IGameObject() = default;
};

#endif