#include "BattleState.h"
#include "Attack.h"
#include "Defense.h"

BattleState::BattleState(Player *player, Area *area) {
    stage = area->getStage();

    /*
        Battle Music 
        change depending of enemy
    */
    music.load("audio/battle.wav");
    music.setLoop(true);
    music.setVolume(0.25);

    /*
        Interact sounds
    */
    buttonChange.load("audio/ui/beep.mp3");
    buttonChange.setVolume(0.5);
    buttonSelect.load("audio/ui/boop.mp3");
    buttonSelect.setVolume(0.5);

    /*
        Interact images 
    */
    button1.load("images/ui/buttons/rock.png");
    button2.load("images/ui/buttons/paper.png");
    button3.load("images/ui/buttons/scissors.png");
    result1.load("images/ui/buttons/rock1.png");
    result2.load("images/ui/buttons/paper1.png");
    result3.load("images/ui/buttons/scissors1.png");

    /*
        default setup
    */
    this->player = player;
    currentButton = 1;
    resultTimer = 0;
    canInteract = true;
    isAttacking = false;
    needsToReHeal = false;
    enemyHasChosenAttack = false;
    currentPlayerHealth = PLAYER_MAX_HP = player->getHealth();
}

Enemy* BattleState::getEnemy() {
    return enemy;
}

void BattleState::setEnemy(Enemy *enemy) {
    this->enemy = enemy;
    ENEMY_MAX_HP = enemy->getHealth();
    Boss* boss = dynamic_cast<Boss*>(enemy);
    if(boss != nullptr)
        bossPhases = boss->getPhases();
}

void BattleState::setStage(ofImage stage) {
    this->stage = stage;
}

void BattleState::startBattle(Enemy *enemy) {
    this->enemy = enemy;
    currentEnemyHealth = enemy->getHealth();
    currentPlayerHealth = player->getHealth();
    ENEMY_MAX_HP = enemy->getHealth();
    Boss* boss = dynamic_cast<Boss*>(enemy);
    if(boss != nullptr)
        bossPhases = boss->getPhases();
}

void BattleState::reHeal() {
    if(currentEnemyHealth > ENEMY_MAX_HP) {
        currentEnemyHealth = ENEMY_MAX_HP;
        needsToReHeal = false;
    } else if(needsToReHeal) {
        currentEnemyHealth += 1;
    }
}

void BattleState::update() {
    if (canInteract) {
        if (currentPlayerHealth <= 0) {
            setNextState(CurrentState::END);
            setFinished(true);
            player->setHealth(currentPlayerHealth);
            return;
        } else if (currentEnemyHealth <= 0) {
            if(bossPhases > 1) {
                bossPhases--;
                needsToReHeal = true;
                currentEnemyHealth = 1;
                return;
            }
            setNextState(CurrentState::WIN);
            setFinished(true);
            player->setHealth(currentPlayerHealth);
            return;
        }
    }

    reHeal();

    //update sprite animation
    player->fightingUpdate();
    enemy->fightingUpdate();

    if(isAttacking) {

        //TODO
        //add defenses
        
        Attack& playerAttack = player->getAttack(player->getAttackChoice());
        playerAttack.provokeAttack(&currentEnemyHealth, 1);

        if(!enemyHasChosenAttack) {
            enemy->setAttackChoice(rand() % enemy->getNumberOfAttacks());
            enemyHasChosenAttack = true;
        }
        Attack& enemyAttack = enemy->getAttack(enemy->getAttackChoice());
        if(!playerAttack.isOnCoolDown()) {
            enemyAttack.provokeAttack(&currentPlayerHealth, enemy->getBaseDamage());
        }

        if(!enemyAttack.isOnCoolDown() && !playerAttack.isOnCoolDown()) {
            enemyAttack.reset();
            playerAttack.reset();
            canInteract = true;
            isAttacking = false;
            enemyHasChosenAttack = false;
        }
    }
}

void BattleState::draw() {
    // render stage
    stage.draw(0, 0, ofGetWidth(), ofGetHeight());

    // render combatant sprites
    player->fightingDraw();
    enemy->fightingDraw();

    //draw healthBar from both enemy and player
    int healthBarWidth = 256;
    int centerXEnemy = enemy->getFightingHitBox().getX() + enemy->getFightingHitBox().getRenderWidth() / 2 - healthBarWidth / 2;
    int centerXPlayer = player->getFightingHitBox().getX() + player->getFightingHitBox().getRenderWidth() / 2 - healthBarWidth / 2;

    enemy->drawHealthBar(centerXEnemy, 64, healthBarWidth, 25, currentEnemyHealth, enemy->getHealth());
    player->drawHealthBar(centerXPlayer, 64, healthBarWidth, 25, currentPlayerHealth, PLAYER_MAX_HP);

    // render attack buttons
    player->drawAttackList();

    ofSetColor(255, 255, 255);
}

void BattleState::keyPressed(int key) {
    /*
        change type of attack
        plus add sounds
    */
    if (canInteract) {
        if (key == OF_KEY_LEFT || key == 'a') {
            buttonChange.play();
            player->setAttackChoice(player->getAttackChoice() - 1);
        }
        if (key == OF_KEY_RIGHT || key == 'd') {
            buttonChange.play();
            player->setAttackChoice(player->getAttackChoice() + 1);
        }
        if (key == OF_KEY_RETURN) {
            buttonSelect.play();
            isAttacking = true;
            canInteract = false;
        }
        if(key == OF_KEY_ESC) {
            setPastState(CurrentState::BATTLE);
            setNextState(CurrentState::PAUSED);
            setFinished(true);
        }
    }
}

void BattleState::reset() {
    setFinished(false);
    setNextState(CurrentState::NONE);
    setPastState(CurrentState::NONE);
    currentPlayerHealth = player->getHealth();
}