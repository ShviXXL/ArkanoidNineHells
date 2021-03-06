#ifndef GAME
#define GAME
#include "Game.hpp"
#include "Timer.hpp"
#include "EntityManager.hpp"
#include "MapManager.hpp"
#include "SpellManager.hpp"
#include "Window.hpp"
#endif

enum Scenes
{
    game_over,
    victory,
    main_menu,
    new_game,
    scoreboard,
    quit_game,
    input_name,
    level,
    SCENES_COUNT = level + 1,
    SCENES_NULL
};

class Button
{
    public:
        Button(const char* text, int x, int y);
        ~Button();
        
        void Update();
        void Render();

        void changeText(const char* text);

        bool Available() { return isAvailable; }
        void toggleAvailable();
        void toggleSelected();

    private:
        bool isAvailable;
        bool isSelected;

        SDL_Texture* texture;
        SDL_Texture* textureAvailable;
        SDL_Texture* textureSelected;

        SDL_Rect windowRect;
};

class Object
{
    public:
        Object(SDL_Texture* texture, int x, int y);
        ~Object();
        
        void Clean();
        void Render();

    private:
        SDL_Texture* texture;

        SDL_Rect windowRect;
};

class GameManager
{
    public:
        static bool Init();
        static void Clean();

        static int HandleEvents(SDL_Event* event);
        static void Update();
        static void Render();

        static void LoadScene(Scenes scene);
        
        static void Continue();

        static void changeSelectedButton(int newButton);
        static void clearMenu();
        static void clearGame();
        
        static void addScore(int amount);
        static void writeScore();

    private:
        static bool isPlaying;
        static Timer* move_timer;

        static Scenes currentScene;
        static std::string currentLevel;

        static Json::Value menuData;

        static Button** buttons;
        static int buttonsCount;
        static int selectedButton;
        
        static std::vector<Object> objects;

        // For "New Game" scene
        static int levelsCount;
        static int selectedLevel;
        
        static Ship** ships;
        static int shipsCount;
        static int selectedShip;

        static Sphere** spheres;
        static int spheresCount;
        static int selectedSphere;
        
        // For "Scoreboard" scene
        static int firstButton;
        static std::vector<std::string> scoreboard_data;
        static std::string username;
        static int score;
};

