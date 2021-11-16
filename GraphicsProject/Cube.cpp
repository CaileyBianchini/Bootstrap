#include "Cube.h"

Cube::Cube(glm::vec4 color)
{
	m_color = color;
}

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& tricount)
{
	Vertex* vertices = nullptr;
	vertexCount = 36;

	vertices = new Vertex[vertexCount];

	//Top
	setVertexPosition(vertices, vertexCount, 0, { -1.0, 1.0f, -1.0f }); //a
	setVertexPosition(vertices, vertexCount, 1, { -1.0, 1.0f,  1.0f }); //B
	setVertexPosition(vertices, vertexCount, 2, {  1.0, 1.0f,  1.0f }); //C

	setVertexPosition(vertices, vertexCount, 3, { -1.0,  1.0f, -1.0f }); //a
	setVertexPosition(vertices, vertexCount, 4, {  1.0,  1.0f, -1.0f }); //e
	setVertexPosition(vertices, vertexCount, 5, {  1.0,  1.0f,  1.0f }); //C

	//back side
	setVertexPosition(vertices, vertexCount, 6, {-1.0, 1.0f, -1.0f }); //a
	setVertexPosition(vertices, vertexCount, 7, { 1.0,-1.0f, -1.0f }); //c
	setVertexPosition(vertices, vertexCount, 8, {-1.0,-1.0f, -1.0f }); //g

	setVertexPosition(vertices, vertexCount, 9, {-1.0, 1.0f, -1.0f }); //a
	setVertexPosition(vertices, vertexCount,10, { 1.0, 1.0f, -1.0f }); //e
	setVertexPosition(vertices, vertexCount,11, { 1.0,-1.0f, -1.0f }); //c

	//side right
	setVertexPosition(vertices, vertexCount,12, { 1.0, 1.0f, -1.0f }); //e
	setVertexPosition(vertices, vertexCount,13, { 1.0,-1.0f, -1.0f }); //c 
	setVertexPosition(vertices, vertexCount,14, { 1.0,-1.0f,  1.0f }); //h

	setVertexPosition(vertices, vertexCount,15, { 1.0, 1.0f, -1.0f }); //e
	setVertexPosition(vertices, vertexCount,16, { 1.0, 1.0f,  1.0f }); //b
	setVertexPosition(vertices, vertexCount,17, { 1.0,-1.0f,  1.0f }); //h

	//side left
	setVertexPosition(vertices, vertexCount,18, {-1.0, 1.0f, -1.0f }); //a
	setVertexPosition(vertices, vertexCount,19, {-1.0, 1.0f,  1.0f }); //b
	setVertexPosition(vertices, vertexCount,20, {-1.0,-1.0f, -1.0f }); //g
	 
	setVertexPosition(vertices, vertexCount,21, {-1.0, 1.0f,  1.0f }); //b
	setVertexPosition(vertices, vertexCount,22, {-1.0,-1.0f,  1.0f }); //d
	setVertexPosition(vertices, vertexCount,23, {-1.0,-1.0f, -1.0f }); //g

	//side front
	setVertexPosition(vertices, vertexCount,24, {-1.0,-1.0f,  1.0f }); //d
	setVertexPosition(vertices, vertexCount,25, {-1.0, 1.0f,  1.0f }); //b
	setVertexPosition(vertices, vertexCount,26, { 1.0, 1.0f,  1.0f }); //c

	setVertexPosition(vertices, vertexCount,27, { 1.0, 1.0f,  1.0f }); //c
	setVertexPosition(vertices, vertexCount,28, { 1.0,-1.0f,  1.0f }); //h
	setVertexPosition(vertices, vertexCount,29, {-1.0,-1.0f,  1.0f }); //d

	//Bottom
	setVertexPosition(vertices, vertexCount,30, { -1.0, -1.0f, -1.0f }); //g
	setVertexPosition(vertices, vertexCount,31, {  1.0, -1.0f, -1.0f }); //c
	setVertexPosition(vertices, vertexCount,32, { -1.0, -1.0f,  1.0f }); //d

	setVertexPosition(vertices, vertexCount,33, {  1.0, -1.0f, -1.0f }); //c
	setVertexPosition(vertices, vertexCount,34, {  1.0, -1.0f,  1.0f }); //h
	setVertexPosition(vertices, vertexCount,35, { -1.0, -1.0f,  1.0f }); //D


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
