#include "model.hpp"

#include "vertex.hpp"

namespace aiko
{

	aiko::Vertex vertices[] =
	{
		glm::vec3(-0.5f,  0.5f, 0.0f),  glm::vec3(1.f, 0.f, 0.f),   glm::vec2(0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(-0.5f, -0.5f, 0.0f),  glm::vec3(0.f, 1.f, 0.f),   glm::vec2(0.0f, 0.0f),	glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.5f, -0.5f, 0.0f),  glm::vec3(0.f, 0.f, 1.f),   glm::vec2(1.0f, 0.0f),	glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.5f,  0.5f, 0.0f),  glm::vec3(1.f, 1.f, 0.f),   glm::vec2(1.0f, 1.0f),	glm::vec3(0.0f, 0.0f, -1.0f),
	};

	uint16_t indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	unsigned int numVertices = sizeof(vertices) / sizeof(uint16_t);

	Model::Model()
        : m_vao(0)
    {
		
    }

	void Model::update(const TimeStep & step)
	{
		angle += step.getDelta();

		if (angle > 360.0f) angle = 0.0f;
		float radian = glm::radians(angle);
		float radius = 0.5f;
		m_transform.m_position.x = cosf(angle) * radius;
		m_transform.m_position.y = sinf(angle) * radius;

		m_transform.m_rotation.y += 90.f * step.getDelta();

	}

	Model::ModelId Model::getId()
	{
		return m_vao;
	}

	void Model::render(Shader & shader)
	{
        // glBindVertexArray(m_vao);
        // glDrawElements(GL_TRIANGLES, numVertices, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0);
	}

	Transform & Model::getTransform()
	{
		return m_transform;
	}

	void Model::loadVao()
	{

		// glCreateVertexArrays(1, &m_vao);
		// glBindVertexArray(m_vao);
        // 
		// glGenBuffers(1, &m_vbo);
		// glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        // 
		// glGenBuffers(1, &m_ebo);
		// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        // 
		// glEnableVertexAttribArray(Vertex::VertexLocation::POSITION);
		// glVertexAttribPointer(Vertex::VertexLocation::POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
        // 
		// glEnableVertexAttribArray(Vertex::VertexLocation::COLOR);
		// glVertexAttribPointer(Vertex::VertexLocation::COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
        // 
		// glEnableVertexAttribArray(Vertex::VertexLocation::TEXTCOORD);
		// glVertexAttribPointer(Vertex::VertexLocation::TEXTCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textCoord));
        // 
		// glEnableVertexAttribArray(Vertex::VertexLocation::NORMAL);
		// glVertexAttribPointer(Vertex::VertexLocation::NORMAL, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
        // 
		// glBindVertexArray(0);

	}

}

