#pragma once

template<class Object, class... ParamArgs>
class Delegate
{
    using PtrFucn = void(Object::*)(const ParamArgs&...);
public:
    Delegate() = default;
    
    Delegate(Object* instance, PtrFucn function)
        : m_instance_(instance)
        , m_function_(function)
    {        
    }
    
    void Bind(Object* instance, PtrFucn function)
    {
        m_instance_ = instance;
        m_function_ = function;        
    }
    
    void Invoke(ParamArgs... param_args)
    {
        if(m_instance_ != nullptr && m_function_ != nullptr)
        {
            (m_instance_->*m_function_)(param_args...);
        }
    }

    bool operator== (Delegate<Object, ParamArgs...> other) const 
    {
        return (other.m_instance_ == m_instance_) &&
               (other.m_function_ == m_function_);
    }

    int64_t ConvertAddressToInt() const
    {
        return reinterpret_cast<int64_t>(&m_function_);
    }
    
private:
    Object* m_instance_ = nullptr;
    PtrFucn m_function_ = nullptr;
};
