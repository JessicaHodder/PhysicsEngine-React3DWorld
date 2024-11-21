#include "dynamicBlock.h"
#include "scene.h"
#include <glm/gtc/type_ptr.hpp>

DynamicBlock::DynamicBlock()
{
	m_body = nullptr;
	glm::mat4 m_model = glm::mat4(1.0f);
	glm::vec3 m_colour = glm::vec3(1.0f);
	glm::vec3 m_halfExtents = glm::vec3(0.5f);

	m_type = ObjectType::dynamicBlock;
}

DynamicBlock::DynamicBlock(const glm::vec3& position, const glm::vec3& orientation, const glm::vec3& halfExtents, const glm::vec3& colour, unsigned int index) : StaticBlock(position, orientation, halfExtents, colour, index)
{
	m_body->setType(rp3d::BodyType::DYNAMIC);

	m_type = ObjectType::dynamicBlock;

	setUserData(index);
}

void DynamicBlock::onUpdate(float timestep)
{
	m_body->getTransform().getOpenGLMatrix(glm::value_ptr(m_model));
}

