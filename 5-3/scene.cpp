#include "scene.h"
#include <iostream>
#include <transformnode.h>

void Scene::render()
{

    root->apply();
}
