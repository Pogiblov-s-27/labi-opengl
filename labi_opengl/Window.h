/*
 * Window.h
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Map.h"
#include "Player.h"
#include "Texture.h"

class Window final
{
	private:
	int _width, _height;

	static constexpr int CELL_SIZE = 20;
	static constexpr int MAP_OFFSET = 10;

	static constexpr double WALL_HEIGHT = 0.5;

	static constexpr int PLAYER_SIZE = 4;
	static constexpr int PLAYER_ARROW = CELL_SIZE / 2;
	static constexpr double PLAYER_WALK_DIST = 0.02;
	static constexpr double PLAYER_TURN_ANGLE = 0.03;
	static constexpr double MOUSE = 0.001;

	std::shared_ptr<SDL_Window> _window;
	std::shared_ptr<void> 		_gl_context;
	std::shared_ptr<Map> _map;
	Player _player;

	std::shared_ptr<Texture> _wall_tex;
	std::shared_ptr<Texture> _floor_tex;
	std::shared_ptr<Texture> _ceiling_tex;

	struct
	{
		bool walk_forward 	{ false };
		bool walk_back 		{ false };
		bool shift_right 	{ false };
		bool shift_left 	{ false };
		bool turn_right 	{ false };
		bool turn_left 		{ false };
		bool tilt_down 		{ false };
		bool tilt_up		{ false };
	} _controls;


	void create_window(int w, int h);
	void create_gl_context();
	void setup_gl();

	void draw_view();
	void draw_minimap();
	void draw_wall();
	void draw_floor();

	public:
		Window(int w, int h);

		void main_loop();
		void render();
		void event(const SDL_Event & e);
		void update();
};

#endif /* WINDOW_H_ */
