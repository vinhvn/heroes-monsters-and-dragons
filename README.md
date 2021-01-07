# A Game of Heroes, Monsters, and Dragons

A simulator of two adventurers braving off against a dragon and its army of monsters.

## Preview

![Preview](https://i.imgur.com/zkGKZOf.gif)

## Features

- Colours!
  - Each player of the game is given a unique colour to distinguish them amongst the chaos.
  - Timmy and Harold (our heroes) are coloured `WHITE`... as well as their graves.
  - Dorcs, Borcs, and Porcs are coloured `RED`.
  - The almighty dragon is coloured `GREEN`.
  - Our treasured emerald is also coloured `GREEN`.
  - The flaming fireballs are coloured `YELLOW`.
  - The slimy beetles are coloured `CYAN`.
  - The false treasure, the amethyst, is coloured `MAGENTA`.
  - The monstrous aliens are coloured `BLUE` along with their tails.
- Various enemy types!
  - Dorcs `d`, Borcs `b`, and Porcs `b`
    - The basic enemy type
    - Random health and strength but overall weak
  - Dragon `D` [invulnerable, insta-kill]
    - The big boss
    - Patrols from top to bottom around the emerald cave's entrance
  - Alien `@z` [20 health, 10 strength]
    - The alien rushes through the area, moving 2 spaces left at a time.
    - The alien also only moves diagonally, up or down on each of its turns.
    - The alien warps back to the cave entrance once it reaches the left border for
      another chance to fight Timmy and Harold.
    - The alien also warps from the top border to the bottom and vice versa.
    - The alien's 10 damage attacks also pierce and ignore Timmy and Harold's armour,
      making it a very dangerous foe, indeed.
    - The alien's tail can also hurt Timmy and Harold so they must be careful.
    - The alien has a 5% chance of spawning and always spawns on the right-most border at a randomly determined height.
  - Amethyst `*` [1 health, 0 strength]
    - The amethyst is a false emerald placed by Dragon to trick Timmy and Harold.
    - If any of our heroes tries to obtain it, it warps them back to the entrance instead.
    - Occasionally, this false gem moves... Hopefully our heroes notice before it's too late.
    - There is a guaranteed Amethyst spawn at the beginning of the game, randomly placed
      and could be anywhere from the first third of the hollows till near the end.
  - Beetle `w` [100 health, 0 strength]
    - The beetle is a creepy crawly that isn't really out to hurt our Heroes...
      although it may accidentally do so from time to time.
    - The beetle is invincible but also incapable of hurting Timmy and Harold directly.
    - If a hero steps on a beetle, they'll be stuck for a turn, slowing their progress.
    - Beetles only move in one direction (up/down) and wrap around the arena to do so.
    - There are 3 guaranteed Beetle spawns at the beginning of the game, placed throughout
      at various x values, spawned at random heights.
  - Fireball `O>` or `O>>` or `O>>>` [1 health, 4 strength]
    - The fireball is a projectile fired by the Dragon to hurt Timmy and Harold at range.
    - The fireball leaves a trail of flame in its wake, which also hurts our heroes.
    - The fireball's trail is randomly chosen when its fired from the Dragon.
    - The fireball's speed is also dependent on the trail as it moves left faster based
      on how large its trail is.
    - The fireball has a 30% chance of spawning, always from the Dragon's mouth.

## Getting Started

First, clone this repository and navigate into the directory.

1. Compile by using the following command

```bash
make
```

2. Run the program by using the command

```bash
./final
```

3. You may check for memory leaks by using the command

  ```bash
  valgrind --leak-check=yes ./final
  ```

4. Clean up generated files afterwards by using the command

```bash
make clean
```

## Additional Notes

- Map size and delay between iterations can be modified within the 'constants.h' file.
- Makefile provided by Shane Bishop, a COMP 2404 TA.
