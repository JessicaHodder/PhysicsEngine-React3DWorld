#include "dynamicSphere.h"
#include "scene.h"
#include <glm/gtc/type_ptr.hpp>

DynamicSphere::DynamicSphere()
{
	m_body = nullptr;
	glm::mat4 m_model = glm::mat4(1.0f);
	glm::vec3 m_colour = glm::vec3(1.0f);
	float m_radius = (0.35f);

	m_type = ObjectType::dynamicSphere;
}

DynamicSphere::DynamicSphere(const glm::vec3& position, const glm::vec3& orientation, const float radius, const glm::vec3& colour, unsigned int index) : StaticSphere(position, orientation, radius, colour, index)
{
	m_body->setType(rp3d::BodyType::DYNAMIC);
	m_type = ObjectType::dynamicSphere;

	setUserData(index);
}

void DynamicSphere::onUpdate(float timestep)
{
	m_body->getTransform().getOpenGLMatrix(glm::value_ptr(m_model));

	m_lifeTimeRemaining -= timestep;
	if (m_lifeTimeRemaining < 0)
	{
		registerForDeletion();
	}
}