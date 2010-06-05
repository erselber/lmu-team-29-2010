#ifndef SCENE_H
#define SCENE_H

#include "rootnode.h"
#include "node.h"

class Scene
{
public:
    Scene(RootNode *node){
        root = node;
    };

    void render();


private:
    RootNode *root;
};

#endif // SCENE_H

