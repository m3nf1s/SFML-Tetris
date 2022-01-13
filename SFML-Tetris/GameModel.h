#pragma once

#include <memory>

#include "Gamefield.h"
#include "Figure.h"

class GameModel
{
public:
    GameModel();

    Gamefield& GetGamefield();

    const Gamefield& GetGamefield() const;

    Figure* GetCurrentFigure() const;

private:
    Figure GetRandomFigure();
    void   SetFigure();

private:
    Gamefield               gamefield_;
    std::unique_ptr<Figure> current_figure_;

    const std::vector<Figure> figures_ =
    {
        std::vector<std::vector<uint32_t>>(
            {
                {1, 1},
                {1, 1},
                {0, 0},
                {0, 0}
            }),

        std::vector<std::vector<uint32_t>>(
            {
                {0, 1},
                {0, 1},
                {0, 1},
                {0, 1}
            }),

        std::vector<std::vector<uint32_t>>(
            {
                {1, 0},
                {1, 1},
                {1, 0},
                {0, 0}
            }),
        std::vector<std::vector<uint32_t>>(
            {
                {0, 1},
                {0, 1},
                {1, 1},
                {0, 0}
            }),
        std::vector<std::vector<uint32_t>>(
            {
                {1, 0},
                {1, 0},
                {1, 1},
                {0, 0}
            }),
        std::vector<std::vector<uint32_t>>(
            {
                {1, 0},
                {1, 1},
                {0, 1},
                {0, 0}
            }),
        std::vector<std::vector<uint32_t>>(
            {
                {0, 1},
                {1, 1},
                {1, 0},
                {0, 0}
            })
    };

};

