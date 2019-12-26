#include "transform.hpp"

#include <gtc/matrix_transform.hpp>

namespace aiko
{
    Transform::Transform()
        : m_position(0.0f, 0.0f, 0.0f)
        , m_rotation(0.0f, 0.0f, 0.0f)
        , m_scale   (1.0f, 1.0f, 1.0f)
    {

    }

	glm::mat4 Transform::getModelMatrix()
    {
		auto modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::translate(modelMatrix, m_position);
		modelMatrix = glm::rotate(modelMatrix, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		modelMatrix = glm::scale(modelMatrix, m_scale);
		return modelMatrix;

    }

}

