#pragma once
#include "staticBlock.h"

class DynamicBlock : public StaticBlock
{
public:
	DynamicBlock() ;
	DynamicBlock(const glm::vec3& position, const glm::vec3& orientation, const glm::vec3& halfExtents, const glm::vec3& colour, unsigned int index);
	virtual void onUpdate(float timestep);
};