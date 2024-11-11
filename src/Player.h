//
// Created by Arek on 11.11.2024.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "math.h"
using namespace sf;

class Player {
private:
    const float START_SPEED = 200;
    const float START_HEALTH = 100;
    Vector2f m_Position;
    Sprite m_Sprite;
    // !!Watch this space – Changes here soon!!
    Texture m_Texture;
    Vector2f m_Resolution;
    IntRect m_Arena;
    int m_TileSize;
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;
    int m_Health;
    int m_MaxHealth;
    Time m_LastHit;
    float m_Speed;
public:
    Player();
    void spawn(IntRect arena, Vector2f resolution, int tileSize);
    // Call this at the end of every game
    void resetPlayerStats();
    bool hit(Time timeHit);
    Time getLastHitTime();
    FloatRect getPosition();
    Vector2f getCenter();
    float getRotation();
    Sprite getSprite();
    // The next four functions move the player
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    void update(float elapsedTime, Vector2i mousePosition);
    void upgradeSpeed();
    void upgradeHealth();
    void increaseHealthLevel(int amount);
    int getHealth();
};

