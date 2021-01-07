#include <iostream>
using namespace std;

#include "Game.h"
#include "Player.h"
#include "Hero.h"
#include "Fighter.h"
#include "Fireball.h"
#include "Alien.h"
#include "constants.h"
#include "random.h"

Game::~Game()
{
    // delete all players
    list<Player *>::iterator ptr;
    for (ptr = players.begin(); ptr != players.end(); ptr++)
        delete (*ptr);
}

list<Player *> *Game::getPlayers() { return &players; }

void Game::add(Player *p)
{
    // if not null, add the player to the list
    if (p != NULL)
        players.push_back(p);
}

void Game::generate()
{
    // make a random choice
    int choice = random(5);
    // 40% chance to do nothing
    if (choice >= 3)
        return;

    // 60% chance each to spawn an orc
    // type is determined within Fighter constructor, 1/3 chance of each orc
    add(new Fighter());

    // 5% chance to spawn an alien
    choice = random(12);
    if (choice == 0)
        add(new Alien());

    // 30% chance to spawn a fireball
    choice = random(2);
    int y;
    list<Player *>::iterator ptr;
    if (choice == 0)
    {
        // if we do spawn a fireball, it should be beside the dragon
        for (ptr = players.begin(); ptr != players.end(); ptr++)
        {
            if ((*ptr)->getAvatar() == 'D')
            {
                y = (*ptr)->getY();
                add(new Fireball(y));
                return;
            }
        }
    }
}

void Game::move()
{
    // move all players and calculate collisions
    list<Player *>::iterator ptr;
    list<Player *>::iterator other;
    for (ptr = players.begin(); ptr != players.end(); ptr++)
    {
        (*ptr)->move();
        // if not a hero, go next
        if (!((*ptr)->isHero()))
            continue;
        // else, interact
        for (other = players.begin(); other != players.end(); other++)
        {
            if (ptr == other)
                continue;
            // cast to hero
            Hero *h = dynamic_cast<Hero *>(*ptr);
            if (h != 0)
                h->interact(*other);
        }
    }
}

void Game::update()
{
    list<Player *>::iterator ptr;
    // check for deaths
    ptr = players.begin();
    while (ptr != players.end())
    {
        // if dead
        if (!(*ptr)->isAlive())
        {
            // if hero, set their grave
            if ((*ptr)->isHero())
                (*ptr)->setAvatar('+');
            // else fighter, so remove
            else
            {
                delete (*ptr);
                ptr = players.erase(ptr);
                continue;
            }
        }
        // increment pointer
        ++ptr;
    }
}

bool Game::gameOver()
{
    // check if both heroes are dead
    list<Player *>::iterator ptr;
    int dead = 0;
    for (ptr = players.begin(); ptr != players.end(); ptr++)
    {
        if ((*ptr)->isHero() && !((*ptr)->isAlive()))
            dead += 1;
    }
    // if 2 dead heroes found, end the game
    if (dead == 2)
    {
        cout << "ALL HEROES ARE DEAD. GAME OVER !!!" << endl;
        return true;
    }

    // let's check if heroes won
    char avatar;
    int x, y, bounds;
    for (ptr = players.begin(); ptr != players.end(); ptr++)
    {
        avatar = (*ptr)->getAvatar();
        if ((*ptr)->isHero())
        {
            (*ptr)->getPos(x, y);
            bounds = MAX_HEIGHT / 3;
            // check if a hero has reached the cave
            if (x == MAX_WIDTH - 1 && y >= bounds && y < MAX_HEIGHT - bounds)
            {
                cout << ((avatar == 'T') ? "Timmy" : "Harold") << " CLAIMS THE EMERALD !!!" << endl;
                return true;
            }
        }
    }
    // otherwise, the game must go on
    return false;
}
