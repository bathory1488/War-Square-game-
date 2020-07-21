#include "snake.h"
#include <cmath>

void snake::generate()
{
	for (int n = 0; n < game_height; n++) {
		for (int k = 0; k < game_width; k++) {
			fruts[n][k] = 0;
		}
	}
	int frut_count = 0;
	while (frut_count != 10) {

		int x = game_height + rand() % game_width - game_height + 1;
		int y = game_width + rand() % game_height - game_width + 1;

		fruts[x][y] = 1;
		frut_count++;
	}
}

void snake::generate_new(int x, int y)
{
	fruts[x][y] = 0;
}

void snake::generate_new_2(int w, int z)
{
	fruts[w][z] = 0;
}

void snake::Draw_fruts_dead(RenderWindow * window, RectangleShape * square_dead, int x, int y, int w, int z)
{
	if (fruts[x][y] == 1) {

		square_dead->setPosition(x * Cells, y * Cells);

		window->draw(*square_dead);

	}

	if (fruts[w][z] == 1) {

		square_dead->setPosition(w * Cells, z * Cells);

		window->draw(*square_dead);

	}
}

void snake::Draw_fruts(RenderWindow * window, RectangleShape * square)
{
	for (int i = 0; i < game_height; i++) {
		for (int j = 0; j < game_width; j++) {

			if (fruts[i][j] == 1) {

				square->setPosition(i * Cells, j * Cells);

				window->draw(*square);

			}
		}
	}
}

void snake::scan(RenderWindow * window, RectangleShape * snake_1)
{
	int s = height + rand() % width;

	for (int i = -(s)+rand() % s; i < game_height; i++) {
		for (int j = -(s)+rand() % s * s; j < game_width; j++) {

			for (int i = 0 + rand() % 52 * 2; i < game_height; i++) {
				for (int j = 0 + rand() % 52 * 2; j < game_width; j++) {

					if (fruts[i][j] == 1) {

						snake_1->setPosition(i * Cells, j * Cells);

						window->draw(*snake_1);
					}
				}
			}


		}
	}

}

void snake::scan_2(RenderWindow * window, RectangleShape * snake_2)
{
	int s = height + rand() % width;

	for (int i = -(s) + rand() % s; i < game_height; i++) {
		for (int j = -(s)+rand() % s * s; j < game_width; j++) {

			for (int i = 0 + rand() % 52 * 2; i < game_height; i++) {
				for (int j = 0 + rand() % 52 * 2; j < game_width; j++) {

					if (fruts[i][j] == 1) {

						snake_2->setPosition(i * Cells, j * Cells);

						window->draw(*snake_2);
					}
				}
			}


		}
	}

}

void snake::dock(RectangleShape *snake_1, RectangleShape *snake_2, RectangleShape *square, RectangleShape *square_dead)
{
	snake_1->setFillColor(Color(1, 1000, 1));
	snake_1->setSize(Vector2f(Cells, Cells));
	snake_1->setPosition(height / 2, width / 2);

	snake_2->setFillColor(Color(1000, 100, 10));
	snake_2->setSize(Vector2f(Cells, Cells));
	snake_2->setPosition(height / 2 - 100, width / 2 - 100);

	square->setFillColor(Color(100, 80, 510));
	square->setSize(Vector2f(Cells, Cells));

	square_dead->setFillColor(Color(0, 0, 0));
	square_dead->setSize(Vector2f(Cells, Cells));
}


void snake::start()
{
	srand(time(NULL));

	Font font;
	//font.loadFromFile("C:\\AdobeClean-Bold.ttf");
	font.loadFromFile("C:\\AdobeClean-Bold.ttf");
	Text text("", font, 35);

	RenderWindow window(VideoMode(height, width), "xxx WarSquare xxx", Style::Close);

	RectangleShape square, snake_1, snake_2, square_dead;

	dock(&snake_1, &snake_2, &square, &square_dead);

	generate();

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();
		}

		window.setFramerateLimit(FPS);

		Vector2f pos = snake_1.getPosition();
		int x = pos.x / Cells;
		int y = pos.y / Cells;

		Vector2f pos_2 = snake_2.getPosition();
		int w = pos_2.x / Cells;
		int z = pos_2.y / Cells;

		window.clear();

		if (fruts[x][y] == 1) {

			generate_new(x, y);
			
			Draw_fruts_dead(&window, &square_dead, x, y, w, z);

			ckor++;

			fruts[game_height + rand() % game_width - game_height + 1][game_width + rand() % game_height - game_width + 1] = 1,
			fruts[game_height + rand() % game_width - game_height + 1][game_width + rand() % game_height - game_width + 1] = 1;
		}
		if (fruts[w][z] == 1) {

			generate_new_2(w, z);

			Draw_fruts_dead(&window, &square_dead, x, y, w, z); 

			ckor_2++;

			fruts[game_height + rand() % game_width - game_height + 1][game_width + rand() % game_height - game_width + 1] = 1;
			fruts[game_height + rand() % game_width - game_height + 1][game_width + rand() % game_height - game_width + 1] = 1;
		}
		
		scan(&window, &snake_1);

		scan_2(&window, &snake_2);

		Draw_fruts(&window, &square);

		std::ostringstream playerCkor;
		playerCkor << ckor;
		text.setFillColor(Color(1, 1000, 1));
		text.setString("Green: " + playerCkor.str());
		text.setPosition(x = 10, y = 10);
		window.draw(text);

		std::ostringstream playerCkor_2;
		playerCkor_2 << ckor_2;
		text.setFillColor(Color(1000, 100, 10));
		text.setString("Orange: " + playerCkor_2.str());
		text.setPosition(x = 10, y = 45);
		window.draw(text);

		window.draw(snake_1);
		window.draw(snake_2);

		window.display();
	}
}
