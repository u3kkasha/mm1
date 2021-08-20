#ifndef AUTO_ENABLED_ID_H
#define AUTO_ENABLED_ID_H

class Auto_enabled_id {
public:
    Auto_enabled_id()
    {

        id = total_id++;
        // for auto generating the IDs
    }

protected:
    int get_id()
    {
        return id;
    }

private:
    static inline int total_id = 0;
    int id;
};

#endif // AUTO_ENABLED_ID_H