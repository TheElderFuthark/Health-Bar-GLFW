/* @Author: Lloyd Thomas
   @Date: 21/07/2021
*/
#include <GL/glew.h>
#include <gl/GL.h>
#include "GLFW/glfw3.h"
#include "../stb/stb_image.h"
#include <iostream>


class Player_HUD_Test {
	public:
		bool is_hud_active = false;

		GLFWwindow* Player_HUD_Test::Open_Graphics_Window();
		void Player_HUD_Test::Draw_HUD_Background_Layer(GLFWwindow* graphics_window);
		void Player_HUD_Test::Draw_HUD(GLFWwindow* graphics_window,
			double bar_location_origin_x, double bar_location_origin_y,
			double bar_height,
			double health,
			double player_health,
			int r, int g, int b
		);

		void Player_HUD_Test::Hide_HUD(GLFWwindow* graphics_window);
		void Player_HUD_Test::Show_HUD(GLFWwindow* graphics_window);
		void Player_HUD_Test::Buffer_HUD(GLFWwindow* graphics_window);


		Player_HUD_Test();
		~Player_HUD_Test();
	protected:
	private:
};