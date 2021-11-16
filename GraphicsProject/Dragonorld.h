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

	void draw();

private:
	PlayerCamera* m_camera = nullptr;
	Light* m_light = nullptr;
	Light* m_light2 = nullptr;
	OBJMesh* m_dragon = nullptr;
	Cube* m_cube = nullptr;
	GLFWcursor* m_playerMouse;
	Quad m_quad = Quad(glm::vec4(2.0f, 0.8f, 0.6f, 1.0f));

	//textures
	aie::Texture m_earthNormal;
	aie::Texture m_earthDiffuse;
	aie::Texture m_earthSpecular;
	
	Engine* camera;

	double m_mouse = 0.0;
};

