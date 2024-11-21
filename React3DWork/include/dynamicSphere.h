#pragma once
#include "staticSphere.h"

class DynamicSphere : public StaticSphere
{
public:
	DynamicSphere();
	DynamicSphere(const glm::vec3& position, const glm::vec3& orientation, const float radius, const glm::vec3& colour, unsigned int index);
	virtual void onUpdate(float timestep);

private:
	float m_lifeTimeRemaining = 10.0f;
};