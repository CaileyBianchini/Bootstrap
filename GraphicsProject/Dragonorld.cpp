#include "Dragonorld.h"
#include "gl_core_4_4.h"
#include "glm/ext.hpp"

void Dragonorld::onStart()
{
	m_quad.getTransform()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	m_quad.start();

	if (!m_earthNormal.load("earth_normal.jpg"))
		printf("Oopsies! Earth Normal didnt load! \n");
	if (!m_earthDiffuse.load("earth_diffuse.jpg"))
		printf("Oopsies! Earth Diffuse didn't load! \n");
	if (!m_earthSpecular.load("earth_specular.jpg"))
		printf("Oopsies! Earth Specular didnt load! \n");

	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Initializes the light
	m_light = new Light(
		0,
		{0.0f, 0.0f, -1.0f},		//Direction
		{0.6f, 0.66f, 0.0f, 1.0f},	//Ambient
		{0.6f, 0.6f,  1.0f, 1.0f},	//Diffuse
		{0.1f, 1.0f,  0.1f, 1.0f}	//Specular
	);
	add(m_light);

	m_light2 = new Light(
		1,
		{1.0f,	0.5f, 0.5f},			//Direction
		{1.0f,  0.5f, 0.0f, 1.0f},	//Ambient
		{0.1f,  0.6f, 0.5f, 1.5f},	//Diffuse
		{0.5f,  0.7f, 1.0f, 0.5f}	//Specular
	);
	add(m_light2);


	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj"); //TO DO: add if check
	m_dragon->getTransform()->setScale(glm::vec3(0.2f));
	add(m_dragon);

	//cube
	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.6f, 0.2f, 0.4f, 1.0f));
	m_cube->getTransform()->setPosition(glm::vec3(0.0f, 1.0f, 0.0f));
	add(m_cube);

}

void Dragonorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_dragon);
	destroy(m_cube);
}

void Dragonorld::draw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("no shader bound. \n");

	//normal
	int normalTextureUniform = glGetUniformLocation(program, "normalTexture"); //this is where normal texture is located
	if (normalTextureUniform >= 0)
		glUniform1i(normalTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_earthNormal.getHandle());

	//diffuse
	int diffuseTextureUniform = glGetUniformLocation(program, "difuseTexture"); //this is where diffuse texture is located
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_earthDiffuse.getHandle());

	//specular
	int specularTextureUniform = glGetUniformLocation(program, "specularTexture"); //this is where specular texture is located
	if (specularTextureUniform >= 0)
		glUniform1i(specularTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_earthSpecular.getHandle());

	m_quad.draw();

}
