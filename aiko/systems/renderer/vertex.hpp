#pragma once

#include <glm.hpp>

namespace aiko
{

	struct Vertex
	{

		enum VertexLocation
		{
			POSITION = 0,
			COLOR = 1,
			TEXTCOORD = 2,
			NORMAL = 3,
		};

		glm::vec3 position;
		glm::vec3 color;
		glm::vec2 textCoord;
		glm::vec3 normal;
	};

}

