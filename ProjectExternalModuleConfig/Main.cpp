/* @Author: Lloyd Thomas
   @Date: 17/10/2021
*/


// Current Self-Developed Modules
#include "ProjectExternalModuleConfig.h"
#include "Modules/PlayerHUDTest.h"


using namespace std;


int main() {
	// Project Modules
	Project_External_Module_Config project_external_modules = 
		Project_External_Module_Config();

	Player_HUD_Test player_hud = Player_HUD_Test();

	// Coordinates & health
	double x, y, height;
	x = -0.75;
	y = 0.00;
	height = 0.05;
	double health = 20.00;
	double player_health = health;

	// Colours
	int r, g, b;
	r = 256;
	g = 0;
	b = 0;

	// Test run methods
	project_external_modules.Run_Test_HUD_Display(player_hud, 
		x, y, 
		height, 
		health, 
		player_health, 
		r, g, b
	);
	
	
	return 0;
}