#include <random>

#include "GameModel.h"

GameModel::GameModel()
{
    SetFigure();
}

Gamefield& GameModel::GetGamefield()
{
    return gamefield_;
}

const Gamefield& GameModel::GetGamefield() const
{
    return gamefield_;
}

Figure* GameModel::GetCurrentFigure() const
{
    return current_figure_.get();
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

    //return figures_[0];
}

void GameModel::SetFigure()
{
    if (current_figure_ == nullptr)
    {
        current_figure_ = std::make_unique<Figure>(GetRandomFigure());
    }

    current_figure_->SetNewPosition(0, gamefield_.COLUMNS / 2 - 1);

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<uint32_t> distribution(1, 6);

    uint32_t new_value = distribution(generator);

    for (uint32_t row = 0; row < current_figure_->number_rows; ++row)
    {
        for (uint32_t column = 0; column < current_figure_->number_columns; ++column)
        {
            if (current_figure_->GetFigure()[row][column] == 1)
            {
                current_figure_->GetFigure()[row][column] = new_value;
            }
        }
    }
}

void GameModel::SetNewFigure()
{
    current_figure_.reset();
    SetFigure();
}