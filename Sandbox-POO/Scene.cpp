// Jules ROBIN

#include <iostream>
#include <vector>
#include "Scene.h"

Scene::Scene(unsigned int sizeX, unsigned int sizeY, bool vide) {
	sizeX_ = sizeX;
	sizeY_ = sizeY;
	vide_ = vide;
	scene_ = {};
	for (int x = 0; x < sizeX; x++) {
		vector<Materiau*> v = {};
		for (int y = 0; y < sizeY; y++) {
			v.push_back(nullptr);
		}
		scene_.push_back(v);
	}
}


Scene::~Scene() {
	for (int x = 0; x < sizeX_; x++) {
		for (int y = 0; y < sizeY_; y++) {
			if (scene_[x][y] != nullptr) {
				delete scene_[x][y];
			}
		}
	}
}


void Scene::print() const{
	for (int x = 0; x < sizeX_; x++) {
		for (int y = 0; y < sizeY_; y++) {
			if (scene_[x][y] != nullptr) {
				cout << " " << scene_[x][y]->getDensity() << " ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < sizeY_; i++) {
		cout << "---";
	}
	cout << endl;
}


void Scene::resize(unsigned int sizeX, unsigned int sizeY) {
	if (sizeY < sizeY_) {
		for (int x = 0; x < sizeX_; x++) {
			for (int m = 0; m < sizeY_ - sizeY; m++) {
				if (scene_.at(x).back() != nullptr) {
					delete scene_.at(x).back();
				}
				scene_[x].pop_back();
			}
		}
	}
	else if (sizeY > sizeY_) {
		for (int x = 0; x < sizeX_; x++) {
			for (int m = 0; m < sizeY - sizeY_; m++) {
				scene_[x].push_back(nullptr);
			}
		}
	}
	sizeY_ = sizeY;

	if (sizeX < sizeX_) {
		for (int n = 1; n <= sizeX_ - sizeX; n++) {
			for (int y = 0; y < sizeY_; y++) {
				if (scene_[sizeX_ - n][y] != nullptr) {
					delete scene_[sizeX_ - n][y];
				}
			}
			scene_.pop_back();
		}
	}
	else if (sizeX > sizeX_) {
		vector<Materiau*> V = {};
		for (int y = 0; y < sizeY_; y++) {
			V.push_back(nullptr);
		}
		for (int n = 0; n < sizeX - sizeX_; n++) {
			scene_.push_back(V);
		}
	}
	sizeX_ = sizeX;
}


void Scene::switchGround() {
	vide_ = not vide_;
}


void Scene::errase() {
	for (int i = 0; i < sizeX_; i++) {
		for (int j = 0; j < sizeY_; j++) {
			removeMaterial(i, j);
		}
	}
}


Materiau* Scene::setMaterial(Materiau* M, unsigned int x, unsigned int y) {
	if ((x >= 0) && (x < sizeX_) && (y >= 0) && (y < sizeY_)) {
		Materiau* exM = getMaterial(x, y);
		scene_[x][y] = M;
		M->setX(x);
		M->setY(y);
		return exM;
	}
	return nullptr;
}


void Scene::removeMaterial(unsigned int x, unsigned int y) {
	if ((x >= 0) && (x < sizeX_) && (y >= 0) && (y < sizeY_) && (scene_[x][y] != nullptr)) {
		Materiau* M = scene_[x][y];
		scene_[x][y] = nullptr;
		delete M;
	}
}


void Scene::evolve() {
	vector<vector<Materiau*>>::reverse_iterator it_ligne;
	vector<Materiau*>::reverse_iterator it_materiau;

	for (it_ligne = scene_.rbegin(); it_ligne != scene_.rend(); it_ligne++) {		//lecture de bas en haut
		vector<Materiau*> ligne = *it_ligne;

		for (it_materiau = ligne.rbegin(); it_materiau != ligne.rend(); it_materiau++) {		//de droite � gauche
			Materiau* M = *it_materiau;

			if (M != nullptr) {
				if (not M->hasMoved()) {
					if (M->evolveState(&scene_, vide_)) {		// Detecte et detruit si le materiau tombe hors de la scene
						if (M->getDensity() == 0) {
							removeMaterial(M->getX(), M->getY());
						}
						else {
							Materiau* M_voisin = setMaterial(M, M->getX(), M->getY());			// Decale le materiau

							if (M_voisin != nullptr) {			// Deplace le materiau remplace
								int n = rand() % 2;
								if (scene_[M_voisin->getX()][M_voisin->getY() + 1 - 2 * n] == nullptr) {
									M_voisin->setY(M_voisin->getY() + 1 - 2 * n);
								}
								else if (scene_[M_voisin->getX()][M_voisin->getY() - 1 + 2 * n] == nullptr) {
									M_voisin->setY(M_voisin->getY() - 1 + 2 * n);
								}
								else if (scene_[M_voisin->getX() - 1][M_voisin->getY()] == nullptr) {
									M_voisin->setX(M_voisin->getX() - 1);
								}
								else {
									n = rand() % 2;
									if (scene_[M_voisin->getX() - 1][M_voisin->getY() + 1 - 2*n] == nullptr) {
										M_voisin->setX(M_voisin->getX() - 1);
										M_voisin->setY(M_voisin->getY() + 1 - 2 * n);
									}
									else{
										M_voisin->setX(M_voisin->getX() - 1);
										M_voisin->setY(M_voisin->getY() - 1 + 2 * n);
									}
								}
								setMaterial(M_voisin, M_voisin->getX(), M_voisin->getY());
								M_voisin->setMovedAt(true);
							}
							M->setMovedAt(true);		// Indique que le materiau a ete deplace pour ne pas le traiter deux fois de suite
						}
					}
				}
			}
		}
	}
	for (vector<Materiau*> ligne : scene_) {		//une fois tous les materiaux bouges
		for (Materiau* M : ligne) {					//on les remets au repos
			if (M != nullptr) {
				M->setMovedAt(false);
			}
		}
	}
}