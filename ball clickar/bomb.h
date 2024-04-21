
#ifndef BOMB_H
#define BOMB_H
#include <vector>
class Bomb
{
public:
	Bomb();
	float x, y;
	int indice;
	float speed_x, speed_y;
	int radius = 40;
	int color = 1;

	void LoadTextures();
	Bomb(float x, float y, int radius, float speed_x, float speed_y);
	void Update();
	void Draw();
	void SetY(float y);
	int GetY();
	void Sound();

private:





};
#endif //BOMB_H
