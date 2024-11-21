#pragma once
#include "IMAT2912.h"
#include <reactphysics3d/reactphysics3d.h>

// Collision Listening
enum class ObjectType {unset = 0, staticBlock, dynamicBlock, staticSphere, dynamicSphere, staticCapsule};


class PhysicalObject
{
public:
	PhysicalObject() {};
	virtual void onUpdate(float timestep) {};
	virtual void onDraw() {};

	//CL
	virtual void onContact(ObjectType contactObjectType, unsigned int contactObjectIndex, rp3d::Collider* contactCollider) {};
	virtual void offContact(ObjectType contactObjectType, unsigned int contactObjectIndex, rp3d::Collider* contactCollider) {};
	virtual void onTrigger(ObjectType contactObjectType, unsigned int contactObjectIndex, rp3d::Collider* contactCollider) {};
	virtual void offTrigger(ObjectType contactObjectType, unsigned int contactObjectIndex, rp3d::Collider* contactCollider) {};


	inline void registerForDeletion() { m_registeredForDeletion = true; }
	inline bool isRegisteredForDeletion() { return m_registeredForDeletion; }
	inline rp3d::RigidBody* getBody() { return m_body; }

	//CL
	void setUserData(unsigned int index)
	{
		unsigned int type = static_cast<unsigned int>(m_type);
		unsigned int typeBits = type << 16;
		unsigned int finalBits = typeBits | index;

		void* userData = reinterpret_cast<void*>(finalBits);
		m_body->setUserData(userData);
	}


protected:
	rp3d::RigidBody* m_body = nullptr;
	rp3d::Collider* m_collider = nullptr;
	bool m_registeredForDeletion = false;

	//CL
	ObjectType m_type = ObjectType::unset;


};
