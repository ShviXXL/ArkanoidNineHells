#ifndef GAME
#define GAME
#include "Game.hpp"
#include "EntityManager.hpp"
#include "SpellManager.hpp"
#include <SDL2/SDL_timer.h>
#endif

enum Levels
{
    avernus,
    LEVELS_COUNT = avernus + 1,
    LEVELS_NULL
};


class Brick
{
    public:
        Brick(int x, int y);
        ~Brick();

        bool Hit();

        void Update();
        void Render(SDL_Texture* brickTexture, SDL_Texture* crackTexture);

        void TranstionStep();

        SDL_Rect getRect() { return windowRect; }
    private:
        int health;
        
        SDL_Rect brickRect;
        SDL_Rect crackRect;

        SDL_Rect windowRect;
};


class Background
{
    public:
        Background();
        ~Background();

        void Render(SDL_Texture* texture);
        void Update();

        void TransitionStep();

    private:
        int frames;
        int frameDelay;
        
        SDL_Rect textureRect;
        SDL_Rect windowRect;
};

class Power
{
    public:
        Power(SDL_Rect* objectRect);
        ~Power();

        void Render(SDL_Texture* texture);
        void Update();

        void TranstionStep();

        SDL_Rect getRect() { return windowRect; }

    private:
        int speed;

        int frames;
        int frameDelay;
        
        SDL_Rect textureRect;
        SDL_Rect windowRect;
};

class MapManager
{
    public:
        static void Init(Levels type, int h, int w);

        static void Clean();

        static void Generate(int spire);
        static void Next();

        static void Update();
        static void UpdateBackground();
        static void UpdateBricks();
        static void UpdatePowers();

        static void Render();

        static Uint32 TransitionStep(Uint32 interval, void*);

    private:
        static int mapHeight;
        static int mapWidth;
        static int** map;

        static int step;
        static int current;

        static int transitionStep;
        static int currentTransitionStep;
        static SDL_TimerID transitionTimer;

        static SDL_Texture* brickTexture;
        static SDL_Texture* crackTexture;
        static SDL_Texture* backgroundTexture;
        static SDL_Texture* powerTexture;

        static std::vector<Brick> bricks;
        static std::vector<Power> powers;
        static Background* background;
};
