#include <raylib.h>
#include "start.cpp"
#include "game.cpp"

class Controller {

private:
    Start start;
    Game game;
    enum State { START, GAME } state;

public:
    Controller() : state(START) {}

    void Draw(const int windowWidth, const int windowHeight)
    {
        switch (state) {
        case START:
            start.Draw(windowWidth, windowHeight);
            break;
        case GAME:
            game.Draw(windowWidth, windowHeight);
            break;
        }
    }

    void Update()
    {
        switch (state) {
        case START:
            start.Update();
            if (IsKeyPressed(KEY_SPACE)) {
                state = GAME;
            }
            break;
        case GAME:
            game.Update();
            break;
        }
    }
};
