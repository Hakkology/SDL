#ifndef GAMES_PACMAN_PACMAN__H__
#define GAMES_PACMAN_PACMAN__H__

#include "game.h"
#include "pacmanlevel.h"
#include "pacmanplayer.h"
#include "spritesheet.h"
#include "inputaction.h"
#include "pacmanghost.h"
#include "pacmanghostai.h"

class Pacman : public Game{

public:
    virtual void Init(GameController& controller) override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw (Screen& screen) override;
    virtual const std::string& GetName() const override;

private:

    void ResetGame();
    void UpdatePacmanMovement();
    void HandleGameControllerState(uint32_t dt, InputState state, PacmanMovement direction);
    void ResetLevel();
    void DrawLives (Screen& screen);
    void DrawScoreTable(Screen &screen);
    void SetupGhosts();
    
    PacmanLevel pLevel;
    PacmanMovement pPressedDirection;
    SpriteSheet pPacmanSpriteSheet;
    PacmanPlayer pPacman;

    size_t pNumLives;
    uint32_t pReleaseGhostTimer;
    std::vector<PacmanGhost> pGhosts;
    std::vector<PacmanGhostAI> pGhostAIs;

};

#endif  //!GAMES_PACMAN_PACMAN__H__