#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

int main()
{
    enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
    State state = State::GAME_OVER;
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(resolution.x,resolution.y),"Zombie Arena",Style::Fullscreen);
    window.setFramerateLimit(144);

    View mainView(FloatRect(0,0,resolution.x,resolution.y));

    Clock clock;
    Time gameTimeTotal;
    Vector2f mouseWorldPosition;
    Vector2f mouseScreenPosition;
    Player player;
    IntRect arena;
    while (window.isOpen())
    {
        for (auto event = Event(); window.pollEvent(event);)
        {
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Return && state == State::PLAYING)
                {
                    state = State::PAUSED;
                }
                else if (event.key.code == Keyboard::Return && state == State::PAUSED)
                {
                    state = State::PLAYING;
                    clock.restart();
                }
                else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
                {
                   state = State::LEVELING_UP;
                }
                if (state == State::PLAYING)
                {
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        // Handle WASD while playing
        if (state == State::PLAYING) {
            // Handle the pressing and releasing of WASD keys
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                player.moveUp();
            }
            else
            {
                player.stopUp();
            }
            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                player.moveDown();
            }
            else
            {
                player.stopDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                player.moveLeft();
            }
            else
            {
                player.stopLeft();
            }
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                player.moveRight();
            }
            else
            {
                player.stopRight();
            }
        }
        // Handle the LEVELING up state
        if (state == State::LEVELING_UP)
        {
            // Handle the player LEVELING up
            if (event.key.code == Keyboard::Num1)
            {
                state = State::PLAYING;
            }
            if (event.key.code == Keyboard::Num2)
            {
                state = State::PLAYING;
            }
            if (event.key.code == Keyboard::Num3)
            {
                state = State::PLAYING;
            }
            if (event.key.code == Keyboard::Num4)
            {
                state = State::PLAYING;
            }
            if (event.key.code == Keyboard::Num5)
            {
                state = State::PLAYING;
            }
            if (event.key.code == Keyboard::Num6)
            {
                state = State::PLAYING;
            }
            if (state == State::PLAYING)
            {
                // Prepare the level
                // We will modify the next two lines later
                arena.width = 500;
                arena.height = 500;
                arena.left = 0;
                arena.top = 0;
                // We will modify this line of code later
                int tileSize = 50;
                // Spawn the player in middle of the arena
                player.spawn(arena, resolution, tileSize);
                // Reset clock so there isn't a frame jump
                clock.restart();
            }
        }
        window.clear();
        window.display();
    }
}
