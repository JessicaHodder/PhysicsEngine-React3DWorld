#pragma once
//#include "physicalObject.h"
#include <reactphysics3d/reactphysics3d.h>
#include <iostream>

class Scene;

class CollisionListener : public rp3d::EventListener
{
public:
	void onContact(const rp3d::CollisionCallback::CallbackData& callbackData) override;
	void onTrigger(const rp3d::OverlapCallback::CallbackData& callbackData) override {};
	void setScene(Scene* scene);
private:
	Scene* m_scene = nullptr;
};