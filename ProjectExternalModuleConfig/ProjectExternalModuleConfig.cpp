/* @Author: Lloyd Thomas
   @Date: 22/07/2021
*/
#include "ProjectExternalModuleConfig.h"
#include "Modules/PlayerHUDTest.h"
#include <iostream>


using namespace std;


void Project_External_Module_Config::Run_Test_HUD_Display(Player_HUD_Test hud_display,
	double x, double y,
	double height,
	double health,
	double player_health,
	int r, int g, int b
) {
	bool game_paused = false; // IF true, hide HUD

	// Opens new graphics window
	GLFWwindow* graphics_window = hud_display.Open_Graphics_Window();

	// Applies context to OpenGL
	glfwMakeContextCurrent(graphics_window);

	// WHILE no key is pressed
	while(true) {
		if(!game_paused) { // IF pause menu is active
			hud_display.is_hud_active = true;
		} else {
			hud_display.is_hud_active = false;
		}

		// Updates and displays HUD
		if(hud_display.is_hud_active) {
			// Draws HUD
			hud_display.Draw_HUD_Background_Layer(graphics_window);
			hud_display.Draw_HUD(graphics_window,
				x, y,
				height,
				health,
				player_health,
				r, g, b
			);
		} else {
			// Hides HUD
			hud_display.Hide_HUD(graphics_window);
		}

		if (player_health <= -0.75) {
			while (player_health < health) {
				player_health += 0.09;
				hud_display.Draw_HUD(graphics_window,
					x, y,
					height,
					health,
					player_health,
					r, g, b
				);

				hud_display.Buffer_HUD(graphics_window);
			}
		} else {
			player_health -= 0.09;
		}

		hud_display.Buffer_HUD(graphics_window);
	}

	// Removes HUD
	glfwMakeContextCurrent('\0');
	
	// Destroys graphics window
	glfwDestroyWindow(graphics_window);
	
	// Terminates GLFW session
	glfwTerminate();
}


Project_External_Module_Config::Project_External_Module_Config() {
	std::cout << "Beginning Module tests..." << std::endl;
}


Project_External_Module_Config::~Project_External_Module_Config() {
	std::cout << "Module Test Processes finished..." << std::endl;
}