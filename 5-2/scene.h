#ifndef SCENE_H
#define SCENE_H

#include "node.h"

class Scene
{
public:
    Scene(Node *node){
        root = node;
    };

    void render();


private:
    Node *root;
};

#endif // SCENE_H

