#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>

class Node
{

public:
    Node(std::string name = "Node");

    virtual ~Node();

    Node* getParent();

    std::vector<Node*> getChildren();

    void addChild(Node *child);

    std::string getType();
    std::string getName();

    void apply();


protected:

    std::string name;
    std::string type;
    Node *parent;

    std::vector<Node*> children;

    void setParent(Node*);

    virtual void applySelf();

};

#endif // NODE_H

