#pragma once

#include <memory>

#include "Gamefield.h"
#include "Figure.h"

class GameModel
{
public:
    GameModel();

    const Gamefield* GetGamefield() const;

    Figure* GetCurrentFigure() const;

    void SetNewFigure();
    Gamefield* GetGamefield();

private:
    class Figure GetRandomFigure();
    void   SetFigure();

private:
    Gamefield               gamefield_;
    std::unique_ptr<Figure> current_figure_;

    using Matrix_t = std::vector<std::vector<int32_t>>;
    const std::vector<Figure> figures_ =
    {
        Matrix_t(
            {
                {1, 1},
                {1, 1},
            }),

        Matrix_t(
            {
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0}
            }),

        Matrix_t(
            {
                {0, 1, 0},
                {0, 1, 1},
                {0, 1, 0}
            }),
        Matrix_t(
            {
                {0, 1, 0},
                {0, 1, 0},
                {1, 1, 0}
            }),
        Matrix_t(
            {
                {0, 1, 0},
                {0, 1, 0},
                {0, 1, 1},

            }),
        Matrix_t(
            {
                {1, 0, 0},
                {1, 1, 0},
                {0, 1, 0}

            }),
        Matrix_t(
            {
                {0, 1, 0},
                {1, 1, 0},
                {1, 0, 0}
            })
    };
};
