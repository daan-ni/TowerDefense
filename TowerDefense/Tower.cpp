#include "Tower.h"
#include "TowerDefense.h"
#include "TowerPower.h"
#include "Enemy.h"
#include "Floor.h"

Tower::Tower(uint twrType) {

	towerType = twrType;

	if (towerType == GREEN) {
		sprite = new Sprite("Resources/statueGreen.png");
		BBox(new Circle(180));
	}

	if (towerType == YELLOW) {
		sprite = new Sprite("Resources/statueYellow.png");
		BBox(new Circle(180));
	}

	// new Rect(-24, -2, 23, 43)

	MoveTo(window->CenterX(), window->CenterY());

	life = 5;

	type = TOWER;
}

Tower::~Tower() {
	delete sprite;
}

void Tower::Update() {
	if (life <= 0) {
		TowerDefense::scene->Delete();
	}

	if (towerType == GREEN || towerType == YELLOW) {
		// s� pra come�ar a contar o tempo
		if (TowerPower::cdr == 50) {
			atackTime.Start();
		}
	}

}

void Tower::Draw() {
	sprite->Draw(x, y, z);

	// , 1.0f, 0.0f, {1.3, 1, 1, 1} -> vermelho soft
	// {2, 35, 212, 1} -> cristal
}

void Tower::OnCollision(Object* obj) {

	if (obj->Type() == ENEMY) {
		Enemy* enemy = dynamic_cast<Enemy*>(obj);

		if (enemy->State() < DEATH || enemy->State() > DEAD) {
			if (towerType == GREEN) {
				if (atackTime.Elapsed(1.0f)) {
					TowerPower* power = new TowerPower(x, y, enemy->X(), enemy->Y(), GREEN);
					TowerDefense::scene->Add(power, MOVING);
					atackTime.Reset();
				}
			}

			if (towerType == YELLOW) {
				if (atackTime.Elapsed(2.0f)) {
					TowerPower* power = new TowerPower(x, y, enemy->X(), enemy->Y(), YELLOW);
					TowerDefense::scene->Add(power, MOVING);
					atackTime.Reset();
				}
			}
		}

	}

	if (obj->Type() == FLOOR) {
		Floor* floor = dynamic_cast<Floor*>(obj);

		text.str("");

		text << floor->X() << ".\n";;
		OutputDebugString(text.str().c_str());

		// Os c�digos a seguir meio que delimitam que as est�tuas n�o podem ser colocadas em cima dos pisos. Existe um ponto cego no meio dos blocos

		/*if ((x + Width()) > floor->X() + floor->Width()) {	// delimitar mais esse if
			MoveTo(floor->X() + floor->Width() - 10, y);
		}

		if ((x + Width()) < floor->X() + floor->Width()) {	// delimitar mais esse if
			MoveTo(floor->X() - floor->Width() + 10, y);
		}*/

		/*if ((y + Height()) > floor->Y() + floor->Height()) {	// delimitar mais esse if
			MoveTo(x, floor->X() - floor->Width() + 10);
		}*/
	}

	if (obj->Type() == TOWER) {

	}
}