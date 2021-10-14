#include "Dragonorld.h"

void Dragonorld::onStart()
{
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Inotializes the light
	m_light = new Light();
	m_light->setDirection(glm::vec3(-1.0f));
	m_light->setAmbient(glm::vec4(0.6f, 0.66, 0.0f, 1.0f));
	m_light->setDiffuse(glm::vec4(0.6f, 0.6f, 1.0f, 1.0f));
	m_light->setSpecular(glm::vec4(glm::vec4(0.1f, 1.0f, 0.1f, 1.0f)));
	m_light->setSpecularPower(1.0f);

	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj"); //TO DO: add if check
	m_dragon->getTransform()->setScale(glm::vec3(0.2f));
	add(m_dragon);

	//cube
	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.6f, 0.2f, 0.4f, 1.0f));
	m_cube->getTransform()->setPosition(glm::vec3(10.0f, 5.0f, 5.0f));
	add(m_cube);
}

void Dragonorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_dragon);
	destroy(m_cube);
}
