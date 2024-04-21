
#ifndef TARGET_H
#define TARGET_H
#include <vector>
class Target
{
public:
	Target();
	float x, y;
	int indice;
	float speed_x, speed_y;
	int radius = 40;
	int color = 1;

	void PlaySoundGameOver();
	void PlaySoundHit();
	void LoadSound2();
	Target(float x, float y, int radius, float speed_x, float speed_y, int color);
	void Update();
	void Draw();
	float GetY();
	float GetX();
	int GetRadius();
	float GetSpeedY();
	float GetSpeedX();

private:





};
#endif //TARGET_H
