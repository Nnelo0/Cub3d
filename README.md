# Ft_Cub3d

## Prerequisites

- **Make** must be available on your system:  
  (Linux/macOS: usually preinstalled, Windows users can use WSL or install Make via Chocolatey or Scoop)

- files in **.cub** for map like :

```NO ./textures/flash.xpm
SO ./textures/sally.xpm
WE ./textures/martin.xpm
EA ./textures/fan.xpm
F 120,170,250
C 120,120,250

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000000001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

```NO : Texture for Nord face bloc```
```SO : Texture for South face bloc```
```WE : Texture for West face bloc```
```EA : Texture for East face bloc```
```F  : Colors for floor```
```C  : Colors for celling```
and the map :
```1 : for wall```
```0 : for nothing (path for player)```
``` N | E | S | W : for player (the letters means the direction of the player at spawn)```

## Setup Instructions
### 1. Launch the project

```bash
make
```

After the project is running, type :

the name of program `./cub3D` and a parameters for a map in .cub
```bash
./cub3D <maps/good_maps/map.cub>
```

## 📜 Credits & Contributors

- **Lumeris4** — Executing ([GitHub](https://github.com/Lumeris4))
- **Nnelo** — Parsing ([GitHub](https://github.com/Nnelo0))
