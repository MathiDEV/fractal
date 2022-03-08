# Fractal

Fractal is like string replace in 2D.

### Initialisation

A fractal is composed of "#" and ".". We have a replacement pattern for each symbol. Here we chose to replace each "#" by :
```
##
#.
```
And each "." by :
```
..
..
```

### Iterations

We begin with a simple "#" :

```
#
```
_(that's our **iteration 0**)_

For each iteration, we replace the characters by the corresponding pattern, so our **first iteration** will be :
```
##
#.
```
_(Because we replaced the single "#" by it's pattern)_

Our **second iteration** will be :

```
              ##  ##                 ####
##            #.  #.                 #.#.
#.     ->                 ->         ##..
              ##  ..                 #...
              #.  ..
```

**With more iterations we can obtain something like this :**

```
################
#.#.#.#.#.#.#.#.
##..##..##..##..
#...#...#...#...
####....####....
#.#.....#.#.....
##......##......
#.......#.......
########........
#.#.#.#.........
##..##..........
#...#...........
####............
#.#.............
##..............
#...............
```

## How to use ?

- Compile via makefile

```
make
```

- Run program

```
./fractals <n iter> <pattern for "#"> <pattern for ".">
```

_You must use "@" as linebreak in the patterns._

> You can use **rectangle patterns**.
> 
> But all lines must have the same length and the two patterns must have the same dimensions.
