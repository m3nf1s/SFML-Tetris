#pragma once

#include <memory>

#include "Gamefield.h"
#include "Figure.h"
#include "Gamedata.h"

class GameModel
{
private:
    using Speed_and_score = std::pair<float, int32_t>;
    using Matrix_t = std::vector<std::vector<int32_t>>;
    using FigureWithRotations = std::vector<Figure>;

public:
    GameModel();

    const Gamefield* GetGamefield() const;

    Figure*    GetCurrentFigure() const;
    Figure*    GetNextFigure()    const;
    Gamedata   GetGamedata()      const;

    void       GenerateNextFigures();
    Gamefield* GetGamefield();
    void       UpdateScore(const int32_t number_removed_lines);
    void       CheckEndGame();

    int32_t GetCurrentLevel() const;
    int32_t GetCurrentScore() const;
    float   GetCurrentSpeed() const;
    int32_t GetNeededScore()  const;
    bool    GetIsGameover()   const;

private:
    void         GenerateFigures();

    class Figure GetRandomFigure()        const;
    int32_t      CalculateRealPositionY() const;

private:
    std::unique_ptr<Gamefield> gamefield_;
    std::unique_ptr<Figure>    current_figure_;
    std::unique_ptr<Figure>    next_figure_;
    
    size_t  current_level_ = 0;
    int32_t current_score_ = 0;
    bool    is_gameover_   = false;

    const std::vector<Speed_and_score> speed_and_score =
    {
        Speed_and_score(2.0f, 2000),
        Speed_and_score(1.9f, 5000),
        Speed_and_score(1.8f, 7500),
        Speed_and_score(1.7f, 10000),
        Speed_and_score(1.6f, 12500),
        Speed_and_score(1.5f, 15000),
        Speed_and_score(1.4f, 17500),
        Speed_and_score(1.3f, 20000),
        Speed_and_score(1.2f, 22500),
        Speed_and_score(1.1f, 25000),
        Speed_and_score(1.0f, 27500),
        Speed_and_score(0.9f, 30000),
        Speed_and_score(0.8f, 32500),
        Speed_and_score(0.7f, 35000),
        Speed_and_score(0.6f, 37500),
        Speed_and_score(0.5f, 40000),
        Speed_and_score(0.4f, 42500),
        Speed_and_score(0.3f, 45000),
        Speed_and_score(0.2f, 47500),
        Speed_and_score(0.1f, 50000)
    };

    std::vector<FigureWithRotations> figures_ =
    {
        {
            Matrix_t(
            {
                {1, 1},
                {1, 1},
            })
        },

        {
            Matrix_t(
            {
                {0, 2, 0, 0},
                {0, 2, 0, 0},
                {0, 2, 0, 0},
                {0, 2, 0, 0}
            }),

            Matrix_t(
            {
                {0, 0, 0, 0},
                {2, 2, 2, 2},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }),

            Matrix_t(
            {
                {0, 0, 2, 0},
                {0, 0, 2, 0},
                {0, 0, 2, 0},
                {0, 0, 2, 0}
            }),

            Matrix_t(
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {2, 2, 2, 2},
                {0, 0, 0, 0}
            }),
        },

        {
            Matrix_t(
            {
                {0, 3, 0},
                {0, 3, 3},
                {0, 3, 0}
            }),

            Matrix_t(
            {
                {0, 0, 0},
                {3, 3, 3},
                {0, 3, 0}
            }),

            Matrix_t(
            {
                {0, 3, 0},
                {3, 3, 0},
                {0, 3, 0}
            }),

            Matrix_t(
            {
                {0, 3, 0},
                {3, 3, 3},
                {0, 0, 0}
            }),
        },

        {
            Matrix_t(
            {
                {0, 4, 0},
                {0, 4, 0},
                {4, 4, 0}
            }),

            Matrix_t(
            {
                {4, 0, 0},
                {4, 4, 4},
                {0, 0, 0}
            }),

            Matrix_t(
            {
                {0, 4, 4},
                {0, 4, 0},
                {0, 4, 0}
            }),

            Matrix_t(
            {
                {0, 0, 0},
                {4, 4, 4},
                {0, 0, 4}
            }),
        },

        {
             Matrix_t(
            {
                {0, 5, 0},
                {0, 5, 0},
                {0, 5, 5},

            }),

            Matrix_t(
            {
                {0, 0, 0},
                {5, 5, 5},
                {5, 0, 0},

            }),

            Matrix_t(
            {
                {5, 5, 0},
                {0, 5, 0},
                {0, 5, 0},

            }),

            Matrix_t(
            {
                {0, 0, 5},
                {5, 5, 5},
                {0, 0, 0},

            }),
        },

        {
             Matrix_t(
             {
                 {6, 0, 0},
                 {6, 6, 0},
                 {0, 6, 0}

             }),

             Matrix_t(
             {
                 {0, 6, 6},
                 {6, 6, 0},
                 {0, 0, 0}

             }),

             Matrix_t(
             {
                 {0, 6, 0},
                 {0, 6, 6},
                 {0, 0, 6}

             }),

             Matrix_t(
             {
                 {0, 0, 0},
                 {0, 6, 6},
                 {6, 6, 0}

             }),
        },

        {
             Matrix_t(
             {
                 {0, 0, 7},
                 {0, 7, 7},
                 {0, 7, 0}
             }),

             Matrix_t(
             {
                 {0, 0, 0},
                 {7, 7, 0},
                 {0, 7, 7}
             }),

             Matrix_t(
             {
                 {0, 7, 0},
                 {7, 7, 0},
                 {7, 0, 0}
             }),

             Matrix_t(
             {
                 {7, 7, 0},
                 {0, 7, 7},
                 {0, 0, 0}
             }),
        },
    };
};
