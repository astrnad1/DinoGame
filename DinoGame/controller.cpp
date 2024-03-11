#include <raylib.h>
#include "start.cpp"
#include "game.cpp"
#include "end.cpp"

class Controller {

private:
    Start start;
    Game game;
    EndScreen endScreen;
    enum State { START, GAME , END } state;

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
        case END:
            endScreen.Draw(windowWidth, windowHeight);
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
            if (game.CheckCollision())
                state = END;
            break;
        case END:
            if (IsKeyPressed(KEY_SPACE)) {
                game.score = 0;
                state = GAME;
            }
            break;
        }
    }
};