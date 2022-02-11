#include <random>

#include "GameModel.h"

GameModel::GameModel()
    : gamefield_(std::make_unique<Gamefield>())
{
    GenerateFigures();
}

Figure GameModel::GetRandomFigure() const
{
    if (!figures_.empty())
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        const std::uniform_int_distribution<> distribution(0, static_cast<int32_t>(figures_.size() - 1u));
        
        FigureWithRotations figure_with_rotations = figures_.at(distribution(generator));

        if (!figure_with_rotations.empty())
        {
            const std::uniform_int_distribution<> distribution_figure(0, static_cast<int32_t>(figure_with_rotations.size() - 1u));

            return figure_with_rotations.at(distribution_figure(generator));
        }
    }

    return Figure();
}

void GameModel::GenerateFigures()
{
    if (current_figure_ == nullptr)
    {
        current_figure_ = std::make_unique<Figure>(std::move(GetRandomFigure()));
    }

    if (next_figure_ == nullptr)
    {
        next_figure_ = std::make_unique<Figure>(std::move(GetRandomFigure()));
    }

    const int current_figure_new_position_X = gamefield_->COLUMNS / 2 - current_figure_->GetSize() / 2;
    const int current_figure_new_position_Y = CalculateRealPositionY();
    current_figure_->SetNewPosition(current_figure_new_position_X, -current_figure_new_position_Y);

    //TO DO
    //Need to improve UI position
    const int next_figure_new_position_X = gamefield_->COLUMNS + 2;
    const int next_figure_new_position_Y = 2;
    next_figure_->SetNewPosition(next_figure_new_position_X, next_figure_new_position_Y);
}

int32_t GameModel::CalculateRealPositionY() const
{
    for (int32_t Y = 0; Y < current_figure_->GetSize(); ++Y)
    {
        for (int32_t X = 0; X < current_figure_->GetSize(); ++X)
        {
            if (current_figure_->Get(Y, X) != 0)
            {
                return Y;
            }
        }
    }

    return 0;
}

void GameModel::GenerateNextFigures()
{
    current_figure_ = std::move(next_figure_);
    GenerateFigures();
}

void GameModel::UpdateScore(const int32_t number_removed_lines)
{
    const int32_t magic_number_score = 100;
    const int32_t additional_score = number_removed_lines * number_removed_lines * magic_number_score;

    current_score_ += additional_score;

    if (current_score_ >= speed_and_score.at(current_level_).second && current_level_ < speed_and_score.size())
    {
        ++current_level_;
    }
}

size_t GameModel::GetCurrentLevel() const
{
    return current_level_;
}

size_t GameModel::GetCurrentScore() const
{
    return current_score_;
}

float GameModel::GetCurrentSpeed() const
{
    return speed_and_score.at(current_level_).first;
}

int32_t GameModel::GetNeededScore() const
{
    return speed_and_score.at(current_level_).second;
}

Gamedata GameModel::GetGamedata() const
{
    return { gamefield_.get(), current_figure_.get(), next_figure_.get(), current_level_, current_score_ };
}

bool GameModel::GetIsGameover() const
{
    return is_gameover_;
}

void GameModel::CheckEndGame()
{
    for (int32_t Y = 0; Y < current_figure_->GetSize(); ++Y)
    {
        for (int32_t X = 0; X < current_figure_->GetSize(); ++X)
        {
            if (current_figure_->Get(Y, X) != 0)
            {
                const int32_t real_position_Y = current_figure_->GetCurrentPosition().Y + Y;
                const int32_t real_position_X = current_figure_->GetCurrentPosition().X + X;

                if (gamefield_->GetCell(real_position_Y, real_position_X) != 0)
                {
                    is_gameover_ = true;
                    return;
                }
            }
        }
    }
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