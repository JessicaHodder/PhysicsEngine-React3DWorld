#pragma once
#include "physicalObject.h"

class StaticSphere : public PhysicalObject
{
public:
	StaticSphere();
	StaticSphere(const glm::vec3& position, const glm::vec3& orientation, const float radius, const glm::vec3& colour, unsigned int index);
	void onDraw() override;
protected:
	glm::mat4 m_model;
	glm::vec3 m_colour;
	float m_radius;
};