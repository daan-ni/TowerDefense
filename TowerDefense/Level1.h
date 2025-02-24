#pragma once
#include "Button.h"
#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Scene.h"
#include "Priest.h"


class Level1 : public Game {
private:
	Sprite* ground;
	Sprite* floor;
	TileSet* rain;
	Animation* rainAnimation;
	// TileSets mobs
	TileSet* tilesetCenoura;
	TileSet* tilesetBatata;
	TileSet* tilesetCebola;
	TileSet* tilesetNabo;
	TileSet* tilesetBrocolis;
	TileSet* tilesetCheiroVerde;
	TileSet* tilesetMilho;
	TileSet* tilesetAlface;
	TileSet* tilesetCouveFlor;
	Button* button1;
	Button* button2;
	Button* button3;
	Button* button4;
	Button* button5;
	Priest * priest;
public:
	static Scene* scene;

	void Init();
	void Update();
	void Draw();
	void Finalize();

};