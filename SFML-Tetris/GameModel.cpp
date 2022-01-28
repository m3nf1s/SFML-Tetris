#include <random>

#include "GameModel.h"

GameModel::GameModel()
    : gamefield_(std::make_unique<Gamefield>())
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

void GameModel::GenerateNewFigure()
{
    current_figure_ = std::move(next_figure_);
    GenerateFigure();
}

const int32_t GameModel::GetCurrentLevel() const
{
    return static_cast<int32_t>(current_level_) + 1;
}

const int32_t GameModel::GetCurrentScore() const
{
    return current_score_;
}

const float GameModel::GetCurrentSpeed() const
{
    return speed_and_score.at(current_level_).first;
}

const int32_t GameModel::GetNeededScore() const
{
    return speed_and_score.at(current_level_).second;
}

void GameModel::UpdateScore(const int32_t number_removed_lines)
{
    int32_t additional_score;

    switch (number_removed_lines)
    {
    case 1:
        additional_score = number_removed_lines * 100;
        break;
    case 2:
        additional_score = number_removed_lines * 200;
        break;
    case 3:
        additional_score = number_removed_lines * 300;
        break;
    case 4:
        additional_score = number_removed_lines * 400;
        break;
    default:
        additional_score = 0;
        break;
    }

    current_score_ += additional_score;

    if (current_score_ >= speed_and_score.at(current_level_).second && current_level_ + 1 < speed_and_score.size())
    {
        ++current_level_;
    }
}