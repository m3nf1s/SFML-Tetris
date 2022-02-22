#pragma once
#include <unordered_map>
#include <unordered_set>

#include "Delegate.h"

template<class Object, class... ParamArgs>
struct DelegateHasher
{
    int64_t operator()(Delegate<Object, ParamArgs...> delegate) const
    {
        return delegate.ConvertAddressToInt();
    }
};

template<class Object, class... ParamArgs>
class Event
{
public:
    Event() = default;
    ~Event() = default;

    int64_t Subscribe(Delegate<Object, ParamArgs...> delegate)
    {
        actions.insert(delegate);
        return delegate.ConvertAddressToInt();
    }
    
    void Unsubscribe(Delegate<Object, ParamArgs...> delegate)
    {
        actions.erase(delegate);
    }
    
    void Broadcast(ParamArgs... param_args)
    {       
        for(auto delegate : actions)
        {
            delegate.Invoke(param_args...);
        }
    }
    
private:
    using Callback = std::unordered_set<Delegate<Object, ParamArgs...>, DelegateHasher<Object, ParamArgs...>>;
    Callback actions;
};
