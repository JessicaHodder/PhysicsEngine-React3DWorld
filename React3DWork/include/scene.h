#pragma once
#include "IMAT2912.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <reactphysics3d/reactphysics3d.h>
#include "staticBlock.h"
#include "dynamicBlock.h"
#include "staticSphere.h"
#include "dynamicSphere.h"
#include "staticCapsule.h"
#include "collisionListener.h"



class Scene
{
public:
	//friend class CollisionListener;

	Scene();
	void onUpdate(float timestep);
	void onDraw();
	static rp3d::PhysicsWorld* getWorld() { return m_world; }
	static rp3d::PhysicsCommon& getPhysicsCommon() { return m_physicsCommon; }

	//CL
	CollisionListener m_collisionListener;



private:

	static rp3d::PhysicsCommon m_physicsCommon;
	static rp3d::PhysicsWorld* m_world;


	std::vector<StaticBlock> m_staticBlocks;
	std::vector<DynamicBlock> m_dynamicBlocks;

	std::vector<StaticSphere> m_staticSpheres;
	std::vector<DynamicSphere> m_dynamicSpheres;

	std::vector<StaticCapsule> m_staticCapsules;

	float m_sphereDelay = 0.f;

	rp3d::BallAndSocketJoint* m_bsj;
	rp3d::SliderJoint* m_sj;
	rp3d::SliderJoint* m_sj2;
	rp3d::HingeJoint* m_hj;

	glm::mat4 id;

	glm::mat4 m_cubeModel;
	glm::vec3 m_cubeColour;
	glm::vec3 m_cubeHalfExtents;

	glm::mat4 m_sphereModel;
	float m_sphereRadius;
	glm::vec3 m_sphereColour;
	glm::vec3 m_sphereTranslationVector;

	glm::vec3 m_sphereRotationSpeed;
	glm::vec3 m_spherePosition;
	glm::vec3 m_sphereOrientation;


	glm::mat4 m_capsuleModel;
	float m_capsuleRadius;
	glm::vec3 m_capsuleColour;
	float m_capsuleHeight;
	glm::vec3 m_capsuleTranslationVector;
	glm::vec3 m_capsulePosition;

	glm::quat m_capsuleOrientation1;
	glm::quat m_capsuleOrientation2;

	bool m_increasing;
	float m_t;

};