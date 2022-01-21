#include "GameInstance.h"
#include <memory.h>

int main()
{
    //GameInstance* instance = GameInstance::GetGameInstance();
    //instance->Start();
    //delete instance;

    std::unique_ptr<GameInstance> instance(GameInstance::GetGameInstance());
    instance->Start();

    return 0;
}