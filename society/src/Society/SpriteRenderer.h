
#ifndef SC_SPRITE_RENDERER_H
#define SC_SPRITE_RENDERER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture.h"
#include "Shader.h"

namespace Society {


	class SpriteRenderer
	{
	public:
		// Constructor (inits shaders/shapes)
		SpriteRenderer();
		// Destructor
		~SpriteRenderer();
		// Renders a defined quad textured with given sprite
		void DrawSprite(Texture2D& texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
		void SetShader(Shader* shader);
	private:
		// Render state
		Shader* m_shader;
		unsigned int quadVAO;
		// Initializes and configures the quad's buffer and vertex attributes
		void initRenderData();
	};
}
#endif
