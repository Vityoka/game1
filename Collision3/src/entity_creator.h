#ifndef ENTITYCREATOR_H_GUARD
#define ENTITYCREATOR_H_GUARD

//forward declaration
class Entity;

class EntityCreator {
public:
    virtual Entity* createProduct() = 0;
private:

};

#endif // ENTITYCREATOR_H_GUARD
