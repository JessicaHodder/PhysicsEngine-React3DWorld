#pragma once
#include "physicalObject.h"

class StaticBlock : public PhysicalObject
{
public:
	StaticBlock();
	StaticBlock(const glm::vec3& position, const glm::vec3& orientation, const glm::vec3& halfExtents, const glm::vec3& colour, unsigned int index);
	void onDraw() override;
protected:
	glm::mat4 m_model;
	glm::vec3 m_colour;
	glm::vec3 m_halfExtents;
};