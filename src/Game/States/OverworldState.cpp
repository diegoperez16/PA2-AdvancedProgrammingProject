#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area) {
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
}

void OverworldState::loadArea(Area *area) {
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    HitBox& playerHitbox = player->getHitBox();
    // playerHitbox.setX(area->getEntrancePos().x);
    // playerHitbox.setY(area->getEntrancePos().y);

    playerHitbox.setX(OXDIMENSION / 2);
    playerHitbox.setY(OYDIMENSION / 2);
}

void OverworldState::update() {
    player->inOverworldUpdate();
    camera->update();

    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        Enemy& enemy = *(area->getEnemies().at(i));
        if (!enemy.isDead()) {
            enemy.inOverworldUpdate();
            HitBox& playerHitbox = player->getHitBox();
            if (playerHitbox.collides(enemy.getHitBox())) {
                setEnemy(area->getEnemies().at(i));
                setNextState("Battle");
                setFinished(true);
                break;
            }
        }
    }
    
    area->rock->inOverworldUpdate();

    HitBox& playerHitbox = player->getHitBox();
    HitBox& rockHitbox = area->rock->getHitBox();
    
    playerHitbox.collides(rockHitbox);
}

void OverworldState::draw() {
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->inOverworldDraw();

    ofDrawBitmapString("player position " + ofToString(player->getHitBox().getX()) + ", " + ofToString(player->getHitBox().getY()), 50, 100);

    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        Enemy& enemy = *(area->getEnemies().at(i));
        if (!enemy.isDead()) {
            // int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            // int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            HitBox& enemyHitbox = enemy.getHitBox();
            int playerDistanceX = enemyHitbox.getX() - camera->getCameraX();
            int playerDistanceY = enemyHitbox.getY() - camera->getCameraY();
            enemy.setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            enemy.setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            enemy.inOverworldDraw();
        }
    }

    if(area->rock == nullptr)
        return;

    HitBox& rockHitbox = area->rock->getHitBox();
    int playerDistanceX = rockHitbox.getX() - camera->getCameraX();
    int playerDistanceY = rockHitbox.getY() - camera->getCameraY();
    area->rock->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
    area->rock->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
    area->rock->inOverworldDraw();

}

void OverworldState::keyPressed(int key) {
    player->keyPressed(key);
}

void OverworldState::keyReleased(int key) {
    player->keyReleased(key);
}

void OverworldState::reset() {
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}