#include "collisionListener.h"
#include "physicalObject.h"
#include "scene.h"
#include <iostream>

void CollisionListener::onContact(const rp3d::CollisionCallback::CallbackData& callbackData)
{
	std::string labels[] = { "unset", "staticBlock", "dynamicBlock", "staticSphere", "dynamicSphere", "staticCapsule" };

	for (unsigned int i = 0; i < callbackData.getNbContactPairs(); i++)
	{
		auto contactPair = callbackData.getContactPair(i);

		unsigned int bitsA = reinterpret_cast<unsigned int>(contactPair.getBody1()->getUserData());
		unsigned int bitsB = reinterpret_cast<unsigned int>(contactPair.getBody2()->getUserData());

		unsigned int ui_typeA = (bitsA & 0xFFFF0000) >> 16;
		unsigned int ui_typeB = (bitsB & 0xFFFF0000) >> 16;

		ObjectType typeA = static_cast<ObjectType>(ui_typeA);
		ObjectType typeB = static_cast<ObjectType>(ui_typeB);


		unsigned int indexA = (bitsA & 0x0000FFFF);
		unsigned int indexB = (bitsB & 0x0000FFFF);

		rp3d::Collider* colliderA = contactPair.getCollider1();
		rp3d::Collider* colliderB = contactPair.getCollider2();


		auto contactType = contactPair.getEventType();


		//if (contactType == CollisionCallback::ContactPair::EventType::ContactStart)
		//{
		//	switch (typeA)
		//	{
		//	case ObjectType::staticBlock: m_scene->m_staticBlocks[indexA].onContact(typeB, indexB, colliderB); break;
		//	case ObjectType::dynamicBlock: m_scene->m_dynamicBlocks[indexA].onContact(typeB, indexB, colliderB); break;
		//	case ObjectType::staticSphere: m_scene->m_staticSpheres[indexA].onContact(typeB, indexB, colliderB); break;
		//	case ObjectType::dynamicSphere: m_scene->m_dynamicSpheres[indexA].onContact(typeB, indexB, colliderB); break;
		//	case ObjectType::staticCapsule: m_scene->m_staticCapsules[indexA].onContact(typeB, indexB, colliderB); break;
		//	}

		//	switch (typeB)
		//	{
		//	case ObjectType::staticBlock: m_scene->m_staticBlocks[indexB].onContact(typeA, indexA, colliderA); break;
		//	case ObjectType::dynamicBlock: m_scene->m_dynamicBlocks[indexB].onContact(typeA, indexA, colliderA); break;
		//	case ObjectType::staticSphere: m_scene->m_staticSpheres[indexB].onContact(typeA, indexA, colliderA); break;
		//	case ObjectType::dynamicSphere: m_scene->m_dynamicSpheres[indexB].onContact(typeA, indexA, colliderA); break;
		//	case ObjectType::staticCapsule: m_scene->m_staticCapsules[indexB].onContact(typeA, indexA, colliderA); break;
		//	}
		//}
		//else if (contactType == CollisionCallback::ContactPair::EventType::ContactExit)
		//{

		//	switch (typeA)
		//	{
		//	case ObjectType::staticBlock: m_scene->m_staticBlocks[indexA].offContact(typeB, indexB, colliderB); break;
		//	case ObjectType::dynamicBlock: m_scene->m_dynamicBlocks[indexA].offContact(typeB, indexB, colliderB); break;
		//	case ObjectType::staticSphere: m_scene->m_staticSpheres[indexA].offContact(typeB, indexB, colliderB); break;
		//	case ObjectType::dynamicSphere: m_scene->m_dynamicSpheres[indexA].offContact(typeB, indexB, colliderB); break;
		//	case ObjectType::staticCapsule: m_scene->m_staticCapsules[indexA].offContact(typeB, indexB, colliderB); break;
		//	}

		//	switch (typeB)
		//	{
		//	case ObjectType::staticBlock: m_scene->m_staticBlocks[indexB].offContact(typeA, indexA, colliderA); break;
		//	case ObjectType::dynamicBlock: m_scene->m_dynamicBlocks[indexB].offContact(typeA, indexA, colliderA); break;
		//	case ObjectType::staticSphere: m_scene->m_staticSpheres[indexB].offContact(typeA, indexA, colliderA); break;
		//	case ObjectType::dynamicSphere: m_scene->m_dynamicSpheres[indexB].offContact(typeA, indexA, colliderA); break;
		//	case ObjectType::staticCapsule: m_scene->m_staticCapsules[indexB].offContact(typeA, indexA, colliderA); break;
		//	}
		//}

		switch (contactType)
		{
			case CollisionCallback::ContactPair::EventType::ContactStart:
				std::cout << "Start contact between " << labels[ui_typeA] << "(" << ui_typeA << ") and " << labels[ui_typeB] << "(" << ui_typeB << ")" << std::endl;
				break;
			case CollisionCallback::ContactPair::EventType::ContactStay:
				//std::cout << "Ongoing contact between " << labels[ui_typeA] << "(" << ui_typeA << ") and " << labels[ui_typeB] << "(" << ui_typeB << ")" << std::endl;
				break;
			case CollisionCallback::ContactPair::EventType::ContactExit:
				std::cout << "End contact between " << labels[ui_typeA] << "(" << ui_typeA << ") and " << labels[ui_typeB] << "(" << ui_typeB << ")" << std::endl;
				break;
		}


	}
}

void CollisionListener::setScene(Scene* scene)
{
	m_scene = scene;
}