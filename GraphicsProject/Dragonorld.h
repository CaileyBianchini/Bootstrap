#pragma once
#include "PlayerCamera.h"
#include "World.h"
#include "Light.h"
#include "OBJMesh.h"
#include "Cube.h"
#include "Quad.h"
#include "Light.h"
#include "GLFW/glfw3.h"
#include "Engine.h"
#include <Texture.h>
#include <Renderer2D.h>

class Dragonorld :
	public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;
	Light* m_light = nullptr;
	Light* m_light2 = nullptr;
	OBJMesh* m_dragon = nullptr;
	Cube* m_cube = nullptr;
	GLFWcursor* m_playerMouse;
	Quad* m_quad = nullptr;
	
	Engine* camera;

	double m_mouse = 0.0;
};

