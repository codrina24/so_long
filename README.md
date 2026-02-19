*This project has been created as part of the 42 curriculum by coholbur.*

# So_long

So_long is a small graphical project that introduces the basics of 2D game development, including game elements such as textures.

## Description

This program can be compiled using Makefile and minilibx library, which are interdependent. The program will not run if MinilibX is not present or if it has not been compiled using its own `Makefile`.

A Makefile must be created and the program should be compiled at the root of the repository,using:

```bash
make
```
 The project must be executed as follows:

```bash
./so_long ./map/<name_of_the_map>
```

The `map` directory contains multiple maps for testing different scenarios and clearly demonstrating possible error cases.

## Architecture

### Parsing

The parsing section of the program ensures that the input map is valid and playable. The following checks and validations are performed:

1. **Argument and file checks**
   - `ft_check_arg` ensures the program receives exactly one map file as an argument.
   - `ft_check_extension` verifies that the file has a `.ber` extension.

2. **Map size and rectangularity**
   - `ft_get_rows` and `ft_get_cols` calculate the number of rows and columns in the map.
   - `ft_check_size` ensures the map is large enough to be playable.
   - `ft_check_rectangular` validates that all rows have the same length.

3. **Character validation**
   - `ft_check_valid_char` ensures only valid characters are present (`0`, `1`, `P`, `E`, `C`).
   - `ft_check_allpos` verifies that the map contains exactly one player (`P`), exactly one exit (`E`), and at least one collectible (`C`).

4. **Walls**
   - `ft_check_walls` ensures that the map is surrounded by walls (`1`) on the top, bottom, left, and right edges.

5. **Collectibles**
   - `ft_count_collectible` counts the number of collectibles and stores it in the map structure.

6. **Path validation (Flood Fill)**
   - `ft_possible_map` uses a flood-fill algorithm (`ft_flood_fill`) to ensure that all collectibles and the exit are reachable from the player’s starting position.

### **MLX Handle**

This section of the program demonstrates the use of the MinilibX (MLX) library to create and manage the game’s graphical interface.

The functions implemented handle:

- Loading map textures (`ft_file_to_image`)
- Rendering the map and updating images on the window (`ft_render`, `ft_img_add`)  
- Handling player movement in all directions (`ft_move_up`, `ft_move_down`, `ft_move_left`, `ft_move_right`, `ft_move_player`)  
- Checking movement validity (`ft_check_move`)  
- Managing user input and window events (`ft_direction`, `ft_setup_hooks`, `ft_handle_cross`)
- Exiting the game and cleaning resources (`ft_check_exit`, `ft_free_game`)

These functions help to create a 2D game, including image management, user interaction. They provide a practical understanding of graphics handling and event-driven programming in a game context.

 ### **Error management**

The program implements comprehensive error handling, covering all possible failure cases and ensuring proper cleanup and descriptive feedback for the user.
The functions that handle these errors are implemented in the files `errors_1.c` and `errors_2.c`.

 ### **Memory**

All dynamically allocated memory in the project is carefully managed to prevent leaks. Maps, game structures, and images created with MinilibX are properly freed using dedicated cleanup functions.

At every stage of the program—during map parsing, game execution, or on errors—resources are released correctly. This ensures that when the program exits, whether normally or due to an error, no memory leaks remain, maintaining stability and reliability. The cleanup functions are implemented in the files `free_game.c` and `free_map.c`.

 ### **Main** 

The `main` function initializes the map and game structures, sets up the MLX window and textures, installs event hooks, and starts the game loop, ensuring proper resource management throughout.

### Resources

 - **Peer-to-peer learning** – was the most valuable resource; this project was developed with guidance and collaboration from other 42 students;
 - **Books** – Classic references to learn C from scratch and understand various programming notions;
 - **Tutorials and articles** – Consulted to better understand the steps in the implementation of a 2D game, `so_long` in this case;
 - **itch.io** – for inspiration and useful textures that I could reuse in my project. 


### AI Assistance
AI tools were used to help:
- Create diagrams and schemas to visualize how functions work and how data flows.
- Help with README section

No AI was used to write the functions directly; all code logic and implementation are my own work and personal vision.
