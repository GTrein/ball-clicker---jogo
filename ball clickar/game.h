#include <vector>
#include "target.h"
#include "bomb.h"
class Game
{
public:
	Game();
	void Run();
	std::vector<Target> targets;
	Bomb bomb;

private:
	void NewTarget();
	void Level();
	void NewBomb();
	void RemoveBomb();


};