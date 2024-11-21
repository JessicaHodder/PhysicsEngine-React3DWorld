#include "scene.h"
#include <iostream>


rp3d::PhysicsCommon Scene::m_physicsCommon;
rp3d::PhysicsWorld* Scene::m_world = nullptr;

Scene::Scene()
{
	
	//m_staticBlocks.push_back(StaticBlock(glm::vec3(), glm::vec3(0.f, 0.f, 0.f), glm::vec3(), glm::vec3(0.f, 1.f, 0.f)));



	if (!m_world) m_world = m_physicsCommon.createPhysicsWorld();

	m_staticBlocks.push_back(StaticBlock(glm::vec3(-12.f, -2.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(2.5f, 0.25f, 15.f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(5.0f, -2.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(10.f, 0.25f, 15.f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(-7.5f, -2.f, -12.5f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(2.5f, 0.25f, 2.5f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(-7.5f, -2.f, 5.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(2.5f, 0.25f, 10.f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));

	m_staticBlocks.push_back(StaticBlock(glm::vec3(0.f, -1.375f, -14.8f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(15.f, 0.4f, 0.2f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(0.f, -1.375f, 14.8f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(15.f, 0.4f, 0.2f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(-14.8f, -1.375f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.2f, 0.4f, 14.6f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(14.8f, -1.375f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.2f, 0.4f, 14.6f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));

	m_staticBlocks.push_back(StaticBlock(glm::vec3(-7.5f, -7.f, -7.5f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(2.875f, 0.25f, 2.875f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));

	m_staticBlocks.push_back(StaticBlock(glm::vec3(-4.8f, -4.5f, -7.5f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.2f, 2.25f, 2.5f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(-10.2f ,-4.5f, -7.5f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.2f, 2.25f, 2.5f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(-7.5f, -4.5f, -4.8f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(2.5f, 2.25f, 0.2f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));
	m_staticBlocks.push_back(StaticBlock(glm::vec3(-7.5f, -4.5f, -10.2f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(2.5f, 2.25f, 0.2f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));

	m_staticBlocks.push_back(StaticBlock(glm::vec3(15.f, 3.f, 8.f), glm::vec3(0.f, 0.f, 30.f), glm::vec3(4.f, 0.25f, 2.f), glm::vec3(0.f, 1.f, 0.f), m_staticBlocks.size()));


	m_dynamicBlocks.push_back(DynamicBlock(glm::vec3(10.f, 5.f, -10.f), glm::vec3(0.f, 0.f, 30.f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.f, 0.f, 0.f), m_dynamicBlocks.size()));
	m_dynamicBlocks.push_back(DynamicBlock(glm::vec3(9.9f, 5.2f, -8.5f), glm::vec3(0.f, 0.f, 30.f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.f, 0.f, 0.f), m_dynamicBlocks.size()));
	m_dynamicBlocks.push_back(DynamicBlock(glm::vec3(10.f, 6.5f, -9.5f), glm::vec3(0.f, 0.f, 30.f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.f, 0.f, 0.f), m_dynamicBlocks.size()));


	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, 10.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, 8.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, 6.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, 4.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, 2.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, 0.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, -2.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, -4.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, -6.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, -8.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_staticSpheres.push_back(StaticSphere(glm::vec3(-12.5f, -1.f, -10.f), glm::vec3(0.f, 0.f, 0.f), (0.35f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));


	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, 9.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, 7.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, 5.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, 3.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, 1.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, -1.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, -3.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, -5.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, -7.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-12.5f, -1.f, -9.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (1.5f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));


	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-5.5f, -5.75f, -5.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-5.5f, -5.75f, -6.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-5.5f, -5.75f, -7.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-5.5f, -5.75f, -8.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-5.5f, -5.75f, -9.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));

	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-6.5f, -5.75f, -6.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-6.5f, -5.75f, -7.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-6.5f, -5.75f, -8.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-6.5f, -5.75f, -9.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));

	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-7.5f, -5.75f, -5.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-7.5f, -5.75f, -6.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-7.5f, -5.75f, -7.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-7.5f, -5.75f, -8.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-7.5f, -5.75f, -9.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));

	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-8.5f, -5.75f, -6.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-8.5f, -5.75f, -7.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-8.5f, -5.75f, -8.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-8.5f, -5.75f, -9.f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));

	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-9.5f, -5.75f, -5.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-9.5f, -5.75f, -6.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-9.5f, -5.75f, -7.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-9.5f, -5.75f, -8.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));
	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-9.5f, -5.75f, -9.5f), glm::vec3(0.f, 0.f, 0.f), (0.1f), (2.f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));


	m_staticSpheres.push_back(StaticSphere(glm::vec3(0.f, 2.2f, 6.f), glm::vec3(0.f, 0.f, 0.f), (0.25f), glm::vec3(1.f, 1.f, 0.f), m_staticSpheres.size()));
	m_dynamicBlocks.push_back(DynamicBlock(glm::vec3(2.f, 2.2f, 6.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.75f, 0.125f, 0.125f), glm::vec3(1.f, 0.f, 0.f), m_dynamicBlocks.size()));

	rp3d::Vector3 anchorPointWorldSpace(0.f, 2.2f, 6.f);
	rp3d::BallAndSocketJointInfo jointInfo(m_staticSpheres[m_staticSpheres.size() - 1].getBody(), m_dynamicBlocks[m_dynamicBlocks.size() - 1].getBody(), anchorPointWorldSpace);
	jointInfo.isCollisionEnabled = false;

	m_bsj = dynamic_cast<rp3d::BallAndSocketJoint*>(m_world->createJoint(jointInfo));


	//joint 2 test

	m_dynamicBlocks.push_back(DynamicBlock(glm::vec3(5.f, 0.f, -6.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.25f, 1.5f, 1.5f), glm::vec3(1.f, 1.f, 1.f), m_dynamicBlocks.size()));

	rp3d::SliderJointInfo jointInfo2(m_staticBlocks[1].getBody(), m_dynamicBlocks[m_dynamicBlocks.size() - 1].getBody(), rp3d::Vector3(5.f, 0.f, -6.f), rp3d::Vector3(0.f, 0.f, 1.f));
	jointInfo2.isMotorEnabled = true;
	jointInfo2.maxMotorForce = 50.f;
	jointInfo2.motorSpeed = 1.0f;
	jointInfo2.isLimitEnabled = true;
	jointInfo2.minTranslationLimit = -4.f;
	jointInfo2.maxTranslationLimit = 4.f;

	m_sj = dynamic_cast<rp3d::SliderJoint*>(m_world->createJoint(jointInfo2));

	//joint test 3

	m_staticCapsules.push_back(StaticCapsule(glm::vec3(-7.5f, 0.f, -7.5f), glm::vec3(0.f, 0.f, 0.f), (0.3f), (2.75f), glm::vec3(1.f, 0.f, 1.f), m_staticCapsules.size()));

	glm::mat4& capsuleModel = m_staticCapsules.back().getModel();

	m_dynamicBlocks.push_back(DynamicBlock(glm::vec3(-7.5f, 0.f, -7.5f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.1f, 1.5f, 1.5f), glm::vec3(1.f, 1.f, 1.f), m_dynamicBlocks.size()));

	m_dynamicBlocks.back().getBody()->setAngularDamping(0.5);

	rp3d::Vector3 rotAxis = rp3d::Vector3(capsuleModel[1][0], capsuleModel[1][1], capsuleModel[1][2]);
	rp3d::HingeJointInfo jointInfo3(m_staticCapsules.back().getBody(), m_dynamicBlocks.back().getBody(), rp3d::Vector3(-7.5f, 0.f, -7.5f), rp3d::Vector3(0., 1.f, 0.f));
	jointInfo3.isMotorEnabled = true;
	jointInfo3.motorSpeed = 0.1f;
	jointInfo3.maxMotorTorque = 1.f;

	m_hj = dynamic_cast<rp3d::HingeJoint*>(m_world->createJoint(jointInfo3));


	//moving target

	m_dynamicBlocks.push_back(DynamicBlock(glm::vec3(-5.f, 5.f, 8.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.25f, 1.5f, 1.5f), glm::vec3(1.f, 1.f, 1.f), m_dynamicBlocks.size()));

	rp3d::SliderJointInfo jointInfo4(m_staticBlocks[0].getBody(), m_dynamicBlocks[m_dynamicBlocks.size() - 1].getBody(), rp3d::Vector3(5.f, 0.f, 6.f), rp3d::Vector3(0.f, 1.f, 0.f));
	jointInfo4.isMotorEnabled = true;
	jointInfo4.maxMotorForce = 50.f;
	jointInfo4.motorSpeed = 3.0f;
	jointInfo4.isLimitEnabled = true;
	jointInfo4.minTranslationLimit = -4.f;
	jointInfo4.maxTranslationLimit = 4.f;

	m_sj2 = dynamic_cast<rp3d::SliderJoint*>(m_world->createJoint(jointInfo4));


	//dynamic sphere test
	//m_dynamicSpheres.push_back(DynamicSphere(glm::vec3(17.5f, 15.f, 8.f), glm::vec3(0.f, 0.f, 0.f), (0.5f), glm::vec3(1.f, 1.f, 0.f)));


	id = glm::mat4(1.0f);



	 m_cubeModel = glm::mat4(1.0f);
	 m_cubeColour = glm::vec3(0.f, 1.0f, 0.f);
	 m_cubeHalfExtents = glm::vec3(1.f);

	 m_sphereTranslationVector = glm::vec3(-5.f, 0.f, 0.f);
	 m_sphereModel = glm::translate(id, m_sphereTranslationVector);
	 m_sphereRadius = (1.f);
	 m_sphereColour = glm::vec3(0.f, 0.0f, 1.f);

	 m_sphereRotationSpeed = glm::vec3(0, glm::radians(270.f), 0);
	 m_spherePosition = glm::vec3(-5.f, 0.f, 0.f);
	 m_sphereOrientation = glm::vec3(0.f, 0.f, 0.f);


	 m_capsuleTranslationVector = glm::vec3(5.f, 0.f, 0.f);
	 m_capsuleModel = glm::translate(id, m_capsuleTranslationVector);
	 m_capsuleRadius = (0.5f);
	 m_capsuleColour = glm::vec3(1.f, 0.f, 0.f);
	 m_capsuleHeight = (1.f);
	 m_capsulePosition = glm::vec3(5.f, 0.f, 0.f);

	 glm::vec3 Euler1(glm::radians(60.f), 0.f, glm::radians(-60.f));
	 glm::quat x1 = glm::angleAxis(Euler1.x, glm::vec3(1.f, 0.f, 0.f));
	 glm::quat y1 = glm::angleAxis(Euler1.y, glm::vec3(0.f, 1.f, 0.f));
	 glm::quat z1 = glm::angleAxis(Euler1.z, glm::vec3(0.f, 0.f, 1.f));
	 m_capsuleOrientation1 = x1 * y1 * z1;

	 glm::vec3 Euler2(glm::radians(-60.f), 0.f, glm::radians(60.f));
	 glm::quat x2 = glm::angleAxis(Euler2.x, glm::vec3(1.f, 0.f, 0.f));
	 glm::quat y2 = glm::angleAxis(Euler2.y, glm::vec3(0.f, 1.f, 0.f));
	 glm::quat z2 = glm::angleAxis(Euler2.z, glm::vec3(0.f, 0.f, 1.f));
	 m_capsuleOrientation2 = x2 * y2 * z2;

	 m_increasing = true;
	 m_t = 0.f;

	 //CL
	 m_collisionListener.setScene(this);
	 m_world->setEventListener(&m_collisionListener);



}

void Scene::onUpdate(float timestep)
{

	m_world->update(timestep);

	for (auto& block : m_dynamicBlocks) block.onUpdate(timestep);
	for (auto& sphere : m_dynamicSpheres) sphere.onUpdate(timestep);

	//std::cout << "Time elapsed: " << timestep << std::endl;

	m_sphereDelay -= timestep;

	if (SC::InputPoller::isKeyPressed(SC_KEY_SPACE) && m_sphereDelay < 0)
	{
		std::cout << "Space is pressed" << std::endl;
		m_dynamicSpheres.push_back(DynamicSphere(glm::vec3(17.5f, 15.f, 8.f), glm::vec3(0.f, 0.f, 0.f), (0.5f), glm::vec3(1.f, 1.f, 0.f), m_dynamicSpheres.size()));
		m_sphereDelay = 1;
	}
	if (SC::InputPoller::isMouseButtonPressed(SC_MOUSE_BUTTON_2))
	{
		std::cout << "Mouse button 2 is pressed" << std::endl;
	}

	if (SC::InputPoller::isKeyPressed(SC_KEY_W)) SC::Renderer::cameraForward();
	if (SC::InputPoller::isKeyPressed(SC_KEY_S)) SC::Renderer::cameraBack();

	if (SC::InputPoller::isKeyPressed(SC_KEY_A)) SC::Renderer::cameraLeft();
	if (SC::InputPoller::isKeyPressed(SC_KEY_D)) SC::Renderer::cameraRight();
	if (SC::InputPoller::isKeyPressed(SC_KEY_UP)) SC::Renderer::cameraUp();
	if (SC::InputPoller::isKeyPressed(SC_KEY_DOWN)) SC::Renderer::cameraDown();

	m_sphereOrientation += m_sphereRotationSpeed * timestep;

	glm::mat4 rotationX = glm::rotate(glm::mat4(1.f), m_sphereOrientation.x, { 1.f, 0.f, 0.f });
	glm::mat4 rotationY = glm::rotate(glm::mat4(1.f), m_sphereOrientation.y, { 0.f, 1.f, 0.f });
	glm::mat4 rotationZ = glm::rotate(glm::mat4(1.f), m_sphereOrientation.z, { 0.f, 0.f, 1.f });
	glm::mat4 rotation = rotationX * rotationY * rotationZ;

	m_sphereModel = glm::translate(glm::mat4(1.f), m_spherePosition) * rotation;


	if (m_increasing)
	{
		m_t += timestep;
	}
	else
	{
		m_t -= timestep;
	}
	if (m_t > 1 || m_t < 0)
	{
		m_increasing = !m_increasing;
	}

	//std::cout << m_t << std::endl;

	glm::quat capsuleOrientation = glm::mix(m_capsuleOrientation1, m_capsuleOrientation2, m_t);
	m_capsuleModel = glm::translate(glm::mat4(1.f), m_capsulePosition) * glm::toMat4(capsuleOrientation);



	for (int i = 0; i < m_dynamicSpheres.size(); i++)
	{
		if (m_dynamicSpheres[i].isRegisteredForDeletion())
		{
			m_world->destroyRigidBody(m_dynamicSpheres[i].getBody());

			m_dynamicSpheres[i] = m_dynamicSpheres.back();
			//m_dynamicSpheres[i].setUserData(i);

			m_dynamicSpheres.erase(m_dynamicSpheres.end() - 1);

			i--;
		}
	}
	
	if (m_sj->getTranslation() <= m_sj->getMinTranslationLimit() || m_sj->getTranslation() >= m_sj->getMaxTranslationLimit()) m_sj->setMotorSpeed(-m_sj->getMotorSpeed());
	if (m_sj2->getTranslation() <= m_sj2->getMinTranslationLimit() || m_sj2->getTranslation() >= m_sj2->getMaxTranslationLimit()) m_sj2->setMotorSpeed(-m_sj2->getMotorSpeed());

}

void Scene::onDraw()
{

	

	SC::Renderer::beginScene();

	for (auto& block : m_staticBlocks) block.onDraw();

	for (auto& block : m_dynamicBlocks) block.onDraw();

	for (auto& sphere : m_staticSpheres) sphere.onDraw();

	for (auto& capsule : m_staticCapsules) capsule.onDraw();


	for (auto& sphere : m_dynamicSpheres) sphere.onDraw();




	SC::Renderer::drawCube(m_cubeModel, m_cubeHalfExtents, m_cubeColour);

	SC::Renderer::drawSphere(m_sphereModel, m_sphereRadius, m_sphereColour);

	SC::Renderer::drawCapsule(m_capsuleModel, m_capsuleRadius, m_capsuleHeight, m_capsuleColour);

	SC::Renderer::endScene();
}
