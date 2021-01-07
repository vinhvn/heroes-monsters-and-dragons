#ifndef PLAYER_H
#define PLAYER_H

/** CLASS: Player
 * Simulates a generic quest player
 *
 * ATTRIBUTES:
 * -avatar: char
 * -x: int
 * -y: int
 * -health: int
 * -strength: int
 *
 * METHODS:
 * +getPos(out: int &, out: int &): void
 *      Returns both x and y values to output parameters
 * +isAlive(): bool
 *      Returns true if a player's health is above 0
 * +move():
 *      Moves the character based on its design, must be implemented by derived classes
 * +isHero(): bool
 */
class Player
{
private:
    char avatar;
    int x;
    int y;
    int health;
    int strength;

public:
    Player(char = 'T', int = 0, int = 0, int = 0, int = 0);
    virtual ~Player();
    char getAvatar();
    int getX();
    int getY();
    void getPos(int &, int &);
    int getHealth();
    int getStrength();
    void setAvatar(char);
    void setX(int);
    void setY(int);
    void setPos(int, int);
    void setHealth(int);
    void setStrength(int);
    bool isAlive();
    virtual void move() = 0;
    virtual bool isHero();
};

#endif