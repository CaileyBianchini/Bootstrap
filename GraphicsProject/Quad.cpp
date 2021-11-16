#include "Quad.h"

Quad::Quad(glm::vec4 color) : Quad::Quad()
{
	m_color = color;
}

void Quad::onStart()
{
	if (!m_earthNormal.load("earth_normal.jpg"))
		printf("Oopsies! Earth Normal didnt load! \n");
	if (!m_earthDiffuse.load("earth_diffuse.jpg"))
		printf("Oopsies! Earth Diffuse didn't load! \n");
	if (!m_earthSpecular.load("earth_specular.jpg"))
		printf("Oopsies! Earth Specular didnt load! \n");

	Mesh::onStart();
}

void Quad::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("no shader bound. \n");
	//diffuse
	int diffuseTextureUniform = glGetUniformLocation(program, "difuseTexture"); //this is where diffuse texture is located
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_earthDiffuse.getHandle());

	//normal
	int normalTextureUniform = glGetUniformLocation(program, "normalTexture"); //this is where normal texture is located
	if (normalTextureUniform >= 0)
		glUniform1i(normalTextureUniform, 0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_earthNormal.getHandle());

	//specular
	int specularTextureUniform = glGetUniformLocation(program, "specularTexture"); //this is where specular texture is located
	if (specularTextureUniform >= 0)
		glUniform1i(specularTextureUniform, 0);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, m_earthSpecular.getHandle());

	Mesh::onDraw();
}

Quad::Vertex* Quad::generateVertices(unsigned int& vertexCount, unsigned int& tricount)
{
	//Set the number of vertices
	vertexCount = 6;
	

	//Define the vertices for a quad
	Vertex* vertices = new Vertex[vertexCount];

	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[3].position = { 0.5f, 0.0f, -0.5f, 1.0f };
	//vertices[4].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	//vertices[5].position = { -0.5f, 0.0f, -0.5f, 1.0f };

	vertices[0].texCoord = { 0.0f, 0.0f };
	vertices[1].texCoord = { 0.0f, 1.0f };
	vertices[2].texCoord = { 1.0f, 0.0f };
	vertices[3].texCoord = { 1.0f, 1.0f };

	for (int i = 0; i < vertexCount; i++) {
		vertices[i].normal = { 0.0f, 1.0f, 0.0f, 0.0f };
		vertices[i].color = m_color;
	}

	return vertices;
}

unsigned int* Quad::generateIndices(unsigned int& indexCount)
{
	//Set the number of indices
	indexCount = 6;

	unsigned int* indices = new unsigned int[indexCount]{
		0, 1, 2,
		2, 1, 3
	};

	return indices;
}
