#pragma once
#include "PlayerCamera.h"
#include "World.h"
#include "Light.h"
#include "Light2.h"
#include "OBJMesh.h"
#include "Cube.h"
#include "Light.h"
#include "GLFW/glfw3.h"
#include "Engine.h"

class Dragonorld :
	public World
{
public:
	void onStart() override;
	void onEnd() override;

	void setMouseLight(glm::vec3 mouseDirection) { m_light2->getTransform()->setPosition(glm::vec3(mouseDirection)); }

private:
	PlayerCamera* m_camera = nullptr;
	Light* m_light = nullptr;
	Light2* m_light2 = nullptr;
	OBJMesh* m_dragon = nullptr;
	Cube* m_cube = nullptr;
	GLFWcursor* m_playerMouse;
	
	Engine* camera;

	double m_mouse = 0.0;
};

