#include"Scene.h"

Scene::Scene() {
	player = new Paddle();
}

Scene::~Scene() {

}

void Scene::draw(sf::RenderTarget &target) {
	target.draw(player->getShape());
}

void Scene::onEvent(const sf::Event event) {
	player->onEvent((sf::Event&)event);
}

void Scene::update(float frameTime) {
	player->update(frameTime);
}