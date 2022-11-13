#include "Enemy.h"
#include "OverworldCamera.h"

Enemy::Enemy(const string& name, EnemyE type, int health, int baseDamage, int ox, int oy) : 
    EntityFighter(name, HitBox(ox, oy, 50, 64), HitBox(420, 220, 97, 125), health, baseDamage)
{
    vector<ofImage> leftFrames;
    vector<ofImage> rightFrames;
    vector<ofImage> idleLeftFrames;
    vector<ofImage> idleRightFrames;
    vector<ofImage> deathFrames;
    vector<ofImage> hitFrames;

    ofImage temp;
    ofImage sprite;

    if(type == EnemyE::MUSHROOM) {

        obtainFramesOf(&rightFrames    , 8, 150, 150, "images/entities/enemy/Mushroom/Run_right.png");
        obtainFramesOf(&leftFrames     , 8, 150, 150, "images/entities/enemy/Mushroom/Run_left.png");
        obtainFramesOf(&idleRightFrames, 4, 150, 150, "images/entities/enemy/Mushroom/Idle_right.png");
        obtainFramesOf(&idleLeftFrames , 4, 150, 150, "images/entities/enemy/Mushroom/Idle_left.png");
        obtainFramesOf(&deathFrames    , 4, 150, 150, "images/entities/enemy/Mushroom/Death.png");
        obtainFramesOf(&hitFrames      , 4, 150, 150, "images/entities/enemy/Mushroom/Hit.png");

        // sprite.load("images/entities/enemy/Mushroom/Run_right.png");
        // for(unsigned int i = 0; i < 8; i++) {
        //     temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
        //     rightFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Mushroom/Run_left.png");
        // for(unsigned int i = 0; i < 8; i++) {
        //     temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
        //     leftFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Mushroom/Idle_right.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     idleRightFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Mushroom/Idle_left.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     idleLeftFrames.push_back(temp);
        // }

        // sprite.load("images/entities/enemy/Mushroom/Death.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     deathFrames.push_back(temp);
        // }

        // sprite.load("images/entities/enemy/Mushroom/Hit.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     hitFrames.push_back(temp);
        // }

        //attack frames
        vector<ofImage> attack1;
        sprite.load("images/entities/enemy/Mushroom/Attack1.png");
        for(unsigned int i = 0; i < 8; i++) {
            temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
            attack1.push_back(temp);
        }
        vector<ofImage> attack2;
        sprite.load("images/entities/enemy/Mushroom/Attack2.png");
        for(unsigned int i = 0; i < 8; i++) {
            temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
            attack2.push_back(temp);
        }
        vector<ofImage> attack3;
        sprite.load("images/entities/enemy/Mushroom/Attack3.png");
        for(unsigned int i = 0; i < 11; i++) {
            temp.cropFrom(sprite, (10 - i) * 150, 0, 150, 150);
            attack3.push_back(temp);
        }

        addAttack(Attack(new Animation(4, attack1), 4, 90));
        addAttack(Attack(new Animation(4, attack2), 6, 90));
        addAttack(Attack(new Animation(4, attack3), 8, 90));
    } else if(type == EnemyE::GOBLIN) {

        obtainFramesOf(&rightFrames    , 8, 150, 150, "images/entities/enemy/Goblin/Run_right.png");
        obtainFramesOf(&leftFrames     , 8, 150, 150, "images/entities/enemy/Goblin/Run_left.png");
        obtainFramesOf(&idleRightFrames, 4, 150, 150, "images/entities/enemy/Goblin/Idle_right.png");
        obtainFramesOf(&idleLeftFrames , 4, 150, 150, "images/entities/enemy/Goblin/Idle_left.png");
        obtainFramesOf(&deathFrames    , 4, 150, 150, "images/entities/enemy/Goblin/Death.png");
        obtainFramesOf(&hitFrames      , 4, 150, 150, "images/entities/enemy/Goblin/Hit.png");

        // sprite.load("images/entities/enemy/Goblin/Run_right.png");
        // for(unsigned int i = 0; i < 8; i++) {
        //     temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
        //     rightFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Goblin/Run_left.png");
        // for(unsigned int i = 0; i < 8; i++) {
        //     temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
        //     leftFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Goblin/Idle_right.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     idleRightFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Goblin/Idle_left.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     idleLeftFrames.push_back(temp);
        // }

        // sprite.load("images/entities/enemy/Goblin/Death.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     deathFrames.push_back(temp);
        // }

        // sprite.load("images/entities/enemy/Goblin/Hit.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     hitFrames.push_back(temp);
        // }

        //attack frames
        vector<ofImage> attack1;
        sprite.load("images/entities/enemy/Goblin/Attack1.png");
        for(unsigned int i = 0; i < 8; i++) {
            temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
            attack1.push_back(temp);
        }
        vector<ofImage> attack2;
        sprite.load("images/entities/enemy/Goblin/Attack2.png");
        for(unsigned int i = 0; i < 8; i++) {
            temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
            attack2.push_back(temp);
        }
        vector<ofImage> attack3;
        sprite.load("images/entities/enemy/Goblin/Attack3.png");
        for(unsigned int i = 0; i < 11; i++) {
            temp.cropFrom(sprite, (10 - i) * 150, 0, 150, 150);
            attack3.push_back(temp);
        }

        addAttack(Attack(new Animation(4, attack1), 4, 90));
        addAttack(Attack(new Animation(4, attack2), 6, 90));
        addAttack(Attack(new Animation(4, attack3), 8, 90));
    }else if(type == EnemyE::SKELETON) {

        obtainFramesOf(&rightFrames    , 4, 150, 150, "images/entities/enemy/Skeleton/Run_right.png");
        obtainFramesOf(&leftFrames     , 4, 150, 150, "images/entities/enemy/Skeleton/Run_left.png");
        obtainFramesOf(&idleRightFrames, 4, 150, 150, "images/entities/enemy/Skeleton/Idle_right.png");
        obtainFramesOf(&idleLeftFrames , 4, 150, 150, "images/entities/enemy/Skeleton/Idle_left.png");
        obtainFramesOf(&deathFrames    , 4, 150, 150, "images/entities/enemy/Skeleton/Death.png");
        obtainFramesOf(&hitFrames      , 4, 150, 150, "images/entities/enemy/Skeleton/Hit.png");

        // sprite.load("images/entities/enemy/Skeleton/Run_right.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     rightFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Skeleton/Run_left.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     leftFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Skeleton/Idle_right.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     idleRightFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/Skeleton/Idle_left.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     idleLeftFrames.push_back(temp);
        // }

        // sprite.load("images/entities/enemy/Skeleton/Death.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     deathFrames.push_back(temp);
        // }

        // sprite.load("images/entities/enemy/Skeleton/Hit.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     hitFrames.push_back(temp);
        // }

        //attack frames
        vector<ofImage> attack1;
        sprite.load("images/entities/enemy/Skeleton/Attack1.png");
        for(unsigned int i = 0; i < 8; i++) {
            temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
            attack1.push_back(temp);
        }
        vector<ofImage> attack2;
        sprite.load("images/entities/enemy/Skeleton/Attack2.png");
        for(unsigned int i = 0; i < 8; i++) {
            temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
            attack2.push_back(temp);
        }
        vector<ofImage> attack3;
        sprite.load("images/entities/enemy/Skeleton/Attack3.png");
        for(unsigned int i = 0; i < 6; i++) {
            temp.cropFrom(sprite, (5 - i) * 150, 0, 150, 150);
            attack3.push_back(temp);
        }

        addAttack(Attack(new Animation(4, attack1), 4, 90));
        addAttack(Attack(new Animation(4, attack2), 6, 90));
        addAttack(Attack(new Animation(4, attack3), 8, 90));
    }else if(type == EnemyE::EVIL_WIZARD) {

        obtainFramesOf(&rightFrames    , 8, 150, 150, "images/entities/enemy/evilWizzard/Run_right.png");
        obtainFramesOf(&leftFrames     , 8, 150, 150, "images/entities/enemy/evilWizzard/Run_left.png");
        obtainFramesOf(&idleRightFrames, 8, 150, 150, "images/entities/enemy/evilWizzard/Idle_right.png");
        obtainFramesOf(&idleLeftFrames , 8, 150, 150, "images/entities/enemy/evilWizzard/Idle_left.png");
        obtainFramesOf(&deathFrames    , 5, 150, 150, "images/entities/enemy/evilWizzard/Death.png");
        obtainFramesOf(&hitFrames      , 4, 150, 150, "images/entities/enemy/evilWizzard/Hit.png");

        // sprite.load("images/entities/enemy/evilWizzard/Run_right.png");
        // for(unsigned int i = 0; i < 8; i++) {
        //     temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
        //     rightFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/evilWizzard/Run_left.png");
        // for(unsigned int i = 0; i < 8; i++) {
        //     temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
        //     leftFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/evilWizzard/Idle_right.png");
        // for(unsigned int i = 0; i < 8; i++) {
        //     temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
        //     idleRightFrames.push_back(temp);
        // }
        // sprite.load("images/entities/enemy/evilWizzard/Idle_left.png");
        // for(unsigned int i = 0; i < 8; i++) {
        //     temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
        //     idleLeftFrames.push_back(temp);
        // }

        // sprite.load("images/entities/enemy/evilWizzard/Death.png");
        // for(unsigned int i = 0; i < 5; i++) {
        //     temp.cropFrom(sprite, (4 - i) * 150, 0, 150, 150);
        //     deathFrames.push_back(temp);
        // }

        // sprite.load("images/entities/enemy/evilWizzard/Hit.png");
        // for(unsigned int i = 0; i < 4; i++) {
        //     temp.cropFrom(sprite, (3 - i) * 150, 0, 150, 150);
        //     hitFrames.push_back(temp);
        // }

        //attack frames
        vector<ofImage> attack1;
        sprite.load("images/entities/enemy/evilWizzard/Attack.png");
        for(unsigned int i = 0; i < 8; i++) {
            temp.cropFrom(sprite, (7 - i) * 150, 0, 150, 150);
            attack1.push_back(temp);
        }

        addAttack(Attack(new Animation(4, attack1), 4, 90));
    }

    /*
        required animations
    */
    walkLeft = new Animation(5, leftFrames);
    walkRight = new Animation(5, rightFrames);
    idleRight = new Animation(5, idleRightFrames);
    idleLeft = new Animation(5, idleLeftFrames);

    fighting = new Animation(7, idleLeftFrames);

    hit = new Animation(4, hitFrames);

    death = new Animation(10, deathFrames);
    death->setShowOnce(true);

    speed = 8;
    movingTime = 15;
    standingStillTime = 50;
    timeDirectionCounter = glm::vec2(0.0, 0.0);
    movementDirection = glm::vec2(0.0, 0.0);
    hitbox.setDirection(Direction::up);
    
}

Enemy::~Enemy() {
    delete walkLeft;
    delete walkRight;
    delete idleRight;
    delete idleLeft;

    delete fighting;

    delete death;
    delete hit;

    vector<Attack>& attacks = getAttacks();
    for(unsigned int i = 0;i < attacks.size(); i++) {
        delete attacks[i].getAnimation();
    }
}

void Enemy::obtainFramesOf(vector<ofImage>* frames, int frameCount, int imgWidth, int imgHeight, const string& path) {
    ofImage sprite;
    ofImage temp;
    sprite.load(path);
    for(int i = 0; i < frameCount; i++) {
        temp.cropFrom(sprite, (frameCount - 1 - i) * imgWidth, 0, imgWidth, imgHeight);
        frames->push_back(temp);
    }
}

Animation* Enemy::getHit() {
    return hit;
}

Animation* Enemy::getDeath() {
    return death;
}

bool Enemy::isDead() { 
    return dead; 
}

void Enemy::kill() {
    this->dead = true;
    this->health = 0;
}

void Enemy::revive() {
    this->dead = false;
    this->health = maxHealth;
}

ofImage Enemy::getSprite() {
    return overworldSprite; 
}

void Enemy::inOverworldUpdate() {

    if(linePath == 0) {
        movementDirection.x = -2.0;
        movementDirection.y =  0.0;
    } else if(linePath == 1) {
        movementDirection.x =  1.0; 
        movementDirection.y =  1.0; 
    }else if(linePath == 2) {
        movementDirection.x =  1.0;
        movementDirection.y = -1.0;
    }

    bool xFinished = false;
    if(timeDirectionCounter.x < movingTime && walking) {
        hitbox.setX(hitbox.getX() + movementDirection.x * speed);
        timeDirectionCounter.x++;
    }else {
        xFinished = true;
    }

    bool yFinished = false;
    if(timeDirectionCounter.y < movingTime && walking) {
        hitbox.setY(hitbox.getY() + movementDirection.y * speed);
        timeDirectionCounter.y++;
    } else {
        yFinished = true;
    }

    if(xFinished && yFinished) {
        timeDirectionCounter.x = 0;
        timeDirectionCounter.y = 0;
        walking = false;
        standingStillCounter++;
    }

    if(standingStillCounter > standingStillTime) {
        standingStillCounter = 0;
        walking = true;
        linePath++;
        if(linePath > 2)
            linePath = 0;
    }

    if(walking) {
        if(movementDirection.x < 0) {
            walkLeft->update();
            overworldSprite = walkLeft->getCurrentFrame();
            hitbox.setDirection(Direction::left);
        } else if(movementDirection.x > 0) {
            walkRight->update();
            overworldSprite = walkRight->getCurrentFrame();
            hitbox.setDirection(Direction::right);
        } else if(movementDirection.y > 0) {
            walkRight->update();
            overworldSprite = walkRight->getCurrentFrame();
            hitbox.setDirection(Direction::down);
        } else if(movementDirection.y < 0) {
            walkRight->update();
            overworldSprite = walkRight->getCurrentFrame();
            hitbox.setDirection(Direction::up);
        }
    }else {
        if(movementDirection.x < 0) {
            idleLeft->update();
            overworldSprite = idleLeft->getCurrentFrame();
        } else if(movementDirection.x > 0) {
            idleRight->update();
            overworldSprite = idleRight->getCurrentFrame();
        } else if(movementDirection.y > 0) {
            idleRight->update();
            overworldSprite = idleRight->getCurrentFrame();
        } else if(movementDirection.y < 0) {
            idleRight->update();
            overworldSprite = idleRight->getCurrentFrame();
        }      
    }
}

void Enemy::inOverworldDraw(void* camera) {
    OverworldCamera* cameraPtr = static_cast<OverworldCamera*>(camera);

    double xAspectDif = ofGetWidth() / cameraPtr->getLenzWidth();
    double yAspectDif = ofGetHeight() / cameraPtr->getLenzHeight();

    int playerDistanceX = (hitbox.getRenderX() - cameraPtr->getCameraX()) * xAspectDif;
    int playerDistanceY = (hitbox.getRenderY() - cameraPtr->getCameraY()) * yAspectDif;

    renderX = ofGetWidth()  / 2 + playerDistanceX;
    renderY = ofGetHeight() / 2 + playerDistanceY;

    overworldSprite.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    overworldSprite.draw(renderX, renderY, hitbox.getRenderWidth() * xAspectDif, hitbox.getRenderHeight() * yAspectDif);
}

void Enemy::fightingUpdate() {
    fightingSprite = fighting->getCurrentFrame();
    fighting->update();

    int xpos = ofGetWidth() * (3.0 / 4.0) - fightingHitbox.getWidth()  / 2;
    int ypos = ofGetHeight() * (1.0 / 2.0) - fightingHitbox.getHeight() / 2;

    fightingHitbox.setX(xpos);
    fightingHitbox.setY(ypos);
}

void Enemy::reset() {
}
