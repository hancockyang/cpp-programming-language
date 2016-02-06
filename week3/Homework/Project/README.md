# Prepared for battle
We have 2 bases: 
1. red
2. blue
* Each one can produce 5 warriors:
1. dragon
2. ninja
3. iceman
4. lion
5. wolf
* Each warrior will have number, lift, attach properties
* The numbering starts from "1" to "n".
* Each base procduces one warrior at a time
* Red is in order: iceman、lion、wolf、ninja、dragon to loop over
* Blue is in order: lion、dragon、ninja、iceman、wolf to loop over
* The warrior production will spend the base life
* m life warrior spends m life of base
* Base would skip producing the next warrior if no enough lift to be spent and change to produce the 2nd next and so on.

## Input:
Case
baselife
warrior life
```
1
20
3 4 5 6 7
```
## Output:
```
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
```
