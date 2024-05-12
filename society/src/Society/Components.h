#ifndef SC_COMPONENTS_H
#define SC_COMPONENTS_H

#include <glm/glm.hpp>

namespace Society
{

	struct TransformComponent
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};

	struct SpriteComponent
	{
		unsigned int textureID;
		unsigned int shaderID;
		unsigned int textureWidth;
		unsigned int textureHeight;
		glm::vec4 color;
	};
}

#endif // SC_COMPONENTS_H
