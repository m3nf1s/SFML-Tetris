#pragma once

#include <unordered_map>

#include "Delegate.h"

template<class Object, class... ParamArgs>
class Event
{
public:
    Event() = default;
    ~Event() = default;

    int64_t Subscribe(Delegate<Object, ParamArgs...> delegate)
    {
        int64_t bucket_index = delegate.ConvertAddressToInt();
        actions[bucket_index] = delegate;
        return bucket_index;
    }
    
    void Unsubscribe(const int64_t bucket_index)
    {
        actions.erase(bucket_index);
    }
    
    void Broadcast(ParamArgs... param_args)
    {
        for(auto [bucket_id, action] : actions)
        {
            action.Invoke(param_args...);
        }
    }
    
private:
    using Callbacks = std::unordered_map<int64_t, Delegate<Object, ParamArgs...>>;
    Callbacks actions;
};
