#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cmath>
using namespace sf;

class snake
{
	#define height 810
	#define width 810
	#define Cells 15
	#define game_height height / Cells
	#define game_width width / Cells
	int fruts[game_height][game_width];
	int frut_count = 0;
	bool r = true;
	int ckor = 0;
	int ckor_2 = 0;
	int FPS = 220;
	int line = 0;

	void generate();

	void generate_new(int x, int y);

	void generate_new_2(int w, int z);

	void Draw_fruts_dead(RenderWindow * window, RectangleShape * square_dead, int x, int y, int w, int z);

	void Draw_fruts(RenderWindow* window, RectangleShape* square);

	void scan(RenderWindow *window, RectangleShape *snake_1);

	void scan_2(RenderWindow *window, RectangleShape *snake_2);

	void dock(RectangleShape *snake_1, RectangleShape *snake_2, RectangleShape *square, RectangleShape *square_dead);
	

public:

	void start();

};

