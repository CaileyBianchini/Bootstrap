#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 36;

	vertices = new Vertex[vertexCount];

	
	//1
	setVertexPosition(vertices, vertexCount, 0, { -1.0,  -1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 1, { -1.0f, -1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 2, { -1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 3, { 1.0f, 1.0f, -1.0f });

	//2
	setVertexPosition(vertices, vertexCount, 4, { -1.0f,-1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 5, { -1.0f, 1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 6, { 1.0f, -1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 7, { -1.0f, -1.0f, -1.0f });

	//3
	setVertexPosition(vertices, vertexCount, 8, { 1.0f,-1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 9, { 1.0f, 1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 10, { 1.0f,-1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 11, { -1.0f,-1.0f,-1.0f });

	//4
	setVertexPosition(vertices, vertexCount, 12, { -1.0f,-1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 13, { -1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 14, { -1.0f, 1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 15, { 1.0f,-1.0f, 1.0f });

	//5
	setVertexPosition(vertices, vertexCount, 16, { -1.0f,-1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 17, { -1.0f,-1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 18, { -1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 19, { -1.0f,-1.0f, 1.0f });

	//6
	setVertexPosition(vertices, vertexCount, 20, { 1.0f,-1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 21, { 1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 22, { 1.0f,-1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 23, { 1.0f, 1.0f,-1.0f });

	//7
	setVertexPosition(vertices, vertexCount, 20, { 1.0f,-1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 21, { 1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 22, { 1.0f,-1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 23, { 1.0f, 1.0f, 1.0f });

	//8
	setVertexPosition(vertices, vertexCount, 20, { 1.0f, 1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 21, { -1.0f, 1.0f,-1.0f });
	setVertexPosition(vertices, vertexCount, 22, { 1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 23, { -1.0f, 1.0f,-1.0f });

	//
	setVertexPosition(vertices, vertexCount, 20, { -1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 21, { 1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 22, { -1.0f, 1.0f, 1.0f });
	setVertexPosition(vertices, vertexCount, 23, { 1.0f,-1.0f, 1.0f });


	return vertices;
}

void Cube::setVertexPosition(Vertex* vertices, int vertexCount, int index, glm::vec3 position)
{
	for (int i = index; i < vertexCount; i += 8)
	{
		vertices[i].position = glm::vec4(position, 1.0f);
		vertices[i].normal = glm::vec4(position, 0.0f);
		vertices[i].color = m_color;
	}
}
