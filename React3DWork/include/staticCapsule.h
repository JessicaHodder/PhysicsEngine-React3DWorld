#pragma once
#include "physicalObject.h"

class StaticCapsule : public PhysicalObject
{
public:
	StaticCapsule();
	StaticCapsule(const glm::vec3& position, const glm::vec3& orientation, const float radius, const float height, const glm::vec3& colour, unsigned int index);
	void onDraw() override;
	glm::mat4 getModel() { return m_model; }

protected:
	glm::mat4 m_model;
	glm::vec3 m_colour;
	float m_radius;
	float m_height;
};