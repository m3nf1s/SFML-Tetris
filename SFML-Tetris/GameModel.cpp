#include <random>

#include "GameModel.h"

GameModel::GameModel()
{
    GenerateFigure();
}

Gamefield* GameModel::GetGamefield()
{
    return gamefield_.get();
}

const Gamefield* GameModel::GetGamefield() const
{
    return gamefield_.get();
}

Figure* GameModel::GetCurrentFigure() const
{
    return current_figure_.get();
}

Figure* GameModel::GetNextFigure() const
{
    return next_figure_.get();
}

Figure GameModel::GetRandomFigure()
{
    if (figures_.size() != 0)
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(0u, figures_.size() - 1u);

        return figures_[distribution(generator)];
    }

    return Figure();
}

void GameModel::ChangeFigure(Figure* figure)
{
    std::random_device random_device;
    std::mt19937 generator(random_device());

    //TO DO: delete magic numbers
    //Create const value with maximum counts of colors
    std::uniform_int_distribution<int32_t> distribution(1, 6);

    const int32_t new_value = distribution(generator);

    for (int32_t row = 0; row < figure->GetSize(); ++row)
    {
        for (int32_t column = 0; column < figure->GetSize(); ++column)
        {
            if (figure->Get(row, column) == 1)
            {
                figure->Get(row, column) = new_value;
            }
        }
    }
}

void GameModel::GenerateFigure()
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int32_t> distribution(0, 3);
    int32_t number_rotation = distribution(generator);

    if (current_figure_ == nullptr)
    {
        current_figure_ = std::make_unique<Figure>(GetRandomFigure());
        for (int32_t i = 0; i < number_rotation; ++i)
        {
            current_figure_->Rotate(gamefield_.get());
        }
    }
    number_rotation = distribution(generator);
    if (next_figure_ == nullptr)
    {
        next_figure_ = std::make_unique<Figure>(GetRandomFigure());
        for (int32_t i = 0; i < number_rotation; ++i)
        {
            next_figure_->Rotate(gamefield_.get());
        }
    }

    current_figure_->SetNewPosition(gamefield_->COLUMNS / 2 - 1, 0);

    //TO DO
    //Need to improve UI position
    next_figure_->SetNewPosition(gamefield_->COLUMNS + 2, 2);

    ChangeFigure(current_figure_.get());
    ChangeFigure(next_figure_.get());
}
}