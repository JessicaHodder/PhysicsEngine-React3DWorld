#include "staticCapsule.h"
#include "scene.h"
//#include <iostream>
#include <glm/gtc/type_ptr.hpp>


StaticCapsule::StaticCapsule()
{
	m_body = nullptr;
	glm::mat4 m_model = glm::mat4(1.0f);
	glm::vec3 m_colour = glm::vec3(1.0f);
	float m_radius = (0.5f);
	float m_height = (0.5f);

	m_type = ObjectType::staticCapsule;
}


StaticCapsule::StaticCapsule(const glm::vec3& position, const glm::vec3& orientation, const float radius, const float height, const glm::vec3& colour, unsigned int index)
{

	m_type = ObjectType::staticCapsule;

	glm::quat quatX = glm::angleAxis(glm::radians(orientation.x), glm::vec3(1.f, 0.f, 0.f));
	glm::quat quatY = glm::angleAxis(glm::radians(orientation.y), glm::vec3(0.f, 1.f, 0.f));
	glm::quat quatZ = glm::angleAxis(glm::radians(orientation.z), glm::vec3(0.f, 0.f, 1.f));
	glm::quat quat = quatX * quatY * quatZ;

	rp3d::Vector3 pos(position.x, position.y, position.z);
	rp3d::Quaternion angle = rp3d::Quaternion(quat.x, quat.y, quat.z, quat.w);
	rp3d::Transform transform(pos, angle);
	m_body = Scene::getWorld()->createRigidBody(transform);
	m_body->setType(rp3d::BodyType::STATIC);

	m_radius = radius;
	m_height = height;
	m_colour = colour;


	// collider
	//rp3d::BoxShape* shape = Scene::getPhysicsCommon().createBoxShape(rp3d::Vector3(halfExtents.x, halfExtents.y, halfExtents.z));
	rp3d::CapsuleShape* shape = Scene::getPhysicsCommon().createCapsuleShape(radius, height);
	rp3d::Transform t = rp3d::Transform::identity();
	m_collider = m_body->addCollider(shape, t);

	rp3d::Material& material = m_collider->getMaterial();
	material.setBounciness(1.0f);

	m_body->getTransform().getOpenGLMatrix(glm::value_ptr(m_model));

	setUserData(index);
}

void StaticCapsule::onDraw()
{
	SC::Renderer::drawCapsule(m_model, m_radius, m_height, m_colour);
}