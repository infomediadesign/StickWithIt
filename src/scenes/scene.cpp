#include "scene.h"


// A pure virtual destructor can be declared in C++. 
// After a destructor has been created as a pure virtual object(instance of a class), where the destructor body is provided. 
// This is due to the fact that destructors will not be overridden in derived classes, but will instead be called in reverse order. 
// As a result, for a pure virtual destructor, you must specify a destructor body.
scenes::Scene::~Scene() {}
