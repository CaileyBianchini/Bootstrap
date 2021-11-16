#pragma once
#include "Mesh.h"
#include <Texture.h>
#include <Renderer2D.h>

class Quad : public Mesh
{
public:
	Quad() : Mesh() {}
	Quad(glm::vec4 color);

	void onStart() override;
	void onDraw() override;

	Vertex* generateVertices(unsigned int& vertexCount, unsigned int& tricount) override;
	unsigned int* generateIndices(unsigned int& indexCount) override;

	glm::vec4 getColor() { return m_color; }
	void setColor(glm::vec4 color) { m_color = color; }

private:
	glm::vec4 m_color = glm::vec4(1.0f);

	//textures
	aie::Texture m_earthNormal;
	aie::Texture m_earthDiffuse;
	aie::Texture m_earthSpecular;
};

