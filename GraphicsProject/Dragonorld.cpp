#include "Dragonorld.h"

void Dragonorld::onStart()
{
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);



	//Initializes the light
	m_light = new Light(
		{0.0f, 0.0f, -1.0f},		//Direction
		{0.6f, 0.66f, 0.0f, 1.0f},	//Ambient
		{0.6f, 0.6f,  1.0f, 1.0f},	//Diffuse
		{0.1f, 1.0f,  0.1f, 1.0f}	//Specular
	);
	add(m_light);

	m_light2 = new Light2(
		{10.0f, 0.0f, 1.0f},			//Direction
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
