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
    Figure* GetNextFigure()    const;

    void       GenerateNewFigure();
    Gamefield* GetGamefield();
    void       UpdateScore(const int32_t number_removed_lines);

    const int32_t GetCurrentLevel() const;
    const int32_t GetCurrentScore() const;
    const float   GetCurrentSpeed() const;
    const int32_t GetNeededScore()  const;

private:
    class Figure GetRandomFigure();
    void         GenerateFigure();
    void         ChangeFigure(Figure* figure);

private:
    Gamefield               gamefield_;
    std::unique_ptr<Figure>    current_figure_;
    std::unique_ptr<Figure>    next_figure_;
    
    size_t  current_level_ = 0;
    int32_t current_score_ = 0;

    using Speed_and_score = std::pair<float, int32_t>;
    const std::vector<Speed_and_score> speed_and_score =
    {
        Speed_and_score(2.0f, 2000),
        Speed_and_score(1.8f, 5000),
        Speed_and_score(1.6f, 7500),
        Speed_and_score(1.4f, 10000),
        Speed_and_score(1.2f, 12500),
        Speed_and_score(1.0f, 15000),
        Speed_and_score(0.8f, 17500),
        Speed_and_score(0.6f, 20000),
        Speed_and_score(0.4f, 22500),
        Speed_and_score(0.2f, 25000)
    };

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
