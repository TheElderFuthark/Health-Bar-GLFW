/* @Author: Lloyd Thomas
   @Date: 17/10/2021
*/
#include "PlayerHUDTest.h"


using namespace std;


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;


void Player_HUD_Test::Buffer_HUD(GLFWwindow* graphics_window) {
    // Buffers window & adds new actions & 
    // executes all current pending events
    glfwSwapBuffers(graphics_window);
    glfwPollEvents();
}


void Player_HUD_Test::Show_HUD(GLFWwindow* graphics_window) {
    // Shows window
    glfwShowWindow(graphics_window);
}


void Player_HUD_Test::Hide_HUD(GLFWwindow* graphics_window) {
    // Hides window
    glfwHideWindow(graphics_window);
}

 
void Player_HUD_Test::Draw_HUD(GLFWwindow* graphics_window,
    double bar_location_origin_x,
    double bar_location_origin_y,
    double bar_height, 
    double health,
    double player_health,
    int r,
    int g,
    int b
) { 
    // Config
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Colour
    glColor3d(r, g, b);
    
    // Begin drawing
    glBegin(GL_QUADS);

    // Sets shape coordinates & Draws
    /* Top left */ glVertex2d(bar_location_origin_x, bar_location_origin_y);
    /* Top right */ glVertex2d( /* width = */ player_health, bar_location_origin_y);
    /* Bottom right */ glVertex2d( /* width = */ player_health, /* height = */ bar_height);
    /* Bottom left */ glVertex2d(bar_location_origin_x /* height = */, bar_height);

    // Finish drawing
    glEnd();
}


GLFWwindow* Player_HUD_Test::Open_Graphics_Window() {
	std::cout << "Graphics Window Opening..." << std::endl;

    // Initialise
    glfwInit();

    // Parse vals to GLFW vars
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    // Generate Graphics Window
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "Graphics Window Test",
        '\0',
        '\0'
    );

    return window;
}


Player_HUD_Test::Player_HUD_Test() {
    std::cout << "Player HUD initialising..." << std::endl;
}


Player_HUD_Test::~Player_HUD_Test() {
    std::cout << "Player HUD process finished..." << std::endl;
}