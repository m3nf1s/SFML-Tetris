#include <random>

#include "GameModel.h"
#include "../EventSystem/Delegate.h"
#include "../EventSystem/EventManager.h"

GameModel::GameModel()
    : m_gamefield_(std::make_unique<Gamefield>())
    , m_handel_(EventManager::GetInstance()->SubscribeToGenerateNewFigures(Delegate<GameModel>(this, &GameModel::GenerateNextFigures)))
{
    GenerateFigures();
}

Figure GameModel::GetRandomFigure() const
{
    if (!m_figures_.empty())
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        const std::uniform_int_distribution<> distribution(0, static_cast<int32_t>(m_figures_.size() - 1u));
        
        FigureWithRotations figure_with_rotations = m_figures_.at(distribution(generator));

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
    if (m_current_figure_ == nullptr)
    {
        m_current_figure_ = std::make_unique<Figure>(std::move(GetRandomFigure()));
    }

    if (m_next_figure_ == nullptr)
    {
        m_next_figure_ = std::make_unique<Figure>(std::move(GetRandomFigure()));
    }

    const int current_figure_new_position_X = m_gamefield_->COLUMNS / 2 - m_current_figure_->GetSize() / 2;
    const int current_figure_new_position_Y = CalculateRealPositionY();
    m_current_figure_->SetNewPosition(current_figure_new_position_X, -current_figure_new_position_Y);

    //TO DO
    //Need to improve UI position
    const int next_figure_new_position_X = m_gamefield_->COLUMNS + 2;
    const int next_figure_new_position_Y = 2;
    m_next_figure_->SetNewPosition(next_figure_new_position_X, next_figure_new_position_Y);
}

int32_t GameModel::CalculateRealPositionY() const
{
    for (int32_t Y = 0; Y < m_current_figure_->GetSize(); ++Y)
    {
        for (int32_t X = 0; X < m_current_figure_->GetSize(); ++X)
        {
            if (m_current_figure_->Get(Y, X) != 0)
            {
                return Y;
            }
        }
    }

    return 0;
}

void GameModel::GenerateNextFigures()
{
    m_current_figure_ = std::move(m_next_figure_);
    GenerateFigures();
}

void GameModel::UpdateScore(const int32_t number_removed_lines)
{
    const int32_t magic_number_score = 100;
    const int32_t additional_score = number_removed_lines * number_removed_lines * magic_number_score;

    m_current_score_ += additional_score;

    if (m_current_score_ >= m_speed_and_score.at(m_current_level_).second && m_current_level_ < m_speed_and_score.size())
    {
        ++m_current_level_;
    }
}

size_t GameModel::GetCurrentLevel() const
{
    return m_current_level_;
}

size_t GameModel::GetCurrentScore() const
{
    return m_current_score_;
}

float GameModel::GetCurrentSpeed() const
{
    return m_speed_and_score.at(m_current_level_).first;
}

int32_t GameModel::GetNeededScore() const
{
    return m_speed_and_score.at(m_current_level_).second;
}

Gamedata GameModel::GetGamedata() const
{
    return { m_gamefield_.get(), m_current_figure_.get(), m_next_figure_.get(), m_current_level_, m_current_score_ };
}

bool GameModel::GetIsGameover() const
{
    return m_is_gameover_;
}

void GameModel::CheckEndGame()
{
    for (int32_t Y = 0; Y < m_current_figure_->GetSize(); ++Y)
    {
        for (int32_t X = 0; X < m_current_figure_->GetSize(); ++X)
        {
            if (m_current_figure_->Get(Y, X) != 0)
            {
                const int32_t real_position_Y = m_current_figure_->GetCurrentPosition().Y + Y;
                const int32_t real_position_X = m_current_figure_->GetCurrentPosition().X + X;

                if (m_gamefield_->GetCell(real_position_Y, real_position_X) != 0)
                {
                    m_is_gameover_ = true;
                    return;
                }
            }
        }
    }
}

Gamefield* GameModel::GetGamefield()
{
    return m_gamefield_.get();
}

const Gamefield* GameModel::GetGamefield() const
{
    return m_gamefield_.get();
}

Figure* GameModel::GetCurrentFigure() const
{
    return m_current_figure_.get();
}

Figure* GameModel::GetNextFigure() const
{
    return m_next_figure_.get();
}