#ifndef IDGENERATOR_HPP
#define IDGENERATOR_HPP

template <typename id_type>
class IdGenerator        
{
public:
    IdGenerator(id_type init = 0)
        : m_Counter(init)
    {

    }

    ~IdGenerator()
    {

    }

    id_type GetNew()
    {
        ++m_Counter;
        return m_Counter;
    }

    void Invalidate(id_type id)
    {
    }

protected:
    id_type m_Counter;
};

#endif // IDGENERATOR_HPP
