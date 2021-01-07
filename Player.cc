#include <iostream>
using namespace std;

#include "Player.h"

Player::Player(char a, int tx, int ty, int hp, int str) : avatar(a), x(tx), y(ty), health(hp), strength(str)
{
    // cout << "--PLAYER ctor: " << avatar << " (" << x << ", " << y << ") w/ " << health << "HP and " << strength << " strength and " << armour << " armour" << endl;
}

Player::~Player()
{
    // cout << "--PLAYER dtor: " << avatar << " (" << x << ", " << y << ")" << endl;
}

// getters
char Player::getAvatar() { return avatar; }
int Player::getX() { return x; }
int Player::getY() { return y; }
void Player::getPos(int &x, int &y)
{
    x = this->x;
    y = this->y;
}
int Player::getHealth() { return health; }
int Player::getStrength() { return strength; }
// setters
void Player::setAvatar(char a) { this->avatar = a; }
void Player::setX(int x) { this->x = x; }
void Player::setY(int y) { this->y = y; }
void Player::setPos(int x, int y)
{
    setX(x);
    setY(y);
}
void Player::setHealth(int hp) { this->health = hp; }
void Player::setStrength(int str) { this->strength = str; }
bool Player::isAlive() { return this->health > 0; }
bool Player::isHero() { return false; }